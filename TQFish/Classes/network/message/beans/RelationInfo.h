//
//  RelationInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_RelationInfo_h
#define Lstx_cocos2dX_RelationInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class RelationInfo : public CCObject{

private:

	/**
	 * 敌对等级
	 */
	int againstLv;
	/**
	 * 角色ID
	 */
	long roleId;
    
public:
    
    RelationInfo(void){
    }
    
    ~RelationInfo(void){
	}
    
	/**
	 * 敌对等级
	 */
	int getAgainstLv() {
		return this->againstLv;
	}
	/**
	 * 敌对等级
	 */
	void setAgainstLv(int againstLv){
		this->againstLv = againstLv;
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
