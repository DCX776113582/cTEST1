//
//  circle.cpp
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "circle.hpp"
Circle:: Circle(double _x,double _y,double _r):Point(_x,_y)
{
    r = _r;
}
double Circle:: area()
{
    return (PI*r*r);
}
void Circle:: print()
{
    cout<<"Circle information:"<<endl;
    Point::print();
    cout<<"半径:"<<r<<endl;
}