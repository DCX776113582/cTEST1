//
//  Circle.h
//  Chapter01
//
//  Created by mac on 18/1/29.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter01__Circle__
#define __Chapter01__Circle__

#include <stdio.h>
#include <math.h>
#include "Point.hpp"
#include "Thing.hpp"
//定义c++的类型
class Circle2{
public:
    Circle2();
    float getRadius();
    float getCentreX();
    float getCentreY();
    void setCircle(float r, float x, float y);
    float distance(Circle2 c1);
private:
    float _radius;
    float _xCentre;
    float _yCentre;
};
class Circle//类型名称（首字母大写）
{
    //stat
private://关闭权限，对内开放
    float _r;//半径
    float _x;//x轴坐标
    float _y;//y轴坐标
    float _w;//限宽度
//     float r;//半径
//     float x;//x轴坐标
//     float y;//y轴坐标
//     float w;//限宽度

    //behaviour
public://打开权限，对外开放
    void drawCircle();//画圆
    void setCircle(float r,float x,float y,float w);//设置圆
    void printCircle();//打印
};
class Circle3
{
public:
    Circle3(){}; //default constructor
    
    Circle3(float x_centre,float y_centre,float r)
    :point(x_centre,y_centre) {radius = r;}
    //初始化列表，在Circle的构造函数里，
    //调用了Point类的构造函数，并传递相应的参数，给Point的成员变量赋值。
    
    void setCircle( float r, Point p )
    {
        radius = r;
        point = p; //point.x=p.x; point.y=p.y
    }
    
    void printCircle() const
    //不能通过成员函数修改成员变量的值
    //当你不需要在成员函数里修改成员变量的值的时候，建议加上const，可以增加程序的健壮性（保护性、安全性）。
    {
        cout << "radius:" <<radius;
        point.printPoint(); //OK
        //cout<<point.x << point.y  //ERROR
    }
private:
    float radius;
    Point point;//圆心
};
class Circle1 {
    float radius;
    float xCentre;
    float yCentre;
//成员函数（公有）
public:
    Circle1();//构造函数：创建对象并初始化数据成员
//    Circle1(float r);//构造函数
    Circle1(float r,float x,float y);//构造函数
public:
    float getRadius();//访问函数：对象的私有成员radius
    float getXCentre();//访问函数：对象的私有成员xCentre
    float getYCentre();//访问函数：对象的私有成员yCentre
public:
    void setRadius(float r);//设置函数：对象的私有成员radius修改
    void setXCentre(float x);//设置函数：对象的私有成员xCentre修改
    void setYCentre(float y);//设置函数：对象的私有成员yCentre修改
    void setCircle(float r,float x,float y);//设置函数：对象所有数据修改
    void setCircleCentre(float x,float y);//设置函数：对象圆心数据修改
public:
    ~Circle1();//析构函数：销毁对象
public:
    void printCircle();//普通函数：打印圆的信息
    void printRadiusOnly();
    float distance(Circle1 c);//普通函数：计算两圆的距离
    float area();//普通函数：计算圆面积
    float perimeter();//普通函数：计算圆周长
};
class Circle4{
private:
    float radius;
    Point1 point;
public://构造函数
    Circle4();
    Circle4(const float& r,const float& x,const float& y);
    Circle4(const float& r,const Point1& p);//普通构造函数
public://设置函数
    void setPoint(const Point1& p);
    void setRadius(const float& r);
public://访问函数
    const float& getRadius();
    const Point1& getPoint();
    const float& getRadius()const;
    const Point1& getPoint()const;

public://普通函数
    void printCircle4()const;
    void printCircle4();
public://析构函数
    ~Circle4();
};
class Circle5//DEmo08
{//Circle5*const this;
    //*this当前对象
public://构造函数
    Circle5( );
    ~Circle5( );
    Circle5(float r,float x,float y);
    
public://访问函数
    float getRadius();//访问函数：对象的私有成员radius
    float getXCentre();//访问函数：对象的私有成员xCentre
    float getYCentre();//访问函数：对象的私有成员yCentre
public://功能函数
    void printRadiusOnly();
    void printCircle();//普通函数：打印圆的信息
public://设置函数
    Circle5& setRadius(const float& r);//设置函数：对象的私有成员radius修改
    Circle5& setXCentre(const float& x);//设置函数：对象的私有成员xCentre修改
    Circle5& setYCentre(const float& y);//设置函数：对象的私有成员yCentre修改
    void setCircle(const float& r,const float& x,const float& y);//设置函数：对象所有数据修改
    void setCircleCentre(const float& x,const float& y);//设置函数：对象圆心数据修改
private:
    float radius;
    float x_centre;
    float y_centre;
    //*this就是对象自己。
    //用this调用成员函数的两种方式：
    //(*this).printRadiusOnly();
    //this->printRadiusOnly();
    //(*this).radius;
};

#endif /* defined(__Chapter01__Circle__) */
