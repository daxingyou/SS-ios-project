/*
** Lua binding: QRSprite
** Generated automatically by tolua++-1.0.92 on 06/07/16 19:17:31.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_QRSprite_open (lua_State* tolua_S);

#include "QRSprite.h"
#include "cocos2d.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"QRSprite");
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"cocos2d::CCLayerColor");
}

/* method: saveQRcodeToFile of class  QRSprite */
#ifndef TOLUA_DISABLE_tolua_QRSprite_QRSprite_saveQRcodeToFile00
static int tolua_QRSprite_QRSprite_saveQRcodeToFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QRSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QRSprite* self = (QRSprite*)  tolua_tousertype(tolua_S,1,0);
  char* fileName = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveQRcodeToFile'", NULL);
#endif
  {
   self->saveQRcodeToFile(fileName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveQRcodeToFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSelfByParent of class  QRSprite */
#ifndef TOLUA_DISABLE_tolua_QRSprite_QRSprite_addSelfByParent00
static int tolua_QRSprite_QRSprite_addSelfByParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QRSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QRSprite* self = (QRSprite*)  tolua_tousertype(tolua_S,1,0);
  CCLayer* parentNode = ((CCLayer*)  tolua_tousertype(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSelfByParent'", NULL);
#endif
  {
   self->addSelfByParent(parentNode,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSelfByParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeBySelf of class  QRSprite */
#ifndef TOLUA_DISABLE_tolua_QRSprite_QRSprite_removeBySelf00
static int tolua_QRSprite_QRSprite_removeBySelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QRSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QRSprite* self = (QRSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeBySelf'", NULL);
#endif
  {
   self->removeBySelf();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeBySelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithString of class  QRSprite */
#ifndef TOLUA_DISABLE_tolua_QRSprite_QRSprite_initWithString00
static int tolua_QRSprite_QRSprite_initWithString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"QRSprite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  QRSprite* self = (QRSprite*)  tolua_tousertype(tolua_S,1,0);
  const std::string code = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithString'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithString(code);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)code);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  QRSprite */
#ifndef TOLUA_DISABLE_tolua_QRSprite_QRSprite_create00
static int tolua_QRSprite_QRSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"QRSprite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string code = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  char* iconName = ((char*)  tolua_tostring(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,512));
  {
   QRSprite* tolua_ret = (QRSprite*)  QRSprite::create(code,iconName,size);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"QRSprite");
   tolua_pushcppstring(tolua_S,(const char*)code);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_QRSprite_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"QRSprite","QRSprite","cocos2d::CCLayerColor",NULL);
  tolua_beginmodule(tolua_S,"QRSprite");
   tolua_function(tolua_S,"saveQRcodeToFile",tolua_QRSprite_QRSprite_saveQRcodeToFile00);
   tolua_function(tolua_S,"addSelfByParent",tolua_QRSprite_QRSprite_addSelfByParent00);
   tolua_function(tolua_S,"removeBySelf",tolua_QRSprite_QRSprite_removeBySelf00);
   tolua_function(tolua_S,"initWithString",tolua_QRSprite_QRSprite_initWithString00);
   tolua_function(tolua_S,"create",tolua_QRSprite_QRSprite_create00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_QRSprite (lua_State* tolua_S) {
 return tolua_QRSprite_open(tolua_S);
};
#endif

