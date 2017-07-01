
//
//  MessageRecognize.h
//  MyCocos2d-xApp
//
//  Created by xing chong on 7/16/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef MyCocos2d_xApp_MessageRecognize_h
#define MyCocos2d_xApp_MessageRecognize_h

#include   <string> 
#include   <map>
#include "BaseMessage.h"
#include "ClassFactory.h"
#include "Register.h"

//消息节点
typedef struct atom_node  
{  
    std::string messageClassName;
    std::string scriptName;  
    std::string functionName;
} MessageNode;

using namespace std;

typedef pair <short, atom_node> _KV_ ;


class MessageRecognize{
    
private:
    
    map<int, MessageNode> messageContainer;
    
public:
    
    MessageRecognize(void);
    ~MessageRecognize(void);
    
    
    /**
     * 识别消息,返回消息节点结构体
     */
    //======
    MessageNode * recognizeMessage(int messageType);
    
    /**
     * 创建消息实例
     */
    BaseMessage * createMessage(string messageClassName);
    
    /**
     * 注册消息
     */
    void registMessage(int messsageType, string messageClassName, CreateFuntion createFuntion, string scriptName, string functionName);
    
    
    
};

#endif
