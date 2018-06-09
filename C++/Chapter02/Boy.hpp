//
//  Boy.h
//  Chapter02
//
//  Created by mac on 18/2/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter02__Boy__
#define __Chapter02__Boy__

#include <iostream>
using namespace std;
#define NUM 12
class Boy
{
private:
    char *name;
    char telephone[NUM];
    int phone;
    
public:
    Boy(char *n, char *g, int p);
    ~Boy();
    
public:
    char*getName()const
    {return name;}
    const char* getTelephone()const
    {return telephone;}
    int getPhone()const
    {return phone;}
    void setName(char *newName);
    void setTel(char *newTel);
    void print();
    void print()const;
    
    const Boy& operator=(const Boy& b);
    friend ostream& operator<<(ostream& out,const Boy& c1);
};

class Int{
private:
    int a;
public:
    Int():a(1) // Int i;
    {
        cout<<"默认构造"<<endl;
    }
    Int(const Int& i):a(i.a) //拷贝构造函数: Int j(i);
    {
        cout<<"拷贝构造"<<endl;
    }
    Int(int _a):a(_a) // Int i(10)
    {
        cout<<"带参数普通构造"<<endl;
    }
public:
    void setA(int _a)
    {
        this->a=_a;
    }
public:
    /*运算符重载
     c++中对类的对象进行操作运算，则需要重新对运算符（操作符）进行重新定义，称为运算符重载。
     运算目标如果为对象，则需要对当前运算符重载
     例如：进行算数运算、关系运算（比较）、输出/输入对象等
     语法：函数名==返回值类型 operator运算符(传递的对象类型);
     使用特点：类的成员函数，类的友元函数，普通的全局函数
     1、算数运算符重载：类的成员函数、类的友元函数
     2、输入/输出运算符重载：类的友元函数*/
    Int operator+(Int& i);
    Int operator-(Int& i);
    Int operator*(Int& i);
    Int operator/(Int& i);
    Int operator%(Int& i);
    Int& operator=(Int&i);
    //prefix: ++i --i
    Int operator++()
    {
        return Int(++a);
    }
    Int operator--()
    {
        return Int(--a);
    }
    //suffix: i++ i--
    Int operator++(int)
    {
        int old = this->a;
        this->a++;
        return Int(old);
    }
    Int operator--(int)
    {
        int old = this->a;
        this->a--;
        return Int(old);
    }
    /*
    类的友元函数：
    概念：一个普通的函数在类定义内部被声明，用friend修饰的函数被称为该类的友元函数；
    特点：函数是类的朋友，不属于类的成员；
    优点：可以直接通过该类的对象/类的作用域在函数实现中直接访问类中的私有成员
    缺点类的友元函数会破坏类的封装，不安全
     */
    /*friend Int operator+(Int& a,Int& b);
    friend Int operator-(Int& a,Int& b);
    friend Int operator*(Int& a,Int& b);
    friend Int operator/(Int& a,Int& b);
    friend Int operator%(Int& a,Int& b);*/
    
    friend ostream& operator<<(ostream& out,const Int& a);
    friend istream& operator>>(istream& in,Int& a);

public:
    void printInt()
    {
        cout<<a<<endl;
    }
public:
    ~Int(){}
};

#endif /* defined(__Chapter02__Boy__) */
