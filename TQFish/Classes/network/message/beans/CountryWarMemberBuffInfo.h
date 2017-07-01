//
//  CountryWarMemberBuffInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_CountryWarMemberBuffInfo_h
#define Lstx_cocos2dX_CountryWarMemberBuffInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class CountryWarMemberBuffInfo : public CCObject{

private:

	/**
	 * 势如破竹
	 */
	int specialBuff_1;
	/**
	 * 振奋
	 */
	int specialBuff_2;
	/**
	 * cdId
	 */
	long cdId;
	/**
	 * 进攻方防守方 0:进攻 1:防守
	 */
	int attDef;
	/**
	 * 攻击Buff次数
	 */
	int attBuff;
	/**
	 * 防守Buff次数
	 */
	int defBuff;
	/**
	 * 固若金汤
	 */
	int fortBuff;
	/**
	 * 倾城之力
	 */
	int policy;
	/**
	 * 天时地利
	 */
	int specialBuff_4;
	/**
	 * 角色id
	 */
	long roleId;
	/**
	 * 旷日持久
	 */
	int specialBuff_3;
	/**
	 * 城下之盟
	 */
	int unionlBuff;
	/**
	 * cd
	 */
	long cd;
    
public:
    
    CountryWarMemberBuffInfo(void){
    }
    
    ~CountryWarMemberBuffInfo(void){
	}
    
	/**
	 * 势如破竹
	 */
	int getSpecialBuff_1() {
		return this->specialBuff_1;
	}
	/**
	 * 势如破竹
	 */
	void setSpecialBuff_1(int specialBuff_1){
		this->specialBuff_1 = specialBuff_1;
	}
	/**
	 * 振奋
	 */
	int getSpecialBuff_2() {
		return this->specialBuff_2;
	}
	/**
	 * 振奋
	 */
	void setSpecialBuff_2(int specialBuff_2){
		this->specialBuff_2 = specialBuff_2;
	}
	/**
	 * cdId
	 */
	long getCdId() {
		return this->cdId;
	}
	/**
	 * cdId
	 */
	void setCdId(long cdId){
		this->cdId = cdId;
	}
	/**
	 * 进攻方防守方 0:进攻 1:防守
	 */
	int getAttDef() {
		return this->attDef;
	}
	/**
	 * 进攻方防守方 0:进攻 1:防守
	 */
	void setAttDef(int attDef){
		this->attDef = attDef;
	}
	/**
	 * 攻击Buff次数
	 */
	int getAttBuff() {
		return this->attBuff;
	}
	/**
	 * 攻击Buff次数
	 */
	void setAttBuff(int attBuff){
		this->attBuff = attBuff;
	}
	/**
	 * 防守Buff次数
	 */
	int getDefBuff() {
		return this->defBuff;
	}
	/**
	 * 防守Buff次数
	 */
	void setDefBuff(int defBuff){
		this->defBuff = defBuff;
	}
	/**
	 * 固若金汤
	 */
	int getFortBuff() {
		return this->fortBuff;
	}
	/**
	 * 固若金汤
	 */
	void setFortBuff(int fortBuff){
		this->fortBuff = fortBuff;
	}
	/**
	 * 倾城之力
	 */
	int getPolicy() {
		return this->policy;
	}
	/**
	 * 倾城之力
	 */
	void setPolicy(int policy){
		this->policy = policy;
	}
	/**
	 * 天时地利
	 */
	int getSpecialBuff_4() {
		return this->specialBuff_4;
	}
	/**
	 * 天时地利
	 */
	void setSpecialBuff_4(int specialBuff_4){
		this->specialBuff_4 = specialBuff_4;
	}
	/**
	 * 角色id
	 */
	long getRoleId() {
		return this->roleId;
	}
	/**
	 * 角色id
	 */
	void setRoleId(long roleId){
		this->roleId = roleId;
	}
	/**
	 * 旷日持久
	 */
	int getSpecialBuff_3() {
		return this->specialBuff_3;
	}
	/**
	 * 旷日持久
	 */
	void setSpecialBuff_3(int specialBuff_3){
		this->specialBuff_3 = specialBuff_3;
	}
	/**
	 * 城下之盟
	 */
	int getUnionlBuff() {
		return this->unionlBuff;
	}
	/**
	 * 城下之盟
	 */
	void setUnionlBuff(int unionlBuff){
		this->unionlBuff = unionlBuff;
	}
	/**
	 * cd
	 */
	long getCd() {
		return this->cd;
	}
	/**
	 * cd
	 */
	void setCd(long cd){
		this->cd = cd;
	}

};

#endif
