#ifndef __LIGINTNING_H__
#define __LIGINTNING_H__

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class Lightning : public cocos2d::CCNode
{
public:
	Lightning(float startPosX,float startPosY,float endPosX,float endPosY,float displace);
	~Lightning();

public:
    static Lightning* create(const std::string& strTextureFile, float startPosX,float startPosY,float endPosX,float endPosY,float displace = 100);
	virtual bool init(const std::string& strTextureFile);

protected:
	virtual void draw()/*override*/;
	virtual void update(float fDelta)/*override*/;

public:
	void setTexture(cocos2d::CCTexture2D *texture);
    
    void addSelfOnLayer(CCLayer * view);
    void removeBySelf();
protected:
	void calculateVertex();
	void addLightningSegment(float x1, float y1, float x2, float y2, float displace);

protected:
	std::vector<cocos2d::CCPoint>	m_vecLightningTrackPoint;
	std::vector<float>				m_vecVertics;
	std::vector<float>				m_vecCoordinates;
	cocos2d::CCTexture2D*			m_pTexture;
    float							_startPosX;
    float							_startPosY;
    float							_endPosX;
    float							_endPosY;
    float							_displace;
};

#endif // __HELLOWORLD_SCENE_H__
