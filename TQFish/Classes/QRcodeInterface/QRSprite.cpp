//
//  QRSprite.cpp
//  CGame
//
//  Created by neo on 15/12/16.
//
//

#include "QRSprite.h"
#include "qrencode.h"
using namespace cocos2d;

const static char * frag_shader =
"													\n\
#ifdef GL_ES										\n\
precision lowp float;								\n\
#endif												\n\
\n\
varying vec4 v_fragmentColor;						\n\
varying vec2 v_texCoord;							\n\
uniform sampler2D CC_Texture0;						\n\
\n\
void main()											\n\
{													\n\
    float c = texture2D(CC_Texture0, v_texCoord).a ; \n\
    gl_FragColor = vec4(1.0,1.0,1.0,1.0) * (1.0 - c ) + c *  v_fragmentColor ;\n\
    gl_FragColor.a = 1.0; \n\
} \n\
";


void QRSprite:: draw()
{

    CC_NODE_DRAW_SETUP();
    
    ccGLBlendFunc( m_tBlendFunc.src, m_tBlendFunc.dst );
    ccGLBindTexture2D( _texture->getName());
    
    ccGLEnableVertexAttribs( kCCVertexAttribFlag_PosColorTex);
    
    //
    // Attributes
    //
#ifdef EMSCRIPTEN
    setGLBufferData(m_pSquareVertices, 4 * sizeof(ccVertex2F), 0);
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    setGLBufferData(m_pSquareColors, 4 * sizeof(ccColor4F), 1);
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_FLOAT, GL_FALSE, 0, 0);
    
    setGLBufferData(&m_pTexCoords, 4 * sizeof(ccVertex2F), 0);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, 0, 0);
#else
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, m_pSquareVertices);
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_FLOAT, GL_FALSE, 0, m_pSquareColors);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords,2, GL_FLOAT, GL_FALSE, 0, &m_pTexCoords);
#endif // EMSCRIPTEN
    
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    CC_INCREMENT_GL_DRAWS(1);
}
bool QRSprite::initWithString(const std::string& code)
{
    CC_SAFE_RELEASE(_texture);
    
    QRcode* _qrcode = QRcode_encodeString(code.c_str(), 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    if (_qrcode != NULL) {
        CCLayerColor::initWithColor(ccc4(0, 0, 0, 255), m_size, m_size);
        _texture = new CCTexture2D;
        CCSize s = CCSizeMake(_qrcode->width, _qrcode->width);
        for (int i =0; i<_qrcode->width; ++i) {
            for (int j = 0; j<_qrcode->width; ++j) {
               if( (_qrcode->data[i * _qrcode->width +j] & 1) == 1)
               {
                   _qrcode->data[i * _qrcode->width +j] = 255;
               }
               else
               {
                   _qrcode->data[i * _qrcode->width +j] = 0;
               }
            }
        }
        _texture->initWithData(_qrcode->data, kCCTexture2DPixelFormat_A8, _qrcode->width, _qrcode->width,s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
        
        
        // shader program
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this,
                                                                      callfuncO_selector(QRSprite::listenBackToForeground),
                                                                      EVENT_COME_TO_FOREGROUND,
                                                                      NULL);
        loadShaderVertex(ccPositionTextureColor_vert, frag_shader);
        ignoreAnchorPointForPosition(false);
        QRcode_free(_qrcode);
        return true;
    }
    return false;
}


void QRSprite::addSelfByParent(CCLayer* parentNode , float x , float y){
    this->setPosition(ccp(x, y));
    this->setZOrder(999999);
    parentNode->addChild(this);

}
void QRSprite::saveQRcodeToFile(char *fileName){
    //添加白色背景
    CCLayerColor * bg = CCLayerColor::create(ccc4(255, 255, 255, 255), m_size+10, m_size+10);
    bg->setAnchorPoint(ccp(0, 0));
    bg->setPosition(ccp(-5, -5));
    bg->setZOrder(-1);
    this->addChild(bg);
    
    CCRenderTexture *screen = CCRenderTexture::create(m_size+10,m_size+10);
    screen->begin();
    this->setAnchorPoint(ccp(0, 0));
    this->setPosition(ccp(5, 5));
    this->visit();//将当前的二维码绘出来
    screen->end();
    screen->saveToFile(fileName, kCCImageFormatPNG);
}

void QRSprite::removeBySelf(){
    this->removeFromParentAndCleanup(true);
}


void QRSprite::loadShaderVertex(const char *vert, const char *frag)
{
    CCGLProgram *shader = new CCGLProgram();
    shader->initWithVertexShaderByteArray(vert, frag);
    
    shader->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
    shader->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
    shader->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
    
    shader->link();
    
    shader->updateUniforms();
    
    this->setShaderProgram(shader);
    
    shader->release();
}

void QRSprite::listenBackToForeground(CCObject *obj)
{
    this->setShaderProgram(NULL);
    loadShaderVertex(ccPositionTextureColor_vert, frag_shader);
}


QRSprite* QRSprite::create(const std::string& code,char * iconName,int size)
{
    QRSprite* s = new QRSprite;
    s->m_size = size;
    s->autorelease();
    if(s->initWithString(code))
    {
        if(iconName != ""){
            CCSprite * iconSp = CCSprite::create(iconName);
            iconSp->setPosition(ccp(size/2, size/2));
            iconSp->setZOrder(10);
            s->addChild(iconSp);
        }
        return s;
    }
    return NULL;
}

QRSprite::QRSprite()
{
    _texture = NULL;
    ccTex2F a = tex2(0,1);
    ccTex2F b = tex2(1,1);
    ccTex2F c = tex2(0,0);
    ccTex2F d = tex2(1,0);
    m_pTexCoords = texCoordCreate(a,b,c,d);
}
QRSprite::~QRSprite()
{
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, EVENT_COME_TO_FOREGROUND);
    CC_SAFE_RELEASE(_texture);
}