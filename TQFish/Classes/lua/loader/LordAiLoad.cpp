/*
** Lua binding: LordAi
** Generated automatically by tolua++-1.0.92 on 08/21/15 13:26:01.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_LordAi_open (lua_State* tolua_S);

#include "LordAi.h"
#include "LocalService.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LordAi (lua_State* tolua_S)
{
 LordAi* self = (LordAi*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LocalService");
 tolua_usertype(tolua_S,"LordAi");
}

/* method: new of class  LordAi */
#ifndef TOLUA_DISABLE_tolua_LordAi_LordAi_new00
static int tolua_LordAi_LordAi_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LordAi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LordAi* tolua_ret = (LordAi*)  Mtolua_new((LordAi)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LordAi");
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

/* method: new_local of class  LordAi */
#ifndef TOLUA_DISABLE_tolua_LordAi_LordAi_new00_local
static int tolua_LordAi_LordAi_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LordAi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LordAi* tolua_ret = (LordAi*)  Mtolua_new((LordAi)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LordAi");
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

/* method: delete of class  LordAi */
#ifndef TOLUA_DISABLE_tolua_LordAi_LordAi_delete00
static int tolua_LordAi_LordAi_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LordAi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LordAi* self = (LordAi*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getLordAiService of class  LordAi */
#ifndef TOLUA_DISABLE_tolua_LordAi_LordAi_getLordAiService00
static int tolua_LordAi_LordAi_getLordAiService00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LordAi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LocalService* tolua_ret = (LocalService*)  LordAi::getLordAiService();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LocalService");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLordAiService'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LordAi_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LordAi","LordAi","",tolua_collect_LordAi);
  #else
  tolua_cclass(tolua_S,"LordAi","LordAi","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LordAi");
   tolua_function(tolua_S,"new",tolua_LordAi_LordAi_new00);
   tolua_function(tolua_S,"new_local",tolua_LordAi_LordAi_new00_local);
   tolua_function(tolua_S,".call",tolua_LordAi_LordAi_new00_local);
   tolua_function(tolua_S,"delete",tolua_LordAi_LordAi_delete00);
   tolua_function(tolua_S,"getLordAiService",tolua_LordAi_LordAi_getLordAiService00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LordAi (lua_State* tolua_S) {
 return tolua_LordAi_open(tolua_S);
};
#endif

