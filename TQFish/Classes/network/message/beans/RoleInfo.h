//
//  RoleInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_RoleInfo_h
#define Lstx_cocos2dX_RoleInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class RoleInfo : public CCObject{

private:

	/**
	 * 玩家官职id
	 */
	int officeId;
	/**
	 * 玩家国家
	 */
	int roleNation;
	/**
	 * 玩家头像
	 */
	std::string roleImg;
	/**
	 * 玩家排行
	 */
	int roleOrder;
	/**
	 * 玩家积分
	 */
	int rolePoints;
	/**
	 * 玩家等级
	 */
	int roleLevel;
	/**
	 * 玩家名字
	 */
	std::string roleName;
	/**
	 * 玩家军团名称
	 */
	std::string roleArmyName;
	/**
	 * 玩家属性
	 */
	int roleAttribute;
	/**
	 * 玩家id
	 */
	long roleId;
    
public:
    
    RoleInfo(void){
    }
    
    ~RoleInfo(void){
        const char *roleImgChar = roleImg.c_str();
        CC_SAFE_DELETE_ARRAY(roleImgChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
        const char *roleArmyNameChar = roleArmyName.c_str();
        CC_SAFE_DELETE_ARRAY(roleArmyNameChar);
	}
    
	/**
	 * 玩家官职id
	 */
	int getOfficeId() {
		return this->officeId;
	}
	/**
	 * 玩家官职id
	 */
	void setOfficeId(int officeId){
		this->officeId = officeId;
	}
	/**
	 * 玩家国家
	 */
	int getRoleNation() {
		return this->roleNation;
	}
	/**
	 * 玩家国家
	 */
	void setRoleNation(int roleNation){
		this->roleNation = roleNation;
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
	 * 玩家排行
	 */
	int getRoleOrder() {
		return this->roleOrder;
	}
	/**
	 * 玩家排行
	 */
	void setRoleOrder(int roleOrder){
		this->roleOrder = roleOrder;
	}
	/**
	 * 玩家积分
	 */
	int getRolePoints() {
		return this->rolePoints;
	}
	/**
	 * 玩家积分
	 */
	void setRolePoints(int rolePoints){
		this->rolePoints = rolePoints;
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
	 * 玩家军团名称
	 */
	std::string getRoleArmyName() {
		return this->roleArmyName;
	}
	/**
	 * 玩家军团名称
	 */
	void setRoleArmyName(std::string roleArmyName){
		this->roleArmyName = roleArmyName;
	}
	/**
	 * 玩家属性
	 */
	int getRoleAttribute() {
		return this->roleAttribute;
	}
	/**
	 * 玩家属性
	 */
	void setRoleAttribute(int roleAttribute){
		this->roleAttribute = roleAttribute;
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
