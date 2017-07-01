/*
** Lua binding: SkeletonAnimation
** Generated automatically by tolua++-1.0.92 on 01/20/17 14:46:19.
*/
extern "C" {
#include "tolua_fix.h"
}
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

//TOLUA_API int  tolua_SkeletonRenderer_open (lua_State* tolua_S);
/* Exported function */
TOLUA_API int  tolua_SkeletonAnimation_open (lua_State* tolua_S);

#include "CCLuaStack.h"
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_cocos2d__CCRect (lua_State* tolua_S)
{
    cocos2d::CCRect* self = (cocos2d::CCRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_SkeletonAnimation (lua_State* tolua_S)
{
    spine::SkeletonAnimation* self = (spine::SkeletonAnimation*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SkeletonRenderer (lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cocos2d::CCRect");
    tolua_usertype(tolua_S,"spSlot");
    tolua_usertype(tolua_S,"cocos2d::ccBlendFunc");
    tolua_usertype(tolua_S,"cocos2d::CCBlendProtocol");
    tolua_usertype(tolua_S,"BlendFunc");
    tolua_usertype(tolua_S,"blendFunc");
    tolua_usertype(tolua_S,"spAttachment");
    tolua_usertype(tolua_S,"spBone");
    tolua_usertype(tolua_S,"spSkeleton");
    tolua_usertype(tolua_S,"spSkeletonData");
    tolua_usertype(tolua_S,"cocos2d::CCNodeRGBA");
    tolua_usertype(tolua_S,"LUA_FUNCTION");
    tolua_usertype(tolua_S,"spTrackEntry");
    tolua_usertype(tolua_S,"SkeletonAnimation");
    tolua_usertype(tolua_S,"spSkeletonData");
    tolua_usertype(tolua_S,"SkeletonRenderer");
    tolua_usertype(tolua_S,"spEvent");
    tolua_usertype(tolua_S,"spAnimationStateData");
    tolua_usertype(tolua_S,"EventListener");
    tolua_usertype(tolua_S,"spEventType");
    tolua_usertype(tolua_S,"spAnimationState");
    tolua_usertype(tolua_S,"CompleteListener");
    tolua_usertype(tolua_S,"StartListener");
    tolua_usertype(tolua_S,"EndListener");
    tolua_usertype(tolua_S,"spAtlas");
}


/* get function: skeleton of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonRenderer_skeleton_ptr
static int tolua_get_SkeletonRenderer_skeleton_ptr(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skeleton'",NULL);
#endif
    tolua_pushusertype(tolua_S,(void*)self->skeleton,"spSkeleton");
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skeleton of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonRenderer_skeleton_ptr
static int tolua_set_SkeletonRenderer_skeleton_ptr(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skeleton'",NULL);
    if (!tolua_isusertype(tolua_S,2,"spSkeleton",0,&tolua_err))
    tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
    self->skeleton = ((spSkeleton*)  tolua_tousertype(tolua_S,2,0))
    ;
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rootBone of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonRenderer_rootBone_ptr
static int tolua_get_SkeletonRenderer_rootBone_ptr(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rootBone'",NULL);
#endif
    tolua_pushusertype(tolua_S,(void*)self->rootBone,"spBone");
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rootBone of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonRenderer_rootBone_ptr
static int tolua_set_SkeletonRenderer_rootBone_ptr(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rootBone'",NULL);
    if (!tolua_isusertype(tolua_S,2,"spBone",0,&tolua_err))
    tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
    self->rootBone = ((spBone*)  tolua_tousertype(tolua_S,2,0))
    ;
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeScale of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonRenderer_timeScale
static int tolua_get_SkeletonRenderer_timeScale(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
#endif
    tolua_pushnumber(tolua_S,(lua_Number)self->timeScale);
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeScale of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonRenderer_timeScale
static int tolua_set_SkeletonRenderer_timeScale(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
    if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
    tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
    self->timeScale = ((float)  tolua_tonumber(tolua_S,2,0))
    ;
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: debugSlots of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonRenderer_debugSlots
static int tolua_get_SkeletonRenderer_debugSlots(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugSlots'",NULL);
#endif
    tolua_pushboolean(tolua_S,(bool)self->debugSlots);
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: debugSlots of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonRenderer_debugSlots
static int tolua_set_SkeletonRenderer_debugSlots(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugSlots'",NULL);
    if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
    tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
    self->debugSlots = ((bool)  tolua_toboolean(tolua_S,2,0))
    ;
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: debugBones of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonRenderer_debugBones
static int tolua_get_SkeletonRenderer_debugBones(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugBones'",NULL);
#endif
    tolua_pushboolean(tolua_S,(bool)self->debugBones);
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: debugBones of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonRenderer_debugBones
static int tolua_set_SkeletonRenderer_debugBones(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugBones'",NULL);
    if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
    tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
    self->debugBones = ((bool)  tolua_toboolean(tolua_S,2,0))
    ;
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: premultipliedAlpha of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonRenderer_premultipliedAlpha
static int tolua_get_SkeletonRenderer_premultipliedAlpha(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'premultipliedAlpha'",NULL);
#endif
    tolua_pushboolean(tolua_S,(bool)self->premultipliedAlpha);
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: premultipliedAlpha of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonRenderer_premultipliedAlpha
static int tolua_set_SkeletonRenderer_premultipliedAlpha(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'premultipliedAlpha'",NULL);
    if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
    tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
    self->premultipliedAlpha = ((bool)  tolua_toboolean(tolua_S,2,0))
    ;
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithData of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_createWithData00
static int tolua_SkeletonRenderer_SkeletonRenderer_createWithData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
        !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
        bool ownsSkeletonData = ((bool)  tolua_toboolean(tolua_S,3,false));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  spine::SkeletonRenderer::createWithData(skeletonData,ownsSkeletonData);
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'createWithData'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_createWithFile00
static int tolua_SkeletonRenderer_SkeletonRenderer_createWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,5,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
        spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
        float scale = ((float)  tolua_tonumber(tolua_S,4,0));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  spine::SkeletonRenderer::createWithFile(skeletonDataFile,atlas,scale);
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'createWithFile'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_createWithFile01
static int tolua_SkeletonRenderer_SkeletonRenderer_createWithFile01(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isstring(tolua_S,3,0,&tolua_err) ||
        !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,5,&tolua_err)
        )
    goto tolua_lerror;
    else
    {
        const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
        const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
        float scale = ((float)  tolua_tonumber(tolua_S,4,0));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  spine::SkeletonRenderer::createWithFile(skeletonDataFile,atlasFile,scale);
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
        }
    }
    return 1;
tolua_lerror:
    return tolua_SkeletonRenderer_SkeletonRenderer_createWithFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSkeletonData of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_getSkeletonData00
static int tolua_SkeletonRenderer_SkeletonRenderer_getSkeletonData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SkeletonRenderer'", NULL);
#endif
        {
            spSkeletonData* tolua_ret = (spSkeletonData*)  self->getSkeletonData();
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"spSkeletonData");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'SkeletonRenderer'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE


/* method: new of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_new00
static int tolua_SkeletonRenderer_SkeletonRenderer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
        !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
        bool ownsSkeletonData = ((bool)  tolua_toboolean(tolua_S,3,false));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  Mtolua_new((spine::SkeletonRenderer)(skeletonData,ownsSkeletonData));
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_new00_local
static int tolua_SkeletonRenderer_SkeletonRenderer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
        !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
        bool ownsSkeletonData = ((bool)  tolua_toboolean(tolua_S,3,false));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  Mtolua_new((spine::SkeletonRenderer)(skeletonData,ownsSkeletonData));
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_new01
static int tolua_SkeletonRenderer_SkeletonRenderer_new01(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,5,&tolua_err)
        )
    goto tolua_lerror;
    else
    {
        const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
        spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
        float scale = ((float)  tolua_tonumber(tolua_S,4,0));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  Mtolua_new((spine::SkeletonRenderer)(skeletonDataFile,atlas,scale));
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
        }
    }
    return 1;
tolua_lerror:
    return tolua_SkeletonRenderer_SkeletonRenderer_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_new01_local
static int tolua_SkeletonRenderer_SkeletonRenderer_new01_local(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,5,&tolua_err)
        )
    goto tolua_lerror;
    else
    {
        const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
        spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
        float scale = ((float)  tolua_tonumber(tolua_S,4,0));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  Mtolua_new((spine::SkeletonRenderer)(skeletonDataFile,atlas,scale));
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
    }
    return 1;
tolua_lerror:
    return tolua_SkeletonRenderer_SkeletonRenderer_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_new02
static int tolua_SkeletonRenderer_SkeletonRenderer_new02(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isstring(tolua_S,3,0,&tolua_err) ||
        !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,5,&tolua_err)
        )
    goto tolua_lerror;
    else
    {
        const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
        const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
        float scale = ((float)  tolua_tonumber(tolua_S,4,0));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  Mtolua_new((spine::SkeletonRenderer)(skeletonDataFile,atlasFile,scale));
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
        }
    }
    return 1;
tolua_lerror:
    return tolua_SkeletonRenderer_SkeletonRenderer_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_new02_local
static int tolua_SkeletonRenderer_SkeletonRenderer_new02_local(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isstring(tolua_S,3,0,&tolua_err) ||
        !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
        !tolua_isnoobj(tolua_S,5,&tolua_err)
        )
    goto tolua_lerror;
    else
    {
        const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
        const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
        float scale = ((float)  tolua_tonumber(tolua_S,4,0));
        {
            spine::SkeletonRenderer* tolua_ret = (spine::SkeletonRenderer*)  Mtolua_new((spine::SkeletonRenderer)(skeletonDataFile,atlasFile,scale));
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonRenderer");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
    }
    return 1;
tolua_lerror:
    return tolua_SkeletonRenderer_SkeletonRenderer_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_delete00
static int tolua_SkeletonRenderer_SkeletonRenderer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
        Mtolua_delete(self);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_update00
static int tolua_SkeletonRenderer_SkeletonRenderer_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        float deltaTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
        {
            self->update(deltaTime);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_draw00
static int tolua_SkeletonRenderer_SkeletonRenderer_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
        {
            self->draw();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boundingBox of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_boundingBox00
static int tolua_SkeletonRenderer_SkeletonRenderer_boundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boundingBox'", NULL);
#endif
        {
            cocos2d::CCRect tolua_ret = (cocos2d::CCRect)  self->boundingBox();
            {
#ifdef __cplusplus
                void* tolua_obj = Mtolua_new((cocos2d::CCRect)(tolua_ret));
                tolua_pushusertype(tolua_S,tolua_obj,"cocos2d::CCRect");
                tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
                void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(cocos2d::CCRect));
                tolua_pushusertype(tolua_S,tolua_obj,"cocos2d::CCRect");
                tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
            }
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'boundingBox'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateWorldTransform of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_updateWorldTransform00
static int tolua_SkeletonRenderer_SkeletonRenderer_updateWorldTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateWorldTransform'", NULL);
#endif
        {
            self->updateWorldTransform();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'updateWorldTransform'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setToSetupPose of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_setToSetupPose00
static int tolua_SkeletonRenderer_SkeletonRenderer_setToSetupPose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setToSetupPose'", NULL);
#endif
        {
            self->setToSetupPose();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setToSetupPose'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBonesToSetupPose of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_setBonesToSetupPose00
static int tolua_SkeletonRenderer_SkeletonRenderer_setBonesToSetupPose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBonesToSetupPose'", NULL);
#endif
        {
            self->setBonesToSetupPose();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setBonesToSetupPose'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSlotsToSetupPose of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_setSlotsToSetupPose00
static int tolua_SkeletonRenderer_SkeletonRenderer_setSlotsToSetupPose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSlotsToSetupPose'", NULL);
#endif
        {
            self->setSlotsToSetupPose();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setSlotsToSetupPose'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findBone of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_findBone00
static int tolua_SkeletonRenderer_SkeletonRenderer_findBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"const SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        const spine::SkeletonRenderer* self = (const spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        const char* boneName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findBone'", NULL);
#endif
        {
            spBone* tolua_ret = (spBone*)  self->findBone(boneName);
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"spBone");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'findBone'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findSlot of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_findSlot00
static int tolua_SkeletonRenderer_SkeletonRenderer_findSlot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"const SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        const spine::SkeletonRenderer* self = (const spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        const char* slotName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findSlot'", NULL);
#endif
        {
            spSlot* tolua_ret = (spSlot*)  self->findSlot(slotName);
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"spSlot");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'findSlot'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkin of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_setSkin00
static int tolua_SkeletonRenderer_SkeletonRenderer_setSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        const char* skinName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkin'", NULL);
#endif
        {
            bool tolua_ret = (bool)  self->setSkin(skinName);
            tolua_pushboolean(tolua_S,(bool)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setSkin'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttachment of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_getAttachment00
static int tolua_SkeletonRenderer_SkeletonRenderer_getAttachment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"const SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isstring(tolua_S,3,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        const spine::SkeletonRenderer* self = (const spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        const char* slotName = ((const char*)  tolua_tostring(tolua_S,2,0));
        const char* attachmentName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttachment'", NULL);
#endif
        {
            spAttachment* tolua_ret = (spAttachment*)  self->getAttachment(slotName,attachmentName);
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"spAttachment");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'getAttachment'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAttachment of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_setAttachment00
static int tolua_SkeletonRenderer_SkeletonRenderer_setAttachment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isstring(tolua_S,3,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        const char* slotName = ((const char*)  tolua_tostring(tolua_S,2,0));
        const char* attachmentName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAttachment'", NULL);
#endif
        {
            bool tolua_ret = (bool)  self->setAttachment(slotName,attachmentName);
            tolua_pushboolean(tolua_S,(bool)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setAttachment'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CC_PROPERTY of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_CC_PROPERTY00
static int tolua_SkeletonRenderer_SkeletonRenderer_CC_PROPERTY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"cocos2d::ccBlendFunc",0,&tolua_err)) ||
        (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"blendFunc",0,&tolua_err)) ||
        (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"BlendFunc",0,&tolua_err)) ||
        !tolua_isnoobj(tolua_S,5,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        cocos2d::ccBlendFunc tolua_var_1 = *((cocos2d::ccBlendFunc*)  tolua_tousertype(tolua_S,2,0));
        //lihy 有事 先暂停
//        blendFunc tolua_var_2 = *((blendFunc*)  tolua_tousertype(tolua_S,3,0));
//        BlendFunc tolua_var_3 = *((BlendFunc*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CC_PROPERTY'", NULL);
#endif
        {
            //self->CC_PROPERTY(tolua_var_1,tolua_var_2,tolua_var_3);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'CC_PROPERTY'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacityModifyRGB of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_setOpacityModifyRGB00
static int tolua_SkeletonRenderer_SkeletonRenderer_setOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
        bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacityModifyRGB'", NULL);
#endif
        {
            self->setOpacityModifyRGB(value);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setOpacityModifyRGB'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOpacityModifyRGB of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_SkeletonRenderer_SkeletonRenderer_isOpacityModifyRGB00
static int tolua_SkeletonRenderer_SkeletonRenderer_isOpacityModifyRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SkeletonRenderer",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOpacityModifyRGB'", NULL);
#endif
        {
            bool tolua_ret = (bool)  self->isOpacityModifyRGB();
            tolua_pushboolean(tolua_S,(bool)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'isOpacityModifyRGB'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __cocos2d of class  SkeletonRenderer */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonRenderer___cocos2d__CCBlendProtocol__
static int tolua_get_SkeletonRenderer___cocos2d__CCBlendProtocol__(lua_State* tolua_S)
{
    spine::SkeletonRenderer* self = (spine::SkeletonRenderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__cocos2d'",NULL);
#endif
#ifdef __cplusplus
    tolua_pushusertype(tolua_S,(void*)static_cast<cocos2d::CCBlendProtocol*>(self), "cocos2d::CCBlendProtocol");
#else
    tolua_pushusertype(tolua_S,(void*)((cocos2d::CCBlendProtocol*)self), "cocos2d::CCBlendProtocol");
#endif
    return 1;
}
#endif //#ifndef TOLUA_DISABLE


/////////////////////////////////////////////////////////

/* get function: state of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonAnimation_state_ptr
static int tolua_get_SkeletonAnimation_state_ptr(lua_State* tolua_S)
{
    spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
#endif
    tolua_pushusertype(tolua_S,(void*)self->state,"spAnimationState");
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: state of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonAnimation_state_ptr
static int tolua_set_SkeletonAnimation_state_ptr(lua_State* tolua_S)
{
    spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
    if (!tolua_isusertype(tolua_S,2,"spAnimationState",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->state = ((spAnimationState*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithData of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_createWithData00
static int tolua_SkeletonAnimation_SkeletonAnimation_createWithData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  spine::SkeletonAnimation::createWithData(skeletonData);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

///* method: getSkeletonData of class  SkeletonAnimation */
//#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_getSkeletonData00
//static int tolua_SkeletonAnimation_SkeletonAnimation_getSkeletonData00(lua_State* tolua_S)
//{
//#ifndef TOLUA_RELEASE
//    tolua_Error tolua_err;
//    if (
//        !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
//        !tolua_isnoobj(tolua_S,2,&tolua_err)
//        )
//        goto tolua_lerror;
//    else
//#endif
//    {
//        spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
//#ifndef TOLUA_RELEASE
//        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSkeletonData'", NULL);
//#endif
//        {
//            spSkeletonData* tolua_ret = (spSkeletonData*)  self->getSkeletonData();
//            tolua_pushusertype(tolua_S,(void*)tolua_ret,"spSkeletonData");
//        }
//    }
//    return 1;
//#ifndef TOLUA_RELEASE
//tolua_lerror:
//    tolua_error(tolua_S,"#ferror in function 'getSkeletonData'.",&tolua_err);
//    return 0;
//#endif
//}
//#endif //#ifndef TOLUA_DISABLE


/* method: createWithFile of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_createWithFile00
static int tolua_SkeletonAnimation_SkeletonAnimation_createWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  spine::SkeletonAnimation::createWithFile(skeletonDataFile,atlas,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_createWithFile01
static int tolua_SkeletonAnimation_SkeletonAnimation_createWithFile01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  spine::SkeletonAnimation::createWithFile(skeletonDataFile,atlasFile,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_SkeletonAnimation_SkeletonAnimation_createWithFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_new00
static int tolua_SkeletonAnimation_SkeletonAnimation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  Mtolua_new((spine::SkeletonAnimation)(skeletonData));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_new00_local
static int tolua_SkeletonAnimation_SkeletonAnimation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  Mtolua_new((spine::SkeletonAnimation)(skeletonData));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_new01
static int tolua_SkeletonAnimation_SkeletonAnimation_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  Mtolua_new((spine::SkeletonAnimation)(skeletonDataFile,atlas,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_SkeletonAnimation_SkeletonAnimation_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_new01_local
static int tolua_SkeletonAnimation_SkeletonAnimation_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  Mtolua_new((spine::SkeletonAnimation)(skeletonDataFile,atlas,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_SkeletonAnimation_SkeletonAnimation_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_new02
static int tolua_SkeletonAnimation_SkeletonAnimation_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  Mtolua_new((spine::SkeletonAnimation)(skeletonDataFile,atlasFile,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_SkeletonAnimation_SkeletonAnimation_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_new02_local
static int tolua_SkeletonAnimation_SkeletonAnimation_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   spine::SkeletonAnimation* tolua_ret = (spine::SkeletonAnimation*)  Mtolua_new((spine::SkeletonAnimation)(skeletonDataFile,atlasFile,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkeletonAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_SkeletonAnimation_SkeletonAnimation_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_delete00
static int tolua_SkeletonAnimation_SkeletonAnimation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_update00
static int tolua_SkeletonAnimation_SkeletonAnimation_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  float deltaTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(deltaTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimationStateData of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setAnimationStateData00
static int tolua_SkeletonAnimation_SkeletonAnimation_setAnimationStateData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spAnimationStateData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  spAnimationStateData* stateData = ((spAnimationStateData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationStateData'", NULL);
#endif
  {
   self->setAnimationStateData(stateData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationStateData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMix of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setMix00
static int tolua_SkeletonAnimation_SkeletonAnimation_setMix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  const char* fromAnimation = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* toAnimation = ((const char*)  tolua_tostring(tolua_S,3,0));
  float duration = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMix'", NULL);
#endif
  {
   self->setMix(fromAnimation,toAnimation,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setAnimation00
static int tolua_SkeletonAnimation_SkeletonAnimation_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->setAnimation(trackIndex,name,loop);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAnimation of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_addAnimation00
static int tolua_SkeletonAnimation_SkeletonAnimation_addAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,4,0));
  float delay = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimation'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->addAnimation(trackIndex,name,loop,delay);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrent of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_getCurrent00
static int tolua_SkeletonAnimation_SkeletonAnimation_getCurrent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrent'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->getCurrent(trackIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTracks of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_clearTracks00
static int tolua_SkeletonAnimation_SkeletonAnimation_clearTracks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTracks'", NULL);
#endif
  {
   self->clearTracks();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTracks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTrack of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_clearTrack00
static int tolua_SkeletonAnimation_SkeletonAnimation_clearTrack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTrack'", NULL);
#endif
  {
   self->clearTrack(trackIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTrack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonAnimation_startListener
static int tolua_get_SkeletonAnimation_startListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startListener'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->startListener,"StartListener");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonAnimation_startListener
static int tolua_set_SkeletonAnimation_startListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startListener'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StartListener",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startListener = *((spine::StartListener*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonAnimation_endListener
static int tolua_get_SkeletonAnimation_endListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endListener'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->endListener,"EndListener");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonAnimation_endListener
static int tolua_set_SkeletonAnimation_endListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endListener'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EndListener",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endListener = *((spine::EndListener*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: completeListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonAnimation_completeListener
static int tolua_get_SkeletonAnimation_completeListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'completeListener'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->completeListener,"CompleteListener");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: completeListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonAnimation_completeListener
static int tolua_set_SkeletonAnimation_completeListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'completeListener'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CompleteListener",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->completeListener = *((spine::CompleteListener*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eventListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_SkeletonAnimation_eventListener
static int tolua_get_SkeletonAnimation_eventListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventListener'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->eventListener,"EventListener");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eventListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_SkeletonAnimation_eventListener
static int tolua_set_SkeletonAnimation_eventListener(lua_State* tolua_S)
{
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventListener'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EventListener",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eventListener = *((spine::EventListener*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE




class LuaSpineWrapper:public cocos2d::CCObject
{
public:
    LuaSpineWrapper();
    virtual ~LuaSpineWrapper();

    void movementEventCallback()
    {
        if (0 != m_lHandler)
        {
            CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
            CCLuaStack* pStack = pEngine->getLuaStack();

            //        pStack->pushCCObject(armature, "CCArmature");
            //        pStack->pushInt(type);
            //pStack->pushString(movementID);
            pStack->executeFunctionByHandler(m_lHandler, 3);
            pStack->clean();
        }
    }

    void setHandler(int handler){ m_lHandler = handler; }
    int  getHandler() { return m_lHandler; }
private:
    long m_lHandler;
};

LuaSpineWrapper::LuaSpineWrapper():m_lHandler(0)
{

}

LuaSpineWrapper::~LuaSpineWrapper()
{

}

void LuaSpine()
{

}

/* method: setMovementEventCallFunc of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setSpineEventCallFunc00
static int tolua_SkeletonAnimation_SkeletonAnimation_setSpineEventCallFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
         !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
         !tolua_isusertype(tolua_S,2,"spTrackEntry",0,&tolua_err) ||
         (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
         !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
    goto tolua_lerror;
    else
#endif
    {
        spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMovementEventCallFunc'", NULL);
#endif
        LuaSpineWrapper* wrapper = new LuaSpineWrapper();
        if (NULL == wrapper)
        {
            tolua_error(tolua_S,"LuaArmatureWrapper create fail\n", NULL);
            return 0;
        }

        wrapper->autorelease();
        spTrackEntry* entry = ((spTrackEntry*)  tolua_tousertype(tolua_S,2,0));
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,3,0));

        wrapper->setHandler(handler);
        self->setUserObject(wrapper);

        self->endListener = [] (int trackIndex) {//同理，结束动作监听
            CCLog("%d end", trackIndex);
        };

        self->eventListener= [] (int trackIndex, spEvent* event) {//同理，事件监听，在spine中编辑好event导出
            CCLog("%d event: %s, %d, %f",trackIndex, event->data->name, event->intValue, event->floatValue);
            //wrapper->movementEventCallback();
        };

        self->setEventListener(entry, self->eventListener);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setMovementEventCallFunc'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE




/* method: setStartListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setStartListener00
static int tolua_SkeletonAnimation_SkeletonAnimation_setStartListener00(lua_State* tolua_S)
{
//#ifndef TOLUA_RELEASE
// tolua_Error tolua_err;
// if (
//     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
//     !tolua_isusertype(tolua_S,2,"spTrackEntry",0,&tolua_err) ||
//     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
//     !tolua_isnoobj(tolua_S,4,&tolua_err)
// )
//  goto tolua_lerror;
// else
//#endif
// {
//  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
//  spTrackEntry* entry = ((spTrackEntry*)  tolua_tousertype(tolua_S,2,0));
//  LUA_FUNCTION scriptHandler = (toluafix_ref_function(tolua_S,3,0));
//#ifndef TOLUA_RELEASE
//  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartListener'", NULL);
//#endif
//  {
//   self->setStartListener(entry, scriptHandler);
//  }
// }
 return 0;
#ifndef TOLUA_RELEASE
// tolua_lerror:
// tolua_error(tolua_S,"#ferror in function 'setStartListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEndListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setEndListener00
static int tolua_SkeletonAnimation_SkeletonAnimation_setEndListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spTrackEntry",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"EndListener",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  spTrackEntry* entry = ((spTrackEntry*)  tolua_tousertype(tolua_S,2,0));
  spine::EndListener listener = *((spine::EndListener*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndListener'", NULL);
#endif
  {
   self->setEndListener(entry,listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCompleteListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setCompleteListener00
static int tolua_SkeletonAnimation_SkeletonAnimation_setCompleteListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spTrackEntry",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CompleteListener",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  spTrackEntry* entry = ((spTrackEntry*)  tolua_tousertype(tolua_S,2,0));
  spine::CompleteListener listener = *((spine::CompleteListener*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCompleteListener'", NULL);
#endif
  {
   self->setCompleteListener(entry,listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCompleteListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEventListener of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_setEventListener00
static int tolua_SkeletonAnimation_SkeletonAnimation_setEventListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spTrackEntry",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"EventListener",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  spTrackEntry* entry = ((spTrackEntry*)  tolua_tousertype(tolua_S,2,0));
  spine::EventListener listener = *((spine::EventListener*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEventListener'", NULL);
#endif
  {
   self->setEventListener(entry,listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEventListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onAnimationStateEvent of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_onAnimationStateEvent00
static int tolua_SkeletonAnimation_SkeletonAnimation_onAnimationStateEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"spEventType",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"spEvent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  spEventType type = *((spEventType*)  tolua_tousertype(tolua_S,3,0));
  spEvent* event = ((spEvent*)  tolua_tousertype(tolua_S,4,0));
  int loopCount = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onAnimationStateEvent'", NULL);
#endif
  {
   self->onAnimationStateEvent(trackIndex,type,event,loopCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onAnimationStateEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onTrackEntryEvent of class  SkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_SkeletonAnimation_SkeletonAnimation_onTrackEntryEvent00
static int tolua_SkeletonAnimation_SkeletonAnimation_onTrackEntryEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"spEventType",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"spEvent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spine::SkeletonAnimation* self = (spine::SkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  spEventType type = *((spEventType*)  tolua_tousertype(tolua_S,3,0));
  spEvent* event = ((spEvent*)  tolua_tousertype(tolua_S,4,0));
  int loopCount = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onTrackEntryEvent'", NULL);
#endif
  {
   self->onTrackEntryEvent(trackIndex,type,event,loopCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onTrackEntryEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_SkeletonAnimation_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);

    #ifdef __cplusplus
        tolua_cclass(tolua_S,"SkeletonRenderer","SkeletonRenderer","cocos2d::CCNodeRGBA",tolua_collect_SkeletonRenderer);
    #else
        tolua_cclass(tolua_S,"SkeletonRenderer","SkeletonRenderer","cocos2d::CCNodeRGBA",NULL);
    #endif
    tolua_beginmodule(tolua_S,"SkeletonRenderer");
    tolua_variable(tolua_S,"skeleton",tolua_get_SkeletonRenderer_skeleton_ptr,tolua_set_SkeletonRenderer_skeleton_ptr);
    tolua_variable(tolua_S,"rootBone",tolua_get_SkeletonRenderer_rootBone_ptr,tolua_set_SkeletonRenderer_rootBone_ptr);
    tolua_variable(tolua_S,"timeScale",tolua_get_SkeletonRenderer_timeScale,tolua_set_SkeletonRenderer_timeScale);
    tolua_variable(tolua_S,"debugSlots",tolua_get_SkeletonRenderer_debugSlots,tolua_set_SkeletonRenderer_debugSlots);
    tolua_variable(tolua_S,"debugBones",tolua_get_SkeletonRenderer_debugBones,tolua_set_SkeletonRenderer_debugBones);
    tolua_variable(tolua_S,"premultipliedAlpha",tolua_get_SkeletonRenderer_premultipliedAlpha,tolua_set_SkeletonRenderer_premultipliedAlpha);
    tolua_function(tolua_S,"createWithData",tolua_SkeletonRenderer_SkeletonRenderer_createWithData00);
    tolua_function(tolua_S,"createWithFile",tolua_SkeletonRenderer_SkeletonRenderer_createWithFile00);
    tolua_function(tolua_S,"createWithFile",tolua_SkeletonRenderer_SkeletonRenderer_createWithFile01);
    tolua_function(tolua_S,"getSkeletonData",tolua_SkeletonRenderer_SkeletonRenderer_getSkeletonData00);
    tolua_function(tolua_S,"new",tolua_SkeletonRenderer_SkeletonRenderer_new00);
    tolua_function(tolua_S,"new_local",tolua_SkeletonRenderer_SkeletonRenderer_new00_local);
    tolua_function(tolua_S,".call",tolua_SkeletonRenderer_SkeletonRenderer_new00_local);
    tolua_function(tolua_S,"new",tolua_SkeletonRenderer_SkeletonRenderer_new01);
    tolua_function(tolua_S,"new_local",tolua_SkeletonRenderer_SkeletonRenderer_new01_local);
    tolua_function(tolua_S,".call",tolua_SkeletonRenderer_SkeletonRenderer_new01_local);
    tolua_function(tolua_S,"new",tolua_SkeletonRenderer_SkeletonRenderer_new02);
    tolua_function(tolua_S,"new_local",tolua_SkeletonRenderer_SkeletonRenderer_new02_local);
    tolua_function(tolua_S,".call",tolua_SkeletonRenderer_SkeletonRenderer_new02_local);
    tolua_function(tolua_S,"delete",tolua_SkeletonRenderer_SkeletonRenderer_delete00);
    tolua_function(tolua_S,"update",tolua_SkeletonRenderer_SkeletonRenderer_update00);
    tolua_function(tolua_S,"draw",tolua_SkeletonRenderer_SkeletonRenderer_draw00);
    tolua_function(tolua_S,"boundingBox",tolua_SkeletonRenderer_SkeletonRenderer_boundingBox00);
    tolua_function(tolua_S,"updateWorldTransform",tolua_SkeletonRenderer_SkeletonRenderer_updateWorldTransform00);
    tolua_function(tolua_S,"setToSetupPose",tolua_SkeletonRenderer_SkeletonRenderer_setToSetupPose00);
    tolua_function(tolua_S,"setBonesToSetupPose",tolua_SkeletonRenderer_SkeletonRenderer_setBonesToSetupPose00);
    tolua_function(tolua_S,"setSlotsToSetupPose",tolua_SkeletonRenderer_SkeletonRenderer_setSlotsToSetupPose00);
    tolua_function(tolua_S,"findBone",tolua_SkeletonRenderer_SkeletonRenderer_findBone00);
    tolua_function(tolua_S,"findSlot",tolua_SkeletonRenderer_SkeletonRenderer_findSlot00);
    tolua_function(tolua_S,"setSkin",tolua_SkeletonRenderer_SkeletonRenderer_setSkin00);
    tolua_function(tolua_S,"getAttachment",tolua_SkeletonRenderer_SkeletonRenderer_getAttachment00);
    tolua_function(tolua_S,"setAttachment",tolua_SkeletonRenderer_SkeletonRenderer_setAttachment00);
    tolua_function(tolua_S,"CC_PROPERTY",tolua_SkeletonRenderer_SkeletonRenderer_CC_PROPERTY00);
    tolua_function(tolua_S,"setOpacityModifyRGB",tolua_SkeletonRenderer_SkeletonRenderer_setOpacityModifyRGB00);
    tolua_function(tolua_S,"isOpacityModifyRGB",tolua_SkeletonRenderer_SkeletonRenderer_isOpacityModifyRGB00);
    tolua_variable(tolua_S,"__cocos2d__CCBlendProtocol__",tolua_get_SkeletonRenderer___cocos2d__CCBlendProtocol__,NULL);
    tolua_endmodule(tolua_S);


  #ifdef __cplusplus
    tolua_cclass(tolua_S,"SkeletonRenderer","SkeletonRenderer","CCNodeRGBA",tolua_collect_SkeletonRenderer);
    tolua_cclass(tolua_S,"SkeletonAnimation","SkeletonAnimation","SkeletonRenderer",tolua_collect_SkeletonAnimation);
  #else
    tolua_cclass(tolua_S,"SkeletonRenderer","SkeletonRenderer","CCNodeRGBA",NULL);
    tolua_cclass(tolua_S,"SkeletonAnimation","SkeletonAnimation","SkeletonRenderer",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SkeletonAnimation");
   tolua_variable(tolua_S,"state",tolua_get_SkeletonAnimation_state_ptr,tolua_set_SkeletonAnimation_state_ptr);
   tolua_function(tolua_S,"createWithData",tolua_SkeletonAnimation_SkeletonAnimation_createWithData00);
   tolua_function(tolua_S,"createWithFile",tolua_SkeletonAnimation_SkeletonAnimation_createWithFile00);
   tolua_function(tolua_S,"createWithFile",tolua_SkeletonAnimation_SkeletonAnimation_createWithFile01);

   tolua_function(tolua_S,"new",tolua_SkeletonAnimation_SkeletonAnimation_new00);
   tolua_function(tolua_S,"new_local",tolua_SkeletonAnimation_SkeletonAnimation_new00_local);
   //tolua_function(tolua_S,"getSkeletonData",tolua_SkeletonAnimation_SkeletonAnimation_getSkeletonData00);
   tolua_function(tolua_S,".call",tolua_SkeletonAnimation_SkeletonAnimation_new00_local);
   tolua_function(tolua_S,"new",tolua_SkeletonAnimation_SkeletonAnimation_new01);
   tolua_function(tolua_S,"new_local",tolua_SkeletonAnimation_SkeletonAnimation_new01_local);
   tolua_function(tolua_S,".call",tolua_SkeletonAnimation_SkeletonAnimation_new01_local);
   tolua_function(tolua_S,"new",tolua_SkeletonAnimation_SkeletonAnimation_new02);
   tolua_function(tolua_S,"new_local",tolua_SkeletonAnimation_SkeletonAnimation_new02_local);
   tolua_function(tolua_S,".call",tolua_SkeletonAnimation_SkeletonAnimation_new02_local);
   tolua_function(tolua_S,"delete",tolua_SkeletonAnimation_SkeletonAnimation_delete00);
   tolua_function(tolua_S,"update",tolua_SkeletonAnimation_SkeletonAnimation_update00);
   tolua_function(tolua_S,"setAnimationStateData",tolua_SkeletonAnimation_SkeletonAnimation_setAnimationStateData00);
   tolua_function(tolua_S,"setMix",tolua_SkeletonAnimation_SkeletonAnimation_setMix00);
   tolua_function(tolua_S,"setAnimation",tolua_SkeletonAnimation_SkeletonAnimation_setAnimation00);
   tolua_function(tolua_S,"addAnimation",tolua_SkeletonAnimation_SkeletonAnimation_addAnimation00);
   tolua_function(tolua_S,"getCurrent",tolua_SkeletonAnimation_SkeletonAnimation_getCurrent00);
   tolua_function(tolua_S,"clearTracks",tolua_SkeletonAnimation_SkeletonAnimation_clearTracks00);
   tolua_function(tolua_S,"clearTrack",tolua_SkeletonAnimation_SkeletonAnimation_clearTrack00);

   tolua_variable(tolua_S,"startListener",tolua_get_SkeletonAnimation_startListener,tolua_set_SkeletonAnimation_startListener);
   tolua_variable(tolua_S,"endListener",tolua_get_SkeletonAnimation_endListener,tolua_set_SkeletonAnimation_endListener);
   tolua_variable(tolua_S,"completeListener",tolua_get_SkeletonAnimation_completeListener,tolua_set_SkeletonAnimation_completeListener);
   tolua_variable(tolua_S,"eventListener",tolua_get_SkeletonAnimation_eventListener,tolua_set_SkeletonAnimation_eventListener);
    tolua_function(tolua_S,"setSpineEventCallFunc",tolua_SkeletonAnimation_SkeletonAnimation_setSpineEventCallFunc00);
   tolua_function(tolua_S,"setStartListener",tolua_SkeletonAnimation_SkeletonAnimation_setStartListener00);
   tolua_function(tolua_S,"setEndListener",tolua_SkeletonAnimation_SkeletonAnimation_setEndListener00);
   tolua_function(tolua_S,"setCompleteListener",tolua_SkeletonAnimation_SkeletonAnimation_setCompleteListener00);
   tolua_function(tolua_S,"setEventListener",tolua_SkeletonAnimation_SkeletonAnimation_setEventListener00);
   tolua_function(tolua_S,"onAnimationStateEvent",tolua_SkeletonAnimation_SkeletonAnimation_onAnimationStateEvent00);
   tolua_function(tolua_S,"onTrackEntryEvent",tolua_SkeletonAnimation_SkeletonAnimation_onTrackEntryEvent00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}

//#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
//TOLUA_API int luaopen_SkeletonRenderer (lua_State* tolua_S) {
//    return tolua_SkeletonRenderer_open(tolua_S);
//};
//#endif


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_SkeletonAnimation (lua_State* tolua_S) {
 return tolua_SkeletonAnimation_open(tolua_S);
};
#endif

