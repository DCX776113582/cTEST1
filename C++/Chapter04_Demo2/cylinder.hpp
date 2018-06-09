//
//  cylinder.h
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo2__cylinder__
#define __Chapter04_Demo2__cylinder__

#include "circle.hpp"
class Cylinder:public Circle{
protected:
    double high;
public:
    Cylinder(double _hv = 0,double _rv = 0,double _xv = 0,double _yv = 0);
    double cylinderV();
    double cyarea();
    void print();
};
#endif /* defined(__Chapter04_Demo2__cylinder__) */
