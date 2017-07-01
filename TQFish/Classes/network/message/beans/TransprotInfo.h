//
//  TransprotInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_TransprotInfo_h
#define Lstx_cocos2dX_TransprotInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class TransprotInfo : public CCObject{

private:

	/**
	 * 国家id
	 */
	int countryId;
	/**
	 * 抢劫获得银币
	 */
	int robSilver;
	/**
	 * 守护玩家获得军功
	 */
	int proExploit;
	/**
	 * 运送获得银币
	 */
	int silver;
	/**
	 * 护送玩家名称
	 */
	std::string proRoleName;
	/**
	 * 角色名称
	 */
	std::string roleName;
	/**
	 * 车辆名称
	 */
	std::string toolName;
	/**
	 * 护送玩家id
	 */
	long proRoleId;
	/**
	 * 运送获得军功
	 */
	int exploit;
	/**
	 * 守护玩家获得银币
	 */
	int proSilver;
	/**
	 * 玩家等级
	 */
	int level;
	/**
	 * 抢劫获得军功
	 */
	int robExploit;
	/**
	 * 运送剩余时间(毫秒单位)
	 */
	long remainTime;
	/**
	 * 被抢次数
	 */
	int robbedCount;
	/**
	 * 车子id
	 */
	int toolId;
	/**
	 * 角色id
	 */
	long roleId;
	/**
	 * 被抢上限
	 */
	int robCount;
    
public:
    
    TransprotInfo(void){
    }
    
    ~TransprotInfo(void){
        const char *proRoleNameChar = proRoleName.c_str();
        CC_SAFE_DELETE_ARRAY(proRoleNameChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
        const char *toolNameChar = toolName.c_str();
        CC_SAFE_DELETE_ARRAY(toolNameChar);
	}
    
	/**
	 * 国家id
	 */
	int getCountryId() {
		return this->countryId;
	}
	/**
	 * 国家id
	 */
	void setCountryId(int countryId){
		this->countryId = countryId;
	}
	/**
	 * 抢劫获得银币
	 */
	int getRobSilver() {
		return this->robSilver;
	}
	/**
	 * 抢劫获得银币
	 */
	void setRobSilver(int robSilver){
		this->robSilver = robSilver;
	}
	/**
	 * 守护玩家获得军功
	 */
	int getProExploit() {
		return this->proExploit;
	}
	/**
	 * 守护玩家获得军功
	 */
	void setProExploit(int proExploit){
		this->proExploit = proExploit;
	}
	/**
	 * 运送获得银币
	 */
	int getSilver() {
		return this->silver;
	}
	/**
	 * 运送获得银币
	 */
	void setSilver(int silver){
		this->silver = silver;
	}
	/**
	 * 护送玩家名称
	 */
	std::string getProRoleName() {
		return this->proRoleName;
	}
	/**
	 * 护送玩家名称
	 */
	void setProRoleName(std::string proRoleName){
		this->proRoleName = proRoleName;
	}
	/**
	 * 角色名称
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 角色名称
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 车辆名称
	 */
	std::string getToolName() {
		return this->toolName;
	}
	/**
	 * 车辆名称
	 */
	void setToolName(std::string toolName){
		this->toolName = toolName;
	}
	/**
	 * 护送玩家id
	 */
	long getProRoleId() {
		return this->proRoleId;
	}
	/**
	 * 护送玩家id
	 */
	void setProRoleId(long proRoleId){
		this->proRoleId = proRoleId;
	}
	/**
	 * 运送获得军功
	 */
	int getExploit() {
		return this->exploit;
	}
	/**
	 * 运送获得军功
	 */
	void setExploit(int exploit){
		this->exploit = exploit;
	}
	/**
	 * 守护玩家获得银币
	 */
	int getProSilver() {
		return this->proSilver;
	}
	/**
	 * 守护玩家获得银币
	 */
	void setProSilver(int proSilver){
		this->proSilver = proSilver;
	}
	/**
	 * 玩家等级
	 */
	int getLevel() {
		return this->level;
	}
	/**
	 * 玩家等级
	 */
	void setLevel(int level){
		this->level = level;
	}
	/**
	 * 抢劫获得军功
	 */
	int getRobExploit() {
		return this->robExploit;
	}
	/**
	 * 抢劫获得军功
	 */
	void setRobExploit(int robExploit){
		this->robExploit = robExploit;
	}
	/**
	 * 运送剩余时间(毫秒单位)
	 */
	long getRemainTime() {
		return this->remainTime;
	}
	/**
	 * 运送剩余时间(毫秒单位)
	 */
	void setRemainTime(long remainTime){
		this->remainTime = remainTime;
	}
	/**
	 * 被抢次数
	 */
	int getRobbedCount() {
		return this->robbedCount;
	}
	/**
	 * 被抢次数
	 */
	void setRobbedCount(int robbedCount){
		this->robbedCount = robbedCount;
	}
	/**
	 * 车子id
	 */
	int getToolId() {
		return this->toolId;
	}
	/**
	 * 车子id
	 */
	void setToolId(int toolId){
		this->toolId = toolId;
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
	/**
	 * 被抢上限
	 */
	int getRobCount() {
		return this->robCount;
	}
	/**
	 * 被抢上限
	 */
	void setRobCount(int robCount){
		this->robCount = robCount;
	}

};

#endif
