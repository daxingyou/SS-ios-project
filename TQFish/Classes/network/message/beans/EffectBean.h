//
//  EffectBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EffectBean_h
#define Lstx_cocos2dX_EffectBean_h

#include "cocos2d.h"
using namespace cocos2d;


class EffectBean : public CCObject{

private:

	/**
	 * 效果id
	 */
	int effectId;
	/**
	 * 效果值
	 */
	int effectValue;
	/**
	 * 虎符的buffId
	 */
	long buffId;
    
public:
    
    EffectBean(void){
    }
    
    ~EffectBean(void){
	}
    
	/**
	 * 效果id
	 */
	int getEffectId() {
		return this->effectId;
	}
	/**
	 * 效果id
	 */
	void setEffectId(int effectId){
		this->effectId = effectId;
	}
	/**
	 * 效果值
	 */
	int getEffectValue() {
		return this->effectValue;
	}
	/**
	 * 效果值
	 */
	void setEffectValue(int effectValue){
		this->effectValue = effectValue;
	}
	/**
	 * 虎符的buffId
	 */
	long getBuffId() {
		return this->buffId;
	}
	/**
	 * 虎符的buffId
	 */
	void setBuffId(long buffId){
		this->buffId = buffId;
	}

};

#endif
