//
//  Person.h
//  Chapter01Demo07
//
//  Created by mac on 18/2/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter01Demo07__Person__
#define __Chapter01Demo07__Person__

#include <iostream>
using namespace std;
class Person {
private:
    //类非静态成员变量
    const long _id;  //编号（唯一性）
    char _name[10];
    int _age;
    char _sex;
    //类的静态成员变量
    static int index; //计数器
public:
    Person();
    Person(const char name[],const int& age,const char&sex);
public:
    ~Person();
public:
    char*getName()
    {
        return this->_name;
    }
public:
    //静态成员函数
    static int total();
    //非静态成员函数
    void printPerson()const;
    void printPerson();
};

#endif /* defined(__Chapter01Demo07__Person__) */
