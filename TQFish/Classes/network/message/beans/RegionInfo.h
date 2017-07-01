//
//  RegionInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_RegionInfo_h
#define Lstx_cocos2dX_RegionInfo_h

#include "cocos2d.h"
#include "BaseMessage.h"

using namespace cocos2d;


class RegionInfo : public CCObject{

private:

	/**
	 * 是否已经开放
	 */
	bool open;
	/**
	 * 占领标志
	 */
	std::string flag;
	/**
	 * 坐标
	 */
	int coordinate;
	/**
	 * 占领势力 0-无 1-魏 2-蜀 4-吴
	 */
	byteT force;
    
public:
    
    RegionInfo(void){
    }
    
    ~RegionInfo(void){
        const char *flagChar = flag.c_str();
        CC_SAFE_DELETE_ARRAY(flagChar);
	}
    
	/**
	 * 是否已经开放
	 */
	bool getOpen() {
		return this->open;
	}
	/**
	 * 是否已经开放
	 */
	void setOpen(bool open){
		this->open = open;
	}
	/**
	 * 占领标志
	 */
	std::string getFlag() {
		return this->flag;
	}
	/**
	 * 占领标志
	 */
	void setFlag(std::string flag){
		this->flag = flag;
	}
	/**
	 * 坐标
	 */
	int getCoordinate() {
		return this->coordinate;
	}
	/**
	 * 坐标
	 */
	void setCoordinate(int coordinate){
		this->coordinate = coordinate;
	}
	/**
	 * 占领势力 0-无 1-魏 2-蜀 4-吴
	 */
	byteT getForce() {
		return this->force;
	}
	/**
	 * 占领势力 0-无 1-魏 2-蜀 4-吴
	 */
	void setForce(byteT force){
		this->force = force;
	}

};

#endif
