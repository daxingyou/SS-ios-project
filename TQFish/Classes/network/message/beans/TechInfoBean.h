//
//  TechInfoBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_TechInfoBean_h
#define Lstx_cocos2dX_TechInfoBean_h

#include "cocos2d.h"
using namespace cocos2d;


class TechInfoBean : public CCObject{

private:

	/**
	 * 科技Id
	 */
	int techId;
	/**
	 * 显示冷却时间单位毫秒
	 */
	long showCdTime;
	/**
	 * 科技级别
	 */
	int techLv;
    
public:
    
    TechInfoBean(void){
    }
    
    ~TechInfoBean(void){
	}
    
	/**
	 * 科技Id
	 */
	int getTechId() {
		return this->techId;
	}
	/**
	 * 科技Id
	 */
	void setTechId(int techId){
		this->techId = techId;
	}
	/**
	 * 显示冷却时间单位毫秒
	 */
	long getShowCdTime() {
		return this->showCdTime;
	}
	/**
	 * 显示冷却时间单位毫秒
	 */
	void setShowCdTime(long showCdTime){
		this->showCdTime = showCdTime;
	}
	/**
	 * 科技级别
	 */
	int getTechLv() {
		return this->techLv;
	}
	/**
	 * 科技级别
	 */
	void setTechLv(int techLv){
		this->techLv = techLv;
	}

};

#endif
