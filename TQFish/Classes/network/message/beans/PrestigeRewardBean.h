//
//  PrestigeRewardBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_PrestigeRewardBean_h
#define Lstx_cocos2dX_PrestigeRewardBean_h

#include "cocos2d.h"
using namespace cocos2d;


class PrestigeRewardBean : public CCObject{

private:

	/**
	 * 是否已获得
	 */
	int isOwned;
	/**
	 * 奖励武将id
	 */
	int generalId;
	/**
	 * 官职id
	 */
	int officialId;
    
public:
    
    PrestigeRewardBean(void){
    }
    
    ~PrestigeRewardBean(void){
	}
    
	/**
	 * 是否已获得
	 */
	int getIsOwned() {
		return this->isOwned;
	}
	/**
	 * 是否已获得
	 */
	void setIsOwned(int isOwned){
		this->isOwned = isOwned;
	}
	/**
	 * 奖励武将id
	 */
	int getGeneralId() {
		return this->generalId;
	}
	/**
	 * 奖励武将id
	 */
	void setGeneralId(int generalId){
		this->generalId = generalId;
	}
	/**
	 * 官职id
	 */
	int getOfficialId() {
		return this->officialId;
	}
	/**
	 * 官职id
	 */
	void setOfficialId(int officialId){
		this->officialId = officialId;
	}

};

#endif
