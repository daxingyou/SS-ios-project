//
//  TeamInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_TeamInfo_h
#define Lstx_cocos2dX_TeamInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class TeamInfo : public CCObject{

private:

	/**
	 * 队伍人员等级限制
	 */
	int minPlayerLevel;
	/**
	 * 队伍国家限制
	 */
	std::string countryName;
	/**
	 * 队伍创建者名称
	 */
	std::string playerName;
	/**
	 * 队伍人员数量
	 */
	int playerCount;
	/**
	 * 队伍ID
	 */
	long teamId;
	/**
	 * 战斗ID
	 */
	long fightId;
    
public:
    
    TeamInfo(void){
    }
    
    ~TeamInfo(void){
        const char *countryNameChar = countryName.c_str();
        CC_SAFE_DELETE_ARRAY(countryNameChar);
        const char *playerNameChar = playerName.c_str();
        CC_SAFE_DELETE_ARRAY(playerNameChar);
	}
    
	/**
	 * 队伍人员等级限制
	 */
	int getMinPlayerLevel() {
		return this->minPlayerLevel;
	}
	/**
	 * 队伍人员等级限制
	 */
	void setMinPlayerLevel(int minPlayerLevel){
		this->minPlayerLevel = minPlayerLevel;
	}
	/**
	 * 队伍国家限制
	 */
	std::string getCountryName() {
		return this->countryName;
	}
	/**
	 * 队伍国家限制
	 */
	void setCountryName(std::string countryName){
		this->countryName = countryName;
	}
	/**
	 * 队伍创建者名称
	 */
	std::string getPlayerName() {
		return this->playerName;
	}
	/**
	 * 队伍创建者名称
	 */
	void setPlayerName(std::string playerName){
		this->playerName = playerName;
	}
	/**
	 * 队伍人员数量
	 */
	int getPlayerCount() {
		return this->playerCount;
	}
	/**
	 * 队伍人员数量
	 */
	void setPlayerCount(int playerCount){
		this->playerCount = playerCount;
	}
	/**
	 * 队伍ID
	 */
	long getTeamId() {
		return this->teamId;
	}
	/**
	 * 队伍ID
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

};

#endif
