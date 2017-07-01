//
//  UserItemEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_UserItemEntity_h
#define Lstx_cocos2dX_UserItemEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class UserItemEntity : public CCObject{

private:

	/**
	 * 物品数量
	 */
	int amount;
	/**
	 * 背包中物品Index
	 */
	long id;
	/**
	 * 物品ID
	 */
	long itemId;
    
public:
    
    UserItemEntity(void){
    }
    
    ~UserItemEntity(void){
	}
    
	/**
	 * 物品数量
	 */
	int getAmount() {
		return this->amount;
	}
	/**
	 * 物品数量
	 */
	void setAmount(int amount){
		this->amount = amount;
	}
	/**
	 * 背包中物品Index
	 */
	long getId() {
		return this->id;
	}
	/**
	 * 背包中物品Index
	 */
	void setId(long id){
		this->id = id;
	}
	/**
	 * 物品ID
	 */
	long getItemId() {
		return this->itemId;
	}
	/**
	 * 物品ID
	 */
	void setItemId(long itemId){
		this->itemId = itemId;
	}

};

#endif
