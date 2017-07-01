//
//  Register.h
//  MyCocos2d-xApp
//
//  Created by xing chong on 7/13/12.
//  Copyright (c) 2012 renren. All rights reserved.
//

//包含回调函数和静态变量

#ifndef MyCocos2d_xApp_Register_h
#define MyCocos2d_xApp_Register_h

#include "RegistyClass.h"

//template<class T,const char name[]>
template<class T>
class Register
{
public:
    Register()
    {
        //这个一定要加，因为编译器不保证程序开始时就初始化变量rc
        //const RegistyClass tmp=rc;
    }
    static void* CreateInstance()
    {
        return new T;
    }
public:
    //static const RegistyClass rc;
};

/**
template<class T,const char name[]>
const RegistyClass Register<T,name>::rc(name,Register<T,name>::CreateInstance);


//这里我们用宏来定义要反射的类会更方便
#define DEFINE_CLASS(class_name) \
char NameArray##class_name[]=#class_name;\
class class_name:public Register<class_name,NameArray##class_name>
#define DEFINE_CLASS_EX(class_name,father_class) \
char NameArray##class_name[]=#class_name;\
class class_name:public Register<class_name,NameArray##class_name>,public father_class
*/



#endif
