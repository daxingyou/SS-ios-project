//
//  OperateListInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_OperateListInfo_h
#define Lstx_cocos2dX_OperateListInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class OperateListInfo : public CCObject{

private:

	/**
	 * 内容
	 */
	std::string content;
	/**
	 * 领取状态
	 */
	int reward;
	/**
	 * 活动内部Id
	 */
	int OPA2_id;
	/**
	 * 参数
	 */
	std::string param;
	/**
	 * 颜色
	 */
	int color;
	/**
	 * 活动Id
	 */
	int OPA_id;
	/**
	 * 名字
	 */
	std::string name;
    
public:
    
    OperateListInfo(void){
    }
    
    ~OperateListInfo(void){
        const char *contentChar = content.c_str();
        CC_SAFE_DELETE_ARRAY(contentChar);
        const char *paramChar = param.c_str();
        CC_SAFE_DELETE_ARRAY(paramChar);
        const char *nameChar = name.c_str();
        CC_SAFE_DELETE_ARRAY(nameChar);
	}
    
	/**
	 * 内容
	 */
	std::string getContent() {
		return this->content;
	}
	/**
	 * 内容
	 */
	void setContent(std::string content){
		this->content = content;
	}
	/**
	 * 领取状态
	 */
	int getReward() {
		return this->reward;
	}
	/**
	 * 领取状态
	 */
	void setReward(int reward){
		this->reward = reward;
	}
	/**
	 * 活动内部Id
	 */
	int getOPA2_id() {
		return this->OPA2_id;
	}
	/**
	 * 活动内部Id
	 */
	void setOPA2_id(int OPA2_id){
		this->OPA2_id = OPA2_id;
	}
	/**
	 * 参数
	 */
	std::string getParam() {
		return this->param;
	}
	/**
	 * 参数
	 */
	void setParam(std::string param){
		this->param = param;
	}
	/**
	 * 颜色
	 */
	int getColor() {
		return this->color;
	}
	/**
	 * 颜色
	 */
	void setColor(int color){
		this->color = color;
	}
	/**
	 * 活动Id
	 */
	int getOPA_id() {
		return this->OPA_id;
	}
	/**
	 * 活动Id
	 */
	void setOPA_id(int OPA_id){
		this->OPA_id = OPA_id;
	}
	/**
	 * 名字
	 */
	std::string getName() {
		return this->name;
	}
	/**
	 * 名字
	 */
	void setName(std::string name){
		this->name = name;
	}

};

#endif
