
#ifndef Lstx_cocos2dX_LordAi_h
#define Lstx_cocos2dX_LordAi_h

#include "LocalService.h"

class LordAi
{
private:
    
    static LocalService *mLocalService;//消息服务
    
public:
    
    LordAi(void){}
    ~LordAi(void){}
    
    static LocalService * getLordAiService()
    {
        if(mLocalService==NULL)
        {
            mLocalService = new LocalService;
        }
        return mLocalService;
    }
};


#endif
