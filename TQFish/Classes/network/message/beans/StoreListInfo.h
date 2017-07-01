//
//  StoreListInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_StoreListInfo_h
#define Lstx_cocos2dX_StoreListInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class StoreListInfo : public CCObject{

private:

	/**
	 * 过期时间
	 */
	long pastTime;
	/**
	 * 装备ID
	 */
	long equipId;
	/**
	 * 碎片数
	 */
	int currentPartsNum;
	/**
	 * 武器级别
	 */
	int equipLevel;
	/**
	 * 绑定状态
	 */
	int bindtype;
	/**
	 * 武将Id
	 */
	int generalid;
	/**
	 * id_value|id_value|.....
	 */
	std::string equipAttribute;
	/**
	 * 装备位置
	 */
	int slot;
	/**
	 * 升级需要金币
	 */
	int needSilver;
	/**
	 * 装备的唯一ID
	 */
	long equipRealId;
	/**
	 * 绑定时间
	 */
	long bindTime;
	/**
	 * 降级返还金币
	 */
	int returnSilverPrice;
    
public:
    
    StoreListInfo(void){
    }
    
    ~StoreListInfo(void){
        const char *equipAttributeChar = equipAttribute.c_str();
        CC_SAFE_DELETE_ARRAY(equipAttributeChar);
	}
    
	/**
	 * 过期时间
	 */
	long getPastTime() {
		return this->pastTime;
	}
	/**
	 * 过期时间
	 */
	void setPastTime(long pastTime){
		this->pastTime = pastTime;
	}
	/**
	 * 装备ID
	 */
	long getEquipId() {
		return this->equipId;
	}
	/**
	 * 装备ID
	 */
	void setEquipId(long equipId){
		this->equipId = equipId;
	}
	/**
	 * 碎片数
	 */
	int getCurrentPartsNum() {
		return this->currentPartsNum;
	}
	/**
	 * 碎片数
	 */
	void setCurrentPartsNum(int currentPartsNum){
		this->currentPartsNum = currentPartsNum;
	}
	/**
	 * 武器级别
	 */
	int getEquipLevel() {
		return this->equipLevel;
	}
	/**
	 * 武器级别
	 */
	void setEquipLevel(int equipLevel){
		this->equipLevel = equipLevel;
	}
	/**
	 * 绑定状态
	 */
	int getBindtype() {
		return this->bindtype;
	}
	/**
	 * 绑定状态
	 */
	void setBindtype(int bindtype){
		this->bindtype = bindtype;
	}
	/**
	 * 武将Id
	 */
	int getGeneralid() {
		return this->generalid;
	}
	/**
	 * 武将Id
	 */
	void setGeneralid(int generalid){
		this->generalid = generalid;
	}
	/**
	 * id_value|id_value|.....
	 */
	std::string getEquipAttribute() {
		return this->equipAttribute;
	}
	/**
	 * id_value|id_value|.....
	 */
	void setEquipAttribute(std::string equipAttribute){
		this->equipAttribute = equipAttribute;
	}
	/**
	 * 装备位置
	 */
	int getSlot() {
		return this->slot;
	}
	/**
	 * 装备位置
	 */
	void setSlot(int slot){
		this->slot = slot;
	}
	/**
	 * 升级需要金币
	 */
	int getNeedSilver() {
		return this->needSilver;
	}
	/**
	 * 升级需要金币
	 */
	void setNeedSilver(int needSilver){
		this->needSilver = needSilver;
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
	/**
	 * 绑定时间
	 */
	long getBindTime() {
		return this->bindTime;
	}
	/**
	 * 绑定时间
	 */
	void setBindTime(long bindTime){
		this->bindTime = bindTime;
	}
	/**
	 * 降级返还金币
	 */
	int getReturnSilverPrice() {
		return this->returnSilverPrice;
	}
	/**
	 * 降级返还金币
	 */
	void setReturnSilverPrice(int returnSilverPrice){
		this->returnSilverPrice = returnSilverPrice;
	}

};

#endif
