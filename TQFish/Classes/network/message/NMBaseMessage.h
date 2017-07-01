//
//  NMBaseMessage.h
//  Lstx_cocos2dX
//
//  Created by xing chong on 8/16/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_NMBaseMessage_h
#define Lstx_cocos2dX_NMBaseMessage_h

#include "BaseMessage.h"

class NMBaseMessage:public BaseMessage
{
    
public:
    NMBaseMessage();
	NMBaseMessage(unsigned int capacity);
    ~NMBaseMessage();
    
	/**
     * 消息长度
     */
	virtual void setLength(short length);

    /**
     * 消息类型
     */
    virtual int getMessageType();

    /**
     * extData
     */
	virtual void setExtData(int extData);
    /**
     * msgVer
     */
	virtual void setMsgVer(int msgVer);
    
    /**
     * 消息名字
     */
    virtual const char * getMessageName();
    
    /**
     * 子类待实现写逻辑
     */
    virtual bool writeImpl();
    
    /**
     * 子类待实现读逻辑
     */
    virtual bool readImpl();
    
    /**
     * 设置消息type
     */
    virtual void setMessageType(int type);
    
    /**
     * lua写数据前
     */
    virtual bool writeStart();
    
    /**
     * lua写数据后
     */
    virtual bool writeOver();
    
    /**
     * lua读数据前
     */
    virtual bool readStart();
    
    
    
    virtual void setReadPos(unsigned int r);
	virtual int getReadPos();
	
};

#endif
