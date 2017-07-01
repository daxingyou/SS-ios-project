//
//  MineStandingBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MineStandingBean_h
#define Lstx_cocos2dX_MineStandingBean_h

#include "cocos2d.h"
using namespace cocos2d;


class MineStandingBean : public CCObject{

private:

	/**
	 * 地区
	 */
	int area;
	/**
	 * 占领剩余时间
	 */
	long remainTime;
	/**
	 * 银矿ID
	 */
	int mineId;
    
public:
    
    MineStandingBean(void){
    }
    
    ~MineStandingBean(void){
	}
    
	/**
	 * 地区
	 */
	int getArea() {
		return this->area;
	}
	/**
	 * 地区
	 */
	void setArea(int area){
		this->area = area;
	}
	/**
	 * 占领剩余时间
	 */
	long getRemainTime() {
		return this->remainTime;
	}
	/**
	 * 占领剩余时间
	 */
	void setRemainTime(long remainTime){
		this->remainTime = remainTime;
	}
	/**
	 * 银矿ID
	 */
	int getMineId() {
		return this->mineId;
	}
	/**
	 * 银矿ID
	 */
	void setMineId(int mineId){
		this->mineId = mineId;
	}

};

#endif
