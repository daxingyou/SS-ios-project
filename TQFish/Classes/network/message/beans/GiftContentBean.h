//
//  GiftContentBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GiftContentBean_h
#define Lstx_cocos2dX_GiftContentBean_h

#include "cocos2d.h"
using namespace cocos2d;


class GiftContentBean : public CCObject{

private:

	/**
	 * 商品id
	 */
	int goodsId;
	/**
	 * 道具名字
	 */
	std::string itemName;
	/**
	 * 数量
	 */
	int count;
	/**
	 * 礼包内容类型
	 */
	int itemType;
    
public:
    
    GiftContentBean(void){
    }
    
    ~GiftContentBean(void){
        const char *itemNameChar = itemName.c_str();
        CC_SAFE_DELETE_ARRAY(itemNameChar);
	}
    
	/**
	 * 商品id
	 */
	int getGoodsId() {
		return this->goodsId;
	}
	/**
	 * 商品id
	 */
	void setGoodsId(int goodsId){
		this->goodsId = goodsId;
	}
	/**
	 * 道具名字
	 */
	std::string getItemName() {
		return this->itemName;
	}
	/**
	 * 道具名字
	 */
	void setItemName(std::string itemName){
		this->itemName = itemName;
	}
	/**
	 * 数量
	 */
	int getCount() {
		return this->count;
	}
	/**
	 * 数量
	 */
	void setCount(int count){
		this->count = count;
	}
	/**
	 * 礼包内容类型
	 */
	int getItemType() {
		return this->itemType;
	}
	/**
	 * 礼包内容类型
	 */
	void setItemType(int itemType){
		this->itemType = itemType;
	}

};

#endif
