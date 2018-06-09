//
//  Data.h
//  ProblemSets
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __ProblemSets__Data__
#define __ProblemSets__Data__

#include <iostream>
using namespace std;
class Date {
private:
    int _year;
    int _month;
    int _day;
public:
//    Date();
    Date(const int& year=2000,const int& month=1,const int& day=1);
    Date(const Date&da):_year(da._year),_month(da._month),_day(da._day){}
public:
    int& getYear();
    int& getMonth();
    int& getDay();
    const int& getYear()const;
    const int& getMonth()const;
    const int& getDay()const;
public:
    const Date& setYear(const int& year);
    const Date& setMonth(const int& month);
    const Date& setDay(const int& day);
    void setBirthday(const int& year,const int& month,const int& day);
public:
    void printDate()const;
    void printDate();
public:
    Date& operator=(const Date& da);
    friend ostream& operator<<(ostream& out,Date&da);
    friend istream& operator>>(istream& in,Date&da);
public:
    ~Date();
};
bool operator>(Date&d1,Date&d2);
#endif /* defined(__ProblemSets__Data__) */
