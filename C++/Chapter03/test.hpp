//
//  test.h
//  Chapter03
//
//  Created by mac on 18/2/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter03__test__
#define __Chapter03__test__

#include <iostream>
using namespace std;
class A{
    int a;
public:
    A(int _a = 0):a(_a){cout<<"带参的默认构造函数"<<endl;}
    A(const A&a):a(a.a){cout<<"拷贝函数"<<endl;}
    friend ostream& operator<<(ostream& out,const A&a1){out<<a1.a<<endl;return out;}
    friend void printA(A&a){cout<<a;}
    A operator=(A&a1){a=a1.a;return *this;}
    friend  A getA();
};
//DEmo01
class B
{
    int b;
public:
    B(){cout << "A();";}
    B(const B& a) //拷贝构造函数
    {
        *this = a;
        cout << "A(A a)";
    }
    friend ostream& operator<<(ostream& out,const B&a1){out<<a1.b<<endl;return out;}
    const B & operator = (const B & a){b=a.b;return *this;}
};
//DEmo02
class Vector
{
public:
    int *rep;
    int size;
public:
    Vector(int s=0);
    Vector(int *, int s);
    Vector(const Vector& v);
    ~Vector( );
public:
    int get_size( ) const;
    const Vector& operator=(const Vector& x);
    void print();
};
//DEmo03
class Demo
{
private:
    int i;
public:
    Demo(int n = 0);
    Demo(const Demo& a);
    ~Demo();
public:
    Demo & set_value(int n);
    int get_value( ) const;
    const Demo& operator=(const Demo& a);
};
Demo foo(Demo x);
#endif /* defined(__Chapter03__test__) */
