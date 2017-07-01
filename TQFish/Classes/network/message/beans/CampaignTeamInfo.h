//
//  CampaignTeamInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampaignTeamInfo_h
#define Lstx_cocos2dX_CampaignTeamInfo_h

#include "cocos2d.h"
#include "BaseMessage.h"

using namespace cocos2d;


class CampaignTeamInfo : public CCObject{

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
	 * 战役难度
	 */
	byteT difficuty;
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
	 * 挑战模式
	 */
	byteT mode;
	/**
	 * 创建者角色名
	 */
	std::string leaderName;
    
public:
    
    CampaignTeamInfo(void){
    }
    
    ~CampaignTeamInfo(void){
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
	 * 战役难度
	 */
	byteT getDifficuty() {
		return this->difficuty;
	}
	/**
	 * 战役难度
	 */
	void setDifficuty(byteT difficuty){
		this->difficuty = difficuty;
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
	 * 挑战模式
	 */
	byteT getMode() {
		return this->mode;
	}
	/**
	 * 挑战模式
	 */
	void setMode(byteT mode){
		this->mode = mode;
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
