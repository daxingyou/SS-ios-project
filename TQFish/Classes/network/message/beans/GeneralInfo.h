//
//  GeneralInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GeneralInfo_h
#define Lstx_cocos2dX_GeneralInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class GeneralInfo : public CCObject{

private:

	/**
	 * 当前兵力
	 */
	int soldierCount;
	/**
	 * 勇
	 */
	int valiant;
	/**
	 * 部队等级
	 */
	int armyLv;
	/**
	 * 武将排行
	 */
	int generalOrder;
	/**
	 * 玩家等级
	 */
	int roleLevel;
	/**
	 * 武将等级
	 */
	long generalLevel;
	/**
	 * 玩家名字
	 */
	std::string roleName;
	/**
	 * 武将Id
	 */
	long generalId;
	/**
	 * 武将等级
	 */
	int level;
	/**
	 * 玩家国家
	 */
	int roleNation;
	/**
	 * 武将属性
	 */
	int generalAttribute;
	/**
	 * 武将实体id
	 */
	long generalEntityId;
	/**
	 * 统
	 */
	int command;
	/**
	 * 最大兵力
	 */
	int soldierMax;
	/**
	 * 智
	 */
	int Int;
	/**
	 * 玩家id
	 */
	long roleId;
    
public:
    
    GeneralInfo(void){
    }
    
    ~GeneralInfo(void){
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
	}
    
	/**
	 * 当前兵力
	 */
	int getSoldierCount() {
		return this->soldierCount;
	}
	/**
	 * 当前兵力
	 */
	void setSoldierCount(int soldierCount){
		this->soldierCount = soldierCount;
	}
	/**
	 * 勇
	 */
	int getValiant() {
		return this->valiant;
	}
	/**
	 * 勇
	 */
	void setValiant(int valiant){
		this->valiant = valiant;
	}
	/**
	 * 部队等级
	 */
	int getArmyLv() {
		return this->armyLv;
	}
	/**
	 * 部队等级
	 */
	void setArmyLv(int armyLv){
		this->armyLv = armyLv;
	}
	/**
	 * 武将排行
	 */
	int getGeneralOrder() {
		return this->generalOrder;
	}
	/**
	 * 武将排行
	 */
	void setGeneralOrder(int generalOrder){
		this->generalOrder = generalOrder;
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
	 * 武将等级
	 */
	long getGeneralLevel() {
		return this->generalLevel;
	}
	/**
	 * 武将等级
	 */
	void setGeneralLevel(long generalLevel){
		this->generalLevel = generalLevel;
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
	 * 武将Id
	 */
	long getGeneralId() {
		return this->generalId;
	}
	/**
	 * 武将Id
	 */
	void setGeneralId(long generalId){
		this->generalId = generalId;
	}
	/**
	 * 武将等级
	 */
	int getLevel() {
		return this->level;
	}
	/**
	 * 武将等级
	 */
	void setLevel(int level){
		this->level = level;
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
	 * 武将属性
	 */
	int getGeneralAttribute() {
		return this->generalAttribute;
	}
	/**
	 * 武将属性
	 */
	void setGeneralAttribute(int generalAttribute){
		this->generalAttribute = generalAttribute;
	}
	/**
	 * 武将实体id
	 */
	long getGeneralEntityId() {
		return this->generalEntityId;
	}
	/**
	 * 武将实体id
	 */
	void setGeneralEntityId(long generalEntityId){
		this->generalEntityId = generalEntityId;
	}
	/**
	 * 统
	 */
	int getCommand() {
		return this->command;
	}
	/**
	 * 统
	 */
	void setCommand(int command){
		this->command = command;
	}
	/**
	 * 最大兵力
	 */
	int getSoldierMax() {
		return this->soldierMax;
	}
	/**
	 * 最大兵力
	 */
	void setSoldierMax(int soldierMax){
		this->soldierMax = soldierMax;
	}
	/**
	 * 智
	 */
	int getInt() {
		return this->Int;
	}
	/**
	 * 智
	 */
	void setInt(int Int){
		this->Int = Int;
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
