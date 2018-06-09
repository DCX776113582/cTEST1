//
//  Circle.cpp
//  Chapter01
//
//  Created by mac on 18/1/29.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Circle.hpp"
#include <iostream>
#include <math.h>
#define PI 3.14f
/*实现类的行为
    返回类型 类名::类成员函数名（参数）{}
 */
using namespace std;
void Circle::drawCircle()
{
    std::cout << "圆的信息为：" << std::endl;
    std::cout << "半径为："<<_r<<std::endl;
    std::cout << "圆心("<<_x<<","<<_y<<")"<<std::endl;
    std::cout << "边宽"<<_w<<std::endl;
}
void Circle::setCircle(float r, float x, float y, float w)
{
    //形参变量的值对应拷贝给类的成员变量
    _r = r;
    _x = x;
    _y = y;
    _w = w;
/*
    Circle::r = r;
    Circle::x = x;
    Circle::y = y;
    Circle::w = w;
    
    this->r = r;
    this->x = x;
    this->y = y;
    this->w = w;*/
}
void Circle::printCircle()
{
    drawCircle();
}

Circle2::Circle2( )
{
    _radius = 0.0;
    _xCentre = 0.0;
    _yCentre = 0.0;
}
float Circle2::getRadius( )
{
    return _radius;
}
float Circle2::getCentreX( )
{
    return _xCentre;
}
float Circle2::getCentreY( )
{
    return _yCentre;
}
void Circle2::setCircle(float r, float x, float y)
{
 _radius = r;
    _xCentre = x;
    _yCentre = y;
}
float Circle2::distance (Circle2 c) {
    float xx = (_xCentre - c._xCentre) * (_xCentre -c._xCentre);
    float yy = (_yCentre - c._yCentre) * (_yCentre -c._yCentre);
    return sqrt(xx + yy);
}

Circle1:: Circle1()//不带参数默认构造函数
{
    this->radius=10.0;
    this->xCentre=0;
    this->yCentre=0;
    cout<<"不带参数默认构造圆并初始化圆的数据信息成功"<<endl;
}
Circle1:: Circle1(float r,float x,float y)//带参数默认构造函数
{
    this->radius = r;
    this->xCentre = x;
    this->yCentre = y;
    cout<<"带参数默认构造圆并初始化圆的数据信息成功"<<endl;
}
Circle1::~Circle1()
{
    cout<<"销毁圆对象成功"<<endl;
}
float Circle1:: getRadius()//访问函数：对象的私有成员radius
{
    return this->radius;
}
float Circle1:: getXCentre()//访问函数：对象的私有成员xCentre
{
    return this->xCentre;
}
float Circle1:: getYCentre()//访问函数：对象的私有成员yCentre
{
    return this->yCentre;
}
void Circle1:: setRadius(float r)//设置函数：对象的私有成员radius修改
{
    radius=r;
}
void Circle1:: setXCentre(float x)//设置函数：对象的私有成员xCentre修改
{
    this->xCentre=x;
}
void Circle1:: setYCentre(float y)//设置函数：对象的私有成员yCentre修改
{
    this->yCentre = y;
}
void Circle1:: setCircle(float r,float x,float y)//设置函数：对象所有数据修改
{
    this->radius = r;
    this->xCentre = x;
    this->yCentre = y;
}
void Circle1:: setCircleCentre(float x,float y)//设置函数：对象圆心数据修改
{
    this->xCentre = x;
    this->yCentre = y;
}
void Circle1:: printCircle()//普通函数：打印圆的信息
{
    cout<<"圆的信息如下："<<endl;
    cout<<"半径："<<this->getRadius()<<endl;
    cout<<"圆心：("<<this->getXCentre()<<","<<this->getYCentre()<<")"<<endl;
}
void Circle1::printRadiusOnly()
{
    //三种调用成员变量radius的方式等效
    cout<< "radius " << radius <<endl;//隐式
    cout<< "this->radius "<< this->radius << endl;//显式
    cout<< "(*this).radius "<< (*this).radius<<endl;//显式
}
float Circle1:: distance(Circle1 c)//普通函数：计算两圆的距离
{
    float dx = this->getXCentre()-c.getXCentre();
    float dy = this->getYCentre()-c.getYCentre();
    float dis = powf(dx,2)+powf(dy,2);
    return sqrtf(dis);
}
float Circle1:: area()//普通函数：计算圆面积
{
    return PI * powf(radius, 2);
}
float Circle1:: perimeter()//普通函数：计算圆周长
{
    return 2*PI*radius;
}



Circle4:: Circle4():radius(1),point(0,0)
{}
Circle4:: Circle4(const float& r,const float& x,const float& y):radius(r),point(x,y)
{}
Circle4:: Circle4(const float& r,const Point1& p):radius(r),point(p)
{}
Circle4:: ~Circle4()
{cout<<"Circle4::析构函数"<<endl;}
const float& Circle4::getRadius()
{
    return radius;
}
const Point1& Circle4::getPoint()
{
    return point;
}
const float& Circle4::getRadius()const
{
    return radius;
}
const Point1& Circle4::getPoint()const
{
    return point;
}
void Circle4:: setPoint(const Point1& p)
{
    point = p;
}
void Circle4:: setRadius(const float& r)
{
    radius=r;
}
void Circle4:: printCircle4()const
{
    cout<<"Circle4::const成员函数"<<endl;
    cout<<"r="<<radius<<endl;
    point.printPoint1();
}
void Circle4:: printCircle4()
{
    cout<<"Circle4::非const成员函数"<<endl;
    cout<<"r="<<radius<<endl;
    point.printPoint1();
}

Circle5::Circle5()
{
    this->radius = 10.0;
    this->x_centre = 0.0;
    this->y_centre = 0.0;
    cout<<"构造完成:"<<endl;
}
Circle5::Circle5(float r,float x,float y){
    this->radius = r;
    this->x_centre = x;
    this->y_centre = y;
    cout<<"构造完成:"<<endl;
}
float Circle5::getRadius()//访问函数：对象的私有成员radius
{
    return this->radius;
}
float Circle5::getXCentre()//访问函数：对象的私有成员xCentre
{
    return this->x_centre;
}
float Circle5::getYCentre()//访问函数：对象的私有成员yCentre
{
    return this->y_centre;
}
void Circle5::printRadiusOnly()
{
    //三种调用成员变量radius的方式等效
    cout<< "radius " << radius <<endl;//隐式
    cout<< "this->radius "<< this->radius << endl;//显式
    cout<< "(*this).radius "<< (*this).radius<<endl;//显式
}
void Circle5::printCircle()//普通函数：打印圆的信息
{
    cout<<"圆的信息如下："<<endl;
    cout<<"半径："<<this->getRadius()<<endl;
    cout<<"圆心：("<<this->getXCentre()<<","<<this->getYCentre()<<")"<<endl;
}
Circle5& Circle5::setRadius(const float& r)//设置函数：对象的私有成员radius修改
{
    this->radius=r;
    return (*this);
}
Circle5& Circle5::setXCentre(const float& x)//设置函数：对象的私有成员xCentre修改
{
    this->x_centre=x;
    return (*this);
}
Circle5& Circle5::setYCentre(const float& y)//设置函数：对象的私有成员yCentre修改
{
    this->y_centre=y;
    return (*this);
}
void Circle5::setCircle(const float& r,const float& x,const float& y)//设置函数：对象所有数据修改
{
    this->radius=r;
    this->x_centre=x;
    this->y_centre=y;
}
void Circle5::setCircleCentre(const float& x,const float& y)//设置函数：对象圆心数据修改
{
    this->x_centre=x;
    this->y_centre=y;
}
Circle5::~Circle5( )
{
    cout<<"析构完成:"<<endl;
}
