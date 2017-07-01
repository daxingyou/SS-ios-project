//
//  CampTroopBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampTroopBean_h
#define Lstx_cocos2dX_CampTroopBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampTroopBean : public CCObject{

private:

	/**
	 * 部队行动时间倒计时(毫秒)
	 */
	long campTroopCdTime;
	/**
	 * 部队方阵图片
	 */
	std::string campTroopImage;
	/**
	 * 部队y坐标
	 */
	int posY;
	/**
	 * 部队x坐标
	 */
	int posX;
	/**
	 * 部队兵力上限
	 */
	int soliderLimit;
	/**
	 * 部队描述
	 */
	std::string campTroopDesc;
	/**
	 * 部队id
	 */
	std::string campTroopId;
	/**
	 * 部队状态 1:正常 2:死亡
	 */
	int stat;
	/**
	 * 杀敌数
	 */
	int killCount;
	/**
	 * 部队类型  1:NPC   2:友军  3:自己
	 */
	int campTroopType;
	/**
	 * 部队名称
	 */
	std::string campTroopName;
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	int operationType;
	/**
	 * 部队头像图片
	 */
	std::string troopHeadImage;
	/**
	 * 部队方向
	 */
	int campDirection;
	/**
	 * 部队兵力
	 */
	int solider;
    
public:
    
    CampTroopBean(void){
    }
    
    ~CampTroopBean(void){
        const char *campTroopImageChar = campTroopImage.c_str();
        CC_SAFE_DELETE_ARRAY(campTroopImageChar);
        const char *campTroopDescChar = campTroopDesc.c_str();
        CC_SAFE_DELETE_ARRAY(campTroopDescChar);
        const char *campTroopIdChar = campTroopId.c_str();
        CC_SAFE_DELETE_ARRAY(campTroopIdChar);
        const char *campTroopNameChar = campTroopName.c_str();
        CC_SAFE_DELETE_ARRAY(campTroopNameChar);
        const char *troopHeadImageChar = troopHeadImage.c_str();
        CC_SAFE_DELETE_ARRAY(troopHeadImageChar);
	}
    
	/**
	 * 部队行动时间倒计时(毫秒)
	 */
	long getCampTroopCdTime() {
		return this->campTroopCdTime;
	}
	/**
	 * 部队行动时间倒计时(毫秒)
	 */
	void setCampTroopCdTime(long campTroopCdTime){
		this->campTroopCdTime = campTroopCdTime;
	}
	/**
	 * 部队方阵图片
	 */
	std::string getCampTroopImage() {
		return this->campTroopImage;
	}
	/**
	 * 部队方阵图片
	 */
	void setCampTroopImage(std::string campTroopImage){
		this->campTroopImage = campTroopImage;
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
	 * 部队兵力上限
	 */
	int getSoliderLimit() {
		return this->soliderLimit;
	}
	/**
	 * 部队兵力上限
	 */
	void setSoliderLimit(int soliderLimit){
		this->soliderLimit = soliderLimit;
	}
	/**
	 * 部队描述
	 */
	std::string getCampTroopDesc() {
		return this->campTroopDesc;
	}
	/**
	 * 部队描述
	 */
	void setCampTroopDesc(std::string campTroopDesc){
		this->campTroopDesc = campTroopDesc;
	}
	/**
	 * 部队id
	 */
	std::string getCampTroopId() {
		return this->campTroopId;
	}
	/**
	 * 部队id
	 */
	void setCampTroopId(std::string campTroopId){
		this->campTroopId = campTroopId;
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
	/**
	 * 杀敌数
	 */
	int getKillCount() {
		return this->killCount;
	}
	/**
	 * 杀敌数
	 */
	void setKillCount(int killCount){
		this->killCount = killCount;
	}
	/**
	 * 部队类型  1:NPC   2:友军  3:自己
	 */
	int getCampTroopType() {
		return this->campTroopType;
	}
	/**
	 * 部队类型  1:NPC   2:友军  3:自己
	 */
	void setCampTroopType(int campTroopType){
		this->campTroopType = campTroopType;
	}
	/**
	 * 部队名称
	 */
	std::string getCampTroopName() {
		return this->campTroopName;
	}
	/**
	 * 部队名称
	 */
	void setCampTroopName(std::string campTroopName){
		this->campTroopName = campTroopName;
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
	 * 部队头像图片
	 */
	std::string getTroopHeadImage() {
		return this->troopHeadImage;
	}
	/**
	 * 部队头像图片
	 */
	void setTroopHeadImage(std::string troopHeadImage){
		this->troopHeadImage = troopHeadImage;
	}
	/**
	 * 部队方向
	 */
	int getCampDirection() {
		return this->campDirection;
	}
	/**
	 * 部队方向
	 */
	void setCampDirection(int campDirection){
		this->campDirection = campDirection;
	}
	/**
	 * 部队兵力
	 */
	int getSolider() {
		return this->solider;
	}
	/**
	 * 部队兵力
	 */
	void setSolider(int solider){
		this->solider = solider;
	}

};

#endif
