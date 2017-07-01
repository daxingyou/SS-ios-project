//
//  SellItemBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_SellItemBean_h
#define Lstx_cocos2dX_SellItemBean_h

#include "cocos2d.h"
using namespace cocos2d;


class SellItemBean : public CCObject{

private:

	/**
	 * 不能购买原因 形如1,2,3, 1-商店等级不足 2-银币不足 3-仓库容量不足
	 */
	std::string reason;
	/**
	 * 是否可以购买
	 */
	bool canBuy;
	/**
	 * 道具Id
	 */
	int itemId;
	/**
	 * 当前库存
	 */
	int buyAmount;
    
public:
    
    SellItemBean(void){
    }
    
    ~SellItemBean(void){
        const char *reasonChar = reason.c_str();
        CC_SAFE_DELETE_ARRAY(reasonChar);
	}
    
	/**
	 * 不能购买原因 形如1,2,3, 1-商店等级不足 2-银币不足 3-仓库容量不足
	 */
	std::string getReason() {
		return this->reason;
	}
	/**
	 * 不能购买原因 形如1,2,3, 1-商店等级不足 2-银币不足 3-仓库容量不足
	 */
	void setReason(std::string reason){
		this->reason = reason;
	}
	/**
	 * 是否可以购买
	 */
	bool getCanBuy() {
		return this->canBuy;
	}
	/**
	 * 是否可以购买
	 */
	void setCanBuy(bool canBuy){
		this->canBuy = canBuy;
	}
	/**
	 * 道具Id
	 */
	int getItemId() {
		return this->itemId;
	}
	/**
	 * 道具Id
	 */
	void setItemId(int itemId){
		this->itemId = itemId;
	}
	/**
	 * 当前库存
	 */
	int getBuyAmount() {
		return this->buyAmount;
	}
	/**
	 * 当前库存
	 */
	void setBuyAmount(int buyAmount){
		this->buyAmount = buyAmount;
	}

};

#endif
