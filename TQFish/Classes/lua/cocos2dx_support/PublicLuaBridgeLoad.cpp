/*
** Lua binding: PublicLuaBridge
** Generated automatically by tolua++-1.0.92 on 07/12/16 11:59:50.
*/
extern "C" {
#include "tolua_fix.h"
}
#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PublicLuaBridge_open (lua_State* tolua_S);

#include "PublicLuaBridge.h"
#include <string>
#include "CCLuaStack.h"
#include "CCLuaEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_PublicLuaBridge (lua_State* tolua_S)
{
 PublicLuaBridge* self = (PublicLuaBridge*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LUA_FUNCTION");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"PublicLuaBridge");
}

/* method: new of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_new00
static int tolua_PublicLuaBridge_PublicLuaBridge_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PublicLuaBridge* tolua_ret = (PublicLuaBridge*)  Mtolua_new((PublicLuaBridge)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PublicLuaBridge");
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

/* method: new_local of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_new00_local
static int tolua_PublicLuaBridge_PublicLuaBridge_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PublicLuaBridge* tolua_ret = (PublicLuaBridge*)  Mtolua_new((PublicLuaBridge)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PublicLuaBridge");
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

/* method: delete of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_delete00
static int tolua_PublicLuaBridge_PublicLuaBridge_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getInstance of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_getInstance00
static int tolua_PublicLuaBridge_PublicLuaBridge_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PublicLuaBridge* tolua_ret = (PublicLuaBridge*)  PublicLuaBridge::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PublicLuaBridge");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: socketState of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_get_PublicLuaBridge_socketState
static int tolua_get_PublicLuaBridge_socketState(lua_State* tolua_S)
{
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'socketState'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->socketState);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: socketState of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_set_PublicLuaBridge_socketState
static int tolua_set_PublicLuaBridge_socketState(lua_State* tolua_S)
{
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'socketState'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->socketState = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: productionModels of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_get_PublicLuaBridge_productionModels
static int tolua_get_PublicLuaBridge_productionModels(lua_State* tolua_S)
{
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'productionModels'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->productionModels);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: productionModels of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_set_PublicLuaBridge_productionModels
static int tolua_set_PublicLuaBridge_productionModels(lua_State* tolua_S)
{
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'productionModels'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->productionModels = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: toDoLuaFile of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaFile00
static int tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
  string luapath = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toDoLuaFile'", NULL);
#endif
  {
   self->toDoLuaFile(luapath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toDoLuaFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toDoLuaString of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaString00
static int tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
  string luastring = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toDoLuaString'", NULL);
#endif
  {
   self->toDoLuaString(luastring);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toDoLuaString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toDoLuaGlobalFunction of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaGlobalFunction00
static int tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaGlobalFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
  string founctionname = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toDoLuaGlobalFunction'", NULL);
#endif
  {
   self->toDoLuaGlobalFunction(founctionname);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toDoLuaGlobalFunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initLua of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_initLua00
static int tolua_PublicLuaBridge_PublicLuaBridge_initLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initLua'", NULL);
#endif
  {
   self->initLua();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applicationEnterBackground of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_applicationEnterBackground00
static int tolua_PublicLuaBridge_PublicLuaBridge_applicationEnterBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applicationEnterBackground'", NULL);
#endif
  {
   self->applicationEnterBackground();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applicationEnterBackground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: applicationEnterForeground of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_applicationEnterForeground00
static int tolua_PublicLuaBridge_PublicLuaBridge_applicationEnterForeground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'applicationEnterForeground'", NULL);
#endif
  {
   self->applicationEnterForeground();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'applicationEnterForeground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerEnterGameScriptHandler of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_registerEnterGameScriptHandler00
static int tolua_PublicLuaBridge_PublicLuaBridge_registerEnterGameScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION scriptHandler = (toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerEnterGameScriptHandler'", NULL);
#endif
  {
   self->registerEnterGameScriptHandler(scriptHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerEnterGameScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeMessageServiceState of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_changeMessageServiceState00
static int tolua_PublicLuaBridge_PublicLuaBridge_changeMessageServiceState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
  int state = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeMessageServiceState'", NULL);
#endif
  {
   self->changeMessageServiceState(state);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeMessageServiceState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerMessageServiceScriptHandler of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_registerMessageServiceScriptHandler00
static int tolua_PublicLuaBridge_PublicLuaBridge_registerMessageServiceScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION scriptHandler = (toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerMessageServiceScriptHandler'", NULL);
#endif
  {
   self->registerMessageServiceScriptHandler(scriptHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerMessageServiceScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMessageServiceState of class  PublicLuaBridge */
#ifndef TOLUA_DISABLE_tolua_PublicLuaBridge_PublicLuaBridge_getMessageServiceState00
static int tolua_PublicLuaBridge_PublicLuaBridge_getMessageServiceState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PublicLuaBridge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PublicLuaBridge* self = (PublicLuaBridge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMessageServiceState'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getMessageServiceState();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMessageServiceState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PublicLuaBridge_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"PublicLuaBridge","PublicLuaBridge","CCObject",tolua_collect_PublicLuaBridge);
  #else
  tolua_cclass(tolua_S,"PublicLuaBridge","PublicLuaBridge","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"PublicLuaBridge");
   tolua_function(tolua_S,"new",tolua_PublicLuaBridge_PublicLuaBridge_new00);
   tolua_function(tolua_S,"new_local",tolua_PublicLuaBridge_PublicLuaBridge_new00_local);
   tolua_function(tolua_S,".call",tolua_PublicLuaBridge_PublicLuaBridge_new00_local);
   tolua_function(tolua_S,"delete",tolua_PublicLuaBridge_PublicLuaBridge_delete00);
   tolua_function(tolua_S,"getInstance",tolua_PublicLuaBridge_PublicLuaBridge_getInstance00);
   tolua_variable(tolua_S,"socketState",tolua_get_PublicLuaBridge_socketState,tolua_set_PublicLuaBridge_socketState);
   tolua_variable(tolua_S,"productionModels",tolua_get_PublicLuaBridge_productionModels,tolua_set_PublicLuaBridge_productionModels);
   tolua_function(tolua_S,"toDoLuaFile",tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaFile00);
   tolua_function(tolua_S,"toDoLuaString",tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaString00);
   tolua_function(tolua_S,"toDoLuaGlobalFunction",tolua_PublicLuaBridge_PublicLuaBridge_toDoLuaGlobalFunction00);
   tolua_function(tolua_S,"initLua",tolua_PublicLuaBridge_PublicLuaBridge_initLua00);
   tolua_function(tolua_S,"applicationEnterBackground",tolua_PublicLuaBridge_PublicLuaBridge_applicationEnterBackground00);
   tolua_function(tolua_S,"applicationEnterForeground",tolua_PublicLuaBridge_PublicLuaBridge_applicationEnterForeground00);
   tolua_function(tolua_S,"registerEnterGameScriptHandler",tolua_PublicLuaBridge_PublicLuaBridge_registerEnterGameScriptHandler00);
   tolua_function(tolua_S,"changeMessageServiceState",tolua_PublicLuaBridge_PublicLuaBridge_changeMessageServiceState00);
   tolua_function(tolua_S,"registerMessageServiceScriptHandler",tolua_PublicLuaBridge_PublicLuaBridge_registerMessageServiceScriptHandler00);
   tolua_function(tolua_S,"getMessageServiceState",tolua_PublicLuaBridge_PublicLuaBridge_getMessageServiceState00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PublicLuaBridge (lua_State* tolua_S) {
 return tolua_PublicLuaBridge_open(tolua_S);
};
#endif

