//
//  LogicRefreshModeBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_LogicRefreshModeBean_h
#define Lstx_cocos2dX_LogicRefreshModeBean_h

#include "cocos2d.h"
using namespace cocos2d;


class LogicRefreshModeBean : public CCObject{

private:

	/**
	 * 消耗货币数量
	 */
	int count;
	/**
	 * 模式Id
	 */
	int refreshModeId;
    
public:
    
    LogicRefreshModeBean(void){
    }
    
    ~LogicRefreshModeBean(void){
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
	 * 模式Id
	 */
	int getRefreshModeId() {
		return this->refreshModeId;
	}
	/**
	 * 模式Id
	 */
	void setRefreshModeId(int refreshModeId){
		this->refreshModeId = refreshModeId;
	}

};

#endif
