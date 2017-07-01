//
//  UserbuildingEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_UserbuildingEntity_h
#define Lstx_cocos2dX_UserbuildingEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class UserbuildingEntity : public CCObject{

private:

	/**
	 * 建筑ID
	 */
	int buildingid;
	/**
	 * 建筑等级
	 */
	int level;
    
public:
    
    UserbuildingEntity(void){
    }
    
    ~UserbuildingEntity(void){
	}
    
	/**
	 * 建筑ID
	 */
	int getBuildingid() {
		return this->buildingid;
	}
	/**
	 * 建筑ID
	 */
	void setBuildingid(int buildingid){
		this->buildingid = buildingid;
	}
	/**
	 * 建筑等级
	 */
	int getLevel() {
		return this->level;
	}
	/**
	 * 建筑等级
	 */
	void setLevel(int level){
		this->level = level;
	}

};

#endif
