//
//  CampOrderBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampOrderBean_h
#define Lstx_cocos2dX_CampOrderBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampOrderBean : public CCObject{

private:

	/**
	 * 战役命令图片
	 */
	std::string campOrderImage;
	/**
	 * 战役命令y坐标
	 */
	int posY;
	/**
	 * 战役命令x坐标
	 */
	int posX;
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	int operationType;
	/**
	 * 战役命令id
	 */
	int campOrderId;
    
public:
    
    CampOrderBean(void){
    }
    
    ~CampOrderBean(void){
        const char *campOrderImageChar = campOrderImage.c_str();
        CC_SAFE_DELETE_ARRAY(campOrderImageChar);
	}
    
	/**
	 * 战役命令图片
	 */
	std::string getCampOrderImage() {
		return this->campOrderImage;
	}
	/**
	 * 战役命令图片
	 */
	void setCampOrderImage(std::string campOrderImage){
		this->campOrderImage = campOrderImage;
	}
	/**
	 * 战役命令y坐标
	 */
	int getPosY() {
		return this->posY;
	}
	/**
	 * 战役命令y坐标
	 */
	void setPosY(int posY){
		this->posY = posY;
	}
	/**
	 * 战役命令x坐标
	 */
	int getPosX() {
		return this->posX;
	}
	/**
	 * 战役命令x坐标
	 */
	void setPosX(int posX){
		this->posX = posX;
	}
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	int getOperationType() {
		return this->operationType;
	}
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	void setOperationType(int operationType){
		this->operationType = operationType;
	}
	/**
	 * 战役命令id
	 */
	int getCampOrderId() {
		return this->campOrderId;
	}
	/**
	 * 战役命令id
	 */
	void setCampOrderId(int campOrderId){
		this->campOrderId = campOrderId;
	}

};

#endif
