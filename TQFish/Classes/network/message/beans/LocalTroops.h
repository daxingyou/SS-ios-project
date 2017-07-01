//
//  LocalTroops.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_LocalTroops_h
#define Lstx_cocos2dX_LocalTroops_h

#include "cocos2d.h"
using namespace cocos2d;


class LocalTroops : public CCObject{

private:

	/**
	 * 战斗对象
	 */
	std::string troops;
	/**
	 * roleId
	 */
	long roleId;
    
public:
    
    LocalTroops(void){
    }
    
    ~LocalTroops(void){
        const char *troopsChar = troops.c_str();
        CC_SAFE_DELETE_ARRAY(troopsChar);
	}
    
	/**
	 * 战斗对象
	 */
	std::string getTroops() {
		return this->troops;
	}
	/**
	 * 战斗对象
	 */
	void setTroops(std::string troops){
		this->troops = troops;
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
