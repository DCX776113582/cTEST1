//
//  multiple.h
//  Chapter04_Demo4
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo4__multiple__
#define __Chapter04_Demo4__multiple__

#include <iostream>
using namespace std;
class Base1 {
public:
    virtual void f()
    {
        cout<<"Base1::f()"<<endl;
    }
    virtual void g()
    {
        cout<<"Base1::g()"<<endl;
    }
    virtual void h()
    {
        cout<<"Base1::h()"<<endl;
    }
};
class Base2 {
public:
    virtual void f()
    {
        cout<<"Base2::f()"<<endl;
    }
    virtual void g()
    {
        cout<<"Base2::g()"<<endl;
    }
    virtual void h()
    {
        cout<<"Base2::h()"<<endl;
    }
};
class Base3 {
public:
    virtual void f()
    {
        cout<<"Base3::f()"<<endl;
    }
    virtual void g()
    {
        cout<<"Base3::g()"<<endl;
    }
    virtual void h()
    {
        cout<<"Base3::h()"<<endl;
    }
};
class Derive:public Base1,public Base2,public Base3 {
public:
    void f()
    {
        cout<<"Derive::f()"<<endl;
    }
    void f1()
    {
        cout<<"Derive::f1()"<<endl;
    }
    void g()
    {
        cout<<"Derive::g()"<<endl;
    }
    void g1()
    {
        cout<<"Derive::g1()"<<endl;
    }
    void h1()
    {
        cout<<"Derive::h()"<<endl;
    }
};

#endif /* defined(__Chapter04_Demo4__multiple__) */
