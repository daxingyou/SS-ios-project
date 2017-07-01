//
//  JadeInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_JadeInfo_h
#define Lstx_cocos2dX_JadeInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class JadeInfo : public CCObject{

private:

	/**
	 * 玉石模板Id
	 */
	long jadeItemId;
	/**
	 * 玉石属性1:玉石属性值1:下限:上限:玉石档次|玉石属性2:玉石属性值2:下限:上限:玉石档次|玉石属性3:玉石属性值3:下限:上限:玉石档次
	 */
	std::string attributes;
	/**
	 * 玉石Id
	 */
	long jadeId;
    
public:
    
    JadeInfo(void){
    }
    
    ~JadeInfo(void){
        const char *attributesChar = attributes.c_str();
        CC_SAFE_DELETE_ARRAY(attributesChar);
	}
    
	/**
	 * 玉石模板Id
	 */
	long getJadeItemId() {
		return this->jadeItemId;
	}
	/**
	 * 玉石模板Id
	 */
	void setJadeItemId(long jadeItemId){
		this->jadeItemId = jadeItemId;
	}
	/**
	 * 玉石属性1:玉石属性值1:下限:上限:玉石档次|玉石属性2:玉石属性值2:下限:上限:玉石档次|玉石属性3:玉石属性值3:下限:上限:玉石档次
	 */
	std::string getAttributes() {
		return this->attributes;
	}
	/**
	 * 玉石属性1:玉石属性值1:下限:上限:玉石档次|玉石属性2:玉石属性值2:下限:上限:玉石档次|玉石属性3:玉石属性值3:下限:上限:玉石档次
	 */
	void setAttributes(std::string attributes){
		this->attributes = attributes;
	}
	/**
	 * 玉石Id
	 */
	long getJadeId() {
		return this->jadeId;
	}
	/**
	 * 玉石Id
	 */
	void setJadeId(long jadeId){
		this->jadeId = jadeId;
	}

};

#endif
