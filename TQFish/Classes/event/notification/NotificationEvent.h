
#ifndef Lstx_cocos2dX_NotificationEvent_h
#define Lstx_cocos2dX_NotificationEvent_h
#include "cocos2d.h"
USING_NS_CC;

class NotificationEvent: public CCObject
{
    CC_SYNTHESIZE(CCObject *,m_data,eventData);
    CC_SYNTHESIZE(char *,m_type,eventType);
public:
    static NotificationEvent *createEvent(const char *type,CCObject *data);

private:
    NotificationEvent();
    ~NotificationEvent();
};


#endif
