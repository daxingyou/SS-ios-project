//
//  InvestInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_InvestInfo_h
#define Lstx_cocos2dX_InvestInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class InvestInfo : public CCObject{

private:

	/**
	 * 投资ID
	 */
	int investId;
	/**
	 * 花费银币
	 */
	int cost;
	/**
	 * 繁荣度
	 */
	int flourish;
    
public:
    
    InvestInfo(void){
    }
    
    ~InvestInfo(void){
	}
    
	/**
	 * 投资ID
	 */
	int getInvestId() {
		return this->investId;
	}
	/**
	 * 投资ID
	 */
	void setInvestId(int investId){
		this->investId = investId;
	}
	/**
	 * 花费银币
	 */
	int getCost() {
		return this->cost;
	}
	/**
	 * 花费银币
	 */
	void setCost(int cost){
		this->cost = cost;
	}
	/**
	 * 繁荣度
	 */
	int getFlourish() {
		return this->flourish;
	}
	/**
	 * 繁荣度
	 */
	void setFlourish(int flourish){
		this->flourish = flourish;
	}

};

#endif
