//
//  EscortItemBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EscortItemBean_h
#define Lstx_cocos2dX_EscortItemBean_h

#include "cocos2d.h"
using namespace cocos2d;


class EscortItemBean : public CCObject{

private:

	/**
	 * 运镖道具id
	 */
	int escortItemId;
	/**
	 * 道具y坐标
	 */
	int posY;
	/**
	 * 道具x坐标
	 */
	int posX;
	/**
	 * 操作类型  0:新增或者更新 1:删除  
	 */
	int operationType;
	/**
	 * 运镖道具是否显示
	 */
	bool isView;
	/**
	 * 运镖道具图片id
	 */
	std::string escortItemImageId;
	/**
	 * 运镖道具名称
	 */
	std::string escortItemName;
	/**
	 * 运镖道具tip
	 */
	std::string escortItemTipInfo;
    
public:
    
    EscortItemBean(void){
    }
    
    ~EscortItemBean(void){
        const char *escortItemImageIdChar = escortItemImageId.c_str();
        CC_SAFE_DELETE_ARRAY(escortItemImageIdChar);
        const char *escortItemNameChar = escortItemName.c_str();
        CC_SAFE_DELETE_ARRAY(escortItemNameChar);
        const char *escortItemTipInfoChar = escortItemTipInfo.c_str();
        CC_SAFE_DELETE_ARRAY(escortItemTipInfoChar);
	}
    
	/**
	 * 运镖道具id
	 */
	int getEscortItemId() {
		return this->escortItemId;
	}
	/**
	 * 运镖道具id
	 */
	void setEscortItemId(int escortItemId){
		this->escortItemId = escortItemId;
	}
	/**
	 * 道具y坐标
	 */
	int getPosY() {
		return this->posY;
	}
	/**
	 * 道具y坐标
	 */
	void setPosY(int posY){
		this->posY = posY;
	}
	/**
	 * 道具x坐标
	 */
	int getPosX() {
		return this->posX;
	}
	/**
	 * 道具x坐标
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
	 * 运镖道具是否显示
	 */
	bool getIsView() {
		return this->isView;
	}
	/**
	 * 运镖道具是否显示
	 */
	void setIsView(bool isView){
		this->isView = isView;
	}
	/**
	 * 运镖道具图片id
	 */
	std::string getEscortItemImageId() {
		return this->escortItemImageId;
	}
	/**
	 * 运镖道具图片id
	 */
	void setEscortItemImageId(std::string escortItemImageId){
		this->escortItemImageId = escortItemImageId;
	}
	/**
	 * 运镖道具名称
	 */
	std::string getEscortItemName() {
		return this->escortItemName;
	}
	/**
	 * 运镖道具名称
	 */
	void setEscortItemName(std::string escortItemName){
		this->escortItemName = escortItemName;
	}
	/**
	 * 运镖道具tip
	 */
	std::string getEscortItemTipInfo() {
		return this->escortItemTipInfo;
	}
	/**
	 * 运镖道具tip
	 */
	void setEscortItemTipInfo(std::string escortItemTipInfo){
		this->escortItemTipInfo = escortItemTipInfo;
	}

};

#endif
