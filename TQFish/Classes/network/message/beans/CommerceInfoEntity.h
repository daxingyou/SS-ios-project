//
//  CommerceInfoEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CommerceInfoEntity_h
#define Lstx_cocos2dX_CommerceInfoEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class CommerceInfoEntity : public CCObject{

private:

	/**
	 * 申请人姓名
	 */
	std::string senderName;
	/**
	 * 货物数量
	 */
	int goodsAmount;
	/**
	 * 货物等级
	 */
	int goodsLv;
	/**
	 * 接受对方申请后自己可得银币
	 */
	int receiverMoney;
	/**
	 * 申请人Id
	 */
	long senderId;
    
public:
    
    CommerceInfoEntity(void){
    }
    
    ~CommerceInfoEntity(void){
        const char *senderNameChar = senderName.c_str();
        CC_SAFE_DELETE_ARRAY(senderNameChar);
	}
    
	/**
	 * 申请人姓名
	 */
	std::string getSenderName() {
		return this->senderName;
	}
	/**
	 * 申请人姓名
	 */
	void setSenderName(std::string senderName){
		this->senderName = senderName;
	}
	/**
	 * 货物数量
	 */
	int getGoodsAmount() {
		return this->goodsAmount;
	}
	/**
	 * 货物数量
	 */
	void setGoodsAmount(int goodsAmount){
		this->goodsAmount = goodsAmount;
	}
	/**
	 * 货物等级
	 */
	int getGoodsLv() {
		return this->goodsLv;
	}
	/**
	 * 货物等级
	 */
	void setGoodsLv(int goodsLv){
		this->goodsLv = goodsLv;
	}
	/**
	 * 接受对方申请后自己可得银币
	 */
	int getReceiverMoney() {
		return this->receiverMoney;
	}
	/**
	 * 接受对方申请后自己可得银币
	 */
	void setReceiverMoney(int receiverMoney){
		this->receiverMoney = receiverMoney;
	}
	/**
	 * 申请人Id
	 */
	long getSenderId() {
		return this->senderId;
	}
	/**
	 * 申请人Id
	 */
	void setSenderId(long senderId){
		this->senderId = senderId;
	}

};

#endif
