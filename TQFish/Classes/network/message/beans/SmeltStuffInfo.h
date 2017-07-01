//
//  SmeltStuffInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_SmeltStuffInfo_h
#define Lstx_cocos2dX_SmeltStuffInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class SmeltStuffInfo : public CCObject{

private:

	/**
	 * 合成物品Index
	 */
	int stuffId;
	/**
	 * 合成物品现拥有数量
	 */
	int stuffNum;
    
public:
    
    SmeltStuffInfo(void){
    }
    
    ~SmeltStuffInfo(void){
	}
    
	/**
	 * 合成物品Index
	 */
	int getStuffId() {
		return this->stuffId;
	}
	/**
	 * 合成物品Index
	 */
	void setStuffId(int stuffId){
		this->stuffId = stuffId;
	}
	/**
	 * 合成物品现拥有数量
	 */
	int getStuffNum() {
		return this->stuffNum;
	}
	/**
	 * 合成物品现拥有数量
	 */
	void setStuffNum(int stuffNum){
		this->stuffNum = stuffNum;
	}

};

#endif
