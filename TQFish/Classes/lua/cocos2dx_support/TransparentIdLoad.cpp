/*
** Lua binding: TransparentId
** Generated automatically by tolua++-1.0.92 on 06/07/16 14:54:32.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_TransparentId_open (lua_State* tolua_S);

#include "TransparentId.h"
#include <stdio.h>
#include "cocos2d.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"TransparentId");
}

/* method: create of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_create00
static int tolua_TransparentId_TransparentId_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* m_id = ((char*)  tolua_tostring(tolua_S,2,0));
  CCNode* fishSprite = ((CCNode*)  tolua_tousertype(tolua_S,3,0));
  bool isNeedRotate = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool isNeedParentPos = ((bool)  tolua_toboolean(tolua_S,5,0));
  bool isNeedParentAngle = ((bool)  tolua_toboolean(tolua_S,6,0));
  {
   TransparentId* tolua_ret = (TransparentId*)  TransparentId::create(m_id,fishSprite,isNeedRotate,isNeedParentPos,isNeedParentAngle);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TransparentId");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_create01
static int tolua_TransparentId_TransparentId_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  char* m_id = ((char*)  tolua_tostring(tolua_S,2,0));
  CCNode* fishSprite = ((CCNode*)  tolua_tousertype(tolua_S,3,0));
  bool isNeedRotate = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool isChildFish = ((bool)  tolua_toboolean(tolua_S,5,0));
  {
   TransparentId* tolua_ret = (TransparentId*)  TransparentId::create(m_id,fishSprite,isNeedRotate,isChildFish);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TransparentId");
  }
 }
 return 1;
tolua_lerror:
 return tolua_TransparentId_TransparentId_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setId of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_setId00
static int tolua_TransparentId_TransparentId_setId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
  char* m_id = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setId'", NULL);
#endif
  {
   self->setId(m_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getId of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_getId00
static int tolua_TransparentId_TransparentId_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getId'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->getId();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFishSprite of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_setFishSprite00
static int tolua_TransparentId_TransparentId_setFishSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
  CCNode* fishSprite = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFishSprite'", NULL);
#endif
  {
   self->setFishSprite(fishSprite);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFishSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFishSprite of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_getFishSprite00
static int tolua_TransparentId_TransparentId_getFishSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFishSprite'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->getFishSprite();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFishSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsNeedRotate of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_setIsNeedRotate00
static int tolua_TransparentId_TransparentId_setIsNeedRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
  bool isNeedRotate = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsNeedRotate'", NULL);
#endif
  {
   self->setIsNeedRotate(isNeedRotate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsNeedRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsNeedRotate of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_getIsNeedRotate00
static int tolua_TransparentId_TransparentId_getIsNeedRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsNeedRotate'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsNeedRotate();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsNeedRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsNeedParentPos of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_setIsNeedParentPos00
static int tolua_TransparentId_TransparentId_setIsNeedParentPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
  bool isNeedParentPos = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsNeedParentPos'", NULL);
#endif
  {
   self->setIsNeedParentPos(isNeedParentPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsNeedParentPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsNeedParentPos of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_getIsNeedParentPos00
static int tolua_TransparentId_TransparentId_getIsNeedParentPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsNeedParentPos'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsNeedParentPos();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsNeedParentPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsNeedParentAngle of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_setIsNeedParentAngle00
static int tolua_TransparentId_TransparentId_setIsNeedParentAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
  bool isNeedParentAngle = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsNeedParentAngle'", NULL);
#endif
  {
   self->setIsNeedParentAngle(isNeedParentAngle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsNeedParentAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsNeedParentAngle of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_getIsNeedParentAngle00
static int tolua_TransparentId_TransparentId_getIsNeedParentAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsNeedParentAngle'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsNeedParentAngle();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsNeedParentAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsChildFish of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_setIsChildFish00
static int tolua_TransparentId_TransparentId_setIsChildFish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
  bool isChildFish = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsChildFish'", NULL);
#endif
  {
   self->setIsChildFish(isChildFish);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsChildFish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsChildFish of class  TransparentId */
#ifndef TOLUA_DISABLE_tolua_TransparentId_TransparentId_getIsChildFish00
static int tolua_TransparentId_TransparentId_getIsChildFish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TransparentId",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TransparentId* self = (TransparentId*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsChildFish'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsChildFish();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsChildFish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_TransparentId_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"TransparentId","TransparentId","",NULL);
  tolua_beginmodule(tolua_S,"TransparentId");
   tolua_function(tolua_S,"create",tolua_TransparentId_TransparentId_create00);
   tolua_function(tolua_S,"create",tolua_TransparentId_TransparentId_create01);
   tolua_function(tolua_S,"setId",tolua_TransparentId_TransparentId_setId00);
   tolua_function(tolua_S,"getId",tolua_TransparentId_TransparentId_getId00);
   tolua_function(tolua_S,"setFishSprite",tolua_TransparentId_TransparentId_setFishSprite00);
   tolua_function(tolua_S,"getFishSprite",tolua_TransparentId_TransparentId_getFishSprite00);
   tolua_function(tolua_S,"setIsNeedRotate",tolua_TransparentId_TransparentId_setIsNeedRotate00);
   tolua_function(tolua_S,"getIsNeedRotate",tolua_TransparentId_TransparentId_getIsNeedRotate00);
   tolua_function(tolua_S,"setIsNeedParentPos",tolua_TransparentId_TransparentId_setIsNeedParentPos00);
   tolua_function(tolua_S,"getIsNeedParentPos",tolua_TransparentId_TransparentId_getIsNeedParentPos00);
   tolua_function(tolua_S,"setIsNeedParentAngle",tolua_TransparentId_TransparentId_setIsNeedParentAngle00);
   tolua_function(tolua_S,"getIsNeedParentAngle",tolua_TransparentId_TransparentId_getIsNeedParentAngle00);
   tolua_function(tolua_S,"setIsChildFish",tolua_TransparentId_TransparentId_setIsChildFish00);
   tolua_function(tolua_S,"getIsChildFish",tolua_TransparentId_TransparentId_getIsChildFish00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_TransparentId (lua_State* tolua_S) {
 return tolua_TransparentId_open(tolua_S);
};
#endif

