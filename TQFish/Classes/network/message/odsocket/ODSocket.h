/*
 * define file about portable socket class. 
 * description:this sock is suit both windows and linux
 * design:odison
 * e-mail:odison@126.com>
 * 
 */

#ifndef _ODSOCKET_H_
#define _ODSOCKET_H_

#include <stdio.h>
#include "ByteBuffer.h"
#include "cocos2d.h"
#ifdef WIN32
	#include <winsock2.h>
	#include <winsock.h>
	typedef int				socklen_t;
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	typedef int				SOCKET;

	//#pragma region define win32 const variable in linux
	#define INVALID_SOCKET	-1
	#define SOCKET_ERROR	-1
	//#pragma endregion
#endif


class ODSocket {

public:
	ODSocket(SOCKET sock = INVALID_SOCKET);
	~ODSocket();
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    //Android版本
    // Create socket object for snd/recv data
    bool CreateForAndroid(int af, int type, int protocol = 0);
    
    // Connect socket
    bool ConnectForAndroid(const char* ip, unsigned short port);
#endif
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    //iOS版本
    // Create socket object for snd/recv data
    bool Create(const struct sockaddr *sa, int type, int protocol = 0);
    
    // Connect socket
    bool Connect(const char* ip, unsigned short port, const struct sockaddr *sa);
#endif
    
	//#region server
	// Bind socket
	bool Bind(unsigned short port);

	// Listen socket
	bool Listen(int backlog = 5); 

	// Accept socket
	bool Accept(ODSocket& s, char* fromip = NULL);
	//#endregion
	
	// Send socket
	int Send(byteT* buf, int len, int flags = 0);

	// Recv socket
	int Recv(byteT* buf, int len, int flags = 0);
	
	// Close socket
	int Close();

	// Get errno
	int GetError();

	int getSock();
	
	//#pragma region just for win32
	// Init winsock DLL 
	static int Init();	
	// Clean winsock DLL
	static int Clean();
	//#pragma endregion

	// Domain parse
	static bool DnsParse(const char* domain, char* ip);

	ODSocket& operator = (SOCKET s);

	operator SOCKET ();

protected:
	SOCKET m_sock;

};

#pragma warning(disable:4996)

#endif
