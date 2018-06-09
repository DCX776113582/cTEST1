//
//  point.h
//  Chapter04_Demo4
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo4__point__
#define __Chapter04_Demo4__point__

#include <iostream>
using namespace std;

class Point
{
private:
    double x;
    double y;
    
public:
    Point(double i, double j);
    void print( ) const;
};

class Figure//图形类
{
private:
    //什么关系？ 组合
    Point center;
    
public:
    Figure (double i = 0, double j = 0);
    Point& location();
    void move(Point p);
    
    //纯虚函数，没有函数体，不需要实现。在子类里实现纯虚函数的具体功能。
    //对于父类Figure来说，无法确定如何绘制， draw函数也就无法实现。
    virtual void draw() = 0;
    virtual void rotate(double d) = 0;
};

class Circle : public Figure
{
private:
    double radius;
    
public:
    Circle(double i = 0, double j = 0, double r = 0);
    void draw();
    void rotate(double d);
};


class Square : public Figure
{
private:
    double side;
    double angle;
    
public:
    Square(double i = 0, double j = 0, double d = 0, double a = 0);
    void draw();
    void rotate(double a);
    void vertices();
};

#endif /* defined(__Chapter04_Demo4__point__) */
