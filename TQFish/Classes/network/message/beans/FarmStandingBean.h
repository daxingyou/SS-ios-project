//
//  FarmStandingBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_FarmStandingBean_h
#define Lstx_cocos2dX_FarmStandingBean_h

#include "cocos2d.h"
using namespace cocos2d;


class FarmStandingBean : public CCObject{

private:

	/**
	 * 占领剩余时间
	 */
	long remainTime;
	/**
	 * 农场ID
	 */
	int farmId;
    
public:
    
    FarmStandingBean(void){
    }
    
    ~FarmStandingBean(void){
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
	 * 农场ID
	 */
	int getFarmId() {
		return this->farmId;
	}
	/**
	 * 农场ID
	 */
	void setFarmId(int farmId){
		this->farmId = farmId;
	}

};

#endif
