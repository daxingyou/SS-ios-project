//
//  LocalInspireData.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_LocalInspireData_h
#define Lstx_cocos2dX_LocalInspireData_h

#include "cocos2d.h"
using namespace cocos2d;


class LocalInspireData : public CCObject{

private:

	/**
	 * 鼓舞次数
	 */
	int count;
	/**
	 * roleId
	 */
	long roleId;
    
public:
    
    LocalInspireData(void){
    }
    
    ~LocalInspireData(void){
	}
    
	/**
	 * 鼓舞次数
	 */
	int getCount() {
		return this->count;
	}
	/**
	 * 鼓舞次数
	 */
	void setCount(int count){
		this->count = count;
	}
	/**
	 * roleId
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * roleId
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
