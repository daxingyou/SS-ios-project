//
//  CrossServerWarFightInfoEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CrossServerWarFightInfoEntity_h
#define Lstx_cocos2dX_CrossServerWarFightInfoEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class CrossServerWarFightInfoEntity : public CCObject{

private:

	/**
	 * 比赛id
	 */
	long id;
	/**
	 * 比赛结果:1-胜利;0-失败
	 */
	int result;
	/**
	 * 对手名
	 */
	std::string competitorName;
	/**
	 * 对手roleId
	 */
	long competitorRoleId;
	/**
	 * 比赛类型:1-小组赛；2-晋级赛
	 */
	int matchType;
	/**
	 * 战场id
	 */
	long instanceId;
	/**
	 * 战报url
	 */
	std::string fightUrl;
	/**
	 * 轮数
	 */
	int round;
	/**
	 * 角色id
	 */
	long roleId;
    
public:
    
    CrossServerWarFightInfoEntity(void){
    }
    
    ~CrossServerWarFightInfoEntity(void){
        const char *competitorNameChar = competitorName.c_str();
        CC_SAFE_DELETE_ARRAY(competitorNameChar);
        const char *fightUrlChar = fightUrl.c_str();
        CC_SAFE_DELETE_ARRAY(fightUrlChar);
	}
    
	/**
	 * 比赛id
	 */
	long getId() {
		return this->id;
	}
	/**
	 * 比赛id
	 */
	void setId(long id){
		this->id = id;
	}
	/**
	 * 比赛结果:1-胜利;0-失败
	 */
	int getResult() {
		return this->result;
	}
	/**
	 * 比赛结果:1-胜利;0-失败
	 */
	void setResult(int result){
		this->result = result;
	}
	/**
	 * 对手名
	 */
	std::string getCompetitorName() {
		return this->competitorName;
	}
	/**
	 * 对手名
	 */
	void setCompetitorName(std::string competitorName){
		this->competitorName = competitorName;
	}
	/**
	 * 对手roleId
	 */
	long getCompetitorRoleId() {
		return this->competitorRoleId;
	}
	/**
	 * 对手roleId
	 */
	void setCompetitorRoleId(long competitorRoleId){
		this->competitorRoleId = competitorRoleId;
	}
	/**
	 * 比赛类型:1-小组赛；2-晋级赛
	 */
	int getMatchType() {
		return this->matchType;
	}
	/**
	 * 比赛类型:1-小组赛；2-晋级赛
	 */
	void setMatchType(int matchType){
		this->matchType = matchType;
	}
	/**
	 * 战场id
	 */
	long getInstanceId() {
		return this->instanceId;
	}
	/**
	 * 战场id
	 */
	void setInstanceId(long instanceId){
		this->instanceId = instanceId;
	}
	/**
	 * 战报url
	 */
	std::string getFightUrl() {
		return this->fightUrl;
	}
	/**
	 * 战报url
	 */
	void setFightUrl(std::string fightUrl){
		this->fightUrl = fightUrl;
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
	 * 角色id
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 角色id
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
