
#include "NotificationEvent.h"
using namespace std;

NotificationEvent *NotificationEvent::createEvent(const char *type,CCObject *data)
{
    NotificationEvent *event=new NotificationEvent();
    event->m_type= new char[strlen(type)+1];
    memset(event->m_type,0,strlen(type)+1);
    string orig(type);
    orig.copy(event->m_type,strlen(type),0);
    
    if(data)
    {
        event->m_data=data;
        event->m_data->retain();
    }
    event->autorelease();
    return event;
}


NotificationEvent::NotificationEvent()
{
    
}
NotificationEvent::~NotificationEvent()
{
    m_data->release();
    if(m_type)
    {
        delete m_type;
    }
}
