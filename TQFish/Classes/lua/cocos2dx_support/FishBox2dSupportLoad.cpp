/*
** Lua binding: FishBox2dSupport
** Generated automatically by tolua++-1.0.92 on 05/25/16 10:43:57.
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
TOLUA_API int  tolua_FishBox2dSupport_open (lua_State* tolua_S);

#include "FishBox2dSupport.h"
#include <stdio.h>
#include "QContactListener.h"
#include "CCLuaStack.h"
#include "CCLuaEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_b2Vec2 (lua_State* tolua_S)
{
 b2Vec2* self = (b2Vec2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LUA_FUNCTION");
 tolua_usertype(tolua_S,"b2Vec2");
 tolua_usertype(tolua_S,"FishBox2dSupport");
 tolua_usertype(tolua_S,"b2ContactListener");
 tolua_usertype(tolua_S,"b2Body");
 tolua_usertype(tolua_S,"b2World");
}

/* method: GetInstance of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_GetInstance00
static int tolua_FishBox2dSupport_FishBox2dSupport_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FishBox2dSupport* tolua_ret = (FishBox2dSupport*)  FishBox2dSupport::GetInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FishBox2dSupport");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReleaseFishBox2dSupport of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_ReleaseFishBox2dSupport00
static int tolua_FishBox2dSupport_FishBox2dSupport_ReleaseFishBox2dSupport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReleaseFishBox2dSupport'", NULL);
#endif
  {
   self->ReleaseFishBox2dSupport();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseFishBox2dSupport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFishBox2dWorld of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_getFishBox2dWorld00
static int tolua_FishBox2dSupport_FishBox2dSupport_getFishBox2dWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFishBox2dWorld'", NULL);
#endif
  {
   b2World* tolua_ret = (b2World*)  self->getFishBox2dWorld();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"b2World");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFishBox2dWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_b2World of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_get_FishBox2dSupport_m_b2World_ptr
static int tolua_get_FishBox2dSupport_m_b2World_ptr(lua_State* tolua_S)
{
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_b2World'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_b2World,"b2World");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_b2World of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_set_FishBox2dSupport_m_b2World_ptr
static int tolua_set_FishBox2dSupport_m_b2World_ptr(lua_State* tolua_S)
{
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_b2World'",NULL);
  if (!tolua_isusertype(tolua_S,2,"b2World",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_b2World = ((b2World*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_b2ContactListener of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_get_FishBox2dSupport_m_b2ContactListener_ptr
static int tolua_get_FishBox2dSupport_m_b2ContactListener_ptr(lua_State* tolua_S)
{
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_b2ContactListener'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_b2ContactListener,"b2ContactListener");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_b2ContactListener of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_set_FishBox2dSupport_m_b2ContactListener_ptr
static int tolua_set_FishBox2dSupport_m_b2ContactListener_ptr(lua_State* tolua_S)
{
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_b2ContactListener'",NULL);
  if (!tolua_isusertype(tolua_S,2,"b2ContactListener",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_b2ContactListener = ((b2ContactListener*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: invokeFishCallbackFunction of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_invokeFishCallbackFunction00
static int tolua_FishBox2dSupport_FishBox2dSupport_invokeFishCallbackFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
  char* id_a = ((char*)  tolua_tostring(tolua_S,2,0));
  char* id_b = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invokeFishCallbackFunction'", NULL);
#endif
  {
   self->invokeFishCallbackFunction(id_a,id_b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invokeFishCallbackFunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerScriptHandler of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_registerScriptHandler00
static int tolua_FishBox2dSupport_FishBox2dSupport_registerScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION nHandler = (toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerScriptHandler'", NULL);
#endif
  {
   self->registerScriptHandler(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getB2Vec2Obj of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_getB2Vec2Obj00
static int tolua_FishBox2dSupport_FishBox2dSupport_getB2Vec2Obj00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getB2Vec2Obj'", NULL);
#endif
  {
   b2Vec2 tolua_ret = (b2Vec2)  self->getB2Vec2Obj(x,y);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((b2Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"b2Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(b2Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"b2Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getB2Vec2Obj'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: b2BodyUpdateTransform of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_b2BodyUpdateTransform00
static int tolua_FishBox2dSupport_FishBox2dSupport_b2BodyUpdateTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"b2Body",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
  b2Body* mBody = ((b2Body*)  tolua_tousertype(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float fRotation = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'b2BodyUpdateTransform'", NULL);
#endif
  {
   self->b2BodyUpdateTransform(mBody,x,y,fRotation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'b2BodyUpdateTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: b2worldUpdate of class  FishBox2dSupport */
#ifndef TOLUA_DISABLE_tolua_FishBox2dSupport_FishBox2dSupport_b2worldUpdate00
static int tolua_FishBox2dSupport_FishBox2dSupport_b2worldUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FishBox2dSupport",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FishBox2dSupport* self = (FishBox2dSupport*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'b2worldUpdate'", NULL);
#endif
  {
   self->b2worldUpdate(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'b2worldUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FishBox2dSupport_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"FishBox2dSupport","FishBox2dSupport","",NULL);
  tolua_beginmodule(tolua_S,"FishBox2dSupport");
   tolua_function(tolua_S,"GetInstance",tolua_FishBox2dSupport_FishBox2dSupport_GetInstance00);
   tolua_function(tolua_S,"ReleaseFishBox2dSupport",tolua_FishBox2dSupport_FishBox2dSupport_ReleaseFishBox2dSupport00);
   tolua_function(tolua_S,"getFishBox2dWorld",tolua_FishBox2dSupport_FishBox2dSupport_getFishBox2dWorld00);
   tolua_variable(tolua_S,"m_b2World",tolua_get_FishBox2dSupport_m_b2World_ptr,tolua_set_FishBox2dSupport_m_b2World_ptr);
   tolua_variable(tolua_S,"m_b2ContactListener",tolua_get_FishBox2dSupport_m_b2ContactListener_ptr,tolua_set_FishBox2dSupport_m_b2ContactListener_ptr);
   tolua_function(tolua_S,"invokeFishCallbackFunction",tolua_FishBox2dSupport_FishBox2dSupport_invokeFishCallbackFunction00);
   tolua_function(tolua_S,"registerScriptHandler",tolua_FishBox2dSupport_FishBox2dSupport_registerScriptHandler00);
   tolua_function(tolua_S,"getB2Vec2Obj",tolua_FishBox2dSupport_FishBox2dSupport_getB2Vec2Obj00);
   tolua_function(tolua_S,"b2BodyUpdateTransform",tolua_FishBox2dSupport_FishBox2dSupport_b2BodyUpdateTransform00);
   tolua_function(tolua_S,"b2worldUpdate",tolua_FishBox2dSupport_FishBox2dSupport_b2worldUpdate00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FishBox2dSupport (lua_State* tolua_S) {
 return tolua_FishBox2dSupport_open(tolua_S);
};
#endif

