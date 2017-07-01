
#include "Event.h"

Event::Event():
m_data(NULL)
{    
}

Event::~Event()
{
    CC_SAFE_RELEASE(m_data);
}

bool Event::init()
{
    return init(NONE, NULL,"");
}

bool Event::init(int type)
{
    return init(type, NULL,"");
}

bool Event::init(int type, cocos2d::CCObject *data,std::string dataName)
{   
    m_type = type;
    m_data = data;
    m_name = dataName;
    
    if(m_data != NULL)
    {
        m_data->retain();  
    }
    
    return true;
}

Event* Event::create()
{
   return create(NONE,NULL,"");
}

Event* Event::create(int type)
{
    return create(type,NULL,"");
}

Event* Event::create(int type, cocos2d::CCObject *data,std::string dataName)
{    
    Event* event = new Event();
    if(event->init(type, data,dataName))
    {
        event->autorelease();    
        return event;
    }
    
    return  NULL;
}

