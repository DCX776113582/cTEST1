//
//  point.cpp
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "point.hpp"
Point:: Point(double _x,double _y):x(_x),y(_y)
{}
void Point:: print()
{
    cout<<"圆心:("<<x<<","<<y<<")"<<endl;
}