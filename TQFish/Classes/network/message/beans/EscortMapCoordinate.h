//
//  EscortMapCoordinate.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EscortMapCoordinate_h
#define Lstx_cocos2dX_EscortMapCoordinate_h

#include "cocos2d.h"
using namespace cocos2d;


class EscortMapCoordinate : public CCObject{

private:

	/**
	 * 地图格y坐标
	 */
	int posY;
	/**
	 * 地图格x坐标
	 */
	int posX;
	/**
	 * 地图格类型
	 */
	int type;
    
public:
    
    EscortMapCoordinate(void){
    }
    
    ~EscortMapCoordinate(void){
	}
    
	/**
	 * 地图格y坐标
	 */
	int getPosY() {
		return this->posY;
	}
	/**
	 * 地图格y坐标
	 */
	void setPosY(int posY){
		this->posY = posY;
	}
	/**
	 * 地图格x坐标
	 */
	int getPosX() {
		return this->posX;
	}
	/**
	 * 地图格x坐标
	 */
	void setPosX(int posX){
		this->posX = posX;
	}
	/**
	 * 地图格类型
	 */
	int getType() {
		return this->type;
	}
	/**
	 * 地图格类型
	 */
	void setType(int type){
		this->type = type;
	}

};

#endif
