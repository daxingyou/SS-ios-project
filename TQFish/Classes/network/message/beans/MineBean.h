//
//  MineBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MineBean_h
#define Lstx_cocos2dX_MineBean_h

#include "cocos2d.h"
using namespace cocos2d;


class MineBean : public CCObject{

private:

	/**
	 * 占领结束时间
	 */
	int remain;
	/**
	 * 占领人员旗帜
	 */
	std::string roleFlag;
	/**
	 * 是否可以占领
	 */
	int canAttack;
	/**
	 * 占领开始时间
	 */
	std::string start;
	/**
	 * 占领人员等级
	 */
	int roleLevel;
	/**
	 * 占领人员姓名
	 */
	std::string roleName;
	/**
	 * 产量
	 */
	int output;
	/**
	 * 银矿ID
	 */
	int mineId;
	/**
	 * 占领人员ID
	 */
	long roleId;
    
public:
    
    MineBean(void){
    }
    
    ~MineBean(void){
        const char *roleFlagChar = roleFlag.c_str();
        CC_SAFE_DELETE_ARRAY(roleFlagChar);
        const char *startChar = start.c_str();
        CC_SAFE_DELETE_ARRAY(startChar);
        const char *roleNameChar = roleName.c_str();
        CC_SAFE_DELETE_ARRAY(roleNameChar);
	}
    
	/**
	 * 占领结束时间
	 */
	int getRemain() {
		return this->remain;
	}
	/**
	 * 占领结束时间
	 */
	void setRemain(int remain){
		this->remain = remain;
	}
	/**
	 * 占领人员旗帜
	 */
	std::string getRoleFlag() {
		return this->roleFlag;
	}
	/**
	 * 占领人员旗帜
	 */
	void setRoleFlag(std::string roleFlag){
		this->roleFlag = roleFlag;
	}
	/**
	 * 是否可以占领
	 */
	int getCanAttack() {
		return this->canAttack;
	}
	/**
	 * 是否可以占领
	 */
	void setCanAttack(int canAttack){
		this->canAttack = canAttack;
	}
	/**
	 * 占领开始时间
	 */
	std::string getStart() {
		return this->start;
	}
	/**
	 * 占领开始时间
	 */
	void setStart(std::string start){
		this->start = start;
	}
	/**
	 * 占领人员等级
	 */
	int getRoleLevel() {
		return this->roleLevel;
	}
	/**
	 * 占领人员等级
	 */
	void setRoleLevel(int roleLevel){
		this->roleLevel = roleLevel;
	}
	/**
	 * 占领人员姓名
	 */
	std::string getRoleName() {
		return this->roleName;
	}
	/**
	 * 占领人员姓名
	 */
	void setRoleName(std::string roleName){
		this->roleName = roleName;
	}
	/**
	 * 产量
	 */
	int getOutput() {
		return this->output;
	}
	/**
	 * 产量
	 */
	void setOutput(int output){
		this->output = output;
	}
	/**
	 * 银矿ID
	 */
	int getMineId() {
		return this->mineId;
	}
	/**
	 * 银矿ID
	 */
	void setMineId(int mineId){
		this->mineId = mineId;
	}
	/**
	 * 占领人员ID
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 占领人员ID
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}

};

#endif
