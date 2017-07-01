//
//  RoleInfoEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_RoleInfoEntity_h
#define Lstx_cocos2dX_RoleInfoEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class RoleInfoEntity : public CCObject{

private:

	/**
	 * 角色等级
	 */
	int Lv;
	/**
	 * 角色名称
	 */
	std::string roleName;
	/**
	 * 角色ID
	 */
	long Id;
	/**
	 * 角色国家
	 */
	int nation;
    
public:
    
    RoleInfoEntity(void){
    }
    
    ~RoleInfoEntity(void){
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
	}
    
	/**
	 * 角色等级
	 */
	int getLv() {
		return this->Lv;
	}
	/**
	 * 角色等级
	 */
	void setLv(int Lv){
		this->Lv = Lv;
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
	 * 角色ID
	 */
	long getId() {
		return this->Id;
	}
	/**
	 * 角色ID
	 */
	void setId(long Id){
		this->Id = Id;
	}
	/**
	 * 角色国家
	 */
	int getNation() {
		return this->nation;
	}
	/**
	 * 角色国家
	 */
	void setNation(int nation){
		this->nation = nation;
	}

};

#endif
