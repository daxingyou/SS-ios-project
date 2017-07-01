/*
** Lua binding: BaseMessage
** Generated automatically by tolua++-1.0.92 on 02/28/17 19:23:28.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_BaseMessage_open (lua_State* tolua_S);

#include "BaseMessage.h"
#include "ByteBuffer.h"
#include "cocos2d.h"
#include "PublicLuaBridge.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_BaseMessage (lua_State* tolua_S)
{
 BaseMessage* self = (BaseMessage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"byteT");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"ByteBuffer");
 tolua_usertype(tolua_S,"BaseMessage");
}

/* method: delete of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_delete00
static int tolua_BaseMessage_BaseMessage_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getMessageType of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_getMessageType00
static int tolua_BaseMessage_BaseMessage_getMessageType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getMessageName of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_getMessageName00
static int tolua_BaseMessage_BaseMessage_getMessageName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: writeImpl of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeImpl00
static int tolua_BaseMessage_BaseMessage_writeImpl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: readImpl of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readImpl00
static int tolua_BaseMessage_BaseMessage_readImpl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getLength of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_getLength00
static int tolua_BaseMessage_BaseMessage_getLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLength'", NULL);
#endif
  {
   short tolua_ret = (short)  self->getLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setByteBuffer of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_setByteBuffer00
static int tolua_BaseMessage_BaseMessage_setByteBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ByteBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  ByteBuffer* byteBuffer = ((ByteBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setByteBuffer'", NULL);
#endif
  {
   self->setByteBuffer(byteBuffer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setByteBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getByteBuffer of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_getByteBuffer00
static int tolua_BaseMessage_BaseMessage_getByteBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getByteBuffer'", NULL);
#endif
  {
   ByteBuffer* tolua_ret = (ByteBuffer*)  self->getByteBuffer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ByteBuffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getByteBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_write00
static int tolua_BaseMessage_BaseMessage_write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->write();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: read of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_read00
static int tolua_BaseMessage_BaseMessage_read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->read();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readByte of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readByte00
static int tolua_BaseMessage_BaseMessage_readByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readByte'", NULL);
#endif
  {
   short tolua_ret = (short)  self->readByte();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readBool of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readBool00
static int tolua_BaseMessage_BaseMessage_readBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readBool'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->readBool();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readShort of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readShort00
static int tolua_BaseMessage_BaseMessage_readShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readShort'", NULL);
#endif
  {
   short tolua_ret = (short)  self->readShort();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
//联运版本
/* method: readInt of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readInt00
static int tolua_BaseMessage_BaseMessage_readInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readInt'", NULL);
#endif
        {
            std::string tolua_ret = (std::string)  self->readInt();
            tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'readInt'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readRealInt of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readRealInt00
static int tolua_BaseMessage_BaseMessage_readRealInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readRealInt'", NULL);
#endif
        {
            int tolua_ret = (int)  self->readRealInt();
            tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'readRealInt'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#endif

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
//主版本
/* method: readInt of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readInt01
static int tolua_BaseMessage_BaseMessage_readInt01(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
    {
        BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readInt'", NULL);
#endif
        {
            int tolua_ret = (int)  self->readInt();
            tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
        }
    }
    return 1;
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'readInt'.",&tolua_err);
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

#endif



/* method: readLong of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readLong00
static int tolua_BaseMessage_BaseMessage_readLong00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readLong'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->readLong();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readLong'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readDouble of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readDouble00
static int tolua_BaseMessage_BaseMessage_readDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readDouble'", NULL);
#endif
  {
   double tolua_ret = (double)  self->readDouble();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readFloat of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readFloat00
static int tolua_BaseMessage_BaseMessage_readFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readFloat'", NULL);
#endif
  {
   float tolua_ret = (float)  self->readFloat();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readString of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readString00
static int tolua_BaseMessage_BaseMessage_readString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readString'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->readString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readUTF of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_readUTF00
static int tolua_BaseMessage_BaseMessage_readUTF00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readUTF'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->readUTF();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readUTF'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeByte of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeByte00
static int tolua_BaseMessage_BaseMessage_writeByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  short data = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeByte'", NULL);
#endif
  {
   self->writeByte(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeBool of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeBool00
static int tolua_BaseMessage_BaseMessage_writeBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  bool data = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeBool'", NULL);
#endif
  {
   self->writeBool(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeShort of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeShort00
static int tolua_BaseMessage_BaseMessage_writeShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  short data = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeShort'", NULL);
#endif
  {
   self->writeShort(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
//联运版本
/* method: writeInt of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeInt00
static int tolua_BaseMessage_BaseMessage_writeInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
        !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
        std::string data = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeInt'", NULL);
#endif
        {
            self->writeInt(&data);
            tolua_pushcppstring(tolua_S,(const char*)data);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'writeInt'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeRealInt of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeRealInt00
static int tolua_BaseMessage_BaseMessage_writeRealInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
        int data = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeRealInt'", NULL);
#endif
        {
            self->writeRealInt(data);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'writeRealInt'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

#endif

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
//主版本
/* method: writeInt of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeInt01
static int tolua_BaseMessage_BaseMessage_writeInt01(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
    {
        BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
        int data = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeInt'", NULL);
#endif
        {
            self->writeInt(data);
        }
    }
    return 0;
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'writeInt'.",&tolua_err);
    return 0;
}
#endif //#ifndef TOLUA_DISABLE

#endif

/* method: writeLong of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeLong00
static int tolua_BaseMessage_BaseMessage_writeLong00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  std::string data = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeLong'", NULL);
#endif
  {
   self->writeLong(&data);
   tolua_pushcppstring(tolua_S,(const char*)data);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeLong'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeDouble of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeDouble00
static int tolua_BaseMessage_BaseMessage_writeDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  double data = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeDouble'", NULL);
#endif
  {
   self->writeDouble(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeFloat of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeFloat00
static int tolua_BaseMessage_BaseMessage_writeFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  float data = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeFloat'", NULL);
#endif
  {
   self->writeFloat(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeString of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeString00
static int tolua_BaseMessage_BaseMessage_writeString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"byteT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  byteT* data = ((byteT*)  tolua_tousertype(tolua_S,2,0));
  int length = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeString'", NULL);
#endif
  {
   self->writeString(data,length);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeString of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeString01
static int tolua_BaseMessage_BaseMessage_writeString01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  std::string data = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeString'", NULL);
#endif
  {
   self->writeString(&data);
   tolua_pushcppstring(tolua_S,(const char*)data);
  }
 }
 return 1;
tolua_lerror:
 return tolua_BaseMessage_BaseMessage_writeString00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeUTF of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_writeUTF00
static int tolua_BaseMessage_BaseMessage_writeUTF00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  std::string data = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeUTF'", NULL);
#endif
  {
   self->writeUTF(&data);
   tolua_pushcppstring(tolua_S,(const char*)data);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeUTF'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAvailable of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_setAvailable00
static int tolua_BaseMessage_BaseMessage_setAvailable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
  bool available = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAvailable'", NULL);
#endif
  {
   self->setAvailable(available);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAvailable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAvailable of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_isAvailable00
static int tolua_BaseMessage_BaseMessage_isAvailable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAvailable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAvailable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAvailable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setReadPos of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_setReadPos00
static int tolua_BaseMessage_BaseMessage_setReadPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getReadPos of class  BaseMessage */
#ifndef TOLUA_DISABLE_tolua_BaseMessage_BaseMessage_getReadPos00
static int tolua_BaseMessage_BaseMessage_getReadPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BaseMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BaseMessage* self = (BaseMessage*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_BaseMessage_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"BaseMessage","BaseMessage","CCObject",tolua_collect_BaseMessage);
  #else
  tolua_cclass(tolua_S,"BaseMessage","BaseMessage","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"BaseMessage");
   tolua_function(tolua_S,"delete",tolua_BaseMessage_BaseMessage_delete00);
   tolua_function(tolua_S,"getMessageType",tolua_BaseMessage_BaseMessage_getMessageType00);
   tolua_function(tolua_S,"getMessageName",tolua_BaseMessage_BaseMessage_getMessageName00);
   tolua_function(tolua_S,"writeImpl",tolua_BaseMessage_BaseMessage_writeImpl00);
   tolua_function(tolua_S,"readImpl",tolua_BaseMessage_BaseMessage_readImpl00);
   tolua_function(tolua_S,"getLength",tolua_BaseMessage_BaseMessage_getLength00);
   tolua_function(tolua_S,"setByteBuffer",tolua_BaseMessage_BaseMessage_setByteBuffer00);
   tolua_function(tolua_S,"getByteBuffer",tolua_BaseMessage_BaseMessage_getByteBuffer00);
   tolua_function(tolua_S,"write",tolua_BaseMessage_BaseMessage_write00);
   tolua_function(tolua_S,"read",tolua_BaseMessage_BaseMessage_read00);
   tolua_function(tolua_S,"readByte",tolua_BaseMessage_BaseMessage_readByte00);
   tolua_function(tolua_S,"readBool",tolua_BaseMessage_BaseMessage_readBool00);
   tolua_function(tolua_S,"readShort",tolua_BaseMessage_BaseMessage_readShort00);
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    tolua_function(tolua_S,"readInt",tolua_BaseMessage_BaseMessage_readInt00);
    tolua_function(tolua_S,"readRealInt",tolua_BaseMessage_BaseMessage_readRealInt00);
#endif
    
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
    //主版本
    tolua_function(tolua_S,"readInt",tolua_BaseMessage_BaseMessage_readInt01);
#endif

   tolua_function(tolua_S,"readLong",tolua_BaseMessage_BaseMessage_readLong00);
   tolua_function(tolua_S,"readDouble",tolua_BaseMessage_BaseMessage_readDouble00);
   tolua_function(tolua_S,"readFloat",tolua_BaseMessage_BaseMessage_readFloat00);
   tolua_function(tolua_S,"readString",tolua_BaseMessage_BaseMessage_readString00);
   tolua_function(tolua_S,"readUTF",tolua_BaseMessage_BaseMessage_readUTF00);
   tolua_function(tolua_S,"writeByte",tolua_BaseMessage_BaseMessage_writeByte00);
   tolua_function(tolua_S,"writeBool",tolua_BaseMessage_BaseMessage_writeBool00);
   tolua_function(tolua_S,"writeShort",tolua_BaseMessage_BaseMessage_writeShort00);
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    tolua_function(tolua_S,"writeInt",tolua_BaseMessage_BaseMessage_writeInt00);
    tolua_function(tolua_S,"writeRealInt",tolua_BaseMessage_BaseMessage_writeRealInt00);
#endif
    
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
    //主版本
       tolua_function(tolua_S,"writeInt",tolua_BaseMessage_BaseMessage_writeInt01);
#endif

   tolua_function(tolua_S,"writeLong",tolua_BaseMessage_BaseMessage_writeLong00);
   tolua_function(tolua_S,"writeDouble",tolua_BaseMessage_BaseMessage_writeDouble00);
   tolua_function(tolua_S,"writeFloat",tolua_BaseMessage_BaseMessage_writeFloat00);
   tolua_function(tolua_S,"writeString",tolua_BaseMessage_BaseMessage_writeString00);
   tolua_function(tolua_S,"writeString",tolua_BaseMessage_BaseMessage_writeString01);
   tolua_function(tolua_S,"writeUTF",tolua_BaseMessage_BaseMessage_writeUTF00);
   tolua_function(tolua_S,"setAvailable",tolua_BaseMessage_BaseMessage_setAvailable00);
   tolua_function(tolua_S,"isAvailable",tolua_BaseMessage_BaseMessage_isAvailable00);
   tolua_function(tolua_S,"setReadPos",tolua_BaseMessage_BaseMessage_setReadPos00);
   tolua_function(tolua_S,"getReadPos",tolua_BaseMessage_BaseMessage_getReadPos00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_BaseMessage (lua_State* tolua_S) {
 return tolua_BaseMessage_open(tolua_S);
};
#endif

