//
//  GeneralInfoEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GeneralInfoEntity_h
#define Lstx_cocos2dX_GeneralInfoEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class GeneralInfoEntity : public CCObject{

private:

	/**
	 * 碎片个数
	 */
	int chipNum;
	/**
	 * 武将等级
	 */
	int generalLv;
	/**
	 * 武将Id
	 */
	int generalId;
    
public:
    
    GeneralInfoEntity(void){
    }
    
    ~GeneralInfoEntity(void){
	}
    
	/**
	 * 碎片个数
	 */
	int getChipNum() {
		return this->chipNum;
	}
	/**
	 * 碎片个数
	 */
	void setChipNum(int chipNum){
		this->chipNum = chipNum;
	}
	/**
	 * 武将等级
	 */
	int getGeneralLv() {
		return this->generalLv;
	}
	/**
	 * 武将等级
	 */
	void setGeneralLv(int generalLv){
		this->generalLv = generalLv;
	}
	/**
	 * 武将Id
	 */
	int getGeneralId() {
		return this->generalId;
	}
	/**
	 * 武将Id
	 */
	void setGeneralId(int generalId){
		this->generalId = generalId;
	}

};

#endif
