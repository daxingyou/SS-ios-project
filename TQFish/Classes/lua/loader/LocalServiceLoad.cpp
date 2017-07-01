/*
** Lua binding: LocalService
** Generated automatically by tolua++-1.0.92 on 09/25/15 10:54:16.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_LocalService_open (lua_State* tolua_S);

#include "LocalService.h"
#include <stdio.h>
#include <vector>
#include <string>
#include "cocos2d.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LocalService (lua_State* tolua_S)
{
 LocalService* self = (LocalService*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LocalService");
}

/* method: new of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_new00
static int tolua_LocalService_LocalService_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LocalService* tolua_ret = (LocalService*)  Mtolua_new((LocalService)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LocalService");
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

/* method: new_local of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_new00_local
static int tolua_LocalService_LocalService_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LocalService* tolua_ret = (LocalService*)  Mtolua_new((LocalService)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LocalService");
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

/* method: delete of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_delete00
static int tolua_LocalService_LocalService_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
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

/* method: shuffleCards of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_shuffleCards00
static int tolua_LocalService_LocalService_shuffleCards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'shuffleCards'", NULL);
#endif
  {
   self->shuffleCards();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'shuffleCards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: creatRobotByPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_creatRobotByPos00
static int tolua_LocalService_LocalService_creatRobotByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'creatRobotByPos'", NULL);
#endif
  {
   self->creatRobotByPos(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'creatRobotByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deleteRobotByPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_deleteRobotByPos00
static int tolua_LocalService_LocalService_deleteRobotByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deleteRobotByPos'", NULL);
#endif
  {
   self->deleteRobotByPos(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteRobotByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllCards of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_removeAllCards00
static int tolua_LocalService_LocalService_removeAllCards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllCards'", NULL);
#endif
  {
   self->removeAllCards();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllCards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: broadcastRobotHandCards of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_broadcastRobotHandCards00
static int tolua_LocalService_LocalService_broadcastRobotHandCards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'broadcastRobotHandCards'", NULL);
#endif
  {
   self->broadcastRobotHandCards();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'broadcastRobotHandCards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHandCardsByPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_getHandCardsByPos00
static int tolua_LocalService_LocalService_getHandCardsByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHandCardsByPos'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getHandCardsByPos(pos);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHandCardsByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRobotShowCardByPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_getRobotShowCardByPos00
static int tolua_LocalService_LocalService_getRobotShowCardByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRobotShowCardByPos'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRobotShowCardByPos(pos);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRobotShowCardByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRobotCallScoreByPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_getRobotCallScoreByPos00
static int tolua_LocalService_LocalService_getRobotCallScoreByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRobotCallScoreByPos'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRobotCallScoreByPos(pos);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRobotCallScoreByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLordPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_setLordPos00
static int tolua_LocalService_LocalService_setLordPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLordPos'", NULL);
#endif
  {
   self->setLordPos(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLordPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: selfTakeCards of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_selfTakeCards00
static int tolua_LocalService_LocalService_selfTakeCards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  string strCardValue = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'selfTakeCards'", NULL);
#endif
  {
   self->selfTakeCards(strCardValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'selfTakeCards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTakeCardByPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_getTakeCardByPos00
static int tolua_LocalService_LocalService_getTakeCardByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTakeCardByPos'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getTakeCardByPos(pos);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTakeCardByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTakeCardsSurplusByPos of class  LocalService */
#ifndef TOLUA_DISABLE_tolua_LocalService_LocalService_getTakeCardsSurplusByPos00
static int tolua_LocalService_LocalService_getTakeCardsSurplusByPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LocalService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LocalService* self = (LocalService*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTakeCardsSurplusByPos'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getTakeCardsSurplusByPos(pos);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTakeCardsSurplusByPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LocalService_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LocalService","LocalService","",tolua_collect_LocalService);
  #else
  tolua_cclass(tolua_S,"LocalService","LocalService","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LocalService");
   tolua_function(tolua_S,"new",tolua_LocalService_LocalService_new00);
   tolua_function(tolua_S,"new_local",tolua_LocalService_LocalService_new00_local);
   tolua_function(tolua_S,".call",tolua_LocalService_LocalService_new00_local);
   tolua_function(tolua_S,"delete",tolua_LocalService_LocalService_delete00);
   tolua_function(tolua_S,"shuffleCards",tolua_LocalService_LocalService_shuffleCards00);
   tolua_function(tolua_S,"creatRobotByPos",tolua_LocalService_LocalService_creatRobotByPos00);
   tolua_function(tolua_S,"deleteRobotByPos",tolua_LocalService_LocalService_deleteRobotByPos00);
   tolua_function(tolua_S,"removeAllCards",tolua_LocalService_LocalService_removeAllCards00);
   tolua_function(tolua_S,"broadcastRobotHandCards",tolua_LocalService_LocalService_broadcastRobotHandCards00);
   tolua_function(tolua_S,"getHandCardsByPos",tolua_LocalService_LocalService_getHandCardsByPos00);
   tolua_function(tolua_S,"getRobotShowCardByPos",tolua_LocalService_LocalService_getRobotShowCardByPos00);
   tolua_function(tolua_S,"getRobotCallScoreByPos",tolua_LocalService_LocalService_getRobotCallScoreByPos00);
   tolua_function(tolua_S,"setLordPos",tolua_LocalService_LocalService_setLordPos00);
   tolua_function(tolua_S,"selfTakeCards",tolua_LocalService_LocalService_selfTakeCards00);
   tolua_function(tolua_S,"getTakeCardByPos",tolua_LocalService_LocalService_getTakeCardByPos00);
   tolua_function(tolua_S,"getTakeCardsSurplusByPos",tolua_LocalService_LocalService_getTakeCardsSurplusByPos00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LocalService (lua_State* tolua_S) {
 return tolua_LocalService_open(tolua_S);
};
#endif

