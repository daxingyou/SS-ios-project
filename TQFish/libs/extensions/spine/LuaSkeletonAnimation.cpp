
#include "LuaSkeletonAnimation.h"
#include "spine-cocos2dx.h"
#include "extension.h"
#include <algorithm>

USING_NS_CC;
using std::min;
using std::max;
using std::vector;

namespace spine {

    LuaSkeletonAnimation::LuaSkeletonAnimation (const char* skeletonDataFile, const char* atlasFile, float scale)
    : spine::SkeletonAnimation(skeletonDataFile, atlasFile, scale)
    {
        
    }
    
    LuaSkeletonAnimation::LuaSkeletonAnimation(SkeletonAnimation* spineData)
    : spine::SkeletonAnimation(spineData->getSkeletonData())
    {
        
    }
    LuaSkeletonAnimation::~LuaSkeletonAnimation()
    {
       // ScriptHandlerMgr::getInstance()->removeObjectAllHandlers((void*)this);
    }
    
    LuaSkeletonAnimation* LuaSkeletonAnimation::createWithFile (const char* skeletonDataFile, const char* atlasFile, float scale)
    {
        LuaSkeletonAnimation* node = new (std::nothrow) LuaSkeletonAnimation(skeletonDataFile, atlasFile, scale);
        node->autorelease();
        return node;
    }
    
    LuaSkeletonAnimation* LuaSkeletonAnimation::createWithSkeletonAnimation(SkeletonAnimation* skeletonAnimation)
    {
        LuaSkeletonAnimation* node = new (std::nothrow) LuaSkeletonAnimation(skeletonAnimation);
        node->autorelease();
        return node;
    }

}
