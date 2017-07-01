//
//  JadeAttribute.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_JadeAttribute_h
#define Lstx_cocos2dX_JadeAttribute_h

#include "cocos2d.h"
using namespace cocos2d;


class JadeAttribute : public CCObject{

private:

	/**
	 * 玉石属性
	 */
	long effectId;
	/**
	 * 属性值上限
	 */
	std::string upper;
	/**
	 * 批量洗练序号 0-7
	 */
	int batchPosition;
	/**
	 * 属性值下限
	 */
	std::string lower;
	/**
	 * 玉石属性值
	 */
	std::string ability;
	/**
	 * 玉石档次
	 */
	int jadeLevel;
	/**
	 * 玉石Id
	 */
	long jadeId;
    
public:
    
    JadeAttribute(void){
    }
    
    ~JadeAttribute(void){
        const char *upperChar = upper.c_str();
        CC_SAFE_DELETE_ARRAY(upperChar);
        const char *lowerChar = lower.c_str();
        CC_SAFE_DELETE_ARRAY(lowerChar);
        const char *abilityChar = ability.c_str();
        CC_SAFE_DELETE_ARRAY(abilityChar);
	}
    
	/**
	 * 玉石属性
	 */
	long getEffectId() {
		return this->effectId;
	}
	/**
	 * 玉石属性
	 */
	void setEffectId(long effectId){
		this->effectId = effectId;
	}
	/**
	 * 属性值上限
	 */
	std::string getUpper() {
		return this->upper;
	}
	/**
	 * 属性值上限
	 */
	void setUpper(std::string upper){
		this->upper = upper;
	}
	/**
	 * 批量洗练序号 0-7
	 */
	int getBatchPosition() {
		return this->batchPosition;
	}
	/**
	 * 批量洗练序号 0-7
	 */
	void setBatchPosition(int batchPosition){
		this->batchPosition = batchPosition;
	}
	/**
	 * 属性值下限
	 */
	std::string getLower() {
		return this->lower;
	}
	/**
	 * 属性值下限
	 */
	void setLower(std::string lower){
		this->lower = lower;
	}
	/**
	 * 玉石属性值
	 */
	std::string getAbility() {
		return this->ability;
	}
	/**
	 * 玉石属性值
	 */
	void setAbility(std::string ability){
		this->ability = ability;
	}
	/**
	 * 玉石档次
	 */
	int getJadeLevel() {
		return this->jadeLevel;
	}
	/**
	 * 玉石档次
	 */
	void setJadeLevel(int jadeLevel){
		this->jadeLevel = jadeLevel;
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
