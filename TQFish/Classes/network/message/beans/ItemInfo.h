//
//  ItemInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ItemInfo_h
#define Lstx_cocos2dX_ItemInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class ItemInfo : public CCObject{

private:

	/**
	 * 玩家国家
	 */
	int roleNation;
	/**
	 * 装备属性
	 */
	int item;
	/**
	 * 装备品质
	 */
	int itemQuality;
	/**
	 * 玩家等级
	 */
	int roleLevel;
	/**
	 * 玩家名字
	 */
	std::string roleName;
	/**
	 * 装备等级
	 */
	long itemLevel;
	/**
	 * 装备实体id
	 */
	long itemEntityId;
	/**
	 * 装备id
	 */
	long itemId;
	/**
	 * 装备排行
	 */
	int itemOrder;
	/**
	 * 玩家id
	 */
	long roleId;
    
public:
    
    ItemInfo(void){
    }
    
    ~ItemInfo(void){
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
	}
    
	/**
	 * 玩家国家
	 */
	int getRoleNation() {
		return this->roleNation;
	}
	/**
	 * 玩家国家
	 */
	void setRoleNation(int roleNation){
		this->roleNation = roleNation;
	}
	/**
	 * 装备属性
	 */
	int getItem() {
		return this->item;
	}
	/**
	 * 装备属性
	 */
	void setItem(int item){
		this->item = item;
	}
	/**
	 * 装备品质
	 */
	int getItemQuality() {
		return this->itemQuality;
	}
	/**
	 * 装备品质
	 */
	void setItemQuality(int itemQuality){
		this->itemQuality = itemQuality;
	}
	/**
	 * 玩家等级
	 */
	int getRoleLevel() {
		return this->roleLevel;
	}
	/**
	 * 玩家等级
	 */
	void setRoleLevel(int roleLevel){
		this->roleLevel = roleLevel;
	}
	/**
	 * 玩家名字
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 玩家名字
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 装备等级
	 */
	long getItemLevel() {
		return this->itemLevel;
	}
	/**
	 * 装备等级
	 */
	void setItemLevel(long itemLevel){
		this->itemLevel = itemLevel;
	}
	/**
	 * 装备实体id
	 */
	long getItemEntityId() {
		return this->itemEntityId;
	}
	/**
	 * 装备实体id
	 */
	void setItemEntityId(long itemEntityId){
		this->itemEntityId = itemEntityId;
	}
	/**
	 * 装备id
	 */
	long getItemId() {
		return this->itemId;
	}
	/**
	 * 装备id
	 */
	void setItemId(long itemId){
		this->itemId = itemId;
	}
	/**
	 * 装备排行
	 */
	int getItemOrder() {
		return this->itemOrder;
	}
	/**
	 * 装备排行
	 */
	void setItemOrder(int itemOrder){
		this->itemOrder = itemOrder;
	}
	/**
	 * 玩家id
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 玩家id
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
