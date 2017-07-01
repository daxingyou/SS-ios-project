//
//  PowerElement.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_PowerElement_h
#define Lstx_cocos2dX_PowerElement_h

#include "cocos2d.h"
using namespace cocos2d;


class PowerElement : public CCObject{

private:

	/**
	 * 关卡对象剩余数量
	 */
	int count;
	/**
	 * 关卡对象id
	 */
	int currElementId;
	/**
	 * 关卡对象是否可攻击
	 */
	bool isAtt;
	/**
	 * 关卡对象是否可收服
	 */
	bool isJoin;
	/**
	 * 关卡对象状态
	 */
	bool stat;
	/**
	 * 关卡对象获得军功
	 */
	int exploit;
    
public:
    
    PowerElement(void){
    }
    
    ~PowerElement(void){
	}
    
	/**
	 * 关卡对象剩余数量
	 */
	int getCount() {
		return this->count;
	}
	/**
	 * 关卡对象剩余数量
	 */
	void setCount(int count){
		this->count = count;
	}
	/**
	 * 关卡对象id
	 */
	int getCurrElementId() {
		return this->currElementId;
	}
	/**
	 * 关卡对象id
	 */
	void setCurrElementId(int currElementId){
		this->currElementId = currElementId;
	}
	/**
	 * 关卡对象是否可攻击
	 */
	bool getIsAtt() {
		return this->isAtt;
	}
	/**
	 * 关卡对象是否可攻击
	 */
	void setIsAtt(bool isAtt){
		this->isAtt = isAtt;
	}
	/**
	 * 关卡对象是否可收服
	 */
	bool getIsJoin() {
		return this->isJoin;
	}
	/**
	 * 关卡对象是否可收服
	 */
	void setIsJoin(bool isJoin){
		this->isJoin = isJoin;
	}
	/**
	 * 关卡对象状态
	 */
	bool getStat() {
		return this->stat;
	}
	/**
	 * 关卡对象状态
	 */
	void setStat(bool stat){
		this->stat = stat;
	}
	/**
	 * 关卡对象获得军功
	 */
	int getExploit() {
		return this->exploit;
	}
	/**
	 * 关卡对象获得军功
	 */
	void setExploit(int exploit){
		this->exploit = exploit;
	}

};

#endif
