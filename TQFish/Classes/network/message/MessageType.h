//#pragma once

#ifndef MyCocos2d_xApp_MessageType_h
#define MyCocos2d_xApp_MessageType_h

class MessageType {

public:
	MessageType(void);
	~MessageType(void);

	//system message code 1001~3000
	const static int NETERR_CONN_FAILED = 1001; //建立连接失败
	const static int NETERR_NET_BROKEN = 1002; //网络断开(开始重连)
	const static int NETERR_CONN_SUCC = 1003; //重连成功
	const static int NETERR_CONN_HOST_FAILED = 1004; //获取host失败
};

#endif
