//
//  CampTargetRewardBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampTargetRewardBean_h
#define Lstx_cocos2dX_CampTargetRewardBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampTargetRewardBean : public CCObject{

private:

	/**
	 * 战役目标奖励数量
	 */
	int campTargetRewardCount;
	/**
	 * 战役目标奖励类型 1:军工 2:威望 3:银币 4:道具
	 */
	int campTargetRewardType;
	/**
	 * 战役目标描述
	 */
	std::string campTargetDes;
	/**
	 * 战役目标奖励道具id
	 */
	int campTargetRewardItemId;
    
public:
    
    CampTargetRewardBean(void){
    }
    
    ~CampTargetRewardBean(void){
        const char *campTargetDesChar = campTargetDes.c_str();
        CC_SAFE_DELETE_ARRAY(campTargetDesChar);
	}
    
	/**
	 * 战役目标奖励数量
	 */
	int getCampTargetRewardCount() {
		return this->campTargetRewardCount;
	}
	/**
	 * 战役目标奖励数量
	 */
	void setCampTargetRewardCount(int campTargetRewardCount){
		this->campTargetRewardCount = campTargetRewardCount;
	}
	/**
	 * 战役目标奖励类型 1:军工 2:威望 3:银币 4:道具
	 */
	int getCampTargetRewardType() {
		return this->campTargetRewardType;
	}
	/**
	 * 战役目标奖励类型 1:军工 2:威望 3:银币 4:道具
	 */
	void setCampTargetRewardType(int campTargetRewardType){
		this->campTargetRewardType = campTargetRewardType;
	}
	/**
	 * 战役目标描述
	 */
	std::string getCampTargetDes() {
		return this->campTargetDes;
	}
	/**
	 * 战役目标描述
	 */
	void setCampTargetDes(std::string campTargetDes){
		this->campTargetDes = campTargetDes;
	}
	/**
	 * 战役目标奖励道具id
	 */
	int getCampTargetRewardItemId() {
		return this->campTargetRewardItemId;
	}
	/**
	 * 战役目标奖励道具id
	 */
	void setCampTargetRewardItemId(int campTargetRewardItemId){
		this->campTargetRewardItemId = campTargetRewardItemId;
	}

};

#endif
