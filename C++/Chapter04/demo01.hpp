//
//  demo01.h
//  Chapter04
//
//  Created by mac on 18/2/25.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04__demo01__
#define __Chapter04__demo01__

#include <iostream>
using namespace std;

//基类
class Base
{
private:
    int b_number;
    
public:
    Base(int i);
    int get_number();
    void print();
};
//派生类继承基类
class Derived : public Base
{
private:
    int d_number;    //子类扩展的成员变量
    //int b_number;  //子类自动继承自父类的成员变量。
    
public:
    Derived(int i, int j);
    void print( );
};

#endif /* defined(__Chapter04__demo01__) */
