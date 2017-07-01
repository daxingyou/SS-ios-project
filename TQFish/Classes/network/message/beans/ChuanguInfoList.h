//
//  ChuanguInfoList.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ChuanguInfoList_h
#define Lstx_cocos2dX_ChuanguInfoList_h

#include "cocos2d.h"
using namespace cocos2d;


class ChuanguInfoList : public CCObject{

private:

	/**
	 * 传古等级
	 */
	int level;
	/**
	 * 古训格式：古训名称,是否激活(0否，1是),id,value,激活古训等级(id:effectId,value:属性值);...
	 */
	std::string guXun;
	/**
	 * 装备的唯一ID
	 */
	long equipRealId;
    
public:
    
    ChuanguInfoList(void){
    }
    
    ~ChuanguInfoList(void){
        const char *guXunChar = guXun.c_str();
        CC_SAFE_DELETE_ARRAY(guXunChar);
	}
    
	/**
	 * 传古等级
	 */
	int getLevel() {
		return this->level;
	}
	/**
	 * 传古等级
	 */
	void setLevel(int level){
		this->level = level;
	}
	/**
	 * 古训格式：古训名称,是否激活(0否，1是),id,value,激活古训等级(id:effectId,value:属性值);...
	 */
	std::string getGuXun() {
		return this->guXun;
	}
	/**
	 * 古训格式：古训名称,是否激活(0否，1是),id,value,激活古训等级(id:effectId,value:属性值);...
	 */
	void setGuXun(std::string guXun){
		this->guXun = guXun;
	}
	/**
	 * 装备的唯一ID
	 */
	long getEquipRealId() {
		return this->equipRealId;
	}
	/**
	 * 装备的唯一ID
	 */
	void setEquipRealId(long equipRealId){
		this->equipRealId = equipRealId;
	}

};

#endif
