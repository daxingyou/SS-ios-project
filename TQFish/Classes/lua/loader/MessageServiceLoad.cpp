/*
** Lua binding: MessageService
** Generated automatically by tolua++-1.0.92 on 07/29/16 17:51:56.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_MessageService_open (lua_State* tolua_S);

#include "MessageService.h"
#include "stdafx.h"
#include "ODSocket.h"
#include "BaseMessage.h"
#include "MessageRecognize.h"
#include "MessageRegister.h"
#include "MessageType.h"
#include "NMBaseMessage.h"
#include <list>
#include "cocos2d.h"
#include "PublicLuaBridge.h"
#include <queue>
#include <pthread.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_MessageService (lua_State* tolua_S)
{
 MessageService* self = (MessageService*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"list<NMBaseMessage*>");
 tolua_usertype(tolua_S,"BaseMessage");
 tolua_usertype(tolua_S,"MessageService");
}

/* method: new of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_new00
static int tolua_MessageService_MessageService_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MessageService* tolua_ret = (MessageService*)  Mtolua_new((MessageService)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageService");
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

/* method: new_local of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_new00_local
static int tolua_MessageService_MessageService_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MessageService* tolua_ret = (MessageService*)  Mtolua_new((MessageService)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageService");
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

/* method: delete of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_delete00
static int tolua_MessageService_MessageService_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
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

/* method: init of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_init00
static int tolua_MessageService_MessageService_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  const char* serverIp = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   self->init(serverIp,port);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllServerIp of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_removeAllServerIp00
static int tolua_MessageService_MessageService_removeAllServerIp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllServerIp'", NULL);
#endif
  {
   self->removeAllServerIp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllServerIp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWaitReconnect of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_setWaitReconnect00
static int tolua_MessageService_MessageService_setWaitReconnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  bool Wait = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWaitReconnect'", NULL);
#endif
  {
   self->setWaitReconnect(Wait);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWaitReconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFristConnect of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_setFristConnect00
static int tolua_MessageService_MessageService_setFristConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  bool isFrist = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFristConnect'", NULL);
#endif
  {
   self->setFristConnect(isFrist);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFristConnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: connect of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_connect00
static int tolua_MessageService_MessageService_connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connect'", NULL);
#endif
  {
   self->connect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: tickReceivedMessage of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_tickReceivedMessage00
static int tolua_MessageService_MessageService_tickReceivedMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tickReceivedMessage'", NULL);
#endif
  {
   self->tickReceivedMessage();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tickReceivedMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendMessage of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_sendMessage00
static int tolua_MessageService_MessageService_sendMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  BaseMessage* baseMessage = ((BaseMessage*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendMessage'", NULL);
#endif
  {
   self->sendMessage(baseMessage);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startReceiveMessage of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_startReceiveMessage00
static int tolua_MessageService_MessageService_startReceiveMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startReceiveMessage'", NULL);
#endif
  {
   self->startReceiveMessage();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startReceiveMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reConnect of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_reConnect00
static int tolua_MessageService_MessageService_reConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reConnect'", NULL);
#endif
  {
   self->reConnect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reConnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopConnect of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_stopConnect00
static int tolua_MessageService_MessageService_stopConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopConnect'", NULL);
#endif
  {
   self->stopConnect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopConnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startConnect of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_startConnect00
static int tolua_MessageService_MessageService_startConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startConnect'", NULL);
#endif
  {
   self->startConnect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startConnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllMessage of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_removeAllMessage00
static int tolua_MessageService_MessageService_removeAllMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllMessage'", NULL);
#endif
  {
   self->removeAllMessage();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: closeSocket of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_closeSocket00
static int tolua_MessageService_MessageService_closeSocket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'closeSocket'", NULL);
#endif
  {
   self->closeSocket();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'closeSocket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pauseSocket of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_pauseSocket00
static int tolua_MessageService_MessageService_pauseSocket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pauseSocket'", NULL);
#endif
  {
   self->pauseSocket();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pauseSocket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resumeSocket of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_resumeSocket00
static int tolua_MessageService_MessageService_resumeSocket00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resumeSocket'", NULL);
#endif
  {
   self->resumeSocket();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resumeSocket'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCutOut of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_setCutOut00
static int tolua_MessageService_MessageService_setCutOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  bool iscutout = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCutOut'", NULL);
#endif
  {
   self->setCutOut(iscutout);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCutOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCutOut of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_getCutOut00
static int tolua_MessageService_MessageService_getCutOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCutOut'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getCutOut();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCutOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: messageToLua of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_messageToLua00
static int tolua_MessageService_MessageService_messageToLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  int messageType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'messageToLua'", NULL);
#endif
  {
   self->messageToLua(messageType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'messageToLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setImportMessage of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_setImportMessage00
static int tolua_MessageService_MessageService_setImportMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  int msgID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setImportMessage'", NULL);
#endif
  {
   self->setImportMessage(msgID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setImportMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImportMessage of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_MessageService_MessageService_getImportMessage00
static int tolua_MessageService_MessageService_getImportMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MessageService",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImportMessage'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getImportMessage(id);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImportMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMessageList of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_get_MessageService_mMessageList
static int tolua_get_MessageService_mMessageList(lua_State* tolua_S)
{
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMessageList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mMessageList,"list<NMBaseMessage*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMessageList of class  MessageService */
#ifndef TOLUA_DISABLE_tolua_set_MessageService_mMessageList
static int tolua_set_MessageService_mMessageList(lua_State* tolua_S)
{
  MessageService* self = (MessageService*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMessageList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"list<NMBaseMessage*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMessageList = *((list<NMBaseMessage*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_MessageService_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"MessageService","MessageService","",tolua_collect_MessageService);
  #else
  tolua_cclass(tolua_S,"MessageService","MessageService","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"MessageService");
   tolua_function(tolua_S,"new",tolua_MessageService_MessageService_new00);
   tolua_function(tolua_S,"new_local",tolua_MessageService_MessageService_new00_local);
   tolua_function(tolua_S,".call",tolua_MessageService_MessageService_new00_local);
   tolua_function(tolua_S,"delete",tolua_MessageService_MessageService_delete00);
   tolua_function(tolua_S,"init",tolua_MessageService_MessageService_init00);
   tolua_function(tolua_S,"removeAllServerIp",tolua_MessageService_MessageService_removeAllServerIp00);
   tolua_function(tolua_S,"setWaitReconnect",tolua_MessageService_MessageService_setWaitReconnect00);
   tolua_function(tolua_S,"setFristConnect",tolua_MessageService_MessageService_setFristConnect00);
   tolua_function(tolua_S,"connect",tolua_MessageService_MessageService_connect00);
   tolua_function(tolua_S,"tickReceivedMessage",tolua_MessageService_MessageService_tickReceivedMessage00);
   tolua_function(tolua_S,"sendMessage",tolua_MessageService_MessageService_sendMessage00);
   tolua_function(tolua_S,"startReceiveMessage",tolua_MessageService_MessageService_startReceiveMessage00);
   tolua_function(tolua_S,"reConnect",tolua_MessageService_MessageService_reConnect00);
   tolua_function(tolua_S,"stopConnect",tolua_MessageService_MessageService_stopConnect00);
   tolua_function(tolua_S,"startConnect",tolua_MessageService_MessageService_startConnect00);
   tolua_function(tolua_S,"removeAllMessage",tolua_MessageService_MessageService_removeAllMessage00);
   tolua_function(tolua_S,"closeSocket",tolua_MessageService_MessageService_closeSocket00);
   tolua_function(tolua_S,"pauseSocket",tolua_MessageService_MessageService_pauseSocket00);
   tolua_function(tolua_S,"resumeSocket",tolua_MessageService_MessageService_resumeSocket00);
   tolua_function(tolua_S,"setCutOut",tolua_MessageService_MessageService_setCutOut00);
   tolua_function(tolua_S,"getCutOut",tolua_MessageService_MessageService_getCutOut00);
   tolua_function(tolua_S,"messageToLua",tolua_MessageService_MessageService_messageToLua00);
   tolua_function(tolua_S,"setImportMessage",tolua_MessageService_MessageService_setImportMessage00);
   tolua_function(tolua_S,"getImportMessage",tolua_MessageService_MessageService_getImportMessage00);
   tolua_variable(tolua_S,"mMessageList",tolua_get_MessageService_mMessageList,tolua_set_MessageService_mMessageList);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MessageService (lua_State* tolua_S) {
 return tolua_MessageService_open(tolua_S);
};
#endif

