//
//  CdShowBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CdShowBean_h
#define Lstx_cocos2dX_CdShowBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CdShowBean : public CCObject{

private:

	/**
	 * cd剩余时间 小于等于0为已结束
	 */
	long leavingTime;
	/**
	 * cdId
	 */
	long cdId;
    
public:
    
    CdShowBean(void){
    }
    
    ~CdShowBean(void){
	}
    
	/**
	 * cd剩余时间 小于等于0为已结束
	 */
	long getLeavingTime() {
		return this->leavingTime;
	}
	/**
	 * cd剩余时间 小于等于0为已结束
	 */
	void setLeavingTime(long leavingTime){
		this->leavingTime = leavingTime;
	}
	/**
	 * cdId
	 */
	long getCdId() {
		return this->cdId;
	}
	/**
	 * cdId
	 */
	void setCdId(long cdId){
		this->cdId = cdId;
	}

};

#endif
