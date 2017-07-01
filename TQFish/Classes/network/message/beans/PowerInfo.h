//
//  PowerInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_PowerInfo_h
#define Lstx_cocos2dX_PowerInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class PowerInfo : public CCObject{

private:

	/**
	 * 关卡id
	 */
	int powerId;
	/**
	 * 关卡是否开启
	 */
	bool stat;
    
public:
    
    PowerInfo(void){
    }
    
    ~PowerInfo(void){
	}
    
	/**
	 * 关卡id
	 */
	int getPowerId() {
		return this->powerId;
	}
	/**
	 * 关卡id
	 */
	void setPowerId(int powerId){
		this->powerId = powerId;
	}
	/**
	 * 关卡是否开启
	 */
	bool getStat() {
		return this->stat;
	}
	/**
	 * 关卡是否开启
	 */
	void setStat(bool stat){
		this->stat = stat;
	}

};

#endif
