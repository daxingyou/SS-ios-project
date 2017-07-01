//
//  HufuInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_HufuInfo_h
#define Lstx_cocos2dX_HufuInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class HufuInfo : public CCObject{

private:

	/**
	 * 虎符道具Id
	 */
	long itemId;
	/**
	 * 虎符的buffId
	 */
	long buffId;
    
public:
    
    HufuInfo(void){
    }
    
    ~HufuInfo(void){
	}
    
	/**
	 * 虎符道具Id
	 */
	long getItemId() {
		return this->itemId;
	}
	/**
	 * 虎符道具Id
	 */
	void setItemId(long itemId){
		this->itemId = itemId;
	}
	/**
	 * 虎符的buffId
	 */
	long getBuffId() {
		return this->buffId;
	}
	/**
	 * 虎符的buffId
	 */
	void setBuffId(long buffId){
		this->buffId = buffId;
	}

};

#endif
