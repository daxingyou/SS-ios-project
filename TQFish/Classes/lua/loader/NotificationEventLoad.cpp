/*
** Lua binding: NotificationEvent
** Generated automatically by tolua++-1.0.92 on 08/20/12 16:37:09.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_NotificationEvent_open (lua_State* tolua_S);

#include "NotificationEvent.h"
#include "cocos2d.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NotificationEvent");
 tolua_usertype(tolua_S,"CCObject");
}

/* method: createEvent of class  NotificationEvent */
#ifndef TOLUA_DISABLE_tolua_NotificationEvent_NotificationEvent_createEvent00
static int tolua_NotificationEvent_NotificationEvent_createEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NotificationEvent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCObject* data = ((CCObject*)  tolua_tousertype(tolua_S,3,0));
  {
   NotificationEvent* tolua_ret = (NotificationEvent*)  NotificationEvent::createEvent(type,data);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NotificationEvent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_NotificationEvent_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"NotificationEvent","NotificationEvent","CCObject",NULL);
  tolua_beginmodule(tolua_S,"NotificationEvent");
   tolua_function(tolua_S,"createEvent",tolua_NotificationEvent_NotificationEvent_createEvent00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_NotificationEvent (lua_State* tolua_S) {
 return tolua_NotificationEvent_open(tolua_S);
};
#endif

