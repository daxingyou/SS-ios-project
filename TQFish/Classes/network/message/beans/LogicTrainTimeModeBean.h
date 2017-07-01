//
//  LogicTrainTimeModeBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_LogicTrainTimeModeBean_h
#define Lstx_cocos2dX_LogicTrainTimeModeBean_h

#include "cocos2d.h"
using namespace cocos2d;


class LogicTrainTimeModeBean : public CCObject{

private:

	/**
	 * 消耗货币数量
	 */
	int count;
	/**
	 * 时间模式Id
	 */
	int timeModeId;
    
public:
    
    LogicTrainTimeModeBean(void){
    }
    
    ~LogicTrainTimeModeBean(void){
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
	 * 时间模式Id
	 */
	int getTimeModeId() {
		return this->timeModeId;
	}
	/**
	 * 时间模式Id
	 */
	void setTimeModeId(int timeModeId){
		this->timeModeId = timeModeId;
	}

};

#endif
