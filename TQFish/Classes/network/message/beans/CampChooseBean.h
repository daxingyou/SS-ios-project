//
//  CampChooseBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampChooseBean_h
#define Lstx_cocos2dX_CampChooseBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampChooseBean : public CCObject{

private:

	/**
	 * 索引位置
	 */
	int index;
	/**
	 * 物品数量
	 */
	int count;
	/**
	 * 物品id
	 */
	int itemId;
	/**
	 * 0:可放弃  1:可恢复  2:已选择 3:金币不足
	 */
	int stat;
    
public:
    
    CampChooseBean(void){
    }
    
    ~CampChooseBean(void){
	}
    
	/**
	 * 索引位置
	 */
	int getIndex() {
		return this->index;
	}
	/**
	 * 索引位置
	 */
	void setIndex(int index){
		this->index = index;
	}
	/**
	 * 物品数量
	 */
	int getCount() {
		return this->count;
	}
	/**
	 * 物品数量
	 */
	void setCount(int count){
		this->count = count;
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
	/**
	 * 0:可放弃  1:可恢复  2:已选择 3:金币不足
	 */
	int getStat() {
		return this->stat;
	}
	/**
	 * 0:可放弃  1:可恢复  2:已选择 3:金币不足
	 */
	void setStat(int stat){
		this->stat = stat;
	}

};

#endif
