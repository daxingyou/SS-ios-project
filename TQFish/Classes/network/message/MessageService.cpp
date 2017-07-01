#include "MessageService.h"

#include "ByteBuffer.h"
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include <netdb.h>
#endif

#include "cocos2d.h"
#include "tolua++.h"
#include "SevTCliNotification.h"
#include "NotificationEvent.h"
#include "NMBaseMessage.h"

using namespace std;
USING_NS_CC;

//int socketHandle=0;
//struct sockaddr_in their_addr;

//#define RECV_BUFF_SIZE 1024 * 8
#define RECV_BUFF_SIZE 1024 * 10

//byteT* const sendBuf       = new byteT[64*100];
byteT* const sendBuf = new byteT[1024 * 10];
byteT recvBuf[RECV_BUFF_SIZE];

static pthread_t ntid;
static pthread_t pid;

struct timeval timeout = {6,0};

bool isFristConnect = false;

/*
 消息是否暂停
 */
bool isPause = false;
//是否开始连接
bool isReconnect = false;
//是否是重连
bool isReconnection = false;
//是否的等待重联
bool isWaitReconnect = false;
//链接ip的指针
int ServiceIPIndex = -1;

MessageService::MessageService(void) {
	messageRecognize = new MessageRecognize;

	MessageRegister *messageRegister = new MessageRegister;
	messageRegister->registMessage(messageRecognize);
	delete messageRegister;

	byteBufferReceive = new ByteBuffer(1024);
	lastSendType = 0;
	lastSendTime = 0;
	curTime = time(0);
	cSocket = INVALID_SOCKET;
	serverCnt = 0;
	isCutOut = false;
	//重要消息
	importMessageCnt = 0;

    pthread_mutex_init(&lock,NULL);

	ODSocket::Init();

	startConnect();
	startReceiveMessage();
}

MessageService::~MessageService(void) {
	ODSocket::Clean();
}

void MessageService::init(const char* serverIp, unsigned short port) {
	serverIpArray[serverCnt] = (char*) serverIp;
	serverPortArray[serverCnt] = port;
	serverCnt++;
}

void MessageService::removeAllServerIp() {
	for (int i = 0; i < serverCnt; i++) {
		serverIpArray[i] = 0;
		serverPortArray[i] = 0;
	}
	serverCnt = 0;
}

void MessageService::setWaitReconnect(bool Wait) {
    isWaitReconnect = Wait;
}

void MessageService::setFristConnect(bool isFrist) {
	isFristConnect = isFrist;
}

void MessageService::connect() {

}

void MessageService::sendMessage(BaseMessage *baseMessage) {
    if (isWaitReconnect) {
        //等待重联时不发消息
        return;
    }
	if (baseMessage == NULL) {
		return;
	}

	curTime = time(0);
	if (lastSendType == baseMessage->getMessageType() && (curTime - lastSendTime < 0)) {
		return;
	}
	lastSendType = baseMessage->getMessageType();
	lastSendTime = curTime;
	short dataLength = baseMessage->getLength();

	CCLOG("send message: dataLength = %d ,type = %d", dataLength, baseMessage->getMessageType());

	if (dataLength <= 0) {
		return;
	}
	ByteBuffer *byteBuffer = baseMessage->getByteBuffer();
	int size = byteBuffer->size();
	if (size < dataLength) {
		return;
	}
	if (byteBuffer->getReadPos() != 0) {
		byteBuffer->setReadPos(0);
	}
	sendBuf[0] = 0;
	sendBuf[1] = 0;
	byteBuffer->getBytes(sendBuf, dataLength); //把msg放入byte数组
	if (sendBuf[0] == 0 && sendBuf[1] == 0) {
		return;
	}
	int sendResult = cSocket.Send(sendBuf, dataLength, 0); //send msg
	//CCLOG("send message: sendResult = %d ", sendResult);
	if (sendResult == -1) {
//		if (isFristConnect) {
//            //如果已经建立过连接
//            //CCLOG("MessageService::sendMessage() NETERR_NET_BROKEN!\n");
//            PublicLuaBridge::getInstance()->changeMessageServiceState(MessageType::NETERR_NET_BROKEN);
//		}
		return;
	}
}

//暂停消息
void MessageService::pauseSocket() {
	isPause = true;
}

//消息继续
void MessageService::resumeSocket() {
	isPause = false;
}

//是否切出游戏
void MessageService::setCutOut(bool iscoutout) {
	isCutOut = iscoutout;
}

//是否已经切出游戏
bool MessageService::getCutOut() {
	return isCutOut;
}

void MessageService::tickReceivedMessage() {
    pthread_mutex_lock(&lock);
	if (isPause || isWaitReconnect) {
		//暂停接收消息时，遍历重要消息序列，下发消息
		//CCLOG("暂停接收消息");
        if (!mMessageList.empty()) {
            for(list<NMBaseMessage*>::iterator iter = mMessageList.begin(); iter != mMessageList.end();)
            {
                bool isImport = false; //当先消息是否是重要消息
                for (int i = 0; i < importMessageCnt; i++) {
                    if ((*iter)->getMessageType() == importMessageList[i]) {
                        //是重要消息
                        //CCLOG("重要消息 getMessageType == %d", (*iter)->getMessageType());
                        NMBaseMessage * nMBaseMessage = NULL;
                        nMBaseMessage = (*iter);//取出第元素
                        if (nMBaseMessage) {
                            messageToScript(nMBaseMessage);
                        }
                        iter = mMessageList.erase(iter);
                        isImport = true;
                        break;
                    }
                }
                //CCLOG("mMessageList.size() == %lu", mMessageList.size());
                if(isImport)
                {
                    break;
                } else {
                    ++iter;
                }
            }
        }
        pthread_mutex_unlock(&lock);
        return;
	} else {
        if (!mMessageList.empty()) {
            //CCLOG("mMessageList.size() == %lu", mMessageList.size());
            NMBaseMessage * nMBaseMessage = NULL;
            list<NMBaseMessage*>::iterator iter = mMessageList.begin();
            nMBaseMessage = (*iter);//取出第元素
            mMessageList.erase(iter);
            //nMBaseMessage = mMessageList.front();//取出第一个元素
            //mMessageList.pop_front();//删除第一个元素
            //CCLOG("nMBaseMessage getMessageType == %d", nMBaseMessage->getMessageType());
            if (nMBaseMessage) {
                messageToScript(nMBaseMessage);
            }
        }
        pthread_mutex_unlock(&lock);
        return;
	}
}

short MessageService::receiveMessage(bool isReadLength, short dataLength) {
	if (cSocket.getSock() == INVALID_SOCKET) {
		return -1;
	}
	if (byteBufferReceive->getReadPos() != 0) {
		byteBufferReceive->setReadPos(0); //设置成未读状态
	}
	if (byteBufferReceive->getWritePos() != 0) {
		byteBufferReceive->setWritePos(0); //设置为未写状态
	}
	recvBuf[0] = 0;
	recvBuf[1] = 0;

	if (isReadLength) { //读取长度
		short padding = 2;
		while (padding > 0) {
			int retv = cSocket.Recv(recvBuf, padding, 0); //receive msg，可能会阻塞
			if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) {
				//Android平台的重连特殊处理
				if (isReconnection) {
					//如果是重连后的第一个消息
					isReconnection = false;
					if (recvBuf[0] + recvBuf[1] == 81) {
						//CCLOG("isReconnection重连...%d_%d\n\n", recvBuf[0], recvBuf[1]);
						retv = cSocket.Recv(recvBuf, padding, 0);
					}
				}
			}
			if (retv <= 0) {
				return 0;
			}
			byteBufferReceive->putBytes(recvBuf, padding);
			padding -= retv;
		}

		short length = byteBufferReceive->getShort();
		if (length > 2) {
			receiveMessage(false, length - 2);
		}
		return length;
	}

	NMBaseMessage * nMBaseMessage = new NMBaseMessage(dataLength);
	nMBaseMessage->setLength(dataLength + 2);
	short padding = dataLength;
	while (padding > 0) {
		int bytes2recv = padding > RECV_BUFF_SIZE ? RECV_BUFF_SIZE : padding;
		int retv = cSocket.Recv(recvBuf, bytes2recv, 0); //receive msg
		if (retv <= 0) {
			return 0;
		}
		nMBaseMessage->getByteBuffer()->putBytes(recvBuf, retv);
		padding -= retv;
	}
	nMBaseMessage->readImpl(); //读取消息类型

	if (nMBaseMessage->getByteBuffer()->size() < (unsigned int) (nMBaseMessage->getLength() - 2)) { //长度异常
		return 0;
	}

    pthread_mutex_lock(&lock);

    mMessageList.push_back(nMBaseMessage);
    //CCLOG("mMessageList push_back == %lu", mMessageList.size());

    pthread_mutex_unlock(&lock);

    return 0;
}

void * MessageService::runRecMsg(void *arg) {
	MessageService * messageService = (MessageService *) arg;
	while (true) {
		short length = messageService->receiveMessage(true, 2);
		if (length < 0) {
			usleep(100 * 1000);//100毫秒
		}else{
			usleep(10 * 1000);//10毫秒
		}
	}
	return (void *) 0;
}

char *get_ip_str(const struct sockaddr *sa, char *s, size_t maxlen)
{
    switch(sa->sa_family) {
        case AF_INET:
            inet_ntop(AF_INET, &(((struct sockaddr_in *)sa)->sin_addr), s, maxlen);
            break;
        case AF_INET6:
            inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)sa)->sin6_addr), s, maxlen);
            break;
        default:
            strncpy(s, "Unknown AF", maxlen);
            return NULL;
    }
    return s;
}


//解析域名中的IP地址
char* GetIPAddr(char* hostname) {

    char* ipAddr;
    struct addrinfo *result;
    struct addrinfo *res;
    char   buf[128];
    int error;

    /* resolve the domain name into a list of addresses */
    error = getaddrinfo(hostname, NULL, NULL, &result);
    if (error != 0)
    {
        CCLOG("error in getaddrinfo: %s", gai_strerror(error));
    }

    for (res = result; res != NULL; res = res->ai_next)
    {
        get_ip_str(res->ai_addr, buf, 128);
        CCLOG("hostname: %s", buf);
    }

    return ipAddr;
}

//解析域名中的IP地址
char* GetIPAddrForAndroid(char* hostname) {
    int nAdapter = 0;
    char* ipAddr;

    hostent* pHostEnt = gethostbyname(hostname);

    if (pHostEnt) {
        if (pHostEnt->h_addrtype == AF_INET) {
            CCLOG("[%s] Official name = [%s]", hostname, pHostEnt->h_name);

            while (pHostEnt->h_addr_list[nAdapter]) {
                in_addr *pAddr = (in_addr*) pHostEnt->h_addr_list[nAdapter];
                ipAddr = inet_ntoa(*pAddr);
                // pHostEnt->h_addr_list[nAdapter] -the current address in host order
                CCLOG("IP(%d):%s", nAdapter+1, ipAddr);
                nAdapter++;
            }
        }
    } else {
        CCLOG("解析主机地址失败============");
    }

    return ipAddr;
}

void MessageService::startReceiveMessage() {
	// 启动接收消息线程
	int result = pthread_create(&ntid, NULL, runRecMsg, this);

	if (result == 0) {
		CCLOG("receiveMessage thread running...");
	}
}

void* MessageService::start_thread(void *arg) {
	CCLOG("thread started...");
	MessageService * messageService = (MessageService *) arg;
	while (true) {
		if (isReconnect) {

            if (messageService->serverCnt == 0) {
                return (void *) 0;
            }

			srand(time(0));

            if (ServiceIPIndex == -1) {
                ServiceIPIndex = rand() % messageService->serverCnt;
            } else {
                ServiceIPIndex = (ServiceIPIndex+1) % messageService->serverCnt;
            }

			char* serverIp = messageService->serverIpArray[ServiceIPIndex];
            short port = messageService->serverPortArray[ServiceIPIndex];

            CCLOG("MessageService::connect() 建立连接 == (%d/%d) %s:%d", ServiceIPIndex, messageService->serverCnt, serverIp, (int) port + 65536);
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
            //Android解析域名
            serverIp = GetIPAddrForAndroid(serverIp);
            if (!serverIp) {
                PublicLuaBridge::getInstance()->changeMessageServiceState(MessageType::NETERR_CONN_FAILED);
                return (void *) 0;
            }
            // 初始化socket
            ODSocket cdSocket;
            cdSocket.Init();
            if (cdSocket.getSock() != INVALID_SOCKET) {
                messageService->closeSocket();
            }
            cdSocket.CreateForAndroid(AF_INET, SOCK_STREAM, 0);
            if (!cdSocket.ConnectForAndroid(serverIp, port)) {
                CCLOG("socket连接失败 == (%d/%d) %s:%d", ServiceIPIndex, messageService->serverCnt, serverIp, (int) port + 65536);
                PublicLuaBridge::getInstance()->changeMessageServiceState(MessageType::NETERR_CONN_FAILED);
            } else {
                CCLOG("socket连接成功 == (%d/%d) %s:%d", ServiceIPIndex, messageService->serverCnt, serverIp, (int) port + 65536);
                messageService->cSocket = cdSocket;
                //设置发送消息超时
                setsockopt(messageService->cSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&timeout,sizeof(struct timeval));
                //设置接收消息超时
                setsockopt(messageService->cSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(struct timeval));

                messageService->setCutOut(false);
                isReconnect = false;
                if (isFristConnect) {
                    isReconnection = true;
                } else {
                    isFristConnect = true;
                }
                PublicLuaBridge::getInstance()->changeMessageServiceState(MessageType::NETERR_CONN_SUCC);
            }
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
            //iOS解析域名
            struct addrinfo *result;

            /* resolve the domain name into a list of addresses */
            int error = getaddrinfo(serverIp, NULL, NULL, &result);
            if (error != 0)
            {
                CCLOG("error in getaddrinfo: %s", gai_strerror(error));
                return (void *) 0;
            }

            get_ip_str(result->ai_addr, serverIp, 128);//只取了返回的第一个ip
            CCLOG("解析域名 hostname: %s", serverIp);

            // 初始化socket
            ODSocket cdSocket;
            cdSocket.Init();
            if (cdSocket.getSock() != INVALID_SOCKET) {
                messageService->closeSocket();
            }
            cdSocket.Create(result->ai_addr, SOCK_STREAM, 0);
            if (!cdSocket.Connect(serverIp, port, result->ai_addr)) {
                CCLOG("socket连接失败 == (%d/%d) %s:%d", ServiceIPIndex, messageService->serverCnt, serverIp, (int) port + 65536);
                PublicLuaBridge::getInstance()->changeMessageServiceState(MessageType::NETERR_CONN_FAILED);
            } else {
                CCLOG("socket连接成功 == (%d/%d) %s:%d", ServiceIPIndex, messageService->serverCnt, serverIp, (int) port + 65536);
                messageService->cSocket = cdSocket;
                //设置发送消息超时
                setsockopt(messageService->cSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&timeout,sizeof(struct timeval));
                //设置接收消息超时
                setsockopt(messageService->cSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(struct timeval));

                messageService->setCutOut(false);
                isReconnect = false;
                if (isFristConnect) {
                    isReconnection = true;
                } else {
                    isFristConnect = true;
                }
                PublicLuaBridge::getInstance()->changeMessageServiceState(MessageType::NETERR_CONN_SUCC);
            }
#endif
        }
		usleep(1000 * 1000);	//1000毫秒
	}

	return (void *) 0;
}

void MessageService::startConnect() {
	int errCode = pthread_create(&pid, NULL, start_thread, this);

	if (errCode == 0) {
		CCLOG("Connect thread running...");
	}
}

void MessageService::reConnect() {
	isReconnect = true;
}

void MessageService::stopConnect() {
	isReconnect = false;
}

void MessageService::removeAllMessage() {
    mMessageList.clear();
}

void MessageService::closeSocket() {

	cSocket.Close();

	cSocket = INVALID_SOCKET;
}

/*
 消息的分发
 从c++通知给lua
 */
void MessageService::messageToScript(NMBaseMessage *nMBaseMessage) {
	SevTCliNotification* notification = SevTCliNotification::sharedNotification();
	CCDictionary *dictionary = CCDictionary::create();
	dictionary->setObject(nMBaseMessage, "baseMessage");
	dictionary->setObject(CCString::create("NMBaseMessage"), "className");
	//可以直接release 不用autorelease 省内存
	NotificationEvent *enent = NotificationEvent::createEvent("ServerMessage", dictionary);
	notification->sendEvent(enent);
	//CCLOG("nreceive message: dataLength = %d ,type = %d", nMBaseMessage->getLength(), nMBaseMessage->getMessageType());
}

void MessageService::socketError(int messageType) {
//	NMBaseMessage * nMBaseMessage = new NMBaseMessage();
//	nMBaseMessage->setMessageType(messageType);
//	this->messageToScript(nMBaseMessage);
    //delete nMBaseMessage;
}

void MessageService::messageToLua(int messageType) {
//	NMBaseMessage * nMBaseMessage = new NMBaseMessage();
//	nMBaseMessage->setMessageType(messageType);
//	this->messageToScript(nMBaseMessage);
    //delete nMBaseMessage;
}

//设置重要消息
//msgID 消息号
void MessageService::setImportMessage(int msgID) {
	importMessageList[importMessageCnt] = msgID;
	importMessageCnt++;
}
//id重要消息编号  0-1023
int MessageService::getImportMessage(int id) {
	return importMessageList[id];
}
