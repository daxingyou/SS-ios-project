//
//  PrestigeBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_PrestigeBean_h
#define Lstx_cocos2dX_PrestigeBean_h

#include "cocos2d.h"
using namespace cocos2d;


class PrestigeBean : public CCObject{

private:

	/**
	 * 下一级声望
	 */
	int nextPrestige;
	/**
	 * 当前声望
	 */
	int currPrestige;
	/**
	 * 金币消耗
	 */
	int gold;
	/**
	 * 贡品消耗
	 */
	int tribute;
	/**
	 * 国家
	 */
	int country;
    
public:
    
    PrestigeBean(void){
    }
    
    ~PrestigeBean(void){
	}
    
	/**
	 * 下一级声望
	 */
	int getNextPrestige() {
		return this->nextPrestige;
	}
	/**
	 * 下一级声望
	 */
	void setNextPrestige(int nextPrestige){
		this->nextPrestige = nextPrestige;
	}
	/**
	 * 当前声望
	 */
	int getCurrPrestige() {
		return this->currPrestige;
	}
	/**
	 * 当前声望
	 */
	void setCurrPrestige(int currPrestige){
		this->currPrestige = currPrestige;
	}
	/**
	 * 金币消耗
	 */
	int getGold() {
		return this->gold;
	}
	/**
	 * 金币消耗
	 */
	void setGold(int gold){
		this->gold = gold;
	}
	/**
	 * 贡品消耗
	 */
	int getTribute() {
		return this->tribute;
	}
	/**
	 * 贡品消耗
	 */
	void setTribute(int tribute){
		this->tribute = tribute;
	}
	/**
	 * 国家
	 */
	int getCountry() {
		return this->country;
	}
	/**
	 * 国家
	 */
	void setCountry(int country){
		this->country = country;
	}

};

#endif
