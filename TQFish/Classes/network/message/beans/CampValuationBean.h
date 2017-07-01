//
//  CampValuationBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampValuationBean_h
#define Lstx_cocos2dX_CampValuationBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampValuationBean : public CCObject{

private:

	/**
	 * 评价时间段标准(毫秒)
	 */
	long valTime;
	/**
	 * 评价描述
	 */
	std::string valDescription;
    
public:
    
    CampValuationBean(void){
    }
    
    ~CampValuationBean(void){
        const char *valDescriptionChar = valDescription.c_str();
        CC_SAFE_DELETE_ARRAY(valDescriptionChar);
	}
    
	/**
	 * 评价时间段标准(毫秒)
	 */
	long getValTime() {
		return this->valTime;
	}
	/**
	 * 评价时间段标准(毫秒)
	 */
	void setValTime(long valTime){
		this->valTime = valTime;
	}
	/**
	 * 评价描述
	 */
	std::string getValDescription() {
		return this->valDescription;
	}
	/**
	 * 评价描述
	 */
	void setValDescription(std::string valDescription){
		this->valDescription = valDescription;
	}

};

#endif
