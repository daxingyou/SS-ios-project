//
//  QRSprite.h
//  CGame
//
//  Created by neo on 15/12/16.
//
//

#ifndef QRSprite_h
#define QRSprite_h

#include "cocos2d.h"
USING_NS_CC;

typedef struct _texCoord {
    cocos2d::ccTex2F a;
    cocos2d::ccTex2F b;
    cocos2d::ccTex2F c;
    cocos2d::ccTex2F d;
} texCoord;
static inline texCoord texCoordCreate(cocos2d::ccTex2F a,cocos2d::ccTex2F b,cocos2d::ccTex2F c,cocos2d::ccTex2F d)
{
    texCoord t = { a , b , c, d };
    return t;
}

class QRSprite : public cocos2d::CCLayerColor{//tolua_export
    
    
private:
    cocos2d::CCTexture2D* _texture;
//    struct {cocos2d::ccTex2F a;cocos2d::ccTex2F b;cocos2d::ccTex2F c;cocos2d::ccTex2F d; } _texCoord;
    texCoord m_pTexCoords;
    virtual void draw();
    
    QRSprite();
    ~QRSprite();
    
    void listenBackToForeground(cocos2d::CCObject *obj);
    void loadShaderVertex(const char *vert, const char *frag);
    
    int m_size;
public:
    void saveQRcodeToFile(char *fileName);
    void addSelfByParent(CCLayer* parentNode , float x , float y);
    void removeBySelf();
    
    bool initWithString(const std::string& code);
    
    //tolua_begin
    static QRSprite* create(const std::string& code,char * iconName,int size = 512);
};
//tolua_end

#endif /* QRSprite_h */
