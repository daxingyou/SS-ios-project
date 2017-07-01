//
//  MatchPlayerListInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MatchPlayerListInfo_h
#define Lstx_cocos2dX_MatchPlayerListInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class MatchPlayerListInfo : public CCObject{

private:

	/**
	 * 玩家等级
	 */
	int playerLevel;
	/**
	 * 玩家发展度
	 */
	long playerContribute;
	/**
	 * 胜利之花个数
	 */
	int goldFlower;
	/**
	 * 玩家名称
	 */
	std::string playerName;
	/**
	 * 玩家先攻值
	 */
	int playerFightPriority;
	/**
	 * 玩家头像Url
	 */
	std::string playerHeadIconUrl;
	/**
	 * 玩家id
	 */
	long playerIdx;
    
public:
    
    MatchPlayerListInfo(void){
    }
    
    ~MatchPlayerListInfo(void){
        const char *playerNameChar = playerName.c_str();
        CC_SAFE_DELETE_ARRAY(playerNameChar);
        const char *playerHeadIconUrlChar = playerHeadIconUrl.c_str();
        CC_SAFE_DELETE_ARRAY(playerHeadIconUrlChar);
	}
    
	/**
	 * 玩家等级
	 */
	int getPlayerLevel() {
		return this->playerLevel;
	}
	/**
	 * 玩家等级
	 */
	void setPlayerLevel(int playerLevel){
		this->playerLevel = playerLevel;
	}
	/**
	 * 玩家发展度
	 */
	long getPlayerContribute() {
		return this->playerContribute;
	}
	/**
	 * 玩家发展度
	 */
	void setPlayerContribute(long playerContribute){
		this->playerContribute = playerContribute;
	}
	/**
	 * 胜利之花个数
	 */
	int getGoldFlower() {
		return this->goldFlower;
	}
	/**
	 * 胜利之花个数
	 */
	void setGoldFlower(int goldFlower){
		this->goldFlower = goldFlower;
	}
	/**
	 * 玩家名称
	 */
	std::string getPlayerName() {
		return this->playerName;
	}
	/**
	 * 玩家名称
	 */
	void setPlayerName(std::string playerName){
		this->playerName = playerName;
	}
	/**
	 * 玩家先攻值
	 */
	int getPlayerFightPriority() {
		return this->playerFightPriority;
	}
	/**
	 * 玩家先攻值
	 */
	void setPlayerFightPriority(int playerFightPriority){
		this->playerFightPriority = playerFightPriority;
	}
	/**
	 * 玩家头像Url
	 */
	std::string getPlayerHeadIconUrl() {
		return this->playerHeadIconUrl;
	}
	/**
	 * 玩家头像Url
	 */
	void setPlayerHeadIconUrl(std::string playerHeadIconUrl){
		this->playerHeadIconUrl = playerHeadIconUrl;
	}
	/**
	 * 玩家id
	 */
	long getPlayerIdx() {
		return this->playerIdx;
	}
	/**
	 * 玩家id
	 */
	void setPlayerIdx(long playerIdx){
		this->playerIdx = playerIdx;
	}

};

#endif
