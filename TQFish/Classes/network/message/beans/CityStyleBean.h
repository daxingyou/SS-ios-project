//
//  CityStyleBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CityStyleBean_h
#define Lstx_cocos2dX_CityStyleBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CityStyleBean : public CCObject{

private:

	/**
	 * 是否正在使用中
	 */
	int isUsing;
	/**
	 * 主城样式id
	 */
	int cityID;
	/**
	 * 是否已购买
	 */
	int isown;
	/**
	 * 时限
	 */
	std::string timeLeft;
    
public:
    
    CityStyleBean(void){
    }
    
    ~CityStyleBean(void){
        const char *timeLeftChar = timeLeft.c_str();
        CC_SAFE_DELETE_ARRAY(timeLeftChar);
	}
    
	/**
	 * 是否正在使用中
	 */
	int getUsing() {
		return this->isUsing;
	}
	/**
	 * 是否正在使用中
	 */
	void setUsing(int isUsing){
		this->isUsing = isUsing;
	}
	/**
	 * 主城样式id
	 */
	int getCityID() {
		return this->cityID;
	}
	/**
	 * 主城样式id
	 */
	void setCityID(int cityID){
		this->cityID = cityID;
	}
	/**
	 * 是否已购买
	 */
	int getIsown() {
		return this->isown;
	}
	/**
	 * 是否已购买
	 */
	void setIsown(int isown){
		this->isown = isown;
	}
	/**
	 * 时限
	 */
	std::string getTimeLeft() {
		return this->timeLeft;
	}
	/**
	 * 时限
	 */
	void setTimeLeft(std::string timeLeft){
		this->timeLeft = timeLeft;
	}

};

#endif
