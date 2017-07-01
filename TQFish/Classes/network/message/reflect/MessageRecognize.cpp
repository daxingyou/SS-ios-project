//
//  MessageRecognize.cpp
//  Lstx_cocos2dX
//
//  Created by xing chong on 7/20/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#include "MessageRecognize.h"


MessageRecognize::MessageRecognize(void){
    
}

MessageRecognize::~MessageRecognize(void){
    
}

/**
 * 识别消息,返回消息节点结构体
 */
MessageNode * MessageRecognize::recognizeMessage(int messageType)

{
    map<int, MessageNode>::iterator it = messageContainer.begin();
    it=messageContainer.find(messageType);
    if(it==messageContainer.end())
    {
        return NULL;
    }
    else
    {
        return &(it->second);
    }
}

/**
 * 创建消息实例
 */
BaseMessage * MessageRecognize::createMessage(string messageClassName)
{
    return (BaseMessage *)ClassFactory::GetClassByName(messageClassName);
}



void MessageRecognize::registMessage(int messsageType, string messageClassName, CreateFuntion createFuntion, string scriptName, string functionName){
    MessageNode messageNode;
    messageNode.messageClassName = messageClassName;
    messageNode.scriptName = scriptName;
    messageNode.functionName = functionName;
    messageContainer.insert(_KV_(messsageType, messageNode));
    
    ClassFactory::RegistClass(messageClassName, createFuntion);
}




