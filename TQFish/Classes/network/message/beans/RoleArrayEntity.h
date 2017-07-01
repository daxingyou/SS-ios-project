//
//  RoleArrayEntity.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_RoleArrayEntity_h
#define Lstx_cocos2dX_RoleArrayEntity_h

#include "cocos2d.h"
using namespace cocos2d;


class RoleArrayEntity : public CCObject{

private:

	/**
	 * 4号位武将
	 */
	int seat4;
	/**
	 * 3号位武将
	 */
	int seat3;
	/**
	 * 2号位武将
	 */
	int seat2;
	/**
	 * 1号位武将
	 */
	int seat1;
	/**
	 * 7号位武将
	 */
	int seat7;
	/**
	 * 8号位武将
	 */
	int seat8;
	/**
	 * 5号位武将
	 */
	int seat5;
	/**
	 * 阵型ID
	 */
	long arrayid;
	/**
	 * 6号位武将
	 */
	int seat6;
	/**
	 * 9号位武将
	 */
	int seat9;
	/**
	 * 是否默认阵型
	 */
	int defaultArray;
    
public:
    
    RoleArrayEntity(void){
    }
    
    ~RoleArrayEntity(void){
	}
    
	/**
	 * 4号位武将
	 */
	int getSeat4() {
		return this->seat4;
	}
	/**
	 * 4号位武将
	 */
	void setSeat4(int seat4){
		this->seat4 = seat4;
	}
	/**
	 * 3号位武将
	 */
	int getSeat3() {
		return this->seat3;
	}
	/**
	 * 3号位武将
	 */
	void setSeat3(int seat3){
		this->seat3 = seat3;
	}
	/**
	 * 2号位武将
	 */
	int getSeat2() {
		return this->seat2;
	}
	/**
	 * 2号位武将
	 */
	void setSeat2(int seat2){
		this->seat2 = seat2;
	}
	/**
	 * 1号位武将
	 */
	int getSeat1() {
		return this->seat1;
	}
	/**
	 * 1号位武将
	 */
	void setSeat1(int seat1){
		this->seat1 = seat1;
	}
	/**
	 * 7号位武将
	 */
	int getSeat7() {
		return this->seat7;
	}
	/**
	 * 7号位武将
	 */
	void setSeat7(int seat7){
		this->seat7 = seat7;
	}
	/**
	 * 8号位武将
	 */
	int getSeat8() {
		return this->seat8;
	}
	/**
	 * 8号位武将
	 */
	void setSeat8(int seat8){
		this->seat8 = seat8;
	}
	/**
	 * 5号位武将
	 */
	int getSeat5() {
		return this->seat5;
	}
	/**
	 * 5号位武将
	 */
	void setSeat5(int seat5){
		this->seat5 = seat5;
	}
	/**
	 * 阵型ID
	 */
	long getArrayid() {
		return this->arrayid;
	}
	/**
	 * 阵型ID
	 */
	void setArrayid(long arrayid){
		this->arrayid = arrayid;
	}
	/**
	 * 6号位武将
	 */
	int getSeat6() {
		return this->seat6;
	}
	/**
	 * 6号位武将
	 */
	void setSeat6(int seat6){
		this->seat6 = seat6;
	}
	/**
	 * 9号位武将
	 */
	int getSeat9() {
		return this->seat9;
	}
	/**
	 * 9号位武将
	 */
	void setSeat9(int seat9){
		this->seat9 = seat9;
	}
	/**
	 * 是否默认阵型
	 */
	int getDefaultArray() {
		return this->defaultArray;
	}
	/**
	 * 是否默认阵型
	 */
	void setDefaultArray(int defaultArray){
		this->defaultArray = defaultArray;
	}

};

#endif
