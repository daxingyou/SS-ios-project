//
//  CityMessageInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CityMessageInfo_h
#define Lstx_cocos2dX_CityMessageInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class CityMessageInfo : public CCObject{

private:

	/**
	 * 留言
	 */
	std::string message;
	/**
	 * 城市ID
	 */
	int cityId;
    
public:
    
    CityMessageInfo(void){
    }
    
    ~CityMessageInfo(void){
        const char *messageChar = message.c_str();
        CC_SAFE_DELETE_ARRAY(messageChar);
	}
    
	/**
	 * 留言
	 */
	std::string getMessage() {
		return this->message;
	}
	/**
	 * 留言
	 */
	void setMessage(std::string message){
		this->message = message;
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
