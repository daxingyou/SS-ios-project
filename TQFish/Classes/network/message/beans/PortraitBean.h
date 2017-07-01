//
//  PortraitBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_PortraitBean_h
#define Lstx_cocos2dX_PortraitBean_h

#include "cocos2d.h"
using namespace cocos2d;


class PortraitBean : public CCObject{

private:

	/**
	 * 是否正在使用中
	 */
	int isUsing;
	/**
	 * 玩家头像Id
	 */
	int imageId;
	/**
	 * 是否已购买
	 */
	int isown;
	/**
	 * 时限
	 */
	std::string timeLeft;
    
public:
    
    PortraitBean(void){
    }
    
    ~PortraitBean(void){
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
	 * 玩家头像Id
	 */
	int getImageId() {
		return this->imageId;
	}
	/**
	 * 玩家头像Id
	 */
	void setImageId(int imageId){
		this->imageId = imageId;
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
