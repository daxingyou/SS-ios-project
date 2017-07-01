//
//  QuestMainInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_QuestMainInfo_h
#define Lstx_cocos2dX_QuestMainInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class QuestMainInfo : public CCObject{

private:

	/**
	 * 任务状态
	 */
	bool status;
	/**
	 * 任务ID
	 */
	std::string questId;
    
public:
    
    QuestMainInfo(void){
    }
    
    ~QuestMainInfo(void){
        const char *questIdChar = questId.c_str();
        CC_SAFE_DELETE_ARRAY(questIdChar);
	}
    
	/**
	 * 任务状态
	 */
	bool getStatus() {
		return this->status;
	}
	/**
	 * 任务状态
	 */
	void setStatus(bool status){
		this->status = status;
	}
	/**
	 * 任务ID
	 */
	std::string getQuestId() {
		return this->questId;
	}
	/**
	 * 任务ID
	 */
	void setQuestId(std::string questId){
		this->questId = questId;
	}

};

#endif
