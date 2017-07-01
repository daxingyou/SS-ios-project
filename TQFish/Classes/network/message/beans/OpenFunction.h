//
//  OpenFunction.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_OpenFunction_h
#define Lstx_cocos2dX_OpenFunction_h

#include "cocos2d.h"
using namespace cocos2d;


class OpenFunction : public CCObject{

private:

	/**
	 * 0关闭1开放
	 */
	int flg;
	/**
	 * 功能id
	 */
	int functionId;
    
public:
    
    OpenFunction(void){
    }
    
    ~OpenFunction(void){
	}
    
	/**
	 * 0关闭1开放
	 */
	int getFlg() {
		return this->flg;
	}
	/**
	 * 0关闭1开放
	 */
	void setFlg(int flg){
		this->flg = flg;
	}
	/**
	 * 功能id
	 */
	int getFunctionId() {
		return this->functionId;
	}
	/**
	 * 功能id
	 */
	void setFunctionId(int functionId){
		this->functionId = functionId;
	}

};

#endif
