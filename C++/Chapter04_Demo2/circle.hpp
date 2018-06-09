//
//  circle.h
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo2__circle__
#define __Chapter04_Demo2__circle__

#include "point.hpp"
#define PI 3.14
class Circle:public Point{
protected:
    double r;
public:
    Circle(double _x = 0,double _y = 0,double _r = 0);
    double area();
    void print();
};
#endif /* defined(__Chapter04_Demo2__circle__) */
