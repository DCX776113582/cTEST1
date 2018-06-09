//
//  test.h
//  Chapter04_Demo4
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo4__test__
#define __Chapter04_Demo4__test__

#include <iostream>
using namespace std;
class A {
public:
    int x;
    A():x(0){}
    virtual void print()const
    {
        cout<<"A:"<<endl;
    }
    void outA()const
    {
        cout<<"outA:"<<endl;
    }
};
class B :public A{
public:
    void print()const
    {
        cout<<"B:"<<endl;
    }
    void outB()const
    {
        cout<<"outB:"<<endl;
    }
};
class C :public A{
public:
    void print()const
    {
        cout<<"C:"<<endl;
    }
    void outC()const
    {
        cout<<"outC:"<<endl;
    }
};

#endif /* defined(__Chapter04_Demo4__test__) */
