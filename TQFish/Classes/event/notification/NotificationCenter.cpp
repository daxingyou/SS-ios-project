
#include "NotificationCenter.h"
#include "script_support/CCScriptSupport.h"
#include "Services.h"

NotificationCenter::NotificationCenter()
{
	m_observers=CCDictionary::create();
	m_observers->retain();
	
	m_eventArray=CCArray::create();
	m_eventArray->retain();
	
	CCDirector *director = CCDirector::sharedDirector();
	m_pScheduler=director->getScheduler();
	m_pScheduler->retain();
	m_flag=0;

	pthread_mutex_init(&lock,NULL);
}

NotificationCenter::~NotificationCenter()
{
	m_observers->release();
	m_eventArray->release();
	m_pScheduler->release();
}


void NotificationCenter::startLoop()
{
	//================================
	//m_pScheduler->scheduleSelector(schedule_selector(NotificationCenter::postNotification), this,0.02f ,false,kCCRepeatForever,0.0f);
	//CCLOG("\nNotificationCenter::startLoop()\n");
	m_pScheduler->scheduleSelector(schedule_selector(NotificationCenter::postNotification), this, 0.015f, false);
	
}

void NotificationCenter::postNotification(float dt) {
    
	Services::getMessageService()->tickReceivedMessage();//把消息推送到lua中
    
    pthread_mutex_lock(&lock);
    
	if(m_eventArray->count() > 0) {
		
		NotificationEvent *event = (NotificationEvent *)m_eventArray->objectAtIndex(0);
        
        if(!event){
            m_eventArray->removeObjectAtIndex(0);
            pthread_mutex_unlock(&lock);
            return;
        }
        
        if (!event->geteventType()) {
            m_eventArray->removeObjectAtIndex(0);
            pthread_mutex_unlock(&lock);
            return;
        }
        
        //CCLOG("\n event->geteventType()=============%s",event->geteventType());
        
		CCArray *obsArray = (CCArray *)m_observers->objectForKey(event->geteventType());
		
        if(!obsArray){
            m_eventArray->removeObjectAtIndex(0);
            pthread_mutex_unlock(&lock);
			return;
		}
        
        if (!obsArray->count()) {
            m_eventArray->removeObjectAtIndex(0);
            pthread_mutex_unlock(&lock);
            return;
        }
        
        if (obsArray->count() <= 0) {
            m_eventArray->removeObjectAtIndex(0);
            pthread_mutex_unlock(&lock);
            return;
        }
        
        //CCLOG("\n obsArray->count()=============%d",obsArray->count());
		
        for(unsigned int i = 0; i < obsArray->count(); i++) {
			NotificationObserver *observer=(NotificationObserver *)obsArray->objectAtIndex(i);
            if(observer) {
				observer->runAction(event);
			}
		}
        m_eventArray->removeObjectAtIndex(0);
        
		pthread_mutex_unlock(&lock);
	} else {
        pthread_mutex_unlock(&lock);
        return;
	}
}

bool NotificationCenter::observerExiste(CCObject *target,const char *eventType)
{
	CCArray *obsevArray=(CCArray *)m_observers->objectForKey(eventType);
	if(obsevArray == NULL)
	{
		return false;
	}
	for(unsigned int i=0;i<obsevArray->count();i++)
	{
		NotificationObserver *obj=(NotificationObserver *)(obsevArray->objectAtIndex(i));
		if(obj==NULL)
		{
			return false;
		}
		if(target==obj->m_target)
		{
			return true;
		}
	}
	return false;
}

bool NotificationCenter::observerExiste(int nHandler,const char *eventType)
{
	CCArray *obsevArray=(CCArray *)m_observers->objectForKey(eventType);
	if(obsevArray == NULL)
	{
		return false;
	}
	for(unsigned int i=0;i<obsevArray->count();i++)
	{
		NotificationObserver *obj=(NotificationObserver *)(obsevArray->objectAtIndex(i));
		if(obj==NULL)
		{
			return false;
		}
		if(obj->scriptFlag)
		{
			if(nHandler==obj->scriptFlag)
			{
				return true;
			}
		}
	}
	return false;
}

void NotificationCenter::addObserver(CCObject *target,Action_CallFunc action,const char *eventType)
{
	if (this->observerExiste(target,eventType))
		return;
	NotificationObserver *observer = new NotificationObserver(target,action);
	if (!observer)
		return;
	CCArray *obserArray =(CCArray *)m_observers->objectForKey(eventType);
	if(obserArray==NULL)
	{
		obserArray=CCArray::create();
	}
	obserArray->addObject(observer);
	m_observers->setObject(obserArray,eventType);
	observer->release();
}

void NotificationCenter::addObserver(int nHandler,const char *eventType)
{
	if (this->observerExiste(nHandler,eventType))
		return;
	NotificationObserver *observer = new NotificationObserver(nHandler);
	if (!observer)
		return;
	CCArray *obserArray =(CCArray *)m_observers->objectForKey(eventType);
	if(obserArray==NULL)
	{
		obserArray=CCArray::create();
	}
	obserArray->addObject(observer);
	m_observers->setObject(obserArray,eventType);
	
	observer->release();
}

void NotificationCenter::removeObserver(CCObject *target,const char *eventType)
{
	CCArray *obsevArray=(CCArray *)m_observers->objectForKey(eventType);
	if(obsevArray == NULL)
	{
		return ;
	}
	for(unsigned int i=0;i<obsevArray->count();i++)
	{
		NotificationObserver *obj=(NotificationObserver *)(obsevArray->objectAtIndex(i));
		if(obj==NULL)
		{
			return ;
		}
		if(target==obj->m_target)
		{
			obsevArray->removeObject(obj);
		}
	}
	return ;

}

void NotificationCenter::removeObserver(int nHandler,const char *eventType)
{
	CCArray *obsevArray=(CCArray *)m_observers->objectForKey(eventType);
	if(obsevArray == NULL)
	{
		return ;
	}
	for(unsigned int i=0;i<obsevArray->count();i++)
	{
		NotificationObserver *obj=(NotificationObserver *)(obsevArray->objectAtIndex(i));
		if(obj==NULL)
		{
			return ;
		}
		if(obj->scriptFlag)
		{
			if(nHandler==obj->scriptFlag)
			{
				obsevArray->removeObject(obj);
			}
		}
	}
	return ;
	
}


void NotificationCenter::sendEvent(NotificationEvent *event)
{
	switch (m_flag) {
		case NotifiStC:
			sendEventNot(event);
			break;
		case NotifiCom:
			sendEventCom(event);
		default:
			break;
	}
}

void NotificationCenter::sendEventCom(NotificationEvent *event)
{
	CCArray *obsArray=(CCArray *)m_observers->objectForKey(event->geteventType());
	for(unsigned int i=0;i<obsArray->count();i++)
	{
		NotificationObserver *observer=(NotificationObserver *)obsArray->objectAtIndex(i);     
		if(observer)
		{
			observer->runAction(event);
		}
	}
}

void NotificationCenter::sendEventNot(NotificationEvent *event)
{ 
	pthread_mutex_lock(&lock);
	
	 m_eventArray->addObject(event);

	pthread_mutex_unlock(&lock);
}

void NotificationCenter::clearEventAndObserver()
{
	m_eventArray->removeAllObjects();
	m_observers->removeAllObjects();
}


////////////////////////////////////////////////
NotificationObserver::NotificationObserver(CCObject *target,Action_CallFunc action)
{
	m_target = target;
	m_target->retain();
	m_action = action;
	scriptFlag=0;
}

NotificationObserver::NotificationObserver(int nHandler)
{
	scriptFlag=nHandler;
	m_target=NULL;
}

NotificationObserver::~NotificationObserver()
{
	if(m_target)
	{
		m_target->release();
	}
}

void NotificationObserver::runAction(NotificationEvent *event)
{
	if(scriptFlag)
	{
		CCScriptEngineManager::sharedManager()->getScriptEngine()->executeFunctionWithCCObject(scriptFlag,event,"NotificationEvent");
	}
	else if(m_target)
	{
		(m_target->*m_action)(event);
	}
}
