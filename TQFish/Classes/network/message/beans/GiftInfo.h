//
//  GiftInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GiftInfo_h
#define Lstx_cocos2dX_GiftInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class GiftInfo : public CCObject{

private:

	/**
	 * 道具2
	 */
	std::string item2;
	/**
	 * 道具1
	 */
	std::string item1;
	/**
	 * 道具数量2
	 */
	int itemNum2;
	/**
	 * 道具数量1
	 */
	int itemNum1;
	/**
	 * 过期时间
	 */
	long expired;
	/**
	 * 礼包类型
	 */
	int giftType;
	/**
	 * 道具品质5
	 */
	int itemQulity5;
	/**
	 * 领取状态
	 */
	int state;
	/**
	 * 道具品质1
	 */
	int itemQulity1;
	/**
	 * 道具品质2
	 */
	int itemQulity2;
	/**
	 * 道具品质3
	 */
	int itemQulity3;
	/**
	 * 道具品质4
	 */
	int itemQulity4;
	/**
	 * 威望
	 */
	long prestige;
	/**
	 * 军令
	 */
	int token;
	/**
	 * 武将2
	 */
	std::string genal2;
	/**
	 * 武将1
	 */
	std::string genal1;
	/**
	 * 武将4
	 */
	std::string genal4;
	/**
	 * 礼包名称
	 */
	std::string giftName;
	/**
	 * 武将3
	 */
	std::string genal3;
	/**
	 * VIP积分
	 */
	long vipScore;
	/**
	 * 礼包ID
	 */
	int giftId;
	/**
	 * 金币
	 */
	long gold;
	/**
	 * 武将5
	 */
	std::string genal5;
	/**
	 * 突飞令
	 */
	int rush;
	/**
	 * 银币
	 */
	long silver;
	/**
	 * 礼包DID
	 */
	long giftDId;
	/**
	 * 军功
	 */
	long exploit;
	/**
	 * 道具4
	 */
	std::string item4;
	/**
	 * 道具3
	 */
	std::string item3;
	/**
	 * 道具5
	 */
	std::string item5;
	/**
	 * 粮食
	 */
	long food;
	/**
	 * 道具数量5
	 */
	int itemNum5;
	/**
	 * 道具数量3
	 */
	int itemNum3;
	/**
	 * 道具数量4
	 */
	int itemNum4;
    
public:
    
    GiftInfo(void){
    }
    
    ~GiftInfo(void){
        const char *item2Char = item2.c_str();
        CC_SAFE_DELETE_ARRAY(item2Char);
        const char *item1Char = item1.c_str();
        CC_SAFE_DELETE_ARRAY(item1Char);
        const char *genal2Char = genal2.c_str();
        CC_SAFE_DELETE_ARRAY(genal2Char);
        const char *genal1Char = genal1.c_str();
        CC_SAFE_DELETE_ARRAY(genal1Char);
        const char *genal4Char = genal4.c_str();
        CC_SAFE_DELETE_ARRAY(genal4Char);
        const char *giftNameChar = giftName.c_str();
        CC_SAFE_DELETE_ARRAY(giftNameChar);
        const char *genal3Char = genal3.c_str();
        CC_SAFE_DELETE_ARRAY(genal3Char);
        const char *genal5Char = genal5.c_str();
        CC_SAFE_DELETE_ARRAY(genal5Char);
        const char *item4Char = item4.c_str();
        CC_SAFE_DELETE_ARRAY(item4Char);
        const char *item3Char = item3.c_str();
        CC_SAFE_DELETE_ARRAY(item3Char);
        const char *item5Char = item5.c_str();
        CC_SAFE_DELETE_ARRAY(item5Char);
	}
    
	/**
	 * 道具2
	 */
	std::string getItem2() {
		return this->item2;
	}
	/**
	 * 道具2
	 */
	void setItem2(std::string item2){
		this->item2 = item2;
	}
	/**
	 * 道具1
	 */
	std::string getItem1() {
		return this->item1;
	}
	/**
	 * 道具1
	 */
	void setItem1(std::string item1){
		this->item1 = item1;
	}
	/**
	 * 道具数量2
	 */
	int getItemNum2() {
		return this->itemNum2;
	}
	/**
	 * 道具数量2
	 */
	void setItemNum2(int itemNum2){
		this->itemNum2 = itemNum2;
	}
	/**
	 * 道具数量1
	 */
	int getItemNum1() {
		return this->itemNum1;
	}
	/**
	 * 道具数量1
	 */
	void setItemNum1(int itemNum1){
		this->itemNum1 = itemNum1;
	}
	/**
	 * 过期时间
	 */
	long getExpired() {
		return this->expired;
	}
	/**
	 * 过期时间
	 */
	void setExpired(long expired){
		this->expired = expired;
	}
	/**
	 * 礼包类型
	 */
	int getGiftType() {
		return this->giftType;
	}
	/**
	 * 礼包类型
	 */
	void setGiftType(int giftType){
		this->giftType = giftType;
	}
	/**
	 * 道具品质5
	 */
	int getItemQulity5() {
		return this->itemQulity5;
	}
	/**
	 * 道具品质5
	 */
	void setItemQulity5(int itemQulity5){
		this->itemQulity5 = itemQulity5;
	}
	/**
	 * 领取状态
	 */
	int getState() {
		return this->state;
	}
	/**
	 * 领取状态
	 */
	void setState(int state){
		this->state = state;
	}
	/**
	 * 道具品质1
	 */
	int getItemQulity1() {
		return this->itemQulity1;
	}
	/**
	 * 道具品质1
	 */
	void setItemQulity1(int itemQulity1){
		this->itemQulity1 = itemQulity1;
	}
	/**
	 * 道具品质2
	 */
	int getItemQulity2() {
		return this->itemQulity2;
	}
	/**
	 * 道具品质2
	 */
	void setItemQulity2(int itemQulity2){
		this->itemQulity2 = itemQulity2;
	}
	/**
	 * 道具品质3
	 */
	int getItemQulity3() {
		return this->itemQulity3;
	}
	/**
	 * 道具品质3
	 */
	void setItemQulity3(int itemQulity3){
		this->itemQulity3 = itemQulity3;
	}
	/**
	 * 道具品质4
	 */
	int getItemQulity4() {
		return this->itemQulity4;
	}
	/**
	 * 道具品质4
	 */
	void setItemQulity4(int itemQulity4){
		this->itemQulity4 = itemQulity4;
	}
	/**
	 * 威望
	 */
	long getPrestige() {
		return this->prestige;
	}
	/**
	 * 威望
	 */
	void setPrestige(long prestige){
		this->prestige = prestige;
	}
	/**
	 * 军令
	 */
	int getToken() {
		return this->token;
	}
	/**
	 * 军令
	 */
	void setToken(int token){
		this->token = token;
	}
	/**
	 * 武将2
	 */
	std::string getGenal2() {
		return this->genal2;
	}
	/**
	 * 武将2
	 */
	void setGenal2(std::string genal2){
		this->genal2 = genal2;
	}
	/**
	 * 武将1
	 */
	std::string getGenal1() {
		return this->genal1;
	}
	/**
	 * 武将1
	 */
	void setGenal1(std::string genal1){
		this->genal1 = genal1;
	}
	/**
	 * 武将4
	 */
	std::string getGenal4() {
		return this->genal4;
	}
	/**
	 * 武将4
	 */
	void setGenal4(std::string genal4){
		this->genal4 = genal4;
	}
	/**
	 * 礼包名称
	 */
	std::string getGiftName() {
		return this->giftName;
	}
	/**
	 * 礼包名称
	 */
	void setGiftName(std::string giftName){
		this->giftName = giftName;
	}
	/**
	 * 武将3
	 */
	std::string getGenal3() {
		return this->genal3;
	}
	/**
	 * 武将3
	 */
	void setGenal3(std::string genal3){
		this->genal3 = genal3;
	}
	/**
	 * VIP积分
	 */
	long getVipScore() {
		return this->vipScore;
	}
	/**
	 * VIP积分
	 */
	void setVipScore(long vipScore){
		this->vipScore = vipScore;
	}
	/**
	 * 礼包ID
	 */
	int getGiftId() {
		return this->giftId;
	}
	/**
	 * 礼包ID
	 */
	void setGiftId(int giftId){
		this->giftId = giftId;
	}
	/**
	 * 金币
	 */
	long getGold() {
		return this->gold;
	}
	/**
	 * 金币
	 */
	void setGold(long gold){
		this->gold = gold;
	}
	/**
	 * 武将5
	 */
	std::string getGenal5() {
		return this->genal5;
	}
	/**
	 * 武将5
	 */
	void setGenal5(std::string genal5){
		this->genal5 = genal5;
	}
	/**
	 * 突飞令
	 */
	int getRush() {
		return this->rush;
	}
	/**
	 * 突飞令
	 */
	void setRush(int rush){
		this->rush = rush;
	}
	/**
	 * 银币
	 */
	long getSilver() {
		return this->silver;
	}
	/**
	 * 银币
	 */
	void setSilver(long silver){
		this->silver = silver;
	}
	/**
	 * 礼包DID
	 */
	long getGiftDId() {
		return this->giftDId;
	}
	/**
	 * 礼包DID
	 */
	void setGiftDId(long giftDId){
		this->giftDId = giftDId;
	}
	/**
	 * 军功
	 */
	long getExploit() {
		return this->exploit;
	}
	/**
	 * 军功
	 */
	void setExploit(long exploit){
		this->exploit = exploit;
	}
	/**
	 * 道具4
	 */
	std::string getItem4() {
		return this->item4;
	}
	/**
	 * 道具4
	 */
	void setItem4(std::string item4){
		this->item4 = item4;
	}
	/**
	 * 道具3
	 */
	std::string getItem3() {
		return this->item3;
	}
	/**
	 * 道具3
	 */
	void setItem3(std::string item3){
		this->item3 = item3;
	}
	/**
	 * 道具5
	 */
	std::string getItem5() {
		return this->item5;
	}
	/**
	 * 道具5
	 */
	void setItem5(std::string item5){
		this->item5 = item5;
	}
	/**
	 * 粮食
	 */
	long getFood() {
		return this->food;
	}
	/**
	 * 粮食
	 */
	void setFood(long food){
		this->food = food;
	}
	/**
	 * 道具数量5
	 */
	int getItemNum5() {
		return this->itemNum5;
	}
	/**
	 * 道具数量5
	 */
	void setItemNum5(int itemNum5){
		this->itemNum5 = itemNum5;
	}
	/**
	 * 道具数量3
	 */
	int getItemNum3() {
		return this->itemNum3;
	}
	/**
	 * 道具数量3
	 */
	void setItemNum3(int itemNum3){
		this->itemNum3 = itemNum3;
	}
	/**
	 * 道具数量4
	 */
	int getItemNum4() {
		return this->itemNum4;
	}
	/**
	 * 道具数量4
	 */
	void setItemNum4(int itemNum4){
		this->itemNum4 = itemNum4;
	}

};

#endif
