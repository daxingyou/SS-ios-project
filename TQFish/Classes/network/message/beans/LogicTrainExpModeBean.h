//
//  LogicTrainExpModeBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_LogicTrainExpModeBean_h
#define Lstx_cocos2dX_LogicTrainExpModeBean_h

#include "cocos2d.h"
using namespace cocos2d;


class LogicTrainExpModeBean : public CCObject{

private:

	/**
	 * 消耗货币数量
	 */
	int count;
	/**
	 * 经验模式Id
	 */
	int expModeId;
    
public:
    
    LogicTrainExpModeBean(void){
    }
    
    ~LogicTrainExpModeBean(void){
	}
    
	/**
	 * 消耗货币数量
	 */
	int getCount() {
		return this->count;
	}
	/**
	 * 消耗货币数量
	 */
	void setCount(int count){
		this->count = count;
	}
	/**
	 * 经验模式Id
	 */
	int getExpModeId() {
		return this->expModeId;
	}
	/**
	 * 经验模式Id
	 */
	void setExpModeId(int expModeId){
		this->expModeId = expModeId;
	}

};

#endif
