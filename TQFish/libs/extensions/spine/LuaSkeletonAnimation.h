
#ifndef SPINE_LUASKELETONANIMATION_H_
#define SPINE_LUASKELETONANIMATION_H_

#include "spine.h"
#include "SkeletonRenderer.h"
#include "SkeletonAnimation.h"
#include "cocos2d.h"
#include <functional>

namespace spine {

    class LuaSkeletonAnimation: public spine::SkeletonAnimation {
    public:
        static LuaSkeletonAnimation* createWithFile (const char* skeletonDataFile, const char* atlasFile, float scale = 1);
        
        // preload spine   添加下面两个方法
        static LuaSkeletonAnimation* createWithSkeletonAnimation(SkeletonAnimation* skeletonAnimation);
        LuaSkeletonAnimation(SkeletonAnimation* spineData);
        
        LuaSkeletonAnimation (const char* skeletonDataFile, const char* atlasFile, float scale = 1);
        
        virtual ~LuaSkeletonAnimation();
    };
}

#endif /* SPINE_SKELETONANIMATION_H_ */
