//
//  EscortTroopBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EscortTroopBean_h
#define Lstx_cocos2dX_EscortTroopBean_h

#include "cocos2d.h"
using namespace cocos2d;


class EscortTroopBean : public CCObject{

private:

	/**
	 * 部队方阵图片
	 */
	std::string escortTroopImage;
	/**
	 * 部队行动时间倒计时(毫秒)
	 */
	long escortTroopCdTime;
	/**
	 * 部队头像图片
	 */
	std::string escortHeadImage;
	/**
	 * 部队y坐标
	 */
	int posY;
	/**
	 * 部队x坐标
	 */
	int posX;
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	int operationType;
	/**
	 * 部队名称
	 */
	std::string troopName;
	/**
	 * 部队类型  1:NPC 2:自己
	 */
	int escortTroopType;
	/**
	 * 部队id(当部队类型为 自己时 为队长id)
	 */
	std::string troopId;
	/**
	 * 部队描述
	 */
	std::string troopDesc;
	/**
	 * 部队状态 1:正常 2:死亡
	 */
	int stat;
    
public:
    
    EscortTroopBean(void){
    }
    
    ~EscortTroopBean(void){
        const char *escortTroopImageChar = escortTroopImage.c_str();
        CC_SAFE_DELETE_ARRAY(escortTroopImageChar);
        const char *escortHeadImageChar = escortHeadImage.c_str();
        CC_SAFE_DELETE_ARRAY(escortHeadImageChar);
        const char *troopNameChar = troopName.c_str();
        CC_SAFE_DELETE_ARRAY(troopNameChar);
        const char *troopIdChar = troopId.c_str();
        CC_SAFE_DELETE_ARRAY(troopIdChar);
        const char *troopDescChar = troopDesc.c_str();
        CC_SAFE_DELETE_ARRAY(troopDescChar);
	}
    
	/**
	 * 部队方阵图片
	 */
	std::string getEscortTroopImage() {
		return this->escortTroopImage;
	}
	/**
	 * 部队方阵图片
	 */
	void setEscortTroopImage(std::string escortTroopImage){
		this->escortTroopImage = escortTroopImage;
	}
	/**
	 * 部队行动时间倒计时(毫秒)
	 */
	long getEscortTroopCdTime() {
		return this->escortTroopCdTime;
	}
	/**
	 * 部队行动时间倒计时(毫秒)
	 */
	void setEscortTroopCdTime(long escortTroopCdTime){
		this->escortTroopCdTime = escortTroopCdTime;
	}
	/**
	 * 部队头像图片
	 */
	std::string getEscortHeadImage() {
		return this->escortHeadImage;
	}
	/**
	 * 部队头像图片
	 */
	void setEscortHeadImage(std::string escortHeadImage){
		this->escortHeadImage = escortHeadImage;
	}
	/**
	 * 部队y坐标
	 */
	int getPosY() {
		return this->posY;
	}
	/**
	 * 部队y坐标
	 */
	void setPosY(int posY){
		this->posY = posY;
	}
	/**
	 * 部队x坐标
	 */
	int getPosX() {
		return this->posX;
	}
	/**
	 * 部队x坐标
	 */
	void setPosX(int posX){
		this->posX = posX;
	}
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	int getOperationType() {
		return this->operationType;
	}
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	void setOperationType(int operationType){
		this->operationType = operationType;
	}
	/**
	 * 部队名称
	 */
	std::string getTroopName() {
		return this->troopName;
	}
	/**
	 * 部队名称
	 */
	void setTroopName(std::string troopName){
		this->troopName = troopName;
	}
	/**
	 * 部队类型  1:NPC 2:自己
	 */
	int getEscortTroopType() {
		return this->escortTroopType;
	}
	/**
	 * 部队类型  1:NPC 2:自己
	 */
	void setEscortTroopType(int escortTroopType){
		this->escortTroopType = escortTroopType;
	}
	/**
	 * 部队id(当部队类型为 自己时 为队长id)
	 */
	std::string getTroopId() {
		return this->troopId;
	}
	/**
	 * 部队id(当部队类型为 自己时 为队长id)
	 */
	void setTroopId(std::string troopId){
		this->troopId = troopId;
	}
	/**
	 * 部队描述
	 */
	std::string getTroopDesc() {
		return this->troopDesc;
	}
	/**
	 * 部队描述
	 */
	void setTroopDesc(std::string troopDesc){
		this->troopDesc = troopDesc;
	}
	/**
	 * 部队状态 1:正常 2:死亡
	 */
	int getStat() {
		return this->stat;
	}
	/**
	 * 部队状态 1:正常 2:死亡
	 */
	void setStat(int stat){
		this->stat = stat;
	}

};

#endif
