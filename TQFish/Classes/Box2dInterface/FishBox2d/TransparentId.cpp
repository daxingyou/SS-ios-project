//
//  TransparentId.cpp
//  TQCocos2dx
//
//  Created by tq on 16/4/8.
//
//

#include "TransparentId.h"


TransparentId::TransparentId(){
    m_previousPos = CCPointZero;
}
TransparentId::~TransparentId(){

}
TransparentId* TransparentId::create(char* m_id,CCNode * fishSprite,bool isNeedRotate,bool isNeedParentPos,bool isNeedParentAngle){
    TransparentId * m_TransparentId = new TransparentId();
    m_TransparentId->setId(m_id);
    m_TransparentId->setFishSprite(fishSprite);
    m_TransparentId->setIsNeedRotate(isNeedRotate);
    m_TransparentId->setIsNeedParentPos(isNeedParentPos);
    m_TransparentId->setIsNeedParentAngle(isNeedParentAngle);
    return m_TransparentId;
}

TransparentId* TransparentId::create(char* m_id,CCNode * fishSprite,bool isNeedRotate,bool isChildFish){
    TransparentId * m_TransparentId = new TransparentId();
    m_TransparentId->setId(m_id);
    m_TransparentId->setFishSprite(fishSprite);
    m_TransparentId->setIsNeedRotate(isNeedRotate);
    m_TransparentId->setIsNeedParentPos(isChildFish);
    m_TransparentId->setIsNeedParentAngle(false);
    return m_TransparentId;
}

void TransparentId::setIsChildFish(bool isChildFish){
    mIsChildFish = isChildFish;
}
bool TransparentId::getIsChildFish(){
    return mIsChildFish;
}

//是否需要获取父节点坐标
void TransparentId::setIsNeedParentPos(bool isNeedParentPos){
    mIsNeedParentPos = isNeedParentPos;
}
bool TransparentId::getIsNeedParentPos(){
    return mIsNeedParentPos;
}
//是否需要获取父节点角度
void TransparentId::setIsNeedParentAngle(bool isNeedParentAngle){
    mIsNeedParentAngle = isNeedParentAngle;
}
bool TransparentId::getIsNeedParentAngle(){
    return mIsNeedParentAngle;
}

void TransparentId::setIsNeedRotate(bool isNeedRotate){
    mIsNeedRotate = isNeedRotate;
}
bool TransparentId::getIsNeedRotate(){
    return mIsNeedRotate;
}

void TransparentId::setFishSprite(CCNode * fishSprite){
    mFishSprite = fishSprite;
}
CCNode* TransparentId::getFishSprite(){
    return mFishSprite;
}


void TransparentId::setId(char* m_id){
    id = m_id;
}
char* TransparentId::getId(){
    return id;
}