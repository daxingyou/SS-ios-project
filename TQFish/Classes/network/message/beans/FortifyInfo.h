//
//  FortifyInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_FortifyInfo_h
#define Lstx_cocos2dX_FortifyInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class FortifyInfo : public CCObject{

private:

	/**
	 * 城防
	 */
	int defense;
	/**
	 * 筑城ID
	 */
	int fortifyId;
	/**
	 * 花费银币
	 */
	int cost;
    
public:
    
    FortifyInfo(void){
    }
    
    ~FortifyInfo(void){
	}
    
	/**
	 * 城防
	 */
	int getDefense() {
		return this->defense;
	}
	/**
	 * 城防
	 */
	void setDefense(int defense){
		this->defense = defense;
	}
	/**
	 * 筑城ID
	 */
	int getFortifyId() {
		return this->fortifyId;
	}
	/**
	 * 筑城ID
	 */
	void setFortifyId(int fortifyId){
		this->fortifyId = fortifyId;
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

};

#endif
