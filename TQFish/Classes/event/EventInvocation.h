
#ifndef Lstx_cocos2dX_EventInvocation_h
#define Lstx_cocos2dX_EventInvocation_h

#include "Event.h"

typedef void (CCObject::*SEL_EventHandle)(Event*);
#define event_select(_SELECTOR) (SEL_EventHandle)(&_SELECTOR)

class EventInvocation : public CCObject
{
    CC_SYNTHESIZE_READONLY(SEL_EventHandle, m_action, Action);
    CC_SYNTHESIZE_READONLY(CCObject*, m_target, Target);
    CC_SYNTHESIZE(int, m_eventType, EventType);
    CC_SYNTHESIZE(int, m_scriptHandler, Script);
public:
    EventInvocation(CCObject* target, SEL_EventHandle action, int evenType);
    EventInvocation(int nHandler,int evenType);
    
    void invoke(Event* event);
};

#endif

