//
//  SubBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_SubBean_h
#define Lstx_cocos2dX_SubBean_h

#include "cocos2d.h"
using namespace cocos2d;


class SubBean : public CCObject{

private:

	/**
	 * 最后上供银币数量
	 */
	int lastSilver;
	/**
	 * 上供总银币数量
	 */
	long sumSilver;
	/**
	 * 属臣等级
	 */
	int level;
	/**
	 * 最后上供季节
	 */
	int season;
	/**
	 * 地区名称
	 */
	std::string areaName;
	/**
	 * 属臣头像
	 */
	std::string image;
	/**
	 * 最后上供时间
	 */
	int year;
	/**
	 * 属臣名称
	 */
	std::string roleName;
	/**
	 * 是否能领取银币
	 */
	bool isGet;
	/**
	 * 官职名称
	 */
	std::string officialName;
	/**
	 * 军团名称
	 */
	std::string armyGroup;
	/**
	 * 属臣id
	 */
	long roleId;
    
public:
    
    SubBean(void){
    }
    
    ~SubBean(void){
        const char *areaNameChar = areaName.c_str();
        CC_SAFE_DELETE_ARRAY(areaNameChar);
        const char *imageChar = image.c_str();
        CC_SAFE_DELETE_ARRAY(imageChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
        const char *officialNameChar = officialName.c_str();
        CC_SAFE_DELETE_ARRAY(officialNameChar);
        const char *armyGroupChar = armyGroup.c_str();
        CC_SAFE_DELETE_ARRAY(armyGroupChar);
	}
    
	/**
	 * 最后上供银币数量
	 */
	int getLastSilver() {
		return this->lastSilver;
	}
	/**
	 * 最后上供银币数量
	 */
	void setLastSilver(int lastSilver){
		this->lastSilver = lastSilver;
	}
	/**
	 * 上供总银币数量
	 */
	long getSumSilver() {
		return this->sumSilver;
	}
	/**
	 * 上供总银币数量
	 */
	void setSumSilver(long sumSilver){
		this->sumSilver = sumSilver;
	}
	/**
	 * 属臣等级
	 */
	int getLevel() {
		return this->level;
	}
	/**
	 * 属臣等级
	 */
	void setLevel(int level){
		this->level = level;
	}
	/**
	 * 最后上供季节
	 */
	int getSeason() {
		return this->season;
	}
	/**
	 * 最后上供季节
	 */
	void setSeason(int season){
		this->season = season;
	}
	/**
	 * 地区名称
	 */
	std::string getAreaName() {
		return this->areaName;
	}
	/**
	 * 地区名称
	 */
	void setAreaName(std::string areaName){
		this->areaName = areaName;
	}
	/**
	 * 属臣头像
	 */
	std::string getImage() {
		return this->image;
	}
	/**
	 * 属臣头像
	 */
	void setImage(std::string image){
		this->image = image;
	}
	/**
	 * 最后上供时间
	 */
	int getYear() {
		return this->year;
	}
	/**
	 * 最后上供时间
	 */
	void setYear(int year){
		this->year = year;
	}
	/**
	 * 属臣名称
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 属臣名称
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 是否能领取银币
	 */
	bool getIsGet() {
		return this->isGet;
	}
	/**
	 * 是否能领取银币
	 */
	void setIsGet(bool isGet){
		this->isGet = isGet;
	}
	/**
	 * 官职名称
	 */
	std::string getOfficialName() {
		return this->officialName;
	}
	/**
	 * 官职名称
	 */
	void setOfficialName(std::string officialName){
		this->officialName = officialName;
	}
	/**
	 * 军团名称
	 */
	std::string getArmyGroup() {
		return this->armyGroup;
	}
	/**
	 * 军团名称
	 */
	void setArmyGroup(std::string armyGroup){
		this->armyGroup = armyGroup;
	}
	/**
	 * 属臣id
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 属臣id
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
