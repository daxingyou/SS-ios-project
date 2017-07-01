//
//  SevTCliNotification.h
//  Lstx_cocos2dX
//
//  Created by zhongjian zhao on 12-7-26.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef Lstx_cocos2dX_SevTCliNotification_h
#define Lstx_cocos2dX_SevTCliNotification_h
#include "NotificationCenter.h"
class SevTCliNotification : public NotificationCenter
{
public:
    static SevTCliNotification *sharedNotification();
private:
    SevTCliNotification();
    ~SevTCliNotification();
};


#endif
