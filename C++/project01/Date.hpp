//
//  Date.h
//  project01
//
//  Created by mac on 18/2/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __project01__Date__
#define __project01__Date__

#include <iostream>
using namespace std;
class Date{
private://成员变量
    int year;
    int month;
    int day;
public://构造函数
    Date();//默认构造函数，创建对象并初始化成员变量
    Date(int _y,int _m,int _d);
    
    Date(const Date& date);//拷贝构造
public://访问函数
    const int getYear() const;
    const int getMonth() const;
    const int getDay() const;
public://设置函数
    void setYear(const int _y);
    void setMonth(const int _m);
    void setDay(const int _d);
public://功能函数
    void print()const;
public://运算符重载
    Date & operator=(const Date& date);//赋值重载
    friend ostream& operator<<(ostream& out,const Date& date);//输出重载
    friend istream& operator>>(istream& in,Date& date);//输入重载
public://析构函数
    ~Date();//销毁对象
};
#endif /* defined(__project01__Date__) */
