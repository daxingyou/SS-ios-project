//
//  MatchListInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MatchListInfo_h
#define Lstx_cocos2dX_MatchListInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class MatchListInfo : public CCObject{

private:

	/**
	 * 位置
	 */
	int position;
	/**
	 * 比赛守方名字
	 */
	std::string defName;
	/**
	 * 比赛下标
	 */
	long index;
	/**
	 * 比赛胜利方头像
	 */
	std::string winerIcon;
	/**
	 * 比赛状态
	 */
	int status;
	/**
	 * 比赛攻方名字
	 */
	std::string attkName;
	/**
	 * 比赛守方roleId
	 */
	long defRoleId;
	/**
	 * 比赛胜利方roleId
	 */
	long winerId;
	/**
	 * 比赛战报地址
	 */
	std::string report;
	/**
	 * 比赛攻方roleId
	 */
	long attkRoleId;
	/**
	 * 轮数
	 */
	int round;
    
public:
    
    MatchListInfo(void){
    }
    
    ~MatchListInfo(void){
        const char *defNameChar = defName.c_str();
        CC_SAFE_DELETE_ARRAY(defNameChar);
        const char *winerIconChar = winerIcon.c_str();
        CC_SAFE_DELETE_ARRAY(winerIconChar);
        const char *attkNameChar = attkName.c_str();
        CC_SAFE_DELETE_ARRAY(attkNameChar);
        const char *reportChar = report.c_str();
        CC_SAFE_DELETE_ARRAY(reportChar);
	}
    
	/**
	 * 位置
	 */
	int getPosition() {
		return this->position;
	}
	/**
	 * 位置
	 */
	void setPosition(int position){
		this->position = position;
	}
	/**
	 * 比赛守方名字
	 */
	std::string getDefName() {
		return this->defName;
	}
	/**
	 * 比赛守方名字
	 */
	void setDefName(std::string defName){
		this->defName = defName;
	}
	/**
	 * 比赛下标
	 */
	long getIndex() {
		return this->index;
	}
	/**
	 * 比赛下标
	 */
	void setIndex(long index){
		this->index = index;
	}
	/**
	 * 比赛胜利方头像
	 */
	std::string getWinerIcon() {
		return this->winerIcon;
	}
	/**
	 * 比赛胜利方头像
	 */
	void setWinerIcon(std::string winerIcon){
		this->winerIcon = winerIcon;
	}
	/**
	 * 比赛状态
	 */
	int getStatus() {
		return this->status;
	}
	/**
	 * 比赛状态
	 */
	void setStatus(int status){
		this->status = status;
	}
	/**
	 * 比赛攻方名字
	 */
	std::string getAttkName() {
		return this->attkName;
	}
	/**
	 * 比赛攻方名字
	 */
	void setAttkName(std::string attkName){
		this->attkName = attkName;
	}
	/**
	 * 比赛守方roleId
	 */
	long getDefRoleId() {
		return this->defRoleId;
	}
	/**
	 * 比赛守方roleId
	 */
	void setDefRoleId(long defRoleId){
		this->defRoleId = defRoleId;
	}
	/**
	 * 比赛胜利方roleId
	 */
	long getWinerId() {
		return this->winerId;
	}
	/**
	 * 比赛胜利方roleId
	 */
	void setWinerId(long winerId){
		this->winerId = winerId;
	}
	/**
	 * 比赛战报地址
	 */
	std::string getReport() {
		return this->report;
	}
	/**
	 * 比赛战报地址
	 */
	void setReport(std::string report){
		this->report = report;
	}
	/**
	 * 比赛攻方roleId
	 */
	long getAttkRoleId() {
		return this->attkRoleId;
	}
	/**
	 * 比赛攻方roleId
	 */
	void setAttkRoleId(long attkRoleId){
		this->attkRoleId = attkRoleId;
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

};

#endif
