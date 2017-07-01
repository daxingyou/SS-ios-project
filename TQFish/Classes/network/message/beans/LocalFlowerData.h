//
//  LocalFlowerData.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_LocalFlowerData_h
#define Lstx_cocos2dX_LocalFlowerData_h

#include "cocos2d.h"
using namespace cocos2d;


class LocalFlowerData : public CCObject{

private:

	/**
	 * 胜利之花个数
	 */
	long goldFlower;
	/**
	 * 普通鲜花个数
	 */
	long silverFlower;
	/**
	 * 轮数
	 */
	int round;
	/**
	 * 目标roleId
	 */
	long targetId;
    
public:
    
    LocalFlowerData(void){
    }
    
    ~LocalFlowerData(void){
	}
    
	/**
	 * 胜利之花个数
	 */
	long getGoldFlower() {
		return this->goldFlower;
	}
	/**
	 * 胜利之花个数
	 */
	void setGoldFlower(long goldFlower){
		this->goldFlower = goldFlower;
	}
	/**
	 * 普通鲜花个数
	 */
	long getSilverFlower() {
		return this->silverFlower;
	}
	/**
	 * 普通鲜花个数
	 */
	void setSilverFlower(long silverFlower){
		this->silverFlower = silverFlower;
	}
	/**
	 * 轮数
	 */
	int getRound() {
		return this->round;
	}
	/**
	 * 轮数
	 */
	void setRound(int round){
		this->round = round;
	}
	/**
	 * 目标roleId
	 */
	long getTargetId() {
		return this->targetId;
	}
	/**
	 * 目标roleId
	 */
	void setTargetId(long targetId){
		this->targetId = targetId;
	}

};

#endif
