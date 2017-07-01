//
//  CampEventArgsBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampEventArgsBean_h
#define Lstx_cocos2dX_CampEventArgsBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampEventArgsBean : public CCObject{

private:

	/**
	 * 事件参数 
	 */
	std::string args;
    
public:
    
    CampEventArgsBean(void){
    }
    
    ~CampEventArgsBean(void){
        const char *argsChar = args.c_str();
        CC_SAFE_DELETE_ARRAY(argsChar);
	}
    
	/**
	 * 事件参数 
	 */
	std::string getArgs() {
		return this->args;
	}
	/**
	 * 事件参数 
	 */
	void setArgs(std::string args){
		this->args = args;
	}

};

#endif
