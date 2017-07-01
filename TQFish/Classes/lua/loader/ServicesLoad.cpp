/*
** Lua binding: Services
** Generated automatically by tolua++-1.0.92 on 07/19/12 15:40:48.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Services_open (lua_State* tolua_S);

#include "MessageService.h"
#include "Services.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"MessageService");
 tolua_usertype(tolua_S,"Services");
}

/* method: getMessageService of class  Services */
#ifndef TOLUA_DISABLE_tolua_Services_Services_getMessageService00
static int tolua_Services_Services_getMessageService00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Services",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MessageService* tolua_ret = (MessageService*)  Services::getMessageService();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageService");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMessageService'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyMessageService of class  Services */
#ifndef TOLUA_DISABLE_tolua_Services_Services_destroyMessageService00
static int tolua_Services_Services_destroyMessageService00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"Services",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        {
            MessageService* tolua_ret = (MessageService*)  Services::destroyMessageService();
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageService");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'destroyMessageService'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Services_open (lua_State* tolua_S)
{
    tolua_open(tolua_S);
    tolua_reg_types(tolua_S);
    tolua_module(tolua_S,NULL,0);
    tolua_beginmodule(tolua_S,NULL);
    tolua_cclass(tolua_S,"Services","Services","",NULL);
    tolua_beginmodule(tolua_S,"Services");
    tolua_function(tolua_S,"getMessageService",tolua_Services_Services_getMessageService00);
    tolua_function(tolua_S,"destroyMessageService",tolua_Services_Services_destroyMessageService00);
    tolua_endmodule(tolua_S);
    tolua_endmodule(tolua_S);
    return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Services (lua_State* tolua_S) {
 return tolua_Services_open(tolua_S);
};
#endif

