//
//  ArmyRoleInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ArmyRoleInfo_h
#define Lstx_cocos2dX_ArmyRoleInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class ArmyRoleInfo : public CCObject{

private:

	/**
	 * 军团职位
	 */
	int army;
	/**
	 * 玩家头像
	 */
	std::string roleImg;
	/**
	 * 玩家等级
	 */
	int roleLevel;
	/**
	 * 玩家名字
	 */
	std::string roleName;
	/**
	 * 玩家id
	 */
	long roleId;
    
public:
    
    ArmyRoleInfo(void){
    }
    
    ~ArmyRoleInfo(void){
        const char *roleImgChar = roleImg.c_str();
        CC_SAFE_DELETE_ARRAY(roleImgChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
	}
    
	/**
	 * 军团职位
	 */
	int getArmy() {
		return this->army;
	}
	/**
	 * 军团职位
	 */
	void setArmy(int army){
		this->army = army;
	}
	/**
	 * 玩家头像
	 */
	std::string getRoleImg() {
		return this->roleImg;
	}
	/**
	 * 玩家头像
	 */
	void setRoleImg(std::string roleImg){
		this->roleImg = roleImg;
	}
	/**
	 * 玩家等级
	 */
	int getRoleLevel() {
		return this->roleLevel;
	}
	/**
	 * 玩家等级
	 */
	void setRoleLevel(int roleLevel){
		this->roleLevel = roleLevel;
	}
	/**
	 * 玩家名字
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 玩家名字
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 玩家id
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 玩家id
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
