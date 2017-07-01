//
//  EscortTroopBufferBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_EscortTroopBufferBean_h
#define Lstx_cocos2dX_EscortTroopBufferBean_h

#include "cocos2d.h"
using namespace cocos2d;


class EscortTroopBufferBean : public CCObject{

private:

	/**
	 * 部队状态剩余时间
	 */
	long bufferRemainTime;
	/**
	 * 部队状态类型 1:buffer  2:debuffer
	 */
	int bufferType;
	/**
	 * 部队状态Id
	 */
	int bufferId;
	/**
	 * 部队状态到期时间
	 */
	long bufferFinishTime;
	/**
	 * 部队状态图片id
	 */
	std::string bufferImage;
	/**
	 * 部队Id
	 */
	std::string escortTroopId;
	/**
	 * 部队状态名称
	 */
	std::string bufferName;
    
public:
    
    EscortTroopBufferBean(void){
    }
    
    ~EscortTroopBufferBean(void){
        const char *bufferImageChar = bufferImage.c_str();
        CC_SAFE_DELETE_ARRAY(bufferImageChar);
        const char *escortTroopIdChar = escortTroopId.c_str();
        CC_SAFE_DELETE_ARRAY(escortTroopIdChar);
        const char *bufferNameChar = bufferName.c_str();
        CC_SAFE_DELETE_ARRAY(bufferNameChar);
	}
    
	/**
	 * 部队状态剩余时间
	 */
	long getBufferRemainTime() {
		return this->bufferRemainTime;
	}
	/**
	 * 部队状态剩余时间
	 */
	void setBufferRemainTime(long bufferRemainTime){
		this->bufferRemainTime = bufferRemainTime;
	}
	/**
	 * 部队状态类型 1:buffer  2:debuffer
	 */
	int getBufferType() {
		return this->bufferType;
	}
	/**
	 * 部队状态类型 1:buffer  2:debuffer
	 */
	void setBufferType(int bufferType){
		this->bufferType = bufferType;
	}
	/**
	 * 部队状态Id
	 */
	int getBufferId() {
		return this->bufferId;
	}
	/**
	 * 部队状态Id
	 */
	void setBufferId(int bufferId){
		this->bufferId = bufferId;
	}
	/**
	 * 部队状态到期时间
	 */
	long getBufferFinishTime() {
		return this->bufferFinishTime;
	}
	/**
	 * 部队状态到期时间
	 */
	void setBufferFinishTime(long bufferFinishTime){
		this->bufferFinishTime = bufferFinishTime;
	}
	/**
	 * 部队状态图片id
	 */
	std::string getBufferImage() {
		return this->bufferImage;
	}
	/**
	 * 部队状态图片id
	 */
	void setBufferImage(std::string bufferImage){
		this->bufferImage = bufferImage;
	}
	/**
	 * 部队Id
	 */
	std::string getEscortTroopId() {
		return this->escortTroopId;
	}
	/**
	 * 部队Id
	 */
	void setEscortTroopId(std::string escortTroopId){
		this->escortTroopId = escortTroopId;
	}
	/**
	 * 部队状态名称
	 */
	std::string getBufferName() {
		return this->bufferName;
	}
	/**
	 * 部队状态名称
	 */
	void setBufferName(std::string bufferName){
		this->bufferName = bufferName;
	}

};

#endif
