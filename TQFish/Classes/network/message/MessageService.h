//#pragma once


#ifndef MyCocos2d_xApp_MessageService_h
#define MyCocos2d_xApp_MessageService_h

#include "stdafx.h"
#include "ODSocket.h"
#include "BaseMessage.h"
#include "MessageRecognize.h"
#include "MessageRegister.h"
#include "MessageType.h"
#include "NMBaseMessage.h"
#include <list>

#include "cocos2d.h"
#include "PublicLuaBridge.h"
#include <queue>
#include <pthread.h>

class MessageService
{
private:
    MessageRecognize * messageRecognize;
    ByteBuffer *byteBufferReceive;
    short lastSendType;
    long  lastSendTime;
    time_t curTime;
    pthread_mutex_t lock; 
    //是否切出游戏
    bool isCutOut;

	ODSocket cSocket;

    //可连接的服务器数量
    short serverCnt;
    char* serverIpArray[255];
    short serverPortArray[255];

	//重要消息
	int importMessageCnt;
	int importMessageList[1024];

	//volatile bool reveivePolicy;

    //reveive message
    short receiveMessage(bool isReadLength, short dataLength);

	static void* start_thread(void *);

    static void *runRecMsg(void *arg);

	void messageToScript(NMBaseMessage * nMBaseMessage);

	void socketError(int messageType);
    
public:
	MessageService(void);
	~MessageService(void);

    //init message service
    void init(const char* serverIp, unsigned short port);
    //remove message service
    void removeAllServerIp();
    
    void setWaitReconnect(bool Wait);
    
    void setFristConnect(bool isFrist);

    void connect();

	// main thread tick here to solve the received message
	void tickReceivedMessage();

    //send message
    void sendMessage(BaseMessage * baseMessage);

	//startReceiveMessage
    void startReceiveMessage();

	void reConnect();

	void stopConnect();

	void startConnect();

    //remove All Message
    void removeAllMessage();

	//close socket
	void closeSocket();

    //pause socket暂停socket
    void pauseSocket();

    //resume socket重新开始socket
    void resumeSocket();

    //设置是否是切出后返回
    void setCutOut(bool iscutout);

    //设置是否是切出后返回
    bool getCutOut();

	//发送数据到lua层
	void messageToLua(int messageType);

	//设置重要消息
	void setImportMessage(int msgID);
    
    //
	int getImportMessage(int id);
    
    list<NMBaseMessage*> mMessageList;
};

#endif
