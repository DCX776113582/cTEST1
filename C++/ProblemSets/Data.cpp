//
//  Data.cpp
//  ProblemSets
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Data.hpp"
//Date:: Date():_year(2018),_month(1),_day(1)
//{}
Date:: Date(const int& year,const int& month,const int& day):_year(year),_month(month),_day(day)
{}
const Date& Date::setYear(const int& year)
{
    this->_year=year;
    return (*this);
}
const Date& Date::setMonth(const int& month)
{
    this->_month=month;
    return (*this);
}
const Date& Date::setDay(const int& day)
{
    this->_day=day;
    return (*this);
}
void Date::setBirthday(const int& year,const int& month,const int& day)
{
    this->_year=year;
    this->_month=month;
    this->_day=day;
}
void Date:: printDate()const
{
    cout<<"("<<this->_year<<"."<<this->_month<<"."<<this->_day<<")"<<endl;
}
void Date::printDate()
{
    cout<<"("<<this->_year<<"."<<this->_month<<"."<<this->_day<<")"<<endl;
}
int& Date::getYear()
{
    return this->_year;
}
int& Date::getMonth()
{
    return this->_month;
}
int& Date::getDay()
{
    return this->_day;
}
const int& Date::getYear()const
{
    return this->_year;
}
const int& Date::getMonth()const
{
    return this->_month;
}
const int& Date::getDay()const
{
    return this->_day;
}
ostream& operator<<(ostream& out,Date&da)
{
    out<<"日期："<<da._year<<"年"<<da._month<<"月"<<da._day<<"日"<<endl;
    return out;
}
istream& operator>>(istream& in,Date&da)
{
    in>>da._year>>da._month>>da._day;
    return in;
}
Date& Date::operator=(const Date&da)
{
    _year=da._year;
    _month=da._month;
    _day=da._day;
    return *this;
}
bool operator>(Date& d1,const Date&d2)
{
    d1.getYear()=d1.getYear()>d2.getYear()?d1.getYear():d2.getYear();
    d1.getMonth() = d1.getMonth()>d2.getMonth()?d1.getMonth():d2.getMonth();
    d1.getDay() =d1.getDay()>d2.getDay()?d1.getDay():d2.getDay();
    return true;
}

Date::~Date()
{}
