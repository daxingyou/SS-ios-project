

#include "EventInvocation.h"
#include "script_support/CCScriptSupport.h"

EventInvocation::EventInvocation(CCObject* target, SEL_EventHandle action, int eventType)
{
    m_target = target;
    m_action = action;
    m_eventType = eventType;
    m_scriptHandler = 0;
}

EventInvocation::EventInvocation(int nHandler,int evenType)
{
    m_scriptHandler = nHandler;
    m_eventType     = evenType;
}

void EventInvocation::invoke(Event* event)
{
    if (m_scriptHandler)
    {
        CCScriptEngineManager::sharedManager()->getScriptEngine()->executeFunctionWithCCObject(m_scriptHandler,event,"Event");
    }
    else if (m_target && m_action)
    {
        (m_target->*m_action)(event);
    }                
}
