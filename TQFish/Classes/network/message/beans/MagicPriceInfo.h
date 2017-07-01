//
//  MagicPriceInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MagicPriceInfo_h
#define Lstx_cocos2dX_MagicPriceInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class MagicPriceInfo : public CCObject{

private:

	/**
	 * 当前物价魔力值
	 */
	int magic;
	/**
	 * 趋势
	 */
	int trend;
	/**
	 * 城市ID
	 */
	int cityId;
    
public:
    
    MagicPriceInfo(void){
    }
    
    ~MagicPriceInfo(void){
	}
    
	/**
	 * 当前物价魔力值
	 */
	int getMagic() {
		return this->magic;
	}
	/**
	 * 当前物价魔力值
	 */
	void setMagic(int magic){
		this->magic = magic;
	}
	/**
	 * 趋势
	 */
	int getTrend() {
		return this->trend;
	}
	/**
	 * 趋势
	 */
	void setTrend(int trend){
		this->trend = trend;
	}
	/**
	 * 城市ID
	 */
	int getCityId() {
		return this->cityId;
	}
	/**
	 * 城市ID
	 */
	void setCityId(int cityId){
		this->cityId = cityId;
	}

};

#endif
