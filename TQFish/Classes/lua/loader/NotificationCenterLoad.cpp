/*
** Lua binding: NotificationCenter
** Generated automatically by tolua++-1.0.92 on 09/18/12 19:39:35.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_NotificationCenter_open (lua_State* tolua_S);

#include "NotificationCenter.h"
#include "NotificationEvent.h"
#include "pthread.h"
#include "tolua_fix.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_NotificationObserver (lua_State* tolua_S)
{
 NotificationObserver* self = (NotificationObserver*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Action_CallFunc");
 tolua_usertype(tolua_S,"NotificationObserver");
 tolua_usertype(tolua_S,"NotificationCenter");
 tolua_usertype(tolua_S,"LUA_FUNCTION");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"NotificationEvent");
}

/* method: addObserver of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_addObserver00
static int tolua_NotificationCenter_NotificationCenter_addObserver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Action_CallFunc",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  Action_CallFunc action = *((Action_CallFunc*)  tolua_tousertype(tolua_S,3,0));
  const char* eventType = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addObserver'", NULL);
#endif
  {
   self->addObserver(target,action,eventType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addObserver'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeObserver of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_removeObserver00
static int tolua_NotificationCenter_NotificationCenter_removeObserver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  const char* eventType = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeObserver'", NULL);
#endif
  {
   self->removeObserver(target,eventType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeObserver'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendEvent of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_sendEvent00
static int tolua_NotificationCenter_NotificationCenter_sendEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NotificationEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
  NotificationEvent* event = ((NotificationEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendEvent'", NULL);
#endif
  {
   self->sendEvent(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendEventCom of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_sendEventCom00
static int tolua_NotificationCenter_NotificationCenter_sendEventCom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NotificationEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
  NotificationEvent* event = ((NotificationEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendEventCom'", NULL);
#endif
  {
   self->sendEventCom(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendEventCom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendEventNot of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_sendEventNot00
static int tolua_NotificationCenter_NotificationCenter_sendEventNot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NotificationEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
  NotificationEvent* event = ((NotificationEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendEventNot'", NULL);
#endif
  {
   self->sendEventNot(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendEventNot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearEventAndObserver of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_clearEventAndObserver00
static int tolua_NotificationCenter_NotificationCenter_clearEventAndObserver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearEventAndObserver'", NULL);
#endif
  {
   self->clearEventAndObserver();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearEventAndObserver'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addObserver of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_addObserver01
static int tolua_NotificationCenter_NotificationCenter_addObserver01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
  int nHandler = (toluafix_ref_function(tolua_S,2,0));
  const char* eventType = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addObserver'", NULL);
#endif
  {
   self->addObserver(nHandler,eventType);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NotificationCenter_NotificationCenter_addObserver00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeObserver of class  NotificationCenter */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationCenter_removeObserver01
static int tolua_NotificationCenter_NotificationCenter_removeObserver01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationCenter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NotificationCenter* self = (NotificationCenter*)  tolua_tousertype(tolua_S,1,0);
  int nHandler = (toluafix_ref_function(tolua_S,2,0));
  const char* eventType = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeObserver'", NULL);
#endif
  {
   self->removeObserver(nHandler,eventType);
  }
 }
 return 0;
tolua_lerror:
 return tolua_NotificationCenter_NotificationCenter_removeObserver00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationObserver_new00
static int tolua_NotificationCenter_NotificationObserver_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NotificationObserver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   NotificationObserver* tolua_ret = (NotificationObserver*)  Mtolua_new((NotificationObserver)(nHandler));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NotificationObserver");
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

/* method: new_local of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationObserver_new00_local
static int tolua_NotificationCenter_NotificationObserver_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NotificationObserver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   NotificationObserver* tolua_ret = (NotificationObserver*)  Mtolua_new((NotificationObserver)(nHandler));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NotificationObserver");
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

/* method: new of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationObserver_new01
static int tolua_NotificationCenter_NotificationObserver_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NotificationObserver",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Action_CallFunc",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  Action_CallFunc action = *((Action_CallFunc*)  tolua_tousertype(tolua_S,3,0));
  {
   NotificationObserver* tolua_ret = (NotificationObserver*)  Mtolua_new((NotificationObserver)(target,action));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NotificationObserver");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NotificationCenter_NotificationObserver_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationObserver_new01_local
static int tolua_NotificationCenter_NotificationObserver_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NotificationObserver",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Action_CallFunc",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  Action_CallFunc action = *((Action_CallFunc*)  tolua_tousertype(tolua_S,3,0));
  {
   NotificationObserver* tolua_ret = (NotificationObserver*)  Mtolua_new((NotificationObserver)(target,action));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NotificationObserver");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NotificationCenter_NotificationObserver_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationObserver_delete00
static int tolua_NotificationCenter_NotificationObserver_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationObserver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: m_target of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_get_NotificationObserver_m_target_ptr
static int tolua_get_NotificationObserver_m_target_ptr(lua_State* tolua_S)
{
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_target'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_target,"CCObject");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_target of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_set_NotificationObserver_m_target_ptr
static int tolua_set_NotificationObserver_m_target_ptr(lua_State* tolua_S)
{
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_target'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_target = ((CCObject*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_action of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_get_NotificationObserver_m_action
static int tolua_get_NotificationObserver_m_action(lua_State* tolua_S)
{
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_action'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->m_action,"Action_CallFunc");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_action of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_set_NotificationObserver_m_action
static int tolua_set_NotificationObserver_m_action(lua_State* tolua_S)
{
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_action'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Action_CallFunc",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_action = *((Action_CallFunc*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scriptFlag of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_get_NotificationObserver_scriptFlag
static int tolua_get_NotificationObserver_scriptFlag(lua_State* tolua_S)
{
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scriptFlag'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scriptFlag);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scriptFlag of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_set_NotificationObserver_scriptFlag
static int tolua_set_NotificationObserver_scriptFlag(lua_State* tolua_S)
{
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scriptFlag'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scriptFlag = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: runAction of class  NotificationObserver */
#ifndef TOLUA_DISABLE_tolua_NotificationCenter_NotificationObserver_runAction00
static int tolua_NotificationCenter_NotificationObserver_runAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NotificationObserver",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NotificationEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NotificationObserver* self = (NotificationObserver*)  tolua_tousertype(tolua_S,1,0);
  NotificationEvent* event = ((NotificationEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'runAction'", NULL);
#endif
  {
   self->runAction(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_NotificationCenter_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"NotificationCenter","NotificationCenter","CCObject",NULL);
  tolua_beginmodule(tolua_S,"NotificationCenter");
   tolua_function(tolua_S,"addObserver",tolua_NotificationCenter_NotificationCenter_addObserver00);
   tolua_function(tolua_S,"removeObserver",tolua_NotificationCenter_NotificationCenter_removeObserver00);
   tolua_function(tolua_S,"sendEvent",tolua_NotificationCenter_NotificationCenter_sendEvent00);
   tolua_function(tolua_S,"sendEventCom",tolua_NotificationCenter_NotificationCenter_sendEventCom00);
   tolua_function(tolua_S,"sendEventNot",tolua_NotificationCenter_NotificationCenter_sendEventNot00);
   tolua_function(tolua_S,"clearEventAndObserver",tolua_NotificationCenter_NotificationCenter_clearEventAndObserver00);
   tolua_function(tolua_S,"addObserver",tolua_NotificationCenter_NotificationCenter_addObserver01);
   tolua_function(tolua_S,"removeObserver",tolua_NotificationCenter_NotificationCenter_removeObserver01);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"NotificationObserver","NotificationObserver","CCObject",tolua_collect_NotificationObserver);
  #else
  tolua_cclass(tolua_S,"NotificationObserver","NotificationObserver","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"NotificationObserver");
   tolua_function(tolua_S,"new",tolua_NotificationCenter_NotificationObserver_new00);
   tolua_function(tolua_S,"new_local",tolua_NotificationCenter_NotificationObserver_new00_local);
   tolua_function(tolua_S,".call",tolua_NotificationCenter_NotificationObserver_new00_local);
   tolua_function(tolua_S,"new",tolua_NotificationCenter_NotificationObserver_new01);
   tolua_function(tolua_S,"new_local",tolua_NotificationCenter_NotificationObserver_new01_local);
   tolua_function(tolua_S,".call",tolua_NotificationCenter_NotificationObserver_new01_local);
   tolua_function(tolua_S,"delete",tolua_NotificationCenter_NotificationObserver_delete00);
   tolua_variable(tolua_S,"m_target",tolua_get_NotificationObserver_m_target_ptr,tolua_set_NotificationObserver_m_target_ptr);
   tolua_variable(tolua_S,"m_action",tolua_get_NotificationObserver_m_action,tolua_set_NotificationObserver_m_action);
   tolua_variable(tolua_S,"scriptFlag",tolua_get_NotificationObserver_scriptFlag,tolua_set_NotificationObserver_scriptFlag);
   tolua_function(tolua_S,"runAction",tolua_NotificationCenter_NotificationObserver_runAction00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_NotificationCenter (lua_State* tolua_S) {
 return tolua_NotificationCenter_open(tolua_S);
};
#endif

