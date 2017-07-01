//
//  VoteInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_VoteInfo_h
#define Lstx_cocos2dX_VoteInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class VoteInfo : public CCObject{

private:

	/**
	 * 玩家军团名称
	 */
	std::string armyGroupName;
	/**
	 * 玩家等级
	 */
	int roleLevel;
	/**
	 * 玩家名称
	 */
	std::string roleName;
	/**
	 * 玩家获得票数
	 */
	int voteCount;
	/**
	 * 玩家id
	 */
	long roleId;
    
public:
    
    VoteInfo(void){
    }
    
    ~VoteInfo(void){
        const char *armyGroupNameChar = armyGroupName.c_str();
        CC_SAFE_DELETE_ARRAY(armyGroupNameChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
	}
    
	/**
	 * 玩家军团名称
	 */
	std::string getArmyGroupName() {
		return this->armyGroupName;
	}
	/**
	 * 玩家军团名称
	 */
	void setArmyGroupName(std::string armyGroupName){
		this->armyGroupName = armyGroupName;
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
	 * 玩家名称
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 玩家名称
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 玩家获得票数
	 */
	int getVoteCount() {
		return this->voteCount;
	}
	/**
	 * 玩家获得票数
	 */
	void setVoteCount(int voteCount){
		this->voteCount = voteCount;
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
