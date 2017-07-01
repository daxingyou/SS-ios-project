//
//  MenuOnOffInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MenuOnOffInfo_h
#define Lstx_cocos2dX_MenuOnOffInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class MenuOnOffInfo : public CCObject{

private:

	/**
	 * onoff
	 */
	int onoff;
	/**
	 * theKey
	 */
	std::string theKey;
    
public:
    
    MenuOnOffInfo(void){
    }
    
    ~MenuOnOffInfo(void){
        const char *theKeyChar = theKey.c_str();
        CC_SAFE_DELETE_ARRAY(theKeyChar);
	}
    
	/**
	 * onoff
	 */
	int getOnoff() {
		return this->onoff;
	}
	/**
	 * onoff
	 */
	void setOnoff(int onoff){
		this->onoff = onoff;
	}
	/**
	 * theKey
	 */
	std::string getTheKey() {
		return this->theKey;
	}
	/**
	 * theKey
	 */
	void setTheKey(std::string theKey){
		this->theKey = theKey;
	}

};

#endif
