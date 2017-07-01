//
//  CityAreaInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CityAreaInfo_h
#define Lstx_cocos2dX_CityAreaInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class CityAreaInfo : public CCObject{

private:

	/**
	 * 地区位置号
	 */
	int areaNum;
	/**
	 * 保护时间
	 */
	long saveTime;
	/**
	 * 城池样式图片
	 */
	std::string areaCityImg;
	/**
	 * 角色名称
	 */
	std::string roleName;
	/**
	 * 旗帜
	 */
	std::string roleShortName;
	/**
	 * 国家
	 */
	int nation;
	/**
	 * 角色ID
	 */
	long roleId;
    
public:
    
    CityAreaInfo(void){
    }
    
    ~CityAreaInfo(void){
        const char *areaCityImgChar = areaCityImg.c_str();
        CC_SAFE_DELETE_ARRAY(areaCityImgChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
        const char *roleShortNameChar = roleShortName.c_str();
        CC_SAFE_DELETE_ARRAY(roleShortNameChar);
	}
    
	/**
	 * 地区位置号
	 */
	int getAreaNum() {
		return this->areaNum;
	}
	/**
	 * 地区位置号
	 */
	void setAreaNum(int areaNum){
		this->areaNum = areaNum;
	}
	/**
	 * 保护时间
	 */
	long getSaveTime() {
		return this->saveTime;
	}
	/**
	 * 保护时间
	 */
	void setSaveTime(long saveTime){
		this->saveTime = saveTime;
	}
	/**
	 * 城池样式图片
	 */
	std::string getAreaCityImg() {
		return this->areaCityImg;
	}
	/**
	 * 城池样式图片
	 */
	void setAreaCityImg(std::string areaCityImg){
		this->areaCityImg = areaCityImg;
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
	 * 旗帜
	 */
	std::string getRoleShortName() {
		return this->roleShortName;
	}
	/**
	 * 旗帜
	 */
	void setRoleShortName(std::string roleShortName){
		this->roleShortName = roleShortName;
	}
	/**
	 * 国家
	 */
	int getNation() {
		return this->nation;
	}
	/**
	 * 国家
	 */
	void setNation(int nation){
		this->nation = nation;
	}
	/**
	 * 角色ID
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 角色ID
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
