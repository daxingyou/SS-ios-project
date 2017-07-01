#ifndef _Q_CONTACT_LISTENER_H_
#define _Q_CONTACT_LISTENER_H_

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "FishBox2dSupport.h"
#include "TransparentId.h"
#include <List>

USING_NS_CC;
using namespace std;


class QContactListener : public b2ContactListener
{
public:
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    
};

#endif