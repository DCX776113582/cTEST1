//
//  Person.h
//  ProblemSets
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __ProblemSets__Person__
#define __ProblemSets__Person__

#include <iostream>
#include "Data.hpp"
using namespace std;
/*
 3、完成任务一：Person类的定义和功能测试（修改其构造函数和默认构造函数的形式、使用初始化列表形式）
 2、继续完成任务一：Person类的定义和功能测试（修改其构造函数和默认构造函数的形式、使用初始化列表形式）
 要求：1)定义一个Person类，属性是Date类的对象。使用复合类的形式完成
 2）为类中的成员函数可以添加const的地方均添加上const的修饰；
 3）其余功能均与Exercise1.txt中一致不变进行测试
 */
#define N 3
class Person{
private://成员变量
    const long _id;  //编号（唯一性）
    char  *_name;
    char  *_email_address;
    Date date;
    
    static int index; //计数器
public:
    Person();
    Person(const char *name,const char *email,const int& year,const int& month,const int& day);
    Person(const char *name,const char *email,const Date BirthDate);
    Person(const Person&a):_id(a._id),date(a.date){_name=new char(strlen(a._name)+1);
        strcpy(_name, a._name);
        _email_address=new char(strlen(a._email_address)+1);
        strcpy(_email_address, a._email_address);
    }
public:
    int& getINde()
    {
        return index;
    }
    const long getId();
    const long getId()const;
    char* GetName();
    char* GetEmailAddress();
    Date GetBirthDate();
    const char* GetName()const;
    const char* GetEmailAddress()const;
    const Date& GetBirthDate()const;
public:
     Person& setName(char *name);
     Person& setEmailAddress(char *email);
     Date& setBirthDate(int year,int month,int day);
     Date& setBirthDate(Date one);
     Person& operator=(const Person& a);
public:
    friend ostream& operator<<(ostream& out,Person& a);
    friend istream& operator>>(istream& in,Person& a);
public:
    const Person& Print()const;
    Person& Print();
    
public:
    ~Person();
};
void CreatDate(Person r[]);
void PrintDate(Person r[]);
void ModifyDate(Person r[]);
void DeleteDate(Person r[]);
void exi();
#endif /* defined(__ProblemSets__Person__) */
