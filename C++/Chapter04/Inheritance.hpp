//
//  Inheritance.h
//  Chapter04
//
//  Created by mac on 18/2/25.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04__Inheritance__
#define __Chapter04__Inheritance__

#include <iostream>
using namespace std;
//父类（基类）
class Person{
protected://受保护
    char name[15];
    int age;
public:
    Person(const char * _name = "rider",int _age = 20)
    {
        strcpy(name, _name);
        age = _age;
    }
    void print()
    {
        cout<<"Person::name="<<name<<endl;
        cout<<"Person::age="<<age<<endl;
    }
};
//子类（派生类）：继承父类
class student:public Person{
private:
    int ID;
public:
    student(int _ID = 1000)
    {
        //构造初始化父类部分
        strcpy(name,"kuuga");
        age = 18;
        //构造初始化子类部分
        ID = _ID;
    }
    //覆盖（重写）
    void print()
    {
        Person::print();//打印子类基本信息（继承父类部分）
        cout<<"student::ID="<<ID<<endl;
    }
};
#endif /* defined(__Chapter04__Inheritance__) */
