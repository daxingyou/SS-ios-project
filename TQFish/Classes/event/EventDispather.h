
#ifndef Lstx_cocos2dX_EventDispather_h
#define Lstx_cocos2dX_EventDispather_h

#include "Event.h"
#include "EventInvocation.h"


//can't create EventDispather directly

class EventDispather
{
public:
    virtual ~EventDispather();
    virtual void sendActionsForEvent(Event* event);         
    
    virtual void addTargetWithActionForEvent(CCObject* target, SEL_EventHandle action, int eventType);    
    
    virtual void removeTargetWithActionForEvent(CCObject* target, SEL_EventHandle action, int eventType);
    
    /** Register menu handler script function */
    virtual void registerScriptAction(int nHandler,int eventType);
    virtual void unregisterScriptAction(int nHandler,int eventType);
    
protected:
    CCDictionary* m_dispatchTable;
    
    CCArray* dispatchListforEvent(int eventType);
protected:
    EventDispather();
};


#endif
