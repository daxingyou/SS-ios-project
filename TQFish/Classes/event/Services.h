
#ifndef Lstx_cocos2dX_Services_h
#define Lstx_cocos2dX_Services_h

#include "MessageService.h"

class Services
{
private:
    
    static MessageService *messageService;//消息服务
    
public:
    
    Services(void){}
    ~Services(void){}
    
    static MessageService * getMessageService()
    {
        if(messageService==NULL)
        {
            messageService = new MessageService;
        }
        return messageService;
    }
    
    static MessageService* destroyMessageService()
    {
        messageService = NULL;
        
        return NULL;
    }
};


#endif
