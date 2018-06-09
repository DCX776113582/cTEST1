//
//  cylinder.cpp
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "cylinder.hpp"
Cylinder:: Cylinder(double _hv,double _rv,double _xv,double _yv):Circle(_xv,_yv,_rv)
{
    high = _hv;
}
double Cylinder:: cylinderV()
{
    return (Circle::area()*high);
}
double Cylinder:: cyarea()
{
    return (2*Circle::area()+(PI*2*r)*high);
}
void Cylinder:: print()
{
    cout<<"圆柱信息:"<<endl;
    cout<<"底圆面积:"<<Circle::area()<<endl;
    cout<<"底圆圆心:";Point::print();
    cout<<"圆柱高:"<<high<<endl;
    cout<<"全面积:"<<cyarea()<<"   体积:"<<cylinderV()<<endl;
}
