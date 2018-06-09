//
//  Date.cpp
//  project01
//
//  Created by mac on 18/2/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Date.hpp"

Date:: Date()
{
    year = 2000;
    month = 1;
    day = 1;
}
Date:: Date(int _y,int _m,int _d):year(_y),month(_m),day(_d)
{}
Date:: Date(const Date& date)
{
    year = date.year;
    month = date.month;
    day = date.day;
}
const int Date:: getYear() const
{
    return year;
}
const int Date:: getMonth() const
{
    return month;
}
const int Date:: getDay() const
{
    return day;
}
void Date:: setYear(const int _y)
{
    year = _y;
}
void Date:: setMonth(const int _m)
{
    month = _m;
}
void Date:: setDay(const int _d)
{
    day = _d;
}
void Date:: print()const
{
    cout<<year<<"-"<<month<<"-"<<day<<endl;
}
Date & Date:: operator=(const Date& date)//赋值重载
{
    if (this!=&date) {
        year = date.year;
        month = date.month;
        day = date.day;
    }
    return (*this);
}
//friend：类外直接通过该对象访问私有成员，破坏封装性
ostream& operator<<(ostream& out,const Date& date)//输出重载
{
    out<<date.year<<"-"<<date.month<<"-"<<date.day<<endl;
    return out;
}
istream& operator>>(istream& in,Date& date)//输入重载
{
    cout<<"Year:";
    in>>date.year;
la:cout<<"Month:";
    in>>date.month;
    if (date.month>12||date.month<=0) {
        cout<<"输入错误，重新输入"<<endl;
        goto la;
    }
lc:cout<<"Day:";
    in>>date.day;
    if (date.day<=0||date.day>31) {
        cout<<"输入错误，重新输入"<<endl;
        goto lc;
    }
    return in;
}

Date:: ~Date()
{}
