//
//  RoleMerchantEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_RoleMerchantEntity_h
#define Lstx_cocos2dX_RoleMerchantEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class RoleMerchantEntity : public CCObject{

private:

	/**
	 * 商人Id
	 */
	int merchantId;
    
public:
    
    RoleMerchantEntity(void){
    }
    
    ~RoleMerchantEntity(void){
	}
    
	/**
	 * 商人Id
	 */
	int getMerchantId() {
		return this->merchantId;
	}
	/**
	 * 商人Id
	 */
	void setMerchantId(int merchantId){
		this->merchantId = merchantId;
	}

};

#endif
