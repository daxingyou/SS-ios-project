
#include "EventDispather.h"

EventDispather::EventDispather()
{
    m_dispatchTable = new CCDictionary();
}

EventDispather::~EventDispather()
{   
    CC_SAFE_RELEASE_NULL(m_dispatchTable);
}

void EventDispather::sendActionsForEvent(Event* event)
{
    CCArray* invocationList= dispatchListforEvent(event->getEventType());
    CCObject* pObj = NULL;
    CCARRAY_FOREACH(invocationList, pObj)
    {
        EventInvocation* invocation = (EventInvocation*)pObj;
        invocation->invoke(event);
    }   
}

CCArray* EventDispather::dispatchListforEvent(int eventType)
{
    CCAssert(m_dispatchTable != NULL, "init");
    
    CCArray* invocationList = dynamic_cast<CCArray*>(m_dispatchTable->objectForKey(eventType));

    if (invocationList == NULL)
    {
        invocationList = CCArray::createWithCapacity(1);
        m_dispatchTable->setObject(invocationList, eventType);
    }    

	
    return invocationList;
}

void EventDispather::addTargetWithActionForEvent(CCObject* target, SEL_EventHandle action, int eventType)
{    
    EventInvocation *invocation=new EventInvocation(target, action, eventType);
    invocation->autorelease();
    CCArray* eventInvocationList = dispatchListforEvent(eventType);
    eventInvocationList->addObject(invocation);    
}

void EventDispather::removeTargetWithActionForEvent(CCObject* target, SEL_EventHandle action, int eventType)
{    
    CCArray *eventInvocationList=dispatchListforEvent(eventType);
    
    bool bDeleteObjects=true;
    if (!target && !action)
    {        
        eventInvocationList->removeAllObjects();
    } 
    else
    {
    
        CCObject* pObj = NULL;
        CCARRAY_FOREACH(eventInvocationList, pObj)
        {
            EventInvocation *invocation = (EventInvocation*)pObj;
            bool shouldBeRemoved=true;
            if (target)                
                shouldBeRemoved=(target==invocation->getTarget());                
            if (action)
                shouldBeRemoved=(shouldBeRemoved && (action==invocation->getAction()));
            
            if (shouldBeRemoved)
                eventInvocationList->removeObject(invocation, bDeleteObjects);
        }
    }
    
}

void EventDispather::registerScriptAction(int nHandler,int eventType)
{
	CCArray *eventInvocationList=dispatchListforEvent(eventType);

	//清空列表 防止重复注册
//	eventInvocationList->removeAllObjects()
	; 

	CCObject* pObj = NULL;
	EventInvocation *delInvocation = NULL;
	CCARRAY_FOREACH(eventInvocationList, pObj)
	{
		EventInvocation *invocation = (EventInvocation*)pObj;
		if(invocation->getScript())
		{
			delInvocation = invocation;
		}
	}
	eventInvocationList->removeObject(delInvocation);
    // Create the invocation object
	
    EventInvocation *invocation=new EventInvocation(nHandler, eventType);
    invocation->autorelease();
    // Add the invocation into the dispatch list for the given Component event
  
    eventInvocationList->addObject(invocation);    
}

void EventDispather::unregisterScriptAction(int nHandler,int eventType)
{
    CCArray *eventInvocationList=dispatchListforEvent(eventType);
    
    bool bDeleteObjects=true;
    //normally we would use a predicate, but this won't work here. Have to do it manually
    CCObject* pObj = NULL;
    bool shouldBeRemoved;
    CCARRAY_FOREACH(eventInvocationList, pObj)
    {
        EventInvocation *invocation = (EventInvocation*)pObj;
        if(invocation->getScript())
        {
            if (nHandler)                
                shouldBeRemoved=(nHandler==invocation->getScript());                
            if (shouldBeRemoved)
            {
                eventInvocationList->removeObject(invocation, bDeleteObjects);
                CCScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(nHandler);
                invocation->setScript(0);
            }
        }
    }
}





