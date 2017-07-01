//
//  GeneralDetailInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GeneralDetailInfo_h
#define Lstx_cocos2dX_GeneralDetailInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class GeneralDetailInfo : public CCObject{

private:

	/**
	 * 部队等级
	 */
	int armyLv;
	/**
	 * 普通攻击
	 */
	int defAtt;
	/**
	 * 武将Id
	 */
	int generalId;
	/**
	 * 战法防御
	 */
	int skillDef;
	/**
	 * 战法攻击
	 */
	int skillAtt;
	/**
	 * 当前兵力
	 */
	int curArms;
	/**
	 * 统
	 */
	int T;
	/**
	 * 武将等级
	 */
	int generalLv;
	/**
	 * 勇
	 */
	int Y;
	/**
	 * 普通防御
	 */
	int defDef;
	/**
	 * 最大兵力
	 */
	int maxArms;
	/**
	 * 策士攻击
	 */
	int policyAtt;
	/**
	 * 策士防御
	 */
	int policyDef;
	/**
	 * 智
	 */
	int Z;
    
public:
    
    GeneralDetailInfo(void){
    }
    
    ~GeneralDetailInfo(void){
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
	 * 普通攻击
	 */
	int getDefAtt() {
		return this->defAtt;
	}
	/**
	 * 普通攻击
	 */
	void setDefAtt(int defAtt){
		this->defAtt = defAtt;
	}
	/**
	 * 武将Id
	 */
	int getGeneralId() {
		return this->generalId;
	}
	/**
	 * 武将Id
	 */
	void setGeneralId(int generalId){
		this->generalId = generalId;
	}
	/**
	 * 战法防御
	 */
	int getSkillDef() {
		return this->skillDef;
	}
	/**
	 * 战法防御
	 */
	void setSkillDef(int skillDef){
		this->skillDef = skillDef;
	}
	/**
	 * 战法攻击
	 */
	int getSkillAtt() {
		return this->skillAtt;
	}
	/**
	 * 战法攻击
	 */
	void setSkillAtt(int skillAtt){
		this->skillAtt = skillAtt;
	}
	/**
	 * 当前兵力
	 */
	int getCurArms() {
		return this->curArms;
	}
	/**
	 * 当前兵力
	 */
	void setCurArms(int curArms){
		this->curArms = curArms;
	}
	/**
	 * 统
	 */
	int getT() {
		return this->T;
	}
	/**
	 * 统
	 */
	void setT(int T){
		this->T = T;
	}
	/**
	 * 武将等级
	 */
	int getGeneralLv() {
		return this->generalLv;
	}
	/**
	 * 武将等级
	 */
	void setGeneralLv(int generalLv){
		this->generalLv = generalLv;
	}
	/**
	 * 勇
	 */
	int getY() {
		return this->Y;
	}
	/**
	 * 勇
	 */
	void setY(int Y){
		this->Y = Y;
	}
	/**
	 * 普通防御
	 */
	int getDefDef() {
		return this->defDef;
	}
	/**
	 * 普通防御
	 */
	void setDefDef(int defDef){
		this->defDef = defDef;
	}
	/**
	 * 最大兵力
	 */
	int getMaxArms() {
		return this->maxArms;
	}
	/**
	 * 最大兵力
	 */
	void setMaxArms(int maxArms){
		this->maxArms = maxArms;
	}
	/**
	 * 策士攻击
	 */
	int getPolicyAtt() {
		return this->policyAtt;
	}
	/**
	 * 策士攻击
	 */
	void setPolicyAtt(int policyAtt){
		this->policyAtt = policyAtt;
	}
	/**
	 * 策士防御
	 */
	int getPolicyDef() {
		return this->policyDef;
	}
	/**
	 * 策士防御
	 */
	void setPolicyDef(int policyDef){
		this->policyDef = policyDef;
	}
	/**
	 * 智
	 */
	int getZ() {
		return this->Z;
	}
	/**
	 * 智
	 */
	void setZ(int Z){
		this->Z = Z;
	}

};

#endif
