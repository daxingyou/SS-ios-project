
#ifndef Lstx_cocos2dX_NotificationCenter_h
#define Lstx_cocos2dX_NotificationCenter_h

#include "NotificationEvent.h"
#include "pthread.h"


typedef void (CCObject::*Action_CallFunc)(NotificationEvent*);

#define notificationCallFunc(_SELECTOR) (Action_CallFunc)(&_SELECTOR)

enum
{
    NotifiStC=1,
    NotifiCom=2,
};

class NotificationCenter : public CCObject
{	    
public: 
    void addObserver(CCObject *target,Action_CallFunc action,const char *eventType); 
    void removeObserver(CCObject *target,const char *eventType);
    void sendEvent(NotificationEvent *event);
    void sendEventCom(NotificationEvent *event);
    void sendEventNot(NotificationEvent *event);

	virtual void clearEventAndObserver();

	////TheScript Function    
	void addObserver(int nHandler,const char *eventType); 
	void removeObserver(int nHandler,const char *eventType);
    
protected:  
	void startLoop();
	NotificationCenter();
	~NotificationCenter();
	int m_flag;

private:
	pthread_mutex_t lock; 
	CCArray* m_eventArray;    
	CCScheduler *m_pScheduler;   
	CCDictionary *m_observers;
	bool observerExiste(CCObject *taget,const char *eventType);
	bool observerExiste(int nHandler,const char *eventType);

	void postNotification(float dt);
};

class NotificationObserver:public CCObject
{
public:
    NotificationObserver(int nHandler);
    NotificationObserver(CCObject *target,Action_CallFunc action);
    ~NotificationObserver();
    CCObject *m_target;
    Action_CallFunc m_action;
    int scriptFlag;
    void runAction(NotificationEvent *event);
};

#endif
