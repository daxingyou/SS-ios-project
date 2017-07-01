//
//  FoodStuffTeamInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_FoodStuffTeamInfo_h
#define Lstx_cocos2dX_FoodStuffTeamInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class FoodStuffTeamInfo : public CCObject{

private:

	/**
	 * 组队人数最大限制
	 */
	int memMax;
	/**
	 * 当前队伍中人数
	 */
	int memSize;
	/**
	 * 创建者ID
	 */
	long leaderId;
	/**
	 * 组队ID
	 */
	long teamId;
	/**
	 * 战斗ID
	 */
	long fightId;
	/**
	 * 国家限制
	 */
	int country;
	/**
	 * 创建者角色名
	 */
	std::string leaderName;
    
public:
    
    FoodStuffTeamInfo(void){
    }
    
    ~FoodStuffTeamInfo(void){
        const char *leaderNameChar = leaderName.c_str();
        CC_SAFE_DELETE_ARRAY(leaderNameChar);
	}
    
	/**
	 * 组队人数最大限制
	 */
	int getMemMax() {
		return this->memMax;
	}
	/**
	 * 组队人数最大限制
	 */
	void setMemMax(int memMax){
		this->memMax = memMax;
	}
	/**
	 * 当前队伍中人数
	 */
	int getMemSize() {
		return this->memSize;
	}
	/**
	 * 当前队伍中人数
	 */
	void setMemSize(int memSize){
		this->memSize = memSize;
	}
	/**
	 * 创建者ID
	 */
	long getLeaderId() {
		return this->leaderId;
	}
	/**
	 * 创建者ID
	 */
	void setLeaderId(long leaderId){
		this->leaderId = leaderId;
	}
	/**
	 * 组队ID
	 */
	long getTeamId() {
		return this->teamId;
	}
	/**
	 * 组队ID
	 */
	void setTeamId(long teamId){
		this->teamId = teamId;
	}
	/**
	 * 战斗ID
	 */
	long getFightId() {
		return this->fightId;
	}
	/**
	 * 战斗ID
	 */
	void setFightId(long fightId){
		this->fightId = fightId;
	}
	/**
	 * 国家限制
	 */
	int getCountry() {
		return this->country;
	}
	/**
	 * 国家限制
	 */
	void setCountry(int country){
		this->country = country;
	}
	/**
	 * 创建者角色名
	 */
	std::string getLeaderName() {
		return this->leaderName;
	}
	/**
	 * 创建者角色名
	 */
	void setLeaderName(std::string leaderName){
		this->leaderName = leaderName;
	}

};

#endif
