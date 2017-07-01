//
//  MyWarListInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MyWarListInfo_h
#define Lstx_cocos2dX_MyWarListInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class MyWarListInfo : public CCObject{

private:

	/**
	 * 战报
	 */
	std::string matchReportUrl;
	/**
	 * 比赛结果
	 */
	int result;
	/**
	 * 对手角色名
	 */
	std::string competitorName;
	/**
	 * 对手角色id
	 */
	long competitorRoleId;
	/**
	 * 比赛类别
	 */
	int matchType;
	/**
	 * 场次
	 */
	int round;
    
public:
    
    MyWarListInfo(void){
    }
    
    ~MyWarListInfo(void){
        const char *matchReportUrlChar = matchReportUrl.c_str();
        CC_SAFE_DELETE_ARRAY(matchReportUrlChar);
        const char *competitorNameChar = competitorName.c_str();
        CC_SAFE_DELETE_ARRAY(competitorNameChar);
	}
    
	/**
	 * 战报
	 */
	std::string getMatchReportUrl() {
		return this->matchReportUrl;
	}
	/**
	 * 战报
	 */
	void setMatchReportUrl(std::string matchReportUrl){
		this->matchReportUrl = matchReportUrl;
	}
	/**
	 * 比赛结果
	 */
	int getResult() {
		return this->result;
	}
	/**
	 * 比赛结果
	 */
	void setResult(int result){
		this->result = result;
	}
	/**
	 * 对手角色名
	 */
	std::string getCompetitorName() {
		return this->competitorName;
	}
	/**
	 * 对手角色名
	 */
	void setCompetitorName(std::string competitorName){
		this->competitorName = competitorName;
	}
	/**
	 * 对手角色id
	 */
	long getCompetitorRoleId() {
		return this->competitorRoleId;
	}
	/**
	 * 对手角色id
	 */
	void setCompetitorRoleId(long competitorRoleId){
		this->competitorRoleId = competitorRoleId;
	}
	/**
	 * 比赛类别
	 */
	int getMatchType() {
		return this->matchType;
	}
	/**
	 * 比赛类别
	 */
	void setMatchType(int matchType){
		this->matchType = matchType;
	}
	/**
	 * 场次
	 */
	int getRound() {
		return this->round;
	}
	/**
	 * 场次
	 */
	void setRound(int round){
		this->round = round;
	}

};

#endif
