/*
** Lua binding: Lightning
** Generated automatically by tolua++-1.0.92 on 05/25/16 16:46:25.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Lightning_open (lua_State* tolua_S);

#include "Lightning.h"
#include <vector>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Lightning (lua_State* tolua_S)
{
 Lightning* self = (Lightning*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"cocos2d::CCNode");
 tolua_usertype(tolua_S,"Lightning");
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"cocos2d::CCTexture2D");
}

/* method: new of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_new00
static int tolua_Lightning_Lightning_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float startPosX = ((float)  tolua_tonumber(tolua_S,2,0));
  float startPosY = ((float)  tolua_tonumber(tolua_S,3,0));
  float endPosX = ((float)  tolua_tonumber(tolua_S,4,0));
  float endPosY = ((float)  tolua_tonumber(tolua_S,5,0));
  float displace = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   Lightning* tolua_ret = (Lightning*)  Mtolua_new((Lightning)(startPosX,startPosY,endPosX,endPosY,displace));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Lightning");
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

/* method: new_local of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_new00_local
static int tolua_Lightning_Lightning_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float startPosX = ((float)  tolua_tonumber(tolua_S,2,0));
  float startPosY = ((float)  tolua_tonumber(tolua_S,3,0));
  float endPosX = ((float)  tolua_tonumber(tolua_S,4,0));
  float endPosY = ((float)  tolua_tonumber(tolua_S,5,0));
  float displace = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   Lightning* tolua_ret = (Lightning*)  Mtolua_new((Lightning)(startPosX,startPosY,endPosX,endPosY,displace));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Lightning");
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

/* method: delete of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_delete00
static int tolua_Lightning_Lightning_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Lightning* self = (Lightning*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_create00
static int tolua_Lightning_Lightning_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string strTextureFile = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  float startPosX = ((float)  tolua_tonumber(tolua_S,3,0));
  float startPosY = ((float)  tolua_tonumber(tolua_S,4,0));
  float endPosX = ((float)  tolua_tonumber(tolua_S,5,0));
  float endPosY = ((float)  tolua_tonumber(tolua_S,6,0));
  float displace = ((float)  tolua_tonumber(tolua_S,7,100));
  {
   Lightning* tolua_ret = (Lightning*)  Lightning::create(strTextureFile,startPosX,startPosY,endPosX,endPosY,displace);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Lightning");
   tolua_pushcppstring(tolua_S,(const char*)strTextureFile);
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

/* method: init of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_init00
static int tolua_Lightning_Lightning_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Lightning* self = (Lightning*)  tolua_tousertype(tolua_S,1,0);
  const std::string strTextureFile = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(strTextureFile);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)strTextureFile);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_setTexture00
static int tolua_Lightning_Lightning_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Lightning* self = (Lightning*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCTexture2D* texture = ((cocos2d::CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(texture);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSelfOnLayer of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_addSelfOnLayer00
static int tolua_Lightning_Lightning_addSelfOnLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Lightning* self = (Lightning*)  tolua_tousertype(tolua_S,1,0);
  CCLayer* view = ((CCLayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSelfOnLayer'", NULL);
#endif
  {
   self->addSelfOnLayer(view);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSelfOnLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeBySelf of class  Lightning */
#ifndef TOLUA_DISABLE_tolua_Lightning_Lightning_removeBySelf00
static int tolua_Lightning_Lightning_removeBySelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Lightning",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Lightning* self = (Lightning*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_Lightning_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Lightning","Lightning","cocos2d::CCNode",tolua_collect_Lightning);
  #else
  tolua_cclass(tolua_S,"Lightning","Lightning","cocos2d::CCNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Lightning");
   tolua_function(tolua_S,"new",tolua_Lightning_Lightning_new00);
   tolua_function(tolua_S,"new_local",tolua_Lightning_Lightning_new00_local);
   tolua_function(tolua_S,".call",tolua_Lightning_Lightning_new00_local);
   tolua_function(tolua_S,"delete",tolua_Lightning_Lightning_delete00);
   tolua_function(tolua_S,"create",tolua_Lightning_Lightning_create00);
   tolua_function(tolua_S,"init",tolua_Lightning_Lightning_init00);
   tolua_function(tolua_S,"setTexture",tolua_Lightning_Lightning_setTexture00);
   tolua_function(tolua_S,"addSelfOnLayer",tolua_Lightning_Lightning_addSelfOnLayer00);
   tolua_function(tolua_S,"removeBySelf",tolua_Lightning_Lightning_removeBySelf00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Lightning (lua_State* tolua_S) {
 return tolua_Lightning_open(tolua_S);
};
#endif

