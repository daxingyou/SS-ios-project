//
//  Lightning.cpp
//  TQCocos2dx
//
//  Created by tq on 16/4/7.
//
//

#include "Lightning.h"

USING_NS_CC;

using namespace std;


Lightning::Lightning(float startPosX,float startPosY,float endPosX,float endPosY,float displace)
	:m_pTexture(NULL)
{
    _startPosX = startPosX;
    _startPosY = startPosY;
    _endPosX = endPosX;
    _endPosY = endPosY;
    _displace = displace;
	m_vecLightningTrackPoint.reserve(64);
	m_vecVertics.reserve(256);
	m_vecCoordinates.reserve(256);
}

Lightning::~Lightning()
{
	CC_SAFE_RELEASE(m_pTexture);
}

Lightning* Lightning::create( const std::string& strTextureFile, float startPosX,float startPosY,float endPosX,float endPosY,float displace )
{
	Lightning * pRet = new Lightning(  startPosX, startPosY, endPosX, endPosY, displace);
	if (pRet && pRet->init(strTextureFile))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}

	return pRet;
}

bool Lightning::init(const string& strFile)
{
	CCNode::init();

	setShaderProgram(CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTexture));
	setTexture(CCTextureCache::sharedTextureCache()->addImage(strFile.c_str()));
	ccTexParams params = {GL_LINEAR,GL_LINEAR,GL_REPEAT,GL_REPEAT};
	m_pTexture->setTexParameters(&params);
	
	scheduleUpdate();
		
	return true;
}
void Lightning::addSelfOnLayer(CCLayer * view ){
    this->setPosition(ccp(_startPosX,_startPosY));
    view->addChild(this,-1);
}


void Lightning::removeBySelf(){
    this->removeFromParentAndCleanup(true);
}

void Lightning::draw()
{
	if(m_vecVertics.empty()||m_vecCoordinates.empty()) return;

	CC_NODE_DRAW_SETUP();
	ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position | kCCVertexAttribFlag_TexCoords );
		
	ccGLBlendFunc( CC_BLEND_SRC,CC_BLEND_DST );
	ccGLBindTexture2D( m_pTexture->getName() );

	glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(&m_vecVertics[0]));
	glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(&m_vecCoordinates[0]));

	glDrawArrays(GL_TRIANGLE_STRIP, 0, m_vecVertics.size()/2);
}

void Lightning::addLightningSegment( float x1, float y1, float x2, float y2, float displace )
{
	if (displace <=m_pTexture->getPixelsWide()/2 )
	{
		m_vecLightningTrackPoint.push_back(ccp(x2,y2));
	}
	else
	{
		float mid_x = (x2+x1)/2;
		float mid_y = (y2+y1)/2;
		mid_x += (CCRANDOM_0_1() - 0.5) * displace;
		mid_y += (CCRANDOM_0_1() - 0.5) * displace;
		addLightningSegment(x1, y1, mid_x, mid_y, displace/2);
		addLightningSegment(mid_x, mid_y,x2, y2, displace/2);
	}
}

void Lightning::update(float delta)
{
	calculateVertex();
}

void Lightning::calculateVertex()
{
	m_vecLightningTrackPoint.clear();
	m_vecLightningTrackPoint.push_back(CCPointZero);
	addLightningSegment(0,0,_endPosX,_endPosY,_displace/3);

	m_vecVertics.clear();
	m_vecCoordinates.clear();

	for (size_t i=0; i<m_vecLightningTrackPoint.size(); i++)
	{
		const cocos2d::CCPoint& pt = m_vecLightningTrackPoint[i];

		m_vecVertics.push_back(pt.x);
		m_vecVertics.push_back(pt.y-m_pTexture->getPixelsHigh()/2);
		m_vecVertics.push_back(pt.x);
		m_vecVertics.push_back(pt.y+m_pTexture->getPixelsHigh()/2);

		m_vecCoordinates.push_back(i);
		m_vecCoordinates.push_back(0);
		m_vecCoordinates.push_back(i);
		m_vecCoordinates.push_back(1);
	}
}

void Lightning::setTexture( cocos2d::CCTexture2D *texture )
{
	CC_SAFE_RETAIN(texture);
	CC_SAFE_RELEASE(m_pTexture);
	m_pTexture = texture;
}


