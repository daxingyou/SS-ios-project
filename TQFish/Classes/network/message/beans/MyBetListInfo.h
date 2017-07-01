//
//  MyBetListInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MyBetListInfo_h
#define Lstx_cocos2dX_MyBetListInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class MyBetListInfo : public CCObject{

private:

	/**
	 * 胜利鲜花结果
	 */
	int resultBottom;
	/**
	 * 普通鲜花结果
	 */
	int resultFront;
	/**
	 * 下注普通鲜花数量
	 */
	int wagerCommonFlower;
	/**
	 * 下注胜利鲜花数量
	 */
	int wagerVictoryFlower;
	/**
	 * 获取花对象的roleId
	 */
	long targetId;
	/**
	 * 获取花对象的名字
	 */
	std::string someBody;
	/**
	 * 战斗状态0战斗中1押中2未押中
	 */
	int winStatus;
	/**
	 * 比赛名称
	 */
	int warName;
    
public:
    
    MyBetListInfo(void){
    }
    
    ~MyBetListInfo(void){
        const char *someBodyChar = someBody.c_str();
        CC_SAFE_DELETE_ARRAY(someBodyChar);
	}
    
	/**
	 * 胜利鲜花结果
	 */
	int getResultBottom() {
		return this->resultBottom;
	}
	/**
	 * 胜利鲜花结果
	 */
	void setResultBottom(int resultBottom){
		this->resultBottom = resultBottom;
	}
	/**
	 * 普通鲜花结果
	 */
	int getResultFront() {
		return this->resultFront;
	}
	/**
	 * 普通鲜花结果
	 */
	void setResultFront(int resultFront){
		this->resultFront = resultFront;
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
	 * 获取花对象的roleId
	 */
	long getTargetId() {
		return this->targetId;
	}
	/**
	 * 获取花对象的roleId
	 */
	void setTargetId(long targetId){
		this->targetId = targetId;
	}
	/**
	 * 获取花对象的名字
	 */
	std::string getSomeBody() {
		return this->someBody;
	}
	/**
	 * 获取花对象的名字
	 */
	void setSomeBody(std::string someBody){
		this->someBody = someBody;
	}
	/**
	 * 战斗状态0战斗中1押中2未押中
	 */
	int getWinStatus() {
		return this->winStatus;
	}
	/**
	 * 战斗状态0战斗中1押中2未押中
	 */
	void setWinStatus(int winStatus){
		this->winStatus = winStatus;
	}
	/**
	 * 比赛名称
	 */
	int getWarName() {
		return this->warName;
	}
	/**
	 * 比赛名称
	 */
	void setWarName(int warName){
		this->warName = warName;
	}

};

#endif
