//
//  MessageRegist.h
//  Lstx_cocos2dX
//
//  Created by xing chong on 7/25/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MessageRegist_h
#define Lstx_cocos2dX_MessageRegist_h

#include "MessageRecognize.h"

class MessageRegister{
    
public:
    MessageRegister(void);
    ~MessageRegister(void);
    
    /**
     * 注册消息，调用registMessage(short string string)
     */
    void registMessage(MessageRecognize * messageRecognize);
};


#endif
