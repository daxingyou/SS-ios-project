//
//  PlayerInfoList.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_PlayerInfoList_h
#define Lstx_cocos2dX_PlayerInfoList_h

#include "cocos2d.h"
using namespace cocos2d;


class PlayerInfoList : public CCObject{

private:

	/**
	 * 位置
	 */
	int position;
	/**
	 * 玩家名称
	 */
	std::string playerName;
	/**
	 * 下注普通鲜花数量
	 */
	int wagerCommonFlower;
	/**
	 * 下注胜利鲜花数量
	 */
	int wagerVictoryFlower;
	/**
	 * 服务器名称
	 */
	std::string serverName;
	/**
	 * 玩家id
	 */
	long playerIdx;
    
public:
    
    PlayerInfoList(void){
    }
    
    ~PlayerInfoList(void){
        const char *playerNameChar = playerName.c_str();
        CC_SAFE_DELETE_ARRAY(playerNameChar);
        const char *serverNameChar = serverName.c_str();
        CC_SAFE_DELETE_ARRAY(serverNameChar);
	}
    
	/**
	 * 位置
	 */
	int getPosition() {
		return this->position;
	}
	/**
	 * 位置
	 */
	void setPosition(int position){
		this->position = position;
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
	 * 下注普通鲜花数量
	 */
	int getWagerCommonFlower() {
		return this->wagerCommonFlower;
	}
	/**
	 * 下注普通鲜花数量
	 */
	void setWagerCommonFlower(int wagerCommonFlower){
		this->wagerCommonFlower = wagerCommonFlower;
	}
	/**
	 * 下注胜利鲜花数量
	 */
	int getWagerVictoryFlower() {
		return this->wagerVictoryFlower;
	}
	/**
	 * 下注胜利鲜花数量
	 */
	void setWagerVictoryFlower(int wagerVictoryFlower){
		this->wagerVictoryFlower = wagerVictoryFlower;
	}
	/**
	 * 服务器名称
	 */
	std::string getServerName() {
		return this->serverName;
	}
	/**
	 * 服务器名称
	 */
	void setServerName(std::string serverName){
		this->serverName = serverName;
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
