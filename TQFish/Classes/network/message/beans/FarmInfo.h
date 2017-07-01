//
//  FarmInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_FarmInfo_h
#define Lstx_cocos2dX_FarmInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class FarmInfo : public CCObject{

private:

	/**
	 * 剩余次数
	 */
	int remainTimes;
	/**
	 * 农场id
	 */
	int farmId;
	/**
	 * 最大次数
	 */
	int maxTimes;
    
public:
    
    FarmInfo(void){
    }
    
    ~FarmInfo(void){
	}
    
	/**
	 * 剩余次数
	 */
	int getRemainTimes() {
		return this->remainTimes;
	}
	/**
	 * 剩余次数
	 */
	void setRemainTimes(int remainTimes){
		this->remainTimes = remainTimes;
	}
	/**
	 * 农场id
	 */
	int getFarmId() {
		return this->farmId;
	}
	/**
	 * 农场id
	 */
	void setFarmId(int farmId){
		this->farmId = farmId;
	}
	/**
	 * 最大次数
	 */
	int getMaxTimes() {
		return this->maxTimes;
	}
	/**
	 * 最大次数
	 */
	void setMaxTimes(int maxTimes){
		this->maxTimes = maxTimes;
	}

};

#endif
