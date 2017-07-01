//
//  CountyrWarInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CountyrWarInfo_h
#define Lstx_cocos2dX_CountyrWarInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class CountyrWarInfo : public CCObject{

private:

	/**
	 * 组队时间 y#s#hh:mm
	 */
	std::string time;
	/**
	 * 城市ID
	 */
	int cityId;
	/**
	 * 加入人数
	 */
	int roles;
	/**
	 * 加入状态 0:可以加入 ?0:不可加入，显示TIP
	 */
	int state;
	/**
	 * 攻击方 0:NPC 1:魏 2:蜀 3: 吴
	 */
	int attacker;
	/**
	 * 防守方 0:NPC 1:魏 2:蜀 3: 吴
	 */
	int defend;
	/**
	 * 类型 0:进攻 1:防守
	 */
	int type;
	/**
	 * 加入人数上限
	 */
	int rolesMax;
    
public:
    
    CountyrWarInfo(void){
    }
    
    ~CountyrWarInfo(void){
        const char *timeChar = time.c_str();
        CC_SAFE_DELETE_ARRAY(timeChar);
	}
    
	/**
	 * 组队时间 y#s#hh:mm
	 */
	std::string getTime() {
		return this->time;
	}
	/**
	 * 组队时间 y#s#hh:mm
	 */
	void setTime(std::string time){
		this->time = time;
	}
	/**
	 * 城市ID
	 */
	int getCityId() {
		return this->cityId;
	}
	/**
	 * 城市ID
	 */
	void setCityId(int cityId){
		this->cityId = cityId;
	}
	/**
	 * 加入人数
	 */
	int getRoles() {
		return this->roles;
	}
	/**
	 * 加入人数
	 */
	void setRoles(int roles){
		this->roles = roles;
	}
	/**
	 * 加入状态 0:可以加入 ?0:不可加入，显示TIP
	 */
	int getState() {
		return this->state;
	}
	/**
	 * 加入状态 0:可以加入 ?0:不可加入，显示TIP
	 */
	void setState(int state){
		this->state = state;
	}
	/**
	 * 攻击方 0:NPC 1:魏 2:蜀 3: 吴
	 */
	int getAttacker() {
		return this->attacker;
	}
	/**
	 * 攻击方 0:NPC 1:魏 2:蜀 3: 吴
	 */
	void setAttacker(int attacker){
		this->attacker = attacker;
	}
	/**
	 * 防守方 0:NPC 1:魏 2:蜀 3: 吴
	 */
	int getDefend() {
		return this->defend;
	}
	/**
	 * 防守方 0:NPC 1:魏 2:蜀 3: 吴
	 */
	void setDefend(int defend){
		this->defend = defend;
	}
	/**
	 * 类型 0:进攻 1:防守
	 */
	int getType() {
		return this->type;
	}
	/**
	 * 类型 0:进攻 1:防守
	 */
	void setType(int type){
		this->type = type;
	}
	/**
	 * 加入人数上限
	 */
	int getRolesMax() {
		return this->rolesMax;
	}
	/**
	 * 加入人数上限
	 */
	void setRolesMax(int rolesMax){
		this->rolesMax = rolesMax;
	}

};

#endif
