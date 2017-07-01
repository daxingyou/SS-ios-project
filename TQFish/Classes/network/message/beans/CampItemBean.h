//
//  CampItemBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CampItemBean_h
#define Lstx_cocos2dX_CampItemBean_h

#include "cocos2d.h"
using namespace cocos2d;


class CampItemBean : public CCObject{

private:

	/**
	 * 战役道具图片id
	 */
	std::string campItemImageId;
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
	 * 战役道具是否显示
	 */
	bool isView;
	/**
	 * 战役道具id
	 */
	int campItemId;
	/**
	 * 战役道具tip
	 */
	std::string campItemTipInfo;
	/**
	 * 战役道具名称
	 */
	std::string campItemName;
    
public:
    
    CampItemBean(void){
    }
    
    ~CampItemBean(void){
        const char *campItemImageIdChar = campItemImageId.c_str();
        CC_SAFE_DELETE_ARRAY(campItemImageIdChar);
        const char *campItemTipInfoChar = campItemTipInfo.c_str();
        CC_SAFE_DELETE_ARRAY(campItemTipInfoChar);
        const char *campItemNameChar = campItemName.c_str();
        CC_SAFE_DELETE_ARRAY(campItemNameChar);
	}
    
	/**
	 * 战役道具图片id
	 */
	std::string getCampItemImageId() {
		return this->campItemImageId;
	}
	/**
	 * 战役道具图片id
	 */
	void setCampItemImageId(std::string campItemImageId){
		this->campItemImageId = campItemImageId;
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
	 * 战役道具是否显示
	 */
	bool getIsView() {
		return this->isView;
	}
	/**
	 * 战役道具是否显示
	 */
	void setIsView(bool isView){
		this->isView = isView;
	}
	/**
	 * 战役道具id
	 */
	int getCampItemId() {
		return this->campItemId;
	}
	/**
	 * 战役道具id
	 */
	void setCampItemId(int campItemId){
		this->campItemId = campItemId;
	}
	/**
	 * 战役道具tip
	 */
	std::string getCampItemTipInfo() {
		return this->campItemTipInfo;
	}
	/**
	 * 战役道具tip
	 */
	void setCampItemTipInfo(std::string campItemTipInfo){
		this->campItemTipInfo = campItemTipInfo;
	}
	/**
	 * 战役道具名称
	 */
	std::string getCampItemName() {
		return this->campItemName;
	}
	/**
	 * 战役道具名称
	 */
	void setCampItemName(std::string campItemName){
		this->campItemName = campItemName;
	}

};

#endif
