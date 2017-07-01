//
//  ClassFactory.h
//  MyCocos2d-xApp
//
//  Created by xing chong on 7/13/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef MyCocos2d_xApp_ClassFactory_h
#define MyCocos2d_xApp_ClassFactory_h

//#include "stdafx.h"
#include   <string> 
#include   <map> 
#include   <iostream>

using namespace std;
typedef void* (*CreateFuntion)(void);//回调函数指针

class ClassFactory
{
public:
    static void* GetClassByName(std::string name);
    
    static void RegistClass(std::string name,CreateFuntion method);
    
private:
    static std::map<std::string,CreateFuntion> m_clsMap;
};

//std::map<std::string,CreateFuntion>   ClassFactory::m_clsMap; 


#endif
