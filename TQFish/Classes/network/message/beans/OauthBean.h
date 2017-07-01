//
//  OauthBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_OauthBean_h
#define Lstx_cocos2dX_OauthBean_h

#include "cocos2d.h"
using namespace cocos2d;


class OauthBean : public CCObject{

private:

	/**
	 * 微博id
	 */
	int weiboid;
	/**
	 * 微博名称
	 */
	std::string weiboname;
	/**
	 * 绑定状态0:未绑定1绑定2:取消绑定
	 */
	int bind;
    
public:
    
    OauthBean(void){
    }
    
    ~OauthBean(void){
        const char *weibonameChar = weiboname.c_str();
        CC_SAFE_DELETE_ARRAY(weibonameChar);
	}
    
	/**
	 * 微博id
	 */
	int getWeiboid() {
		return this->weiboid;
	}
	/**
	 * 微博id
	 */
	void setWeiboid(int weiboid){
		this->weiboid = weiboid;
	}
	/**
	 * 微博名称
	 */
	std::string getWeiboname() {
		return this->weiboname;
	}
	/**
	 * 微博名称
	 */
	void setWeiboname(std::string weiboname){
		this->weiboname = weiboname;
	}
	/**
	 * 绑定状态0:未绑定1绑定2:取消绑定
	 */
	int getBind() {
		return this->bind;
	}
	/**
	 * 绑定状态0:未绑定1绑定2:取消绑定
	 */
	void setBind(int bind){
		this->bind = bind;
	}

};

#endif
