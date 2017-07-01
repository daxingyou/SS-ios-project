//
//  GrilPanelInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GrilPanelInfo_h
#define Lstx_cocos2dX_GrilPanelInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class GrilPanelInfo : public CCObject{

private:

	/**
	 * 功能id 对应building.xls-building_function
	 */
	int id;
	/**
	 * 参数1 不同功能id对应显示的意义不同 具体顺序参照策划文档
	 */
	std::string param1;
	/**
	 * 参数2 不同功能id对应显示的意义不同 具体顺序参照策划文档
	 */
	std::string param2;
    
public:
    
    GrilPanelInfo(void){
    }
    
    ~GrilPanelInfo(void){
        const char *param1Char = param1.c_str();
        CC_SAFE_DELETE_ARRAY(param1Char);
        const char *param2Char = param2.c_str();
        CC_SAFE_DELETE_ARRAY(param2Char);
	}
    
	/**
	 * 功能id 对应building.xls-building_function
	 */
	int getId() {
		return this->id;
	}
	/**
	 * 功能id 对应building.xls-building_function
	 */
	void setId(int id){
		this->id = id;
	}
	/**
	 * 参数1 不同功能id对应显示的意义不同 具体顺序参照策划文档
	 */
	std::string getParam1() {
		return this->param1;
	}
	/**
	 * 参数1 不同功能id对应显示的意义不同 具体顺序参照策划文档
	 */
	void setParam1(std::string param1){
		this->param1 = param1;
	}
	/**
	 * 参数2 不同功能id对应显示的意义不同 具体顺序参照策划文档
	 */
	std::string getParam2() {
		return this->param2;
	}
	/**
	 * 参数2 不同功能id对应显示的意义不同 具体顺序参照策划文档
	 */
	void setParam2(std::string param2){
		this->param2 = param2;
	}

};

#endif
