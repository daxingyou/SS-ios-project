//
//  WorldCityInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_WorldCityInfo_h
#define Lstx_cocos2dX_WorldCityInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class WorldCityInfo : public CCObject{

private:

	/**
	 * 国家ID，表示这里的国家旗帜
	 */
	int countryID;
	/**
	 * 都城ID
	 */
	int cityID;
	/**
	 * 都城状态ID
	 */
	int cityStatusID;
    
public:
    
    WorldCityInfo(void){
    }
    
    ~WorldCityInfo(void){
	}
    
	/**
	 * 国家ID，表示这里的国家旗帜
	 */
	int getCountryID() {
		return this->countryID;
	}
	/**
	 * 国家ID，表示这里的国家旗帜
	 */
	void setCountryID(int countryID){
		this->countryID = countryID;
	}
	/**
	 * 都城ID
	 */
	int getCityID() {
		return this->cityID;
	}
	/**
	 * 都城ID
	 */
	void setCityID(int cityID){
		this->cityID = cityID;
	}
	/**
	 * 都城状态ID
	 */
	int getCityStatusID() {
		return this->cityStatusID;
	}
	/**
	 * 都城状态ID
	 */
	void setCityStatusID(int cityStatusID){
		this->cityStatusID = cityStatusID;
	}

};

#endif
