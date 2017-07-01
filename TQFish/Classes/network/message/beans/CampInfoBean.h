//
//  CampInfoBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampInfoBean_h
#define Lstx_cocos2dX_CampInfoBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampInfoBean : public CCObject{

private:

	/**
	 * 战役id 
	 */
	int campId;
	/**
	 * 英雄难度完成度
	 */
	int hero;
	/**
	 * 完成度上限
	 */
	int finishLimit;
	/**
	 * 简单模式完成度
	 */
	int normal;
	/**
	 * 关卡名称
	 */
	std::string powerName;
	/**
	 * 是否可攻打  0：不可攻打 ：关卡未完成  1：可以攻打
	 */
	int isAtt;
	/**
	 * 困难难度完成度
	 */
	int difficult;
	/**
	 * 等待队伍数量
	 */
	int teamCount;
    
public:
    
    CampInfoBean(void){
    }
    
    ~CampInfoBean(void){
        const char *powerNameChar = powerName.c_str();
        CC_SAFE_DELETE_ARRAY(powerNameChar);
	}
    
	/**
	 * 战役id 
	 */
	int getCampId() {
		return this->campId;
	}
	/**
	 * 战役id 
	 */
	void setCampId(int campId){
		this->campId = campId;
	}
	/**
	 * 英雄难度完成度
	 */
	int getHero() {
		return this->hero;
	}
	/**
	 * 英雄难度完成度
	 */
	void setHero(int hero){
		this->hero = hero;
	}
	/**
	 * 完成度上限
	 */
	int getFinishLimit() {
		return this->finishLimit;
	}
	/**
	 * 完成度上限
	 */
	void setFinishLimit(int finishLimit){
		this->finishLimit = finishLimit;
	}
	/**
	 * 简单模式完成度
	 */
	int getNormal() {
		return this->normal;
	}
	/**
	 * 简单模式完成度
	 */
	void setNormal(int normal){
		this->normal = normal;
	}
	/**
	 * 关卡名称
	 */
	std::string getPowerName() {
		return this->powerName;
	}
	/**
	 * 关卡名称
	 */
	void setPowerName(std::string powerName){
		this->powerName = powerName;
	}
	/**
	 * 是否可攻打  0：不可攻打 ：关卡未完成  1：可以攻打
	 */
	int getIsAtt() {
		return this->isAtt;
	}
	/**
	 * 是否可攻打  0：不可攻打 ：关卡未完成  1：可以攻打
	 */
	void setIsAtt(int isAtt){
		this->isAtt = isAtt;
	}
	/**
	 * 困难难度完成度
	 */
	int getDifficult() {
		return this->difficult;
	}
	/**
	 * 困难难度完成度
	 */
	void setDifficult(int difficult){
		this->difficult = difficult;
	}
	/**
	 * 等待队伍数量
	 */
	int getTeamCount() {
		return this->teamCount;
	}
	/**
	 * 等待队伍数量
	 */
	void setTeamCount(int teamCount){
		this->teamCount = teamCount;
	}

};

#endif
