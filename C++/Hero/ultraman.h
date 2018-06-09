//
//  ultraman.h
//  GameDrive
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __GameDrive__ultraman__
#define __GameDrive__ultraman__

#include "hero.h"
class Ultraman:public Hero{
protected:
    int age;
    string address;
public:
    Ultraman(string _name="name",string _high="high",string _wight="wight",int _age = 0,string _address = "address");//构造函数
    ~Ultraman();//析构函数
    void print();//函数重写
    Ultraman& operator=(Ultraman& u1);//赋值运算符重载
    //输出/输入运算符重载
    friend ostream& operator<<(ostream& out,const Ultraman& u1);
    friend istream& operator>>(istream& in,Ultraman& u1);
};
/*class ultraman:public Ultraman{
public:
    ultraman(string _name="Ultraman",string _high="48m",string _wight="1500t",int _age = 0,string _address = "M78星云");//构造函数
    ~ultraman();//析构函数
    void print();//函数重写
    ultraman& operator=(ultraman& u1);//赋值运算符重载
    //输出/输入运算符重载
    friend ostream& operator<<(ostream& out,const ultraman& u1);
    friend istream& operator>>(istream& in,ultraman& u1);
};*/
#endif /* defined(__GameDrive__ultraman__) */
