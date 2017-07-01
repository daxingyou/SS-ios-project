//
//  CountryWarMemberInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CountryWarMemberInfo_h
#define Lstx_cocos2dX_CountryWarMemberInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class CountryWarMemberInfo : public CCObject{

private:

	/**
	 * 进攻方防守方 0:进攻 1:防守
	 */
	int attDef;
	/**
	 * 角色名称
	 */
	std::string roleName;
	/**
	 * 角色头像
	 */
	std::string roleHead;
	/**
	 * 角色id
	 */
	long roleId;
    
public:
    
    CountryWarMemberInfo(void){
    }
    
    ~CountryWarMemberInfo(void){
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
        const char *roleHeadChar = roleHead.c_str();
        CC_SAFE_DELETE_ARRAY(roleHeadChar);
	}
    
	/**
	 * 进攻方防守方 0:进攻 1:防守
	 */
	int getAttDef() {
		return this->attDef;
	}
	/**
	 * 进攻方防守方 0:进攻 1:防守
	 */
	void setAttDef(int attDef){
		this->attDef = attDef;
	}
	/**
	 * 角色名称
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 角色名称
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 角色头像
	 */
	std::string getRoleHead() {
		return this->roleHead;
	}
	/**
	 * 角色头像
	 */
	void setRoleHead(std::string roleHead){
		this->roleHead = roleHead;
	}
	/**
	 * 角色id
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 角色id
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
