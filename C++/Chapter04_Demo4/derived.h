//
//  derived.h
//  Chapter04_Demo4
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo4__derived__
#define __Chapter04_Demo4__derived__

#include "base.h"

class Derived:public Base{
public:
    void fun() override;//重写父类函数
};
class Animal:public Thing{
public:
    virtual void what_Am_I();
    ~Animal();
};
#endif /* defined(__Chapter04_Demo4__derived__) */
