//
//  CrossServerEssenceFightInfoEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CrossServerEssenceFightInfoEntity_h
#define Lstx_cocos2dX_CrossServerEssenceFightInfoEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class CrossServerEssenceFightInfoEntity : public CCObject{

private:

	/**
	 * 战报
	 */
	std::string reportUrl;
	/**
	 * 攻击方roleId
	 */
	long attRoleId;
	/**
	 * 防守方roleId
	 */
	long defRoleId;
	/**
	 * 比赛类型
	 */
	int matchType;
	/**
	 * 副本id
	 */
	long instanceId;
	/**
	 * 轮数
	 */
	int round;
	/**
	 * 下标
	 */
	int bout;
	/**
	 * 胜利方roleId
	 */
	long winRoleId;
    
public:
    
    CrossServerEssenceFightInfoEntity(void){
    }
    
    ~CrossServerEssenceFightInfoEntity(void){
        const char *reportUrlChar = reportUrl.c_str();
        CC_SAFE_DELETE_ARRAY(reportUrlChar);
	}
    
	/**
	 * 战报
	 */
	std::string getReportUrl() {
		return this->reportUrl;
	}
	/**
	 * 战报
	 */
	void setReportUrl(std::string reportUrl){
		this->reportUrl = reportUrl;
	}
	/**
	 * 攻击方roleId
	 */
	long getAttRoleId() {
		return this->attRoleId;
	}
	/**
	 * 攻击方roleId
	 */
	void setAttRoleId(long attRoleId){
		this->attRoleId = attRoleId;
	}
	/**
	 * 防守方roleId
	 */
	long getDefRoleId() {
		return this->defRoleId;
	}
	/**
	 * 防守方roleId
	 */
	void setDefRoleId(long defRoleId){
		this->defRoleId = defRoleId;
	}
	/**
	 * 比赛类型
	 */
	int getMatchType() {
		return this->matchType;
	}
	/**
	 * 比赛类型
	 */
	void setMatchType(int matchType){
		this->matchType = matchType;
	}
	/**
	 * 副本id
	 */
	long getInstanceId() {
		return this->instanceId;
	}
	/**
	 * 副本id
	 */
	void setInstanceId(long instanceId){
		this->instanceId = instanceId;
	}
	/**
	 * 轮数
	 */
	int getRound() {
		return this->round;
	}
	/**
	 * 轮数
	 */
	void setRound(int round){
		this->round = round;
	}
	/**
	 * 下标
	 */
	int getBout() {
		return this->bout;
	}
	/**
	 * 下标
	 */
	void setBout(int bout){
		this->bout = bout;
	}
	/**
	 * 胜利方roleId
	 */
	long getWinRoleId() {
		return this->winRoleId;
	}
	/**
	 * 胜利方roleId
	 */
	void setWinRoleId(long winRoleId){
		this->winRoleId = winRoleId;
	}

};

#endif
