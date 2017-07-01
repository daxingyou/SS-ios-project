#include "QContactListener.h"
void QContactListener::BeginContact(b2Contact* contact)
{
	if (contact)
    {
		TransparentId* psa = (TransparentId*) (contact->GetFixtureA()->GetBody()->GetUserData());
		TransparentId* psb = (TransparentId*) (contact->GetFixtureB()->GetBody()->GetUserData());
        
        
        FishBox2dSupport::GetInstance()->invokeFishCallbackFunction(psa->getId(),psb->getId());
    }
		
	B2_NOT_USED(contact);
}


void QContactListener::EndContact(b2Contact* contact)
{
	B2_NOT_USED(contact);
}
