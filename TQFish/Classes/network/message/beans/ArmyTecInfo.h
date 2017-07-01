//
//  ArmyTecInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ArmyTecInfo_h
#define Lstx_cocos2dX_ArmyTecInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class ArmyTecInfo : public CCObject{

private:

	/**
	 * 当前科技升级最大值
	 */
	long techMaxValue;
	/**
	 * 军团科技类型
	 */
	int techType;
	/**
	 * 军团等级
	 */
	int armyLv;
	/**
	 * 军团科技等级
	 */
	int techLevel;
	/**
	 * 军团团长等级
	 */
	int generalLevel;
	/**
	 * 军团团长ID
	 */
	long generalId;
	/**
	 * 军团ID
	 */
	long amryId;
	/**
	 * 当前科技捐献值
	 */
	long techValue;
    
public:
    
    ArmyTecInfo(void){
    }
    
    ~ArmyTecInfo(void){
	}
    
	/**
	 * 当前科技升级最大值
	 */
	long getTechMaxValue() {
		return this->techMaxValue;
	}
	/**
	 * 当前科技升级最大值
	 */
	void setTechMaxValue(long techMaxValue){
		this->techMaxValue = techMaxValue;
	}
	/**
	 * 军团科技类型
	 */
	int getTechType() {
		return this->techType;
	}
	/**
	 * 军团科技类型
	 */
	void setTechType(int techType){
		this->techType = techType;
	}
	/**
	 * 军团等级
	 */
	int getArmyLv() {
		return this->armyLv;
	}
	/**
	 * 军团等级
	 */
	void setArmyLv(int armyLv){
		this->armyLv = armyLv;
	}
	/**
	 * 军团科技等级
	 */
	int getTechLevel() {
		return this->techLevel;
	}
	/**
	 * 军团科技等级
	 */
	void setTechLevel(int techLevel){
		this->techLevel = techLevel;
	}
	/**
	 * 军团团长等级
	 */
	int getGeneralLevel() {
		return this->generalLevel;
	}
	/**
	 * 军团团长等级
	 */
	void setGeneralLevel(int generalLevel){
		this->generalLevel = generalLevel;
	}
	/**
	 * 军团团长ID
	 */
	long getGeneralId() {
		return this->generalId;
	}
	/**
	 * 军团团长ID
	 */
	void setGeneralId(long generalId){
		this->generalId = generalId;
	}
	/**
	 * 军团ID
	 */
	long getAmryId() {
		return this->amryId;
	}
	/**
	 * 军团ID
	 */
	void setAmryId(long amryId){
		this->amryId = amryId;
	}
	/**
	 * 当前科技捐献值
	 */
	long getTechValue() {
		return this->techValue;
	}
	/**
	 * 当前科技捐献值
	 */
	void setTechValue(long techValue){
		this->techValue = techValue;
	}

};

#endif
