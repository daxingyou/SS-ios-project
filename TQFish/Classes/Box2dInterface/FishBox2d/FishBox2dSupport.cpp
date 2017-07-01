//
//  FishBox2dSupport.cpp
//  TQCocos2dx
//
//  Created by tq on 16/4/7.
//
//

#include "FishBox2dSupport.h"
#define PTM_RATIO 32.0

FishBox2dSupport * m_FishBox2dSupport = NULL;


FishBox2dSupport::FishBox2dSupport(){
    
    b2Vec2 gravity = b2Vec2(0, 0);
    m_b2World = new b2World(gravity);
    m_b2World->SetAllowSleeping(false);
    
    m_b2ContactListener = new QContactListener();
    m_b2World->SetContactListener(m_b2ContactListener);
}

FishBox2dSupport::~FishBox2dSupport(){
    m_b2World = NULL;
    m_b2ContactListener = NULL;
    m_FishBox2dSupport = NULL;
}
//获取捕鱼 box2d 的单例
FishBox2dSupport * FishBox2dSupport::GetInstance(){
    if (m_FishBox2dSupport == NULL) {
        m_FishBox2dSupport = new FishBox2dSupport();
    }
    return m_FishBox2dSupport;
}
//删除捕鱼 box2d 的单例
void FishBox2dSupport::ReleaseFishBox2dSupport(){
    delete m_b2ContactListener;
    delete m_b2World;
    delete m_FishBox2dSupport;
}
//获取box2d 世界
b2World * FishBox2dSupport::getFishBox2dWorld(){
    return m_b2World;
}

void FishBox2dSupport::invokeFishCallbackFunction(char* id_a,char* id_b){
    if(mLuaHandlerId > 0)
    {
        CCLuaStack* stack = CCLuaEngine::defaultEngine()->getLuaStack();
        stack->pushString(id_a);
        stack->pushString(id_b);
        stack->executeFunctionByHandler(mLuaHandlerId, 2);
//        stack->clean();
    }
}

void FishBox2dSupport::registerScriptHandler(int nHandler){
    mLuaHandlerId = nHandler;
}


b2Vec2 FishBox2dSupport::getB2Vec2Obj(float x,float y){
    return b2Vec2(x,y);
}

void FishBox2dSupport::b2BodyUpdateTransform(b2Body * mBody,float x,float y,float fRotation){
    b2Vec2 pos = b2Vec2(x,y);
    float angle = -1 * CC_DEGREES_TO_RADIANS(fRotation);
    mBody->SetTransform(pos,angle);
}

void FishBox2dSupport::b2worldUpdate(float dt)
{
    m_b2World->Step(dt, 10, 10);
    
    
    for (b2Body* b=m_b2World->GetBodyList(); b; b=b->GetNext())
    {
        TransparentId* bodyUserData = (TransparentId*) b->GetUserData();
        CCNode* fishSprite = bodyUserData->getFishSprite();
        if (fishSprite)
        {
            
            //精灵当前的world坐标
            CCPoint pSPos = fishSprite->getPosition();
            //精灵新的角度
            float fRotation = fishSprite->getRotation();
            
            //如果是鱼群中的鱼要转化坐标
            if (bodyUserData->getIsNeedParentPos())
            {
                pSPos = fishSprite->getParent()->convertToWorldSpace(pSPos);
            }
            //是子鱼并且不用旋转 角度跟父节点是一样的
            if (bodyUserData->getIsNeedParentAngle()) {
                fRotation = fishSprite->getParent()->getRotation();
            }
            //调整鱼的旋转角度
            if (bodyUserData->getIsNeedRotate())
            {
            
                //更新鱼的角度
                CCPoint newPos = pSPos;//当前坐标
                CCPoint previousPos = bodyUserData->getPreviousPos();//上一帧坐标
                
                CCPoint dirPoint = ccpSub(newPos, previousPos);
                
                if (dirPoint.x != 0 && dirPoint.y != 0)
                {
                    bodyUserData->setPreviousPos(newPos);
                    float fRadian = atanf(dirPoint.y/dirPoint.x);
                        
                    
                    if((dirPoint.y > 0 && dirPoint.x > 0)
                        || (dirPoint.y < 0 && dirPoint.x > 0))
                    {
                        fRadian = M_PI_2 - fRadian;
                    }
                    else if((dirPoint.y < 0 && dirPoint.x < 0)||
                            (dirPoint.y > 0 && dirPoint.x < 0))
                    {
                        fRadian = -M_PI_2 - fRadian;
                    }
                        
                    //加90度是为了保证初始状态时精灵的头部向上
                    fRotation = CC_RADIANS_TO_DEGREES(fRadian + M_PI_2);
                    //更新鱼的角度
                    fishSprite->setRotation(fRotation);
                }
            }
            
            b2Vec2 pos = b2Vec2(pSPos.x/PTM_RATIO, pSPos.y/PTM_RATIO);
            float angle = -1 * CC_DEGREES_TO_RADIANS(fRotation);
            b->SetTransform(pos, angle);
        }
    }
}


