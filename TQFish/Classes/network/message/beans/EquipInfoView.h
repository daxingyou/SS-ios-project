//
//  EquipInfoView.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EquipInfoView_h
#define Lstx_cocos2dX_EquipInfoView_h

#include "cocos2d.h"
using namespace cocos2d;


class EquipInfoView : public CCObject{

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
	 * 物品唯一id
	 */
	long realId;
	/**
	 * 武将id
	 */
	int generalid;
	/**
	 * id_value_addNum_addNum|id_value_addNum_addNum|格式：id_属性值(基础值+强化值+传古值)_强化一级增量_传古一级增量.....
	 */
	std::string equipAttribute;
	/**
	 * 物品id
	 */
	int itemId;
    
public:
    
    EquipInfoView(void){
    }
    
    ~EquipInfoView(void){
        const char *guXunChar = guXun.c_str();
        CC_SAFE_DELETE_ARRAY(guXunChar);
        const char *equipAttributeChar = equipAttribute.c_str();
        CC_SAFE_DELETE_ARRAY(equipAttributeChar);
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
	 * 物品唯一id
	 */
	long getRealId() {
		return this->realId;
	}
	/**
	 * 物品唯一id
	 */
	void setRealId(long realId){
		this->realId = realId;
	}
	/**
	 * 武将id
	 */
	int getGeneralid() {
		return this->generalid;
	}
	/**
	 * 武将id
	 */
	void setGeneralid(int generalid){
		this->generalid = generalid;
	}
	/**
	 * id_value_addNum_addNum|id_value_addNum_addNum|格式：id_属性值(基础值+强化值+传古值)_强化一级增量_传古一级增量.....
	 */
	std::string getEquipAttribute() {
		return this->equipAttribute;
	}
	/**
	 * id_value_addNum_addNum|id_value_addNum_addNum|格式：id_属性值(基础值+强化值+传古值)_强化一级增量_传古一级增量.....
	 */
	void setEquipAttribute(std::string equipAttribute){
		this->equipAttribute = equipAttribute;
	}
	/**
	 * 物品id
	 */
	int getItemId() {
		return this->itemId;
	}
	/**
	 * 物品id
	 */
	void setItemId(int itemId){
		this->itemId = itemId;
	}

};

#endif
