//
//  ReportResult.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_ReportResult_h
#define Lstx_cocos2dX_ReportResult_h

#include "cocos2d.h"
using namespace cocos2d;


class ReportResult : public CCObject{

private:

	/**
	 * 角色等级
	 */
	int level;
	/**
	 * 角色名称
	 */
	std::string name;
	/**
	 * 角色国家名称
	 */
	std::string nation;
	/**
	 * 战报url
	 */
	std::string url;
    
public:
    
    ReportResult(void){
    }
    
    ~ReportResult(void){
        const char *nameChar = name.c_str();
        CC_SAFE_DELETE_ARRAY(nameChar);
        const char *nationChar = nation.c_str();
        CC_SAFE_DELETE_ARRAY(nationChar);
        const char *urlChar = url.c_str();
        CC_SAFE_DELETE_ARRAY(urlChar);
	}
    
	/**
	 * 角色等级
	 */
	int getLevel() {
		return this->level;
	}
	/**
	 * 角色等级
	 */
	void setLevel(int level){
		this->level = level;
	}
	/**
	 * 角色名称
	 */
	std::string getName() {
		return this->name;
	}
	/**
	 * 角色名称
	 */
	void setName(std::string name){
		this->name = name;
	}
	/**
	 * 角色国家名称
	 */
	std::string getNation() {
		return this->nation;
	}
	/**
	 * 角色国家名称
	 */
	void setNation(std::string nation){
		this->nation = nation;
	}
	/**
	 * 战报url
	 */
	std::string getUrl() {
		return this->url;
	}
	/**
	 * 战报url
	 */
	void setUrl(std::string url){
		this->url = url;
	}

};

#endif
