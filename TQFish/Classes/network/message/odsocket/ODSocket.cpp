//#include "StdAfx.h"
#include "ODSocket.h"
#include "cocos2d.h"

#ifdef WIN32
	#pragma comment(lib, "wsock32")
#endif


ODSocket::ODSocket(SOCKET sock) {
	m_sock = sock;
}

ODSocket::~ODSocket() {
}

int isReadDataIndex = 0;

int ODSocket::Init() {
    isReadDataIndex = 0;

#ifdef WIN32
	/*
	http://msdn.microsoft.com/zh-cn/vstudio/ms741563(en-us,VS.85).aspx

	typedef struct WSAData {
		WORD wVersion;								//winsock version
		WORD wHighVersion;							//The highest version of the Windows Sockets specification that the Ws2_32.dll can support
		char szDescription[WSADESCRIPTION_LEN+1];
		char szSystemStatus[WSASYSSTATUS_LEN+1];
		unsigned short iMaxSockets;
		unsigned short iMaxUdpDg;
		char FAR * lpVendorInfo;
	}WSADATA, *LPWSADATA;
	*/
	WSADATA wsaData;
	//#define MAKEWORD(a,b) ((WORD) (((BYTE) (a)) | ((WORD) ((BYTE) (b))) << 8))
	WORD version = MAKEWORD(2, 0);
	int ret = WSAStartup(version, &wsaData);//win sock start up
	if (ret) {
//		cerr << "Initilize winsock error !" << endl;
		return -1;
	}
#endif

	return 0;
}
//this is just for windows
int ODSocket::Clean() {
#ifdef WIN32
		return (WSACleanup());
#endif
		return 0;
}

ODSocket& ODSocket::operator = (SOCKET s) {
	m_sock = s;
	return (*this);
}

ODSocket::operator SOCKET () {
	return m_sock;
}
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
//iOS版本
//create a socket object win/lin is the same
// af:
bool ODSocket::Create(const struct sockaddr *sa, int type, int protocol) {
    m_sock = socket(sa->sa_family, type, protocol);
    if ( m_sock == INVALID_SOCKET ) {
        return false;
    }
    return true;
}

bool ODSocket::Connect(const char* ip, unsigned short port, const struct sockaddr *sa) {
    switch(sa->sa_family) {
        case AF_INET:
        {
            struct sockaddr_in svraddr;
            svraddr.sin_family = AF_INET;
            svraddr.sin_addr.s_addr = inet_addr(ip);
            svraddr.sin_port = htons(port);
            int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
            if ( ret == SOCKET_ERROR ) {
                return false;
            }
            return true;
        }
            break;
        case AF_INET6:
        {
            struct sockaddr_in6 svraddr;
            memset(&svraddr, 0, sizeof(svraddr));
            svraddr.sin6_len = sizeof(svraddr);
            svraddr.sin6_family = AF_INET6;
            svraddr.sin6_port = htons(port);
            inet_pton(AF_INET6, ip, &svraddr.sin6_addr);
            int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
            if ( ret == SOCKET_ERROR ) {
                return false;
            }
            return true;
        }
            break;
        default:
            CCLOG("ODSocket Connect Error");
            return false;
    }
    
}
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
//Android版本
bool ODSocket::CreateForAndroid(int af, int type, int protocol) {
    m_sock = socket(af, type, protocol);
    if ( m_sock == INVALID_SOCKET ) {
        return false;
    }
    return true;
}

bool ODSocket::ConnectForAndroid(const char* ip, unsigned short port) {
    struct sockaddr_in svraddr;
    svraddr.sin_family = AF_INET;
    svraddr.sin_addr.s_addr = inet_addr(ip);
    svraddr.sin_port = htons(port);
    int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
    if ( ret == SOCKET_ERROR ) {
        return false;
    }
    return true;
}
#endif

bool ODSocket::Bind(unsigned short port)
{
	struct sockaddr_in svraddr;
	svraddr.sin_family = AF_INET;
	svraddr.sin_addr.s_addr = INADDR_ANY;
	svraddr.sin_port = htons(port);

	int opt =  1;
	if ( setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0 )
		return false;

	int ret = bind(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
	if ( ret == SOCKET_ERROR ) {
		return false;
	}
	return true;
}
//for server
bool ODSocket::Listen(int backlog)
{
	int ret = listen(m_sock, backlog);
	if ( ret == SOCKET_ERROR ) {
		return false;
	}
	return true;
}

bool ODSocket::Accept(ODSocket& s, char* fromip)
{
	struct sockaddr_in cliaddr;
	socklen_t addrlen = sizeof(cliaddr);
	SOCKET sock = accept(m_sock, (struct sockaddr*)&cliaddr, &addrlen);
	if ( sock == SOCKET_ERROR ) {
		return false;
	}

	s = sock;
	if ( fromip != NULL )
		sprintf(fromip, "%s", inet_ntoa(cliaddr.sin_addr));

	return true;
}

int ODSocket::Send(byteT* buf, int len, int flags)
{
    const char * buf_;
    buf_ = (const char *)buf;
    
	int bytes;
	int count = 0;
    fd_set readfd;
    struct timeval timeout = {0, 0};
    //char c;

	while (count < len) {
        if (m_sock == INVALID_SOCKET || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) {
            //Android平台
            bytes = send(m_sock, buf_ + count, len - count, flags);
            if (bytes == -1 || bytes == 0) {
                return -1;
            }
            count += bytes;
        } else {
            FD_ZERO(&readfd);
            FD_SET(m_sock, &readfd);
            int ret = select(m_sock + 1, &readfd, NULL, NULL, &timeout);
            //CCLOG("ODSocket === Send select==== %d", ret);
            if(ret == 1 && FD_ISSET(m_sock, &readfd)){
                //延时，递归
                isReadDataIndex = isReadDataIndex + 1;
                //CCLOG("ODSocket === 有数据可以接收 ==== 延时 index == %d",isReadDataIndex);
                if (isReadDataIndex >= 20) {
                    //一直有消息接收，抛弃此消息，返回-2
                    return -2;
                }
                
                usleep(10 * 1000);//10毫秒
                
            } else {
            	isReadDataIndex = 0;
                bytes = send(m_sock, buf_ + count, len - count, flags);
                if (bytes == -1 || bytes == 0) {
                    return -1;
                }
                count += bytes;
            }
        }
	}

	return count;
}

int ODSocket::Recv(byteT* buf, int len, int flags)
{
    char * buf_;
    buf_ = (char *)buf;

	return (recv(m_sock, buf_, len, flags));
}

int ODSocket::Close()
{
#ifdef WIN32
	return (closesocket(m_sock));
#else
	return (close(m_sock));
#endif
}

int ODSocket::GetError()
{
#ifdef WIN32
	return (WSAGetLastError());
#else
	return (-1);
#endif
}

int ODSocket::getSock()
{
	return this->m_sock;
}

bool ODSocket::DnsParse(const char* domain, char* ip)
{
	struct hostent* p;
	if ( (p = gethostbyname(domain)) == NULL )
		return false;

	sprintf(ip,
		"%u.%u.%u.%u",
		(unsigned char)p->h_addr_list[0][0],
		(unsigned char)p->h_addr_list[0][1],
		(unsigned char)p->h_addr_list[0][2],
		(unsigned char)p->h_addr_list[0][3]);

	return true;
}


