/*
** Lua binding: SevTCliNotification
** Generated automatically by tolua++-1.0.92 on 08/13/12 20:40:58.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_SevTCliNotification_open (lua_State* tolua_S);

#include "SevTCliNotification.h"
#include "NotificationCenter.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NotificationCenter");
 tolua_usertype(tolua_S,"SevTCliNotification");
}

/* method: sharedNotification of class  SevTCliNotification */
#ifndef TOLUA_DISABLE_tolua_SevTCliNotification_SevTCliNotification_sharedNotification00
static int tolua_SevTCliNotification_SevTCliNotification_sharedNotification00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SevTCliNotification",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SevTCliNotification* tolua_ret = (SevTCliNotification*)  SevTCliNotification::sharedNotification();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SevTCliNotification");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedNotification'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_SevTCliNotification_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"SevTCliNotification","SevTCliNotification","NotificationCenter",NULL);
  tolua_beginmodule(tolua_S,"SevTCliNotification");
   tolua_function(tolua_S,"sharedNotification",tolua_SevTCliNotification_SevTCliNotification_sharedNotification00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_SevTCliNotification (lua_State* tolua_S) {
 return tolua_SevTCliNotification_open(tolua_S);
};
#endif

