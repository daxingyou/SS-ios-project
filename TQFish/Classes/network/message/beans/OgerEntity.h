//
//  OgerEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_OgerEntity_h
#define Lstx_cocos2dX_OgerEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class OgerEntity : public CCObject{

private:

	/**
	 * ID
	 */
	int id;
	/**
	 * 参数
	 */
	int num;
    
public:
    
    OgerEntity(void){
    }
    
    ~OgerEntity(void){
	}
    
	/**
	 * ID
	 */
	int getId() {
		return this->id;
	}
	/**
	 * ID
	 */
	void setId(int id){
		this->id = id;
	}
	/**
	 * 参数
	 */
	int getNum() {
		return this->num;
	}
	/**
	 * 参数
	 */
	void setNum(int num){
		this->num = num;
	}

};

#endif
