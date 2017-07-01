//
//  TransportWar.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_TransportWar_h
#define Lstx_cocos2dX_TransportWar_h

#include "cocos2d.h"
using namespace cocos2d;


class TransportWar : public CCObject{

private:

	/**
	 * 战报
	 */
	std::string report;
	/**
	 * 战报地址
	 */
	std::string url;
    
public:
    
    TransportWar(void){
    }
    
    ~TransportWar(void){
        const char *reportChar = report.c_str();
        CC_SAFE_DELETE_ARRAY(reportChar);
        const char *urlChar = url.c_str();
        CC_SAFE_DELETE_ARRAY(urlChar);
	}
    
	/**
	 * 战报
	 */
	std::string getReport() {
		return this->report;
	}
	/**
	 * 战报
	 */
	void setReport(std::string report){
		this->report = report;
	}
	/**
	 * 战报地址
	 */
	std::string getUrl() {
		return this->url;
	}
	/**
	 * 战报地址
	 */
	void setUrl(std::string url){
		this->url = url;
	}

};

#endif
