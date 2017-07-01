/*
** Lua binding: NMBaseMessage
** Generated automatically by tolua++-1.0.92 on 12/25/13 11:48:17.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_NMBaseMessage_open (lua_State* tolua_S);

#include "NMBaseMessage.h"
#include "BaseMessage.h"


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_NMBaseMessage (lua_State* tolua_S)
{
 NMBaseMessage* self = (NMBaseMessage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NMBaseMessage");
 tolua_usertype(tolua_S,"BaseMessage");
}

/* method: new of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_new00
static int tolua_NMBaseMessage_NMBaseMessage_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NMBaseMessage* tolua_ret = (NMBaseMessage*)  Mtolua_new((NMBaseMessage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NMBaseMessage");
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

/* method: new_local of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_new00_local
static int tolua_NMBaseMessage_NMBaseMessage_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NMBaseMessage* tolua_ret = (NMBaseMessage*)  Mtolua_new((NMBaseMessage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NMBaseMessage");
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

/* method: new of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_new01
static int tolua_NMBaseMessage_NMBaseMessage_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int capacity = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   NMBaseMessage* tolua_ret = (NMBaseMessage*)  Mtolua_new((NMBaseMessage)(capacity));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NMBaseMessage");
  }
 }
 return 1;
tolua_lerror:
 return tolua_NMBaseMessage_NMBaseMessage_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_new01_local
static int tolua_NMBaseMessage_NMBaseMessage_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int capacity = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   NMBaseMessage* tolua_ret = (NMBaseMessage*)  Mtolua_new((NMBaseMessage)(capacity));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NMBaseMessage");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_NMBaseMessage_NMBaseMessage_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_delete00
static int tolua_NMBaseMessage_NMBaseMessage_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setLength of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_setLength00
static int tolua_NMBaseMessage_NMBaseMessage_setLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
  short length = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLength'", NULL);
#endif
  {
   self->setLength(length);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMessageType of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_getMessageType00
static int tolua_NMBaseMessage_NMBaseMessage_getMessageType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMessageType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMessageType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMessageType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setExtData of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_setExtData00
static int tolua_NMBaseMessage_NMBaseMessage_setExtData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
  int extData = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setExtData'", NULL);
#endif
  {
   self->setExtData(extData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setExtData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMsgVer of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_setMsgVer00
static int tolua_NMBaseMessage_NMBaseMessage_setMsgVer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
  int msgVer = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMsgVer'", NULL);
#endif
  {
   self->setMsgVer(msgVer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMsgVer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMessageName of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_getMessageName00
static int tolua_NMBaseMessage_NMBaseMessage_getMessageName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMessageName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getMessageName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMessageName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeImpl of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_writeImpl00
static int tolua_NMBaseMessage_NMBaseMessage_writeImpl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeImpl'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->writeImpl();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeImpl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readImpl of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_readImpl00
static int tolua_NMBaseMessage_NMBaseMessage_readImpl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readImpl'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->readImpl();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readImpl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMessageType of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_setMessageType00
static int tolua_NMBaseMessage_NMBaseMessage_setMessageType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMessageType'", NULL);
#endif
  {
   self->setMessageType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMessageType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeStart of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_writeStart00
static int tolua_NMBaseMessage_NMBaseMessage_writeStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeStart'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->writeStart();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeOver of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_writeOver00
static int tolua_NMBaseMessage_NMBaseMessage_writeOver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeOver'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->writeOver();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeOver'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readStart of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_readStart00
static int tolua_NMBaseMessage_NMBaseMessage_readStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readStart'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->readStart();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setReadPos of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_setReadPos00
static int tolua_NMBaseMessage_NMBaseMessage_setReadPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
  unsigned int r = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setReadPos'", NULL);
#endif
  {
   self->setReadPos(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setReadPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getReadPos of class  NMBaseMessage */
#ifndef TOLUA_DISABLE_tolua_NMBaseMessage_NMBaseMessage_getReadPos00
static int tolua_NMBaseMessage_NMBaseMessage_getReadPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NMBaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NMBaseMessage* self = (NMBaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getReadPos'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getReadPos();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getReadPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_NMBaseMessage_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"NMBaseMessage","NMBaseMessage","BaseMessage",tolua_collect_NMBaseMessage);
  #else
  tolua_cclass(tolua_S,"NMBaseMessage","NMBaseMessage","BaseMessage",NULL);
  #endif
  tolua_beginmodule(tolua_S,"NMBaseMessage");
   tolua_function(tolua_S,"new",tolua_NMBaseMessage_NMBaseMessage_new00);
   tolua_function(tolua_S,"new_local",tolua_NMBaseMessage_NMBaseMessage_new00_local);
   tolua_function(tolua_S,".call",tolua_NMBaseMessage_NMBaseMessage_new00_local);
   tolua_function(tolua_S,"new",tolua_NMBaseMessage_NMBaseMessage_new01);
   tolua_function(tolua_S,"new_local",tolua_NMBaseMessage_NMBaseMessage_new01_local);
   tolua_function(tolua_S,".call",tolua_NMBaseMessage_NMBaseMessage_new01_local);
   tolua_function(tolua_S,"delete",tolua_NMBaseMessage_NMBaseMessage_delete00);
   tolua_function(tolua_S,"setLength",tolua_NMBaseMessage_NMBaseMessage_setLength00);
   tolua_function(tolua_S,"getMessageType",tolua_NMBaseMessage_NMBaseMessage_getMessageType00);
   tolua_function(tolua_S,"setExtData",tolua_NMBaseMessage_NMBaseMessage_setExtData00);
   tolua_function(tolua_S,"setMsgVer",tolua_NMBaseMessage_NMBaseMessage_setMsgVer00);
   tolua_function(tolua_S,"getMessageName",tolua_NMBaseMessage_NMBaseMessage_getMessageName00);
   tolua_function(tolua_S,"writeImpl",tolua_NMBaseMessage_NMBaseMessage_writeImpl00);
   tolua_function(tolua_S,"readImpl",tolua_NMBaseMessage_NMBaseMessage_readImpl00);
   tolua_function(tolua_S,"setMessageType",tolua_NMBaseMessage_NMBaseMessage_setMessageType00);
   tolua_function(tolua_S,"writeStart",tolua_NMBaseMessage_NMBaseMessage_writeStart00);
   tolua_function(tolua_S,"writeOver",tolua_NMBaseMessage_NMBaseMessage_writeOver00);
   tolua_function(tolua_S,"readStart",tolua_NMBaseMessage_NMBaseMessage_readStart00);
   tolua_function(tolua_S,"setReadPos",tolua_NMBaseMessage_NMBaseMessage_setReadPos00);
   tolua_function(tolua_S,"getReadPos",tolua_NMBaseMessage_NMBaseMessage_getReadPos00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_NMBaseMessage (lua_State* tolua_S) {
 return tolua_NMBaseMessage_open(tolua_S);
};
#endif

