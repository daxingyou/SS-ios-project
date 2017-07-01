//
//  ClassFactory.cpp
//  Lstx_cocos2dX
//
//  Created by xing chong on 7/19/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

#include "ClassFactory.h"


std::map<std::string,CreateFuntion>   ClassFactory::m_clsMap; 


void* ClassFactory::GetClassByName(std::string name)
{
    std::map<std::string,CreateFuntion>::const_iterator find;
    find=m_clsMap.find(name);
    if(find==m_clsMap.end())
    {
        return NULL;
    }
    else
    {
        return find->second();
    }
}
void ClassFactory::RegistClass(std::string name,CreateFuntion method)
{
    m_clsMap.insert(std::make_pair(name,method));
}