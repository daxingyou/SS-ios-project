//
//  QuestDayInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_QuestDayInfo_h
#define Lstx_cocos2dX_QuestDayInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class QuestDayInfo : public CCObject{

private:

	/**
	 * 完成次数
	 */
	int times;
	/**
	 * 任务状态
	 */
	bool status;
	/**
	 * 立即完成消耗金币
	 */
	long dgold;
	/**
	 * 任务ID
	 */
	std::string questId;
    
public:
    
    QuestDayInfo(void){
    }
    
    ~QuestDayInfo(void){
        const char *questIdChar = questId.c_str();
        CC_SAFE_DELETE_ARRAY(questIdChar);
	}
    
	/**
	 * 完成次数
	 */
	int getTimes() {
		return this->times;
	}
	/**
	 * 完成次数
	 */
	void setTimes(int times){
		this->times = times;
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
	 * 立即完成消耗金币
	 */
	long getDgold() {
		return this->dgold;
	}
	/**
	 * 立即完成消耗金币
	 */
	void setDgold(long dgold){
		this->dgold = dgold;
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
