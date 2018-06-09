//
//  base.h
//  Chapter04_Demo4
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo4__base__
#define __Chapter04_Demo4__base__

#include <iostream>
using namespace std;
class Base{
public:
    virtual void fun();
};
class Thing{
public:
    virtual void what_Am_I();
    virtual ~Thing();
    /*3：虚析构的概念：
     虚析构函数：防止动态内存的泄漏（潜在内存泄漏）
     应用：类外使用父类指针new申请子类对象，以及通过父类指针delete释放子类对象时，可能导致潜在内存问题
     4：虚函数的原理
     类：虚函数表
     对象：虚指针 -> 虚函数表（第一个元素）
     影响：增加内存消耗 + 延长运行时间
     5：多态性*/
};
#endif /* defined(__Chapter04_Demo4__base__) */
