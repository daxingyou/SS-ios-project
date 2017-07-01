//
//  EscortTargetRewardBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EscortTargetRewardBean_h
#define Lstx_cocos2dX_EscortTargetRewardBean_h

#include "cocos2d.h"
using namespace cocos2d;


class EscortTargetRewardBean : public CCObject{

private:

	/**
	 * 运镖目标描述
	 */
	std::string escortTargetDes;
	/**
	 * 运镖目标奖励数量
	 */
	int escortTargetRewardCount;
	/**
	 * 运镖目标奖励道具id
	 */
	int escortTargetRewardItemId;
	/**
	 * 运镖目标奖励类型 1:军工 2:威望 3:银币 4:道具 6:贡品
	 */
	int escortTargetRewardType;
    
public:
    
    EscortTargetRewardBean(void){
    }
    
    ~EscortTargetRewardBean(void){
        const char *escortTargetDesChar = escortTargetDes.c_str();
        CC_SAFE_DELETE_ARRAY(escortTargetDesChar);
	}
    
	/**
	 * 运镖目标描述
	 */
	std::string getEscortTargetDes() {
		return this->escortTargetDes;
	}
	/**
	 * 运镖目标描述
	 */
	void setEscortTargetDes(std::string escortTargetDes){
		this->escortTargetDes = escortTargetDes;
	}
	/**
	 * 运镖目标奖励数量
	 */
	int getEscortTargetRewardCount() {
		return this->escortTargetRewardCount;
	}
	/**
	 * 运镖目标奖励数量
	 */
	void setEscortTargetRewardCount(int escortTargetRewardCount){
		this->escortTargetRewardCount = escortTargetRewardCount;
	}
	/**
	 * 运镖目标奖励道具id
	 */
	int getEscortTargetRewardItemId() {
		return this->escortTargetRewardItemId;
	}
	/**
	 * 运镖目标奖励道具id
	 */
	void setEscortTargetRewardItemId(int escortTargetRewardItemId){
		this->escortTargetRewardItemId = escortTargetRewardItemId;
	}
	/**
	 * 运镖目标奖励类型 1:军工 2:威望 3:银币 4:道具 6:贡品
	 */
	int getEscortTargetRewardType() {
		return this->escortTargetRewardType;
	}
	/**
	 * 运镖目标奖励类型 1:军工 2:威望 3:银币 4:道具 6:贡品
	 */
	void setEscortTargetRewardType(int escortTargetRewardType){
		this->escortTargetRewardType = escortTargetRewardType;
	}

};

#endif
