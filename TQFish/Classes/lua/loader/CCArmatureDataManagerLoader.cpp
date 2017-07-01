/*
** Lua binding: CCArmatureDataManager
** Generated automatically by tolua++-1.0.92 on 01/13/14 17:25:24.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_CCArmatureDataManager_open (lua_State* tolua_S);

#include "CCArmatureDataManager.h"
#include "CCArmatureDefine.h"
#include "CCDatas.h"


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCArmatureData");
 tolua_usertype(tolua_S,"CCArmatureDataManager");
 tolua_usertype(tolua_S,"CCDictionary");
 tolua_usertype(tolua_S,"SEL_SCHEDULE");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"CCAnimationData");
 tolua_usertype(tolua_S,"CCTextureData");
}

/* method: sharedArmatureDataManager of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_sharedArmatureDataManager00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_sharedArmatureDataManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureDataManager* tolua_ret = (CCArmatureDataManager*)  CCArmatureDataManager::sharedArmatureDataManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCArmatureDataManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedArmatureDataManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: purge of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_purge00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_purge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureDataManager::purge();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'purge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_init00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCArmatureData* armatureData = ((CCArmatureData*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureData'", NULL);
#endif
  {
   self->addArmatureData(id,armatureData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmatureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_getArmatureData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_getArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmatureData'", NULL);
#endif
  {
   CCArmatureData* tolua_ret = (CCArmatureData*)  self->getArmatureData(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCArmatureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeArmatureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_removeArmatureData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_removeArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeArmatureData'", NULL);
#endif
  {
   self->removeArmatureData(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAnimationData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addAnimationData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCAnimationData* animationData = ((CCAnimationData*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimationData'", NULL);
#endif
  {
   self->addAnimationData(id,animationData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_getAnimationData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_getAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationData'", NULL);
#endif
  {
   CCAnimationData* tolua_ret = (CCAnimationData*)  self->getAnimationData(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCAnimationData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAnimationData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_removeAnimationData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_removeAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAnimationData'", NULL);
#endif
  {
   self->removeAnimationData(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTextureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addTextureData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addTextureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTextureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCTextureData* textureData = ((CCTextureData*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTextureData'", NULL);
#endif
  {
   self->addTextureData(id,textureData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTextureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_getTextureData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_getTextureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureData'", NULL);
#endif
  {
   CCTextureData* tolua_ret = (CCTextureData*)  self->getTextureData(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCTextureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTextureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_removeTextureData00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_removeTextureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTextureData'", NULL);
#endif
  {
   self->removeTextureData(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTextureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureFileInfo of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfo00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* configFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureFileInfo'", NULL);
#endif
  {
   self->addArmatureFileInfo(configFilePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addArmatureFileInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureFileInfoAsync of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfoAsync00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfoAsync00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SEL_SCHEDULE",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* configFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,3,0));
  SEL_SCHEDULE selector = *((SEL_SCHEDULE*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureFileInfoAsync'", NULL);
#endif
  {
   self->addArmatureFileInfoAsync(configFilePath,target,selector);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addArmatureFileInfoAsync'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureFileInfo of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfo01
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfo01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* imagePath = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* plistPath = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* configFilePath = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureFileInfo'", NULL);
#endif
  {
   self->addArmatureFileInfo(imagePath,plistPath,configFilePath);
  }
 }
 return 0;
tolua_lerror:
 return tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfo00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureFileInfoAsync of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfoAsync01
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfoAsync01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"SEL_SCHEDULE",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* imagePath = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* plistPath = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* configFilePath = ((const char*)  tolua_tostring(tolua_S,4,0));
  CCObject* target = ((CCObject*)  tolua_tousertype(tolua_S,5,0));
  SEL_SCHEDULE selector = *((SEL_SCHEDULE*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureFileInfoAsync'", NULL);
#endif
  {
   self->addArmatureFileInfoAsync(imagePath,plistPath,configFilePath,target,selector);
  }
 }
 return 0;
tolua_lerror:
 return tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfoAsync00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSpriteFrameFromFile of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_addSpriteFrameFromFile00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_addSpriteFrameFromFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* plistPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* imagePath = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSpriteFrameFromFile'", NULL);
#endif
  {
   self->addSpriteFrameFromFile(plistPath,imagePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSpriteFrameFromFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAll of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_removeAll00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_removeAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAll'", NULL);
#endif
  {
   self->removeAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAutoLoadSpriteFile of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_isAutoLoadSpriteFile00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_isAutoLoadSpriteFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAutoLoadSpriteFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAutoLoadSpriteFile();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAutoLoadSpriteFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmatureDatas of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_getArmatureDatas00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_getArmatureDatas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmatureDataManager* self = (const CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmatureDatas'", NULL);
#endif
  {
   CCDictionary* tolua_ret = (CCDictionary*)  self->getArmatureDatas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDictionary");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmatureDatas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationDatas of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_getAnimationDatas00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_getAnimationDatas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmatureDataManager* self = (const CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationDatas'", NULL);
#endif
  {
   CCDictionary* tolua_ret = (CCDictionary*)  self->getAnimationDatas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDictionary");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationDatas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureDatas of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CCArmatureDataManager_CCArmatureDataManager_getTextureDatas00
static int tolua_CCArmatureDataManager_CCArmatureDataManager_getTextureDatas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmatureDataManager* self = (const CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureDatas'", NULL);
#endif
  {
   CCDictionary* tolua_ret = (CCDictionary*)  self->getTextureDatas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDictionary");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureDatas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_CCArmatureDataManager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"CCArmatureDataManager","CCArmatureDataManager","CCObject",NULL);
  tolua_beginmodule(tolua_S,"CCArmatureDataManager");
   tolua_function(tolua_S,"sharedArmatureDataManager",tolua_CCArmatureDataManager_CCArmatureDataManager_sharedArmatureDataManager00);
   tolua_function(tolua_S,"purge",tolua_CCArmatureDataManager_CCArmatureDataManager_purge00);
   tolua_function(tolua_S,"init",tolua_CCArmatureDataManager_CCArmatureDataManager_init00);
   tolua_function(tolua_S,"addArmatureData",tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureData00);
   tolua_function(tolua_S,"getArmatureData",tolua_CCArmatureDataManager_CCArmatureDataManager_getArmatureData00);
   tolua_function(tolua_S,"removeArmatureData",tolua_CCArmatureDataManager_CCArmatureDataManager_removeArmatureData00);
   tolua_function(tolua_S,"addAnimationData",tolua_CCArmatureDataManager_CCArmatureDataManager_addAnimationData00);
   tolua_function(tolua_S,"getAnimationData",tolua_CCArmatureDataManager_CCArmatureDataManager_getAnimationData00);
   tolua_function(tolua_S,"removeAnimationData",tolua_CCArmatureDataManager_CCArmatureDataManager_removeAnimationData00);
   tolua_function(tolua_S,"addTextureData",tolua_CCArmatureDataManager_CCArmatureDataManager_addTextureData00);
   tolua_function(tolua_S,"getTextureData",tolua_CCArmatureDataManager_CCArmatureDataManager_getTextureData00);
   tolua_function(tolua_S,"removeTextureData",tolua_CCArmatureDataManager_CCArmatureDataManager_removeTextureData00);
   tolua_function(tolua_S,"addArmatureFileInfo",tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfo00);
   tolua_function(tolua_S,"addArmatureFileInfoAsync",tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfoAsync00);
   tolua_function(tolua_S,"addArmatureFileInfo",tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfo01);
   tolua_function(tolua_S,"addArmatureFileInfoAsync",tolua_CCArmatureDataManager_CCArmatureDataManager_addArmatureFileInfoAsync01);
   tolua_function(tolua_S,"addSpriteFrameFromFile",tolua_CCArmatureDataManager_CCArmatureDataManager_addSpriteFrameFromFile00);
   tolua_function(tolua_S,"removeAll",tolua_CCArmatureDataManager_CCArmatureDataManager_removeAll00);
   tolua_function(tolua_S,"isAutoLoadSpriteFile",tolua_CCArmatureDataManager_CCArmatureDataManager_isAutoLoadSpriteFile00);
   tolua_function(tolua_S,"getArmatureDatas",tolua_CCArmatureDataManager_CCArmatureDataManager_getArmatureDatas00);
   tolua_function(tolua_S,"getAnimationDatas",tolua_CCArmatureDataManager_CCArmatureDataManager_getAnimationDatas00);
   tolua_function(tolua_S,"getTextureDatas",tolua_CCArmatureDataManager_CCArmatureDataManager_getTextureDatas00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_CCArmatureDataManager (lua_State* tolua_S) {
 return tolua_CCArmatureDataManager_open(tolua_S);
};
#endif

