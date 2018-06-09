//
//  Person.h
//  project01
//
//  Created by mac on 18/2/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __project01__Person__
#define __project01__Person__

#include "Date.hpp"

class Person{
private:
    //姓名、邮件、生日
    char* name;//姓名
    char* emailAddress;//邮件
    Date birthday;//生日
public:
    Person();
    Person(const char * _name,const char * _emailAddress,Date& _birthday);
    Person(const char * _name,const char * _emailAddress,int _year,int _month,int _day);
    Person(const Person & per);
public:
    ~Person();
public:
    //普通功能函数
    void print();
    //设置函数
    void setName(const char * _name);
    void setEmailAddress(const char * _emailAddress);
    void setBirthday(Date & _birthday);
    void setBirthday(int _year,int _month,int _day);
    //访问函数
    char * getName();
    char * getEmailAddress();
    Date & getBirthday();
    //赋值运算符重载
    Person& operator=(Person& person);
    //输出、输入重载函数
    friend ostream& operator<<(ostream& out,const Person& per);
    friend istream& operator>>(istream& in,Person& per);
};
#endif /* defined(__project01__Person__) */
