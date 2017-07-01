//
//  EscortOrderBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EscortOrderBean_h
#define Lstx_cocos2dX_EscortOrderBean_h

#include "cocos2d.h"
using namespace cocos2d;


class EscortOrderBean : public CCObject{

private:

	/**
	 * 运镖命令y坐标
	 */
	int posY;
	/**
	 * 运镖命令id
	 */
	int escortOrderId;
	/**
	 * 运镖命令x坐标
	 */
	int posX;
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	int operationType;
	/**
	 * 运镖命令图片
	 */
	std::string escortOrderImage;
    
public:
    
    EscortOrderBean(void){
    }
    
    ~EscortOrderBean(void){
        const char *escortOrderImageChar = escortOrderImage.c_str();
        CC_SAFE_DELETE_ARRAY(escortOrderImageChar);
	}
    
	/**
	 * 运镖命令y坐标
	 */
	int getPosY() {
		return this->posY;
	}
	/**
	 * 运镖命令y坐标
	 */
	void setPosY(int posY){
		this->posY = posY;
	}
	/**
	 * 运镖命令id
	 */
	int getEscortOrderId() {
		return this->escortOrderId;
	}
	/**
	 * 运镖命令id
	 */
	void setEscortOrderId(int escortOrderId){
		this->escortOrderId = escortOrderId;
	}
	/**
	 * 运镖命令x坐标
	 */
	int getPosX() {
		return this->posX;
	}
	/**
	 * 运镖命令x坐标
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
	 * 运镖命令图片
	 */
	std::string getEscortOrderImage() {
		return this->escortOrderImage;
	}
	/**
	 * 运镖命令图片
	 */
	void setEscortOrderImage(std::string escortOrderImage){
		this->escortOrderImage = escortOrderImage;
	}

};

#endif
