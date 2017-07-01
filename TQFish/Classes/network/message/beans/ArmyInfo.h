//
//  ArmyInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ArmyInfo_h
#define Lstx_cocos2dX_ArmyInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class ArmyInfo : public CCObject{

private:

	/**
	 * 军团留言
	 */
	std::string message;
	/**
	 * 军团ID
	 */
	long armyId;
	/**
	 * 军团最大人数上限
	 */
	int memberMaxSize;
	/**
	 * 军团长昵称
	 */
	std::string generalName;
	/**
	 * 军团人数
	 */
	int armySize;
	/**
	 * 军团名称
	 */
	std::string armyName;
	/**
	 * 军团等级
	 */
	int armyLevel;
	/**
	 * 军徽名称
	 */
	std::string shortName;
	/**
	 * 军徽等级
	 */
	int shorNameLevel;
	/**
	 * 军团国家
	 */
	int country;
    
public:
    
    ArmyInfo(void){
    }
    
    ~ArmyInfo(void){
        const char *messageChar = message.c_str();
        CC_SAFE_DELETE_ARRAY(messageChar);
        const char *generalNameChar = generalName.c_str();
        CC_SAFE_DELETE_ARRAY(generalNameChar);
        const char *armyNameChar = armyName.c_str();
        CC_SAFE_DELETE_ARRAY(armyNameChar);
        const char *shortNameChar = shortName.c_str();
        CC_SAFE_DELETE_ARRAY(shortNameChar);
	}
    
	/**
	 * 军团留言
	 */
	std::string getMessage() {
		return this->message;
	}
	/**
	 * 军团留言
	 */
	void setMessage(std::string message){
		this->message = message;
	}
	/**
	 * 军团ID
	 */
	long getArmyId() {
		return this->armyId;
	}
	/**
	 * 军团ID
	 */
	void setArmyId(long armyId){
		this->armyId = armyId;
	}
	/**
	 * 军团最大人数上限
	 */
	int getMemberMaxSize() {
		return this->memberMaxSize;
	}
	/**
	 * 军团最大人数上限
	 */
	void setMemberMaxSize(int memberMaxSize){
		this->memberMaxSize = memberMaxSize;
	}
	/**
	 * 军团长昵称
	 */
	std::string getGeneralName() {
		return this->generalName;
	}
	/**
	 * 军团长昵称
	 */
	void setGeneralName(std::string generalName){
		this->generalName = generalName;
	}
	/**
	 * 军团人数
	 */
	int getArmySize() {
		return this->armySize;
	}
	/**
	 * 军团人数
	 */
	void setArmySize(int armySize){
		this->armySize = armySize;
	}
	/**
	 * 军团名称
	 */
	std::string getArmyName() {
		return this->armyName;
	}
	/**
	 * 军团名称
	 */
	void setArmyName(std::string armyName){
		this->armyName = armyName;
	}
	/**
	 * 军团等级
	 */
	int getArmyLevel() {
		return this->armyLevel;
	}
	/**
	 * 军团等级
	 */
	void setArmyLevel(int armyLevel){
		this->armyLevel = armyLevel;
	}
	/**
	 * 军徽名称
	 */
	std::string getShortName() {
		return this->shortName;
	}
	/**
	 * 军徽名称
	 */
	void setShortName(std::string shortName){
		this->shortName = shortName;
	}
	/**
	 * 军徽等级
	 */
	int getShorNameLevel() {
		return this->shorNameLevel;
	}
	/**
	 * 军徽等级
	 */
	void setShorNameLevel(int shorNameLevel){
		this->shorNameLevel = shorNameLevel;
	}
	/**
	 * 军团国家
	 */
	int getCountry() {
		return this->country;
	}
	/**
	 * 军团国家
	 */
	void setCountry(int country){
		this->country = country;
	}

};

#endif
