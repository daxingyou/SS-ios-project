//
//  GoldMineEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GoldMineEntity_h
#define Lstx_cocos2dX_GoldMineEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class GoldMineEntity : public CCObject{

private:

	/**
	 * 是否领取过金币 0-未领 1-已领
	 */
	int gotGold;
	/**
	 * 被炸次数
	 */
	int bombCount;
	/**
	 * 金矿Id
	 */
	int goldMineId;
    
public:
    
    GoldMineEntity(void){
    }
    
    ~GoldMineEntity(void){
	}
    
	/**
	 * 是否领取过金币 0-未领 1-已领
	 */
	int getGotGold() {
		return this->gotGold;
	}
	/**
	 * 是否领取过金币 0-未领 1-已领
	 */
	void setGotGold(int gotGold){
		this->gotGold = gotGold;
	}
	/**
	 * 被炸次数
	 */
	int getBombCount() {
		return this->bombCount;
	}
	/**
	 * 被炸次数
	 */
	void setBombCount(int bombCount){
		this->bombCount = bombCount;
	}
	/**
	 * 金矿Id
	 */
	int getGoldMineId() {
		return this->goldMineId;
	}
	/**
	 * 金矿Id
	 */
	void setGoldMineId(int goldMineId){
		this->goldMineId = goldMineId;
	}

};

#endif
