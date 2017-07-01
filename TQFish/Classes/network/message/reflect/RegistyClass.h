//
//  RegistyClass.h
//  MyCocos2d-xApp
//
//  Created by xing chong on 7/13/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef MyCocos2d_xApp_RegistyClass_h
#define MyCocos2d_xApp_RegistyClass_h

#include "ClassFactory.h"

class RegistyClass
{
public:
    RegistyClass(std::string name,CreateFuntion method)
    {
        ClassFactory::RegistClass(name,method);
    }
};

#endif
