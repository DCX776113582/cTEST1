//
//  point.cpp
//  Chapter04_Demo4
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "point.h"
Point::Point(double i, double j) : x(i), y(j){}

void Point::print( ) const
{
    cout << "(" << x << ", " << y << ")";
}


Figure::Figure(double i, double j) : center(i, j) {}

Point& Figure::location( )
{
    return center;
}

void Figure::move(Point p)
{
    center = p;
    
    //移动图形后，重新绘制
    draw( );
}

Circle::Circle(double i, double j, double r) : Figure(i, j), radius(r){}

//在子类里，实现了继承自父类的纯虚函数。
void Circle::draw( )
{
    cout << "A circle with center ";
    location( ).print( );
    cout << " and radius " << radius << endl;
}

void Circle::rotate(double)
{
    cout << "no effect.\n";
}

Square::Square(double i, double j, double d, double a)	: Figure(i, j), side(d), angle(a) {}

void Square::draw( )
{
    cout << "A square with center ";
    location().print();
    cout << " side length " << side << ".\n"
    << "The angle between one side and the X-axis is " << angle << endl;
}

void Square::rotate(double a)
{
    angle += a;
    cout << "The angle between one side and the X-axis is " << angle << endl;
}

void Square::vertices()
{
    cout << "The vertices of the square are: 3\n";
}
