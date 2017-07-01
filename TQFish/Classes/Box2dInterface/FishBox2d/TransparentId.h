//
//  TransparentId.h
//  TQCocos2dx
//
//  Created by tq on 16/4/8.
//
//

#ifndef TransparentId_h
#define TransparentId_h

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
//由于box2d body 的userdata 是一个指针
//需要把字符串封装一下 才能赋值
class TransparentId
{
private:
    //刚体id
    char* id;
    //刚体中的精灵
    CCNode * mFishSprite;
    //这个刚体是否需要旋转
    bool mIsNeedRotate;
    //这个刚体是不是子鱼
    bool mIsNeedParentPos;
    bool mIsNeedParentAngle;
    bool mIsChildFish;
    //刚体中精灵 上一帧的坐标
    CCPoint m_previousPos;
    TransparentId();
    ~TransparentId();
public:
    static TransparentId* create(char* m_id,CCNode * fishSprite,bool isNeedRotate,bool isNeedParentPos,bool isNeedParentAngle);
    
    static TransparentId* create(char* m_id,CCNode * fishSprite,bool isNeedRotate,bool isChildFish);
    //刚体的id
    void setId(char* m_id);
    char* getId();
    //刚体中的精灵对象
    void setFishSprite(CCNode * fishSprite);
    CCNode* getFishSprite();
    //刚体或刚体中的精灵是否需要旋转
    void setIsNeedRotate(bool isNeedRotate);
    bool getIsNeedRotate();
    //是否需要获取父节点坐标
    void setIsNeedParentPos(bool isNeedParentPos);
    bool getIsNeedParentPos();
    //是否需要获取父节点角度
    void setIsNeedParentAngle(bool isNeedParentAngle);
    bool getIsNeedParentAngle();
    //还否是子鱼
    void setIsChildFish(bool isChildFish);
    bool getIsChildFish();
    
    inline CCPoint getPreviousPos() {return m_previousPos;};
    inline void setPreviousPos(CCPoint pos) {m_previousPos=pos;};
};


#endif /* TransparentId_h */
