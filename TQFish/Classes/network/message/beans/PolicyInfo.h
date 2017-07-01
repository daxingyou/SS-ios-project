//
//  PolicyInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_PolicyInfo_h
#define Lstx_cocos2dX_PolicyInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class PolicyInfo : public CCObject{

private:

	/**
	 * 领取状态 0-可领取，1-领取次数已满，2-粮食已满，3-银币已满，4-军令已满
	 */
	int actionState;
	/**
	 * 开启状态 0-可开启,1-已开启，2-不可开启
	 */
	int openState;
	/**
	 * 政策id
	 */
	int policyId;
    
public:
    
    PolicyInfo(void){
    }
    
    ~PolicyInfo(void){
	}
    
	/**
	 * 领取状态 0-可领取，1-领取次数已满，2-粮食已满，3-银币已满，4-军令已满
	 */
	int getActionState() {
		return this->actionState;
	}
	/**
	 * 领取状态 0-可领取，1-领取次数已满，2-粮食已满，3-银币已满，4-军令已满
	 */
	void setActionState(int actionState){
		this->actionState = actionState;
	}
	/**
	 * 开启状态 0-可开启,1-已开启，2-不可开启
	 */
	int getOpenState() {
		return this->openState;
	}
	/**
	 * 开启状态 0-可开启,1-已开启，2-不可开启
	 */
	void setOpenState(int openState){
		this->openState = openState;
	}
	/**
	 * 政策id
	 */
	int getPolicyId() {
		return this->policyId;
	}
	/**
	 * 政策id
	 */
	void setPolicyId(int policyId){
		this->policyId = policyId;
	}

};

#endif
