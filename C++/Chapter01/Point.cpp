//
//  Point.cpp
//  Chapter01
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Point.hpp"
Point1:: Point1():xPoint(0),yPoint(0)
{}
Point1:: Point1(const float& x,const float& y):xPoint(x),yPoint(y)
{}
Point1:: ~Point1()
{cout<<"Point1::析构函数"<<endl;}
void Point1:: printPoint1()const
{
    cout<<"Point1::const成员函数"<<endl;
    cout<<"("<<xPoint<<","<<yPoint<<")"<<endl;
}
void Point1::setXPoint(const float& x)
{
    xPoint = x;
}
void Point1::setYPoint(const float& y)
{
    yPoint = y;
}

const float& Point1::getXPoint()
{
    return xPoint;
}
const float& Point1::getYPoint()
{
    return yPoint;
}
const float& Point1::getXPoint()const
{
    return xPoint;
}
const float& Point1::getYPoint()const
{
    return yPoint;
}

void Point1:: printPoint1()
{
    cout<<"Point1::非const成员函数"<<endl;
    cout<<"("<<xPoint<<","<<yPoint<<")"<<endl;
}


