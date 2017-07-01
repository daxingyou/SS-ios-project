//
//  UnionFarmInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_UnionFarmInfo_h
#define Lstx_cocos2dX_UnionFarmInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class UnionFarmInfo : public CCObject{

private:

	/**
	 * 银币加成
	 */
	int silverbonus;
	/**
	 * 产量
	 */
	int yield;
	/**
	 * 农场ID
	 */
	int farmId;
	/**
	 * 加入状态 0:可以加入 ?0:不可加入，显示TIP
	 */
	int state;
	/**
	 * 类型 0:进攻 1:防守
	 */
	int type;
	/**
	 * 攻击方军团等级
	 */
	int attackerLv;
	/**
	 * 农场名字
	 */
	std::string farmName;
	/**
	 * 组队时间 y#s#hh:mm
	 */
	std::string time;
	/**
	 * 加入人数
	 */
	int roles;
	/**
	 * 所属
	 */
	std::string owner;
	/**
	 * 攻击方军团名字
	 */
	std::string attacker;
	/**
	 * 防守方军团等级
	 */
	int defLv;
	/**
	 * 防守方军团名字
	 */
	std::string defend;
	/**
	 * 加入人数上限
	 */
	int rolesMax;
    
public:
    
    UnionFarmInfo(void){
    }
    
    ~UnionFarmInfo(void){
        const char *farmNameChar = farmName.c_str();
        CC_SAFE_DELETE_ARRAY(farmNameChar);
        const char *timeChar = time.c_str();
        CC_SAFE_DELETE_ARRAY(timeChar);
        const char *ownerChar = owner.c_str();
        CC_SAFE_DELETE_ARRAY(ownerChar);
        const char *attackerChar = attacker.c_str();
        CC_SAFE_DELETE_ARRAY(attackerChar);
        const char *defendChar = defend.c_str();
        CC_SAFE_DELETE_ARRAY(defendChar);
	}
    
	/**
	 * 银币加成
	 */
	int getSilverbonus() {
		return this->silverbonus;
	}
	/**
	 * 银币加成
	 */
	void setSilverbonus(int silverbonus){
		this->silverbonus = silverbonus;
	}
	/**
	 * 产量
	 */
	int getYield() {
		return this->yield;
	}
	/**
	 * 产量
	 */
	void setYield(int yield){
		this->yield = yield;
	}
	/**
	 * 农场ID
	 */
	int getFarmId() {
		return this->farmId;
	}
	/**
	 * 农场ID
	 */
	void setFarmId(int farmId){
		this->farmId = farmId;
	}
	/**
	 * 加入状态 0:可以加入 ?0:不可加入，显示TIP
	 */
	int getState() {
		return this->state;
	}
	/**
	 * 加入状态 0:可以加入 ?0:不可加入，显示TIP
	 */
	void setState(int state){
		this->state = state;
	}
	/**
	 * 类型 0:进攻 1:防守
	 */
	int getType() {
		return this->type;
	}
	/**
	 * 类型 0:进攻 1:防守
	 */
	void setType(int type){
		this->type = type;
	}
	/**
	 * 攻击方军团等级
	 */
	int getAttackerLv() {
		return this->attackerLv;
	}
	/**
	 * 攻击方军团等级
	 */
	void setAttackerLv(int attackerLv){
		this->attackerLv = attackerLv;
	}
	/**
	 * 农场名字
	 */
	std::string getFarmName() {
		return this->farmName;
	}
	/**
	 * 农场名字
	 */
	void setFarmName(std::string farmName){
		this->farmName = farmName;
	}
	/**
	 * 组队时间 y#s#hh:mm
	 */
	std::string getTime() {
		return this->time;
	}
	/**
	 * 组队时间 y#s#hh:mm
	 */
	void setTime(std::string time){
		this->time = time;
	}
	/**
	 * 加入人数
	 */
	int getRoles() {
		return this->roles;
	}
	/**
	 * 加入人数
	 */
	void setRoles(int roles){
		this->roles = roles;
	}
	/**
	 * 所属
	 */
	std::string getOwner() {
		return this->owner;
	}
	/**
	 * 所属
	 */
	void setOwner(std::string owner){
		this->owner = owner;
	}
	/**
	 * 攻击方军团名字
	 */
	std::string getAttacker() {
		return this->attacker;
	}
	/**
	 * 攻击方军团名字
	 */
	void setAttacker(std::string attacker){
		this->attacker = attacker;
	}
	/**
	 * 防守方军团等级
	 */
	int getDefLv() {
		return this->defLv;
	}
	/**
	 * 防守方军团等级
	 */
	void setDefLv(int defLv){
		this->defLv = defLv;
	}
	/**
	 * 防守方军团名字
	 */
	std::string getDefend() {
		return this->defend;
	}
	/**
	 * 防守方军团名字
	 */
	void setDefend(std::string defend){
		this->defend = defend;
	}
	/**
	 * 加入人数上限
	 */
	int getRolesMax() {
		return this->rolesMax;
	}
	/**
	 * 加入人数上限
	 */
	void setRolesMax(int rolesMax){
		this->rolesMax = rolesMax;
	}

};

#endif
