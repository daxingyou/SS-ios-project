//
//  FishBox2dSupport.h
//  TQCocos2dx
//
//  Created by tq on 16/4/7.
//
//

#ifndef FishBox2dSupport_h
#define FishBox2dSupport_h

#include <stdio.h>
#include "Box2D/Box2D.h"
#include "QContactListener.h"
#include "CCLuaStack.h"
#include "CCLuaEngine.h"

class FishBox2dSupport
{
private:
    FishBox2dSupport();
    ~FishBox2dSupport();
    
public:
    //获取单例 创建单例的同时  物理世界和监听已经同步创建出来了
    static FishBox2dSupport * GetInstance();
    //释放单例
    void ReleaseFishBox2dSupport();
    //获取单例创建的物理世界
    b2World * getFishBox2dWorld();

    
    b2World *m_b2World;
    b2ContactListener *m_b2ContactListener;
    //碰撞回调函数 C++调用lua
    void invokeFishCallbackFunction(char* id_a,char* id_b);
    //注册监听方法  LUA调用此方法 把监听方法传过来
    void registerScriptHandler(int nHandler);
    //原来用于在C++层获取所需对象  没有作用  以废弃
    b2Vec2 getB2Vec2Obj(float x,float y);
    //在C++层更新box2d的刚体信息  有效果  但不能完全解决卡顿   以废弃
    void b2BodyUpdateTransform(b2Body * mBody,float x,float y,float fRotation);
    //鱼的旋转  box2d刚体的更新 全部移至C++中
    void b2worldUpdate(float dt);
    
private:
    int mLuaHandlerId;
    
};



#endif /* FishBox2dSupport_h */
