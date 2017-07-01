//
//  ActivitiesListInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ActivitiesListInfo_h
#define Lstx_cocos2dX_ActivitiesListInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class ActivitiesListInfo : public CCObject{

private:

	/**
	 * 序号
	 */
	int theCount;
	/**
	 * 角色等级
	 */
	int lv;
	/**
	 * 角色姓名
	 */
	std::string roleName;
	/**
	 * 积分
	 */
	long integral;
	/**
	 * 角色ID
	 */
	long roleId;
	/**
	 * 国家
	 */
	int country;
    
public:
    
    ActivitiesListInfo(void){
    }
    
    ~ActivitiesListInfo(void){
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
	}
    
	/**
	 * 序号
	 */
	int getTheCount() {
		return this->theCount;
	}
	/**
	 * 序号
	 */
	void setTheCount(int theCount){
		this->theCount = theCount;
	}
	/**
	 * 角色等级
	 */
	int getLv() {
		return this->lv;
	}
	/**
	 * 角色等级
	 */
	void setLv(int lv){
		this->lv = lv;
	}
	/**
	 * 角色姓名
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 角色姓名
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 积分
	 */
	long getIntegral() {
		return this->integral;
	}
	/**
	 * 积分
	 */
	void setIntegral(long integral){
		this->integral = integral;
	}
	/**
	 * 角色ID
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 角色ID
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}
	/**
	 * 国家
	 */
	int getCountry() {
		return this->country;
	}
	/**
	 * 国家
	 */
	void setCountry(int country){
		this->country = country;
	}

};

#endif
