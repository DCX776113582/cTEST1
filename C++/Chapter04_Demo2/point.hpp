//
//  point.h
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo2__point__
#define __Chapter04_Demo2__point__

#include <iostream>
using namespace std;
class Point{
protected:
    double x;
    double y;
public:
    Point(double _x = 0,double _y = 0);
    void print();
};
#endif /* defined(__Chapter04_Demo2__point__) */
