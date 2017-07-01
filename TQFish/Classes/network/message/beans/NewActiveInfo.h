//
//  NewActiveInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_NewActiveInfo_h
#define Lstx_cocos2dX_NewActiveInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class NewActiveInfo : public CCObject{

private:

	/**
	 * 活动限制   格式：（ 限制类型：限制条件;）
	 */
	std::string limit;
	/**
	 * 活动id 1001：运镖活动
	 */
	int id;
	/**
	 * 跨服战活动专用字段，表示跨服战状态。格式：主状态,子状态 状态位说明参照跨服战状态
	 */
	std::string status;
	/**
	 * 玩家可参与的活动总次数 -1表示无次数限制
	 */
	int totalTimes;
	/**
	 * 活动名称
	 */
	std::string name;
	/**
	 * 玩家剩余可参与的活动次数 -1表示无次数限制
	 */
	int leftTime;
	/**
	 * 活动开始时间
	 */
	std::string openTime;
	/**
	 * 活动图片
	 */
	std::string pic;
	/**
	 * 是否可以加入活动 0：可加入  1：未到活动时间  2:您还未加入国家 3:次数不够
	 */
	int canjoin;
	/**
	 * 活动结束事件
	 */
	std::string endTime;
	/**
	 * 活动文字描述
	 */
	std::string intro;
	/**
	 * 活动图片Tip
	 */
	std::string pic_intro;
    
public:
    
    NewActiveInfo(void){
    }
    
    ~NewActiveInfo(void){
        const char *limitChar = limit.c_str();
        CC_SAFE_DELETE_ARRAY(limitChar);
        const char *statusChar = status.c_str();
        CC_SAFE_DELETE_ARRAY(statusChar);
        const char *nameChar = name.c_str();
        CC_SAFE_DELETE_ARRAY(nameChar);
        const char *openTimeChar = openTime.c_str();
        CC_SAFE_DELETE_ARRAY(openTimeChar);
        const char *picChar = pic.c_str();
        CC_SAFE_DELETE_ARRAY(picChar);
        const char *endTimeChar = endTime.c_str();
        CC_SAFE_DELETE_ARRAY(endTimeChar);
        const char *introChar = intro.c_str();
        CC_SAFE_DELETE_ARRAY(introChar);
        const char *pic_introChar = pic_intro.c_str();
        CC_SAFE_DELETE_ARRAY(pic_introChar);
	}
    
	/**
	 * 活动限制   格式：（ 限制类型：限制条件;）
	 */
	std::string getLimit() {
		return this->limit;
	}
	/**
	 * 活动限制   格式：（ 限制类型：限制条件;）
	 */
	void setLimit(std::string limit){
		this->limit = limit;
	}
	/**
	 * 活动id 1001：运镖活动
	 */
	int getId() {
		return this->id;
	}
	/**
	 * 活动id 1001：运镖活动
	 */
	void setId(int id){
		this->id = id;
	}
	/**
	 * 跨服战活动专用字段，表示跨服战状态。格式：主状态,子状态 状态位说明参照跨服战状态
	 */
	std::string getStatus() {
		return this->status;
	}
	/**
	 * 跨服战活动专用字段，表示跨服战状态。格式：主状态,子状态 状态位说明参照跨服战状态
	 */
	void setStatus(std::string status){
		this->status = status;
	}
	/**
	 * 玩家可参与的活动总次数 -1表示无次数限制
	 */
	int getTotalTimes() {
		return this->totalTimes;
	}
	/**
	 * 玩家可参与的活动总次数 -1表示无次数限制
	 */
	void setTotalTimes(int totalTimes){
		this->totalTimes = totalTimes;
	}
	/**
	 * 活动名称
	 */
	std::string getName() {
		return this->name;
	}
	/**
	 * 活动名称
	 */
	void setName(std::string name){
		this->name = name;
	}
	/**
	 * 玩家剩余可参与的活动次数 -1表示无次数限制
	 */
	int getLeftTime() {
		return this->leftTime;
	}
	/**
	 * 玩家剩余可参与的活动次数 -1表示无次数限制
	 */
	void setLeftTime(int leftTime){
		this->leftTime = leftTime;
	}
	/**
	 * 活动开始时间
	 */
	std::string getOpenTime() {
		return this->openTime;
	}
	/**
	 * 活动开始时间
	 */
	void setOpenTime(std::string openTime){
		this->openTime = openTime;
	}
	/**
	 * 活动图片
	 */
	std::string getPic() {
		return this->pic;
	}
	/**
	 * 活动图片
	 */
	void setPic(std::string pic){
		this->pic = pic;
	}
	/**
	 * 是否可以加入活动 0：可加入  1：未到活动时间  2:您还未加入国家 3:次数不够
	 */
	int getCanjoin() {
		return this->canjoin;
	}
	/**
	 * 是否可以加入活动 0：可加入  1：未到活动时间  2:您还未加入国家 3:次数不够
	 */
	void setCanjoin(int canjoin){
		this->canjoin = canjoin;
	}
	/**
	 * 活动结束事件
	 */
	std::string getEndTime() {
		return this->endTime;
	}
	/**
	 * 活动结束事件
	 */
	void setEndTime(std::string endTime){
		this->endTime = endTime;
	}
	/**
	 * 活动文字描述
	 */
	std::string getIntro() {
		return this->intro;
	}
	/**
	 * 活动文字描述
	 */
	void setIntro(std::string intro){
		this->intro = intro;
	}
	/**
	 * 活动图片Tip
	 */
	std::string getPic_intro() {
		return this->pic_intro;
	}
	/**
	 * 活动图片Tip
	 */
	void setPic_intro(std::string pic_intro){
		this->pic_intro = pic_intro;
	}

};

#endif
