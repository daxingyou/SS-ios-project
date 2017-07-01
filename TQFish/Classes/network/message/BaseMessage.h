//
//  BaseMessage.h
//  MyCocos2d-xApp
//
//  Created by xing chong on 7/3/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef MyCocos2d_xApp_BaseMessage_h
#define MyCocos2d_xApp_BaseMessage_h

#include "ByteBuffer.h"
#include "cocos2d.h"
#include "PublicLuaBridge.h"
USING_NS_CC;

class BaseMessage : public CCObject 
{
    
public:
    
    BaseMessage(void);
	~BaseMessage(void);
    
    /**
     * 消息类型
     */
    virtual int getMessageType()=0;
    
    /**
     * 消息名字
     */
    virtual const char * getMessageName()=0;
    
    /**
     * 子类待实现写逻辑
     */
    virtual bool writeImpl()=0;
    
    /**
     * 子类待实现读逻辑
     */
    virtual bool readImpl()=0;

    /**
     * 消息长度
     */
    short getLength();
    
    /**
     * 设置ByteBuffer
     */
    void setByteBuffer(ByteBuffer *byteBuffer);
    
    /**
     * 取得ByteBuffer
     */
    ByteBuffer * getByteBuffer();
    
    /**
     * 顶层写逻辑
     */
    bool write();
    
    /**
     * 顶层读逻辑
     */
    bool read();

public:
    //read date from byteBuffer
    short  readByte();
    bool   readBool();
    short  readShort();
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    std::string readInt();//实际上读取的是long
    int    readRealInt();
#endif

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
    //主版本
    int    readInt();
#endif
    std::string readLong();
    
    double readDouble();
    float  readFloat();
    std::string readString();
	 //读取UTF8字符串
    std::string readUTF();
    
    //write data to byteBuffer
    void writeByte(short data);
    void writeBool(bool data);
    void writeShort(short data);
    
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    void writeInt(std::string *data);//实际上发送的是long
    void writeRealInt(int data);
#endif
    
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
    //主版本
    void writeInt(int data);
#endif
    
    void writeLong(std::string *data);
    void writeDouble(double data);
    void writeFloat(float data);
    void writeString(byteT *data, int length);
    void writeString(std::string *data);
    void writeUTF(std::string *data);

	virtual void setAvailable(bool available);
	virtual bool isAvailable();
    
    virtual void setReadPos(unsigned int r);
	virtual int getReadPos();

private:
	virtual bool checkData(int dataLength);
    
protected:
    ByteBuffer *byteBuffer;
    
    short length;
    int type;
    byteT extData;
    byteT msgVer;
    int userID;
    
    

private :
	bool available;
    
};



#endif
