//
//  BaseMessage.cpp
//  MyCocos2d-xApp
//
//  Created by xing chong on 7/16/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#include "BaseMessage.h"


BaseMessage::BaseMessage(void)
{
	this->available = true;
    this->userID = 0;
    this->msgVer = 0;
    this->extData = 1;
}

BaseMessage::~BaseMessage(void)
{
    //delete byteBuffer;
}

short BaseMessage::getLength()
{
    return this->length;
}

/**
 * 设置ByteBuffer
 */
void BaseMessage::setByteBuffer(ByteBuffer *byteBuffer){
    this->byteBuffer = byteBuffer;
}

/**
 * 取得ByteBuffer
 */
ByteBuffer* BaseMessage::getByteBuffer()
{
    return byteBuffer;
}

/**
 * 顶层写逻辑
 */
bool BaseMessage::write(){
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
    
    bool success = writeImpl();
    if (success) {
        length = byteBuffer->size();
        byteBuffer->setWritePos(0);
        byteBuffer->putShort(length);//put length
        return true;
    }
    return false;
}

/**
 * 顶层读逻辑
 */
bool BaseMessage::read(){
    length = readShort();
    
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

    return readImpl();
}




//read date from byteBuffer
short  BaseMessage::readByte(){
	if(!checkData(1)){
		return 0;
	}
	short temp = this->byteBuffer->get();
    return temp;
}

bool   BaseMessage::readBool(){
	if(!checkData(2)){
		return false;
	}
    if(this->byteBuffer->getShort()==1){
        return true;
    }else {
        return false;
    }
}

short  BaseMessage::readShort(){
	if(!checkData(2)){
		return 0;
	}
    return this->byteBuffer->getShort();
}

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
//联运版本
int BaseMessage::readRealInt(){
    if(!checkData(4)){
        return 0;
    }
    return this->byteBuffer->getInt();
}

std::string BaseMessage::readInt(){
    if(!checkData(8)){
        return "0";
    }
    std::stringstream ss;
    ss<<(this->byteBuffer->getLong());
    return ss.str();
}
#endif

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
//主版本
int BaseMessage::readInt(){
    if(!checkData(4)){
        return 0;
    }
    return this->byteBuffer->getInt();
}
#endif

std::string BaseMessage::readLong() {
	if(!checkData(8)){
		return "0";
	}
    std::stringstream ss;
    ss<<(this->byteBuffer->getLong());
    return ss.str();
}

double BaseMessage::readDouble() {
	if(!checkData(8)){
		return 0;
	}
    return this->byteBuffer->getDouble();
}

float  BaseMessage::readFloat(){
	if(!checkData(4)){
		return 0;
	}
    return this->byteBuffer->getFloat();
}

//std::string UnicodeToUTF8(std::string & _srcStr)
//
//{
//    const unsigned char* pchar = (const unsigned char *)_srcStr.c_str();
//    std::string strResult;
//    int nLen = _srcStr.length();
//    strResult.reserve( nLen + nLen/2);
//    int cp1 = *(pchar);
//    int cp2 = *(++pchar);
//    int i = 0;
//
//    while( i++ < nLen/2 )
//    {
//        if(cp1 == 0 && cp2 < 0x80)     //ascii
//        {
//            strResult += (char)cp2;
//        }
//        else if(cp1 < 0x08)                   // unicode 2 bytes to utf-8 2 bytes
//        {
//            strResult += (char)(0xC0 | ((cp1 & 0x07) << 2)) + ((cp2 & 0xC0) >> 6);
//            strResult += (char)(0x80 | (cp2 & 0x3F));
//        }
//        else                          // unicode 2 bytes to utf-8 3bytes , escape more than 3 bytes
//        {
//            strResult += (char)(0xE0 | ((cp1 & 0xF0) >> 4));
//            strResult += (char)(0x80 | ((cp1 & 0x0F) << 2)) + ((cp2 & 0xC0) >> 6);
//            strResult += (char)(0x80 | ( cp2 & 0x3F));
//        }
//        cp1 = *(++pchar);
//        cp2 = *(++pchar);
//    }
//    return strResult;
//}

void string_replace(std::string&s1,const std::string&s2,const std::string&s3)
{
    std::string::size_type pos=0;
    std::string::size_type a=s2.size();
    std::string::size_type b=s3.size();
    while((pos=s1.find(s2,pos))!=std::string::npos)
    {
        s1.replace(pos,a,s3);
        pos+=b;
    }
}

std::string BaseMessage::readString(){
	short readPos = this->byteBuffer->getReadPos();
	short dataSize   = this->byteBuffer->size();
    short size = this->byteBuffer->getShort();
	if(size<=0){
		return "";
	}
	if(!checkData(size)){
		return "";
	}
    std::stringstream ss;
    byteT* dt = (byteT*)malloc(size * 3 / 2);
    memset(dt, 0, size * 3 / 2);
    this->byteBuffer->getBytes(dt, size);

    //如果是SmallEndian，则转序
    if (dt[0] == '\xfe')
    {
        for (int i=0; i<size; i++)
        {
            byteT tmp = dt[i];
            dt[i] = dt[i+1];
            dt[i+1] = tmp;
            i++;
        }
    }

    for (int i=0; i<size; i++) {
		if (dt[i] == '\xff' || dt[i] == '\xfe') {
            if(i < 2) {
                continue;
            }
        }
        int n = dt[i];
        n = n < 0 ? 256 + n : n;
        if (n <= 0x80 && (int)dt[i + 1] == 0x00) {
            ss << (byteT)(dt[i]);
            i++;
            continue;
        }
		//发现中文
        if (i >= size - 1) {
            //没有两个字节，一定是出错了。
            continue;
        }
        //开始吧Unicode转位UTF8
        //先处理BigEdian
        byteT bt2 = dt[i];
        byteT bt1 = dt[i+1];
        i++;
        //
        ss << (byteT)(0xe0 | ((bt1 >> 4) & 0x0f));
        ss << (byteT)(0x80 | ((bt1 & 0x0f) << 2) | ((bt2 >> 6) & 0x03));
        ss << (byteT)(0x80 | (bt2 & 0x3f));
    }
    std::string s = ss.str();
    free(dt);
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    string_replace(s,"同趣棋牌","疯狂棋牌");
    string_replace(s,"同趣","疯狂棋牌");
#endif
    return s;
}
std::string BaseMessage::readUTF(){
    short size = this->byteBuffer->getShort();
	if(size<=0){
		return "";
	}
	if(!checkData(size)){
		return "";
	}
    std::stringstream ss;
    for (int i=0; i<size; i++) {
		ss<<(this->byteBuffer->get());
    }
    std::string s = ss.str();
#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
    //联运版本
    string_replace(s,"同趣棋牌","疯狂棋牌");
    string_replace(s,"同趣","疯狂棋牌");
#endif
    return s;
}
//write data to byteBuffer
void BaseMessage::writeByte(short data){
    this->byteBuffer->put((byteT)data);
}

void BaseMessage::writeBool(bool data){
    if(data){
        this->byteBuffer->putShort(1);
    }else {
        this->byteBuffer->putShort(0);
    }
}

void BaseMessage::writeShort(short data){
    this->byteBuffer->putShort(data);
}

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_LIANYUN_GAME
//联运版本
void BaseMessage::writeInt(std::string *data){
    // string to number
    long long number;
    std::stringstream ss(*data);
    ss>>number;
    // longlong  to high and low
    int high = number>>32;
    int low = (number & 0xFFFFFFFF);
    this->byteBuffer->putInt(high);
    this->byteBuffer->putInt(low);
}

void BaseMessage::writeRealInt(int data){
    this->byteBuffer->putInt(data);
}
#endif

#if TQ_TARGET_PLATFORM == TQ_PLATFORM_MAIN_GAME
//主版本
void BaseMessage::writeInt(int data){
    this->byteBuffer->putInt(data);
}
#endif

void BaseMessage::writeLong(std::string *data){
    // string to number
    long long number;
    std::stringstream ss(*data);
    ss>>number;
    // longlong  to high and low
    int high = number>>32;
    int low = (number & 0xFFFFFFFF);
    this->byteBuffer->putInt(high);
    this->byteBuffer->putInt(low);
}

void BaseMessage::writeDouble(double data){
    this->byteBuffer->putDouble(data);
}

void BaseMessage::writeFloat(float data){
    this->byteBuffer->putFloat(data);
}

void BaseMessage::writeString(byteT * data, int length){
    this->byteBuffer->putShort(length);
    for (int i=0; i< length; i++) {
        this->byteBuffer->put(data[i]);
    }
}

void BaseMessage::writeString(std::string *data){

    int length = data->length();

    byteT* dt = (byteT*)malloc(length * 2);
    int pos = 0;

    int i = 0;
    //如果有BOM头
    if (length >= 3 && data->at(0) == '\xef' && data->at(1) == '\xbb' && data->at(2) == '\xbf') {
        i = 3;
    }
    for (; i<length; i++) {
        byteT d = data->at(i);
        //如果是英文
        int n = (int)d;
        n = n < 0 ? 256 + n : n;
        if ((int)n <= 0x80) {
            dt[pos++] = '\x00';
            dt[pos++] = n;
            continue;
        }
        //如果是中文
        byteT n1 = d;
        byteT n2 = data->at(i+1);
        byteT n3 = data->at(i+2);
        i += 2;
        //开始转码为unicode
        byteT u1 = ((n1 & 0x0f) << 4) | ((n2 >> 2) & 0x0f);
        byteT u2 = ((n2 & 0x03) << 6) | (n3 & 0x3f);
        dt[pos++] = u1;
        dt[pos++] = u2;

    }

    this->byteBuffer->putShort(pos);
    for (int i=0; i<pos; i++) {
        this->byteBuffer->put(dt[i]);
    }
    free(dt);
}

void BaseMessage::writeUTF(std::string *data){
    int length = data->length();
    this->byteBuffer->putShort(length);
    for (int i=0; i<length; i++) {
        this->byteBuffer->put(data->at(i));
    }
}

bool BaseMessage::checkData(int dataLength){
	if(!this->available){
		return this->available;
	}
	int readPos = this->byteBuffer->getReadPos();
	int bufferLength = this->byteBuffer->size();
	this->available = (bufferLength-readPos)>=dataLength;
	if(this->available){
		return true;
	}else{
		return false;
	}
}


void BaseMessage::setAvailable(bool available){
	this->available = available;
}

bool BaseMessage::isAvailable(){
	return this->available;
}
void BaseMessage::setReadPos(unsigned int r) {
    this->byteBuffer->setReadPos(r);
}

int BaseMessage::getReadPos() {
    return this->byteBuffer->getReadPos();
}
