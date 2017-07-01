//
//  NMBaseMessage.cpp
//  Lstx_cocos2dX
//
//  Created by xing chong on 8/16/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#include <iostream>
#include "NMBaseMessage.h"

NMBaseMessage::NMBaseMessage()
{
    byteBuffer = new ByteBuffer;
}

NMBaseMessage::NMBaseMessage(unsigned int capacity)
{
	byteBuffer = new ByteBuffer(capacity);
}

NMBaseMessage::~NMBaseMessage()
{
    delete byteBuffer;
}

void NMBaseMessage::setLength(short length)
{
     this->length = length;
}

void NMBaseMessage::setExtData(int extData)
{
    this->extData = extData;
}

void NMBaseMessage::setMsgVer(int msgVer)
{
    this->msgVer = msgVer;
}
int NMBaseMessage::getMessageType()
{
    return this->type;
}

const char * NMBaseMessage::getMessageName()
{
    return "";
}

bool NMBaseMessage::writeImpl()
{
    return true;
}

bool NMBaseMessage::readImpl() {
    
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    type = readRealInt();
    extData = readByte();
    msgVer = readByte();
    userID = readRealInt();
#endif
    
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
    //主版本
    type = readInt();
    extData = readByte();
    msgVer = readByte();
    userID = readInt();
#endif
    return true;
}

void NMBaseMessage::setMessageType(int type) {
    this->type = type;
}

bool NMBaseMessage::writeStart() {
    writeShort(0);//write data length
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    writeRealInt(getMessageType());//write message type
    writeByte(extData);
    writeByte(msgVer);
    writeRealInt(userID);
#endif
    
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
    //主版本
    writeInt(getMessageType());//write message type
    writeByte(extData);
    writeByte(msgVer);
    writeInt(userID);
#endif
    return true;
}

bool NMBaseMessage::writeOver() {
    length = byteBuffer->size();
    byteBuffer->setWritePos(0);
    byteBuffer->putShort(length);//put length
    return true;
}

bool NMBaseMessage::readStart()
{
    byteBuffer->setReadPos(0);
    readImpl();
    return true;
}

void NMBaseMessage::setReadPos(unsigned int r) {
    this->byteBuffer->setReadPos(r);
}

int NMBaseMessage::getReadPos() {
    return this->byteBuffer->getReadPos();
}




