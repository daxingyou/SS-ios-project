//
//  BombInfoBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_BombInfoBean_h
#define Lstx_cocos2dX_BombInfoBean_h

#include "cocos2d.h"
using namespace cocos2d;


class BombInfoBean : public CCObject{

private:

	/**
	 * 角色名
	 */
	std::string roleName;
	/**
	 * 炸矿时间
	 */
	std::string bombTime;
	/**
	 * 角色Id
	 */
	long roleId;
    
public:
    
    BombInfoBean(void){
    }
    
    ~BombInfoBean(void){
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
        const char *bombTimeChar = bombTime.c_str();
        CC_SAFE_DELETE_ARRAY(bombTimeChar);
	}
    
	/**
	 * 角色名
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 角色名
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 炸矿时间
	 */
	std::string getBombTime() {
		return this->bombTime;
	}
	/**
	 * 炸矿时间
	 */
	void setBombTime(std::string bombTime){
		this->bombTime = bombTime;
	}
	/**
	 * 角色Id
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 角色Id
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
