//
//  ProvideInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ProvideInfo_h
#define Lstx_cocos2dX_ProvideInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class ProvideInfo : public CCObject{

private:

	/**
	 * 信息类型 1:属臣上供 2:讨好主公 3:领取 4:放弃属臣
	 */
	int type;
	/**
	 * 格式：属臣名称|时间|银币数量 ，时间|数量,时间|属臣名|数量,时间|属臣名
	 */
	std::string info;
    
public:
    
    ProvideInfo(void){
    }
    
    ~ProvideInfo(void){
        const char *infoChar = info.c_str();
        CC_SAFE_DELETE_ARRAY(infoChar);
	}
    
	/**
	 * 信息类型 1:属臣上供 2:讨好主公 3:领取 4:放弃属臣
	 */
	int getType() {
		return this->type;
	}
	/**
	 * 信息类型 1:属臣上供 2:讨好主公 3:领取 4:放弃属臣
	 */
	void setType(int type){
		this->type = type;
	}
	/**
	 * 格式：属臣名称|时间|银币数量 ，时间|数量,时间|属臣名|数量,时间|属臣名
	 */
	std::string getInfo() {
		return this->info;
	}
	/**
	 * 格式：属臣名称|时间|银币数量 ，时间|数量,时间|属臣名|数量,时间|属臣名
	 */
	void setInfo(std::string info){
		this->info = info;
	}

};

#endif
