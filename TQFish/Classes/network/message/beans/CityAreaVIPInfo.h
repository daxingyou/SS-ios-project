//
//  CityAreaVIPInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CityAreaVIPInfo_h
#define Lstx_cocos2dX_CityAreaVIPInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class CityAreaVIPInfo : public CCObject{

private:

	/**
	 * 角色VIP等级
	 */
	int vipLv;
	/**
	 * 角色ID
	 */
	long roleId;
    
public:
    
    CityAreaVIPInfo(void){
    }
    
    ~CityAreaVIPInfo(void){
	}
    
	/**
	 * 角色VIP等级
	 */
	int getVipLv() {
		return this->vipLv;
	}
	/**
	 * 角色VIP等级
	 */
	void setVipLv(int vipLv){
		this->vipLv = vipLv;
	}
	/**
	 * 角色ID
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 角色ID
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
