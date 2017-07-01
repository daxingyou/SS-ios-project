//
//  ArmyMember.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ArmyMember_h
#define Lstx_cocos2dX_ArmyMember_h

#include "cocos2d.h"
using namespace cocos2d;


class ArmyMember : public CCObject{

private:

	/**
	 * 人员头像
	 */
	std::string roleImg;
	/**
	 * 离线类型
	 */
	int offLine;
	/**
	 * 城市ID
	 */
	long cityId;
	/**
	 * 留言
	 */
	std::string Message;
	/**
	 * 人员等级
	 */
	int roleLv;
	/**
	 * 提升职位  0：表示可用，1 表示贡献不足，2表示贡献排名不够，3 若是要提升为军团长但军团长三天内有上线 4军团长
	 */
	int memberLvup;
	/**
	 * 城市名称
	 */
	std::string cityName;
	/**
	 * 官职
	 */
	std::string dutyName;
	/**
	 * 待批人员姓名
	 */
	std::string roleName;
	/**
	 * 地区位置
	 */
	int areaSite;
	/**
	 * 贡献值排名
	 */
	int contributionRank;
	/**
	 * 提升职位  0：表示可开除，1 表示不可开除
	 */
	int kickMember;
	/**
	 * 军团职位
	 */
	int armyDuty;
	/**
	 * 可显示金矿入口
	 */
	bool canGoldMine;
	/**
	 * 贡献值
	 */
	long contribution;
	/**
	 * 军团职位名称
	 */
	std::string armyDutyName;
	/**
	 * 待批人员ID
	 */
	long roleId;
    
public:
    
    ArmyMember(void){
    }
    
    ~ArmyMember(void){
        const char *roleImgChar = roleImg.c_str();
        CC_SAFE_DELETE_ARRAY(roleImgChar);
        const char *MessageChar = Message.c_str();
        CC_SAFE_DELETE_ARRAY(MessageChar);
        const char *cityNameChar = cityName.c_str();
        CC_SAFE_DELETE_ARRAY(cityNameChar);
        const char *dutyNameChar = dutyName.c_str();
        CC_SAFE_DELETE_ARRAY(dutyNameChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
        const char *armyDutyNameChar = armyDutyName.c_str();
        CC_SAFE_DELETE_ARRAY(armyDutyNameChar);
	}
    
	/**
	 * 人员头像
	 */
	std::string getRoleImg() {
		return this->roleImg;
	}
	/**
	 * 人员头像
	 */
	void setRoleImg(std::string roleImg){
		this->roleImg = roleImg;
	}
	/**
	 * 离线类型
	 */
	int getOffLine() {
		return this->offLine;
	}
	/**
	 * 离线类型
	 */
	void setOffLine(int offLine){
		this->offLine = offLine;
	}
	/**
	 * 城市ID
	 */
	long getCityId() {
		return this->cityId;
	}
	/**
	 * 城市ID
	 */
	void setCityId(long cityId){
		this->cityId = cityId;
	}
	/**
	 * 留言
	 */
	std::string getMessage() {
		return this->Message;
	}
	/**
	 * 留言
	 */
	void setMessage(std::string Message){
		this->Message = Message;
	}
	/**
	 * 人员等级
	 */
	int getRoleLv() {
		return this->roleLv;
	}
	/**
	 * 人员等级
	 */
	void setRoleLv(int roleLv){
		this->roleLv = roleLv;
	}
	/**
	 * 提升职位  0：表示可用，1 表示贡献不足，2表示贡献排名不够，3 若是要提升为军团长但军团长三天内有上线 4军团长
	 */
	int getMemberLvup() {
		return this->memberLvup;
	}
	/**
	 * 提升职位  0：表示可用，1 表示贡献不足，2表示贡献排名不够，3 若是要提升为军团长但军团长三天内有上线 4军团长
	 */
	void setMemberLvup(int memberLvup){
		this->memberLvup = memberLvup;
	}
	/**
	 * 城市名称
	 */
	std::string getCityName() {
		return this->cityName;
	}
	/**
	 * 城市名称
	 */
	void setCityName(std::string cityName){
		this->cityName = cityName;
	}
	/**
	 * 官职
	 */
	std::string getDutyName() {
		return this->dutyName;
	}
	/**
	 * 官职
	 */
	void setDutyName(std::string dutyName){
		this->dutyName = dutyName;
	}
	/**
	 * 待批人员姓名
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 待批人员姓名
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 地区位置
	 */
	int getAreaSite() {
		return this->areaSite;
	}
	/**
	 * 地区位置
	 */
	void setAreaSite(int areaSite){
		this->areaSite = areaSite;
	}
	/**
	 * 贡献值排名
	 */
	int getContributionRank() {
		return this->contributionRank;
	}
	/**
	 * 贡献值排名
	 */
	void setContributionRank(int contributionRank){
		this->contributionRank = contributionRank;
	}
	/**
	 * 提升职位  0：表示可开除，1 表示不可开除
	 */
	int getKickMember() {
		return this->kickMember;
	}
	/**
	 * 提升职位  0：表示可开除，1 表示不可开除
	 */
	void setKickMember(int kickMember){
		this->kickMember = kickMember;
	}
	/**
	 * 军团职位
	 */
	int getArmyDuty() {
		return this->armyDuty;
	}
	/**
	 * 军团职位
	 */
	void setArmyDuty(int armyDuty){
		this->armyDuty = armyDuty;
	}
	/**
	 * 可显示金矿入口
	 */
	bool getCanGoldMine() {
		return this->canGoldMine;
	}
	/**
	 * 可显示金矿入口
	 */
	void setCanGoldMine(bool canGoldMine){
		this->canGoldMine = canGoldMine;
	}
	/**
	 * 贡献值
	 */
	long getContribution() {
		return this->contribution;
	}
	/**
	 * 贡献值
	 */
	void setContribution(long contribution){
		this->contribution = contribution;
	}
	/**
	 * 军团职位名称
	 */
	std::string getArmyDutyName() {
		return this->armyDutyName;
	}
	/**
	 * 军团职位名称
	 */
	void setArmyDutyName(std::string armyDutyName){
		this->armyDutyName = armyDutyName;
	}
	/**
	 * 待批人员ID
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 待批人员ID
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
