//
//  Point.h
//  Chapter01
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter01__Point__
#define __Chapter01__Point__

#include <iostream>
using namespace std;
class Point1{
private:
    float xPoint;
    float yPoint;
public:
    Point1();
    Point1(const float& x,const float& y);
public:
    //非const函数返回值为引用
    const float& getXPoint();
    const float& getYPoint();
    const float& getXPoint()const;
    const float& getYPoint()const;
public:
    void setXPoint(const float& x);
    void setYPoint(const float& y);
public:
    ~Point1();
public:
    void printPoint1()const;
    void printPoint1();
};

#endif /* defined(__Chapter01__Point__) */
