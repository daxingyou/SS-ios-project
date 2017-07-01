//
//   SevTCliNotification.cpp
//  Lstx_cocos2dX
//
//  Created by zhongjian zhao on 12-7-26.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "SevTCliNotification.h"

static SevTCliNotification *s_sharedNotification=NULL;

SevTCliNotification::SevTCliNotification()
{
    this->startLoop();
    this->m_flag=NotifiStC;
}
SevTCliNotification::~SevTCliNotification()
{

}

SevTCliNotification *SevTCliNotification::sharedNotification()
{
	//CCLOG("\nSevTCliNotification::sharedNotification()\n");
    if(s_sharedNotification == NULL)
    {
        s_sharedNotification = new SevTCliNotification;
    }
    return s_sharedNotification;

}
