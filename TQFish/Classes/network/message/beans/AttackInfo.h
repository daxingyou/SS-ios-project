//
//  AttackInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_AttackInfo_h
#define Lstx_cocos2dX_AttackInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class AttackInfo : public CCObject{

private:

	/**
	 * 开始城市id
	 */
	int startCity;
	/**
	 * 结束城市id
	 */
	int endCity;
	/**
	 * 国家
	 */
	int nation;
    
public:
    
    AttackInfo(void){
    }
    
    ~AttackInfo(void){
	}
    
	/**
	 * 开始城市id
	 */
	int getStartCity() {
		return this->startCity;
	}
	/**
	 * 开始城市id
	 */
	void setStartCity(int startCity){
		this->startCity = startCity;
	}
	/**
	 * 结束城市id
	 */
	int getEndCity() {
		return this->endCity;
	}
	/**
	 * 结束城市id
	 */
	void setEndCity(int endCity){
		this->endCity = endCity;
	}
	/**
	 * 国家
	 */
	int getNation() {
		return this->nation;
	}
	/**
	 * 国家
	 */
	void setNation(int nation){
		this->nation = nation;
	}

};

#endif
