//
//  Problem.cpp
//  ProblemSets
//
//  Created by mac on 18/1/30.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Problem.hpp"
#include <math.h>
/******************************************************
 *                  C++_Exercise1.txt第一题            *
 ******************************************************/
using namespace std;
CPoint::CPoint():xCPoint(0),yCPoint(0)
{}
CPoint::CPoint(float x,float y):xCPoint(x),yCPoint(y)
{}
CPoint::~CPoint()
{
    cout<<"销毁成功"<<endl;
}
void CPoint:: setCPoint(float x,float y)
{
    xCPoint=x;
    yCPoint=y;
}
float CPoint:: getCPointAx()
{
    return xCPoint;
}
float CPoint:: getCPointAy()
{
    return yCPoint;
}
void CPoint:: printCPoint()
{
    cout<<"坐标:("<<xCPoint<<","<<yCPoint<<")"<<endl;
}
float CPoint:: distance(CPoint c1)
{
    float dx = c1.xCPoint-xCPoint;
    float dy = c1.yCPoint-yCPoint;
    float dis = powf(dx,2)+powf(dy,2);
    return sqrtf(dis);
}
/******************************************************
 *                  C++_Exercise1.txt第二题            *
 ******************************************************/
CLine::CLine():_ACentreX(0),_ACentreY(0),_BCentreX(1),_BCentreY(1)
{}
CLine:: CLine(float Ax,float Ay,float Bx,float By):_ACentreX(Ax),_ACentreY(Ay),_BCentreX(Bx),_BCentreY(By)
{}
CLine:: ~CLine()
{
    cout<<"销毁成功"<<endl;
}
void CLine:: setCLine(float Ax,float Ay,float Bx,float By)
{
    _ACentreX = Ax;
    _ACentreY = Ay;
    _BCentreX = Bx;
    _BCentreY = By;
}
float CLine:: getCLineAx()
{
    return _ACentreX;
}
float CLine:: getCLineBx()
{
    return _BCentreX;
}
float CLine:: getCLineAy()
{
    return _ACentreY;
}
float CLine:: getCLineBy()
{
    return _BCentreY;
}
void CLine:: printCLine()
{
    cout<<"A:("<<_ACentreX<<","<<_ACentreY<<")"<<endl;
    cout<<"B:("<<_BCentreX<<","<<_BCentreY<<")"<<endl;
}
float CLine:: lengthCLine()
{
    float dx = _ACentreX-_BCentreX;
    float dy = _ACentreY-_BCentreY;
    float dis = powf(dx,2)+powf(dy,2);
    return sqrtf(dis);
}
/******************************************************
 *                  C++_Exercise2.txt第一题            *
 ******************************************************/
CPoint1:: CPoint1():xCPoint1(0),yCPoint1(0)
{
    cout<<"构造成功"<<endl;
}
CPoint1:: CPoint1(const float& x,const float& y):xCPoint1(x),yCPoint1(y)
{
    cout<<"构造成功"<<endl;
}
void CPoint1:: setCPoint1(const float& x,const float& y)
{
    xCPoint1=x;
    yCPoint1=y;
}
const float& CPoint1::getCPoint1Ax()
{
    return xCPoint1;
}
const float& CPoint1::getCPoint1Ay()
{
    return yCPoint1;
}
const float& CPoint1::getCPoint1Ax()const
{
    return xCPoint1;
}
const float& CPoint1::getCPoint1Ay()const
{
    return yCPoint1;
}

const void CPoint1::printCPoint1()const
{
    cout<<"("<<xCPoint1<<","<<yCPoint1<<")"<<endl;
}
const void CPoint1::printCPoint1()
{
    cout<<"("<<xCPoint1<<","<<yCPoint1<<")"<<endl;
}
const float CPoint1::distance(CPoint1 c1)const
{
    float dx = c1.xCPoint1-xCPoint1;
    float dy = c1.yCPoint1-yCPoint1;
    float dis = powf(dx,2)+powf(dy,2);
    return sqrtf(dis);
}
const float CPoint1::distance(CPoint1 c1)
{
    float dx = c1.xCPoint1-xCPoint1;
    float dy = c1.yCPoint1-yCPoint1;
    float dis = powf(dx,2)+powf(dy,2);
    return sqrtf(dis);
}
CPoint1::~CPoint1()
{
    cout<<"销毁成功"<<endl;
}

CLine1:: CLine1():_A(100,200),_B(200,300)
{
    cout<<"构造成功"<<endl;
}
CLine1:: CLine1(const CPoint1& da,const CPoint1& db):_A(da),_B(db)
{
    cout<<"构造成功"<<endl;
}
const CPoint1& CLine1:: getAPoint1()
{
    return _A;
}
const CPoint1& CLine1:: getBPoint1()
{
    return _B;
}
const CPoint1& CLine1::getAPoint1()const
{
    return _A;
}
const CPoint1& CLine1::getBPoint1()const
{
    return _B;
}
void CLine1::setCLine1(const CPoint1& da,const CPoint1& db)
{
    _A=da;
    _B=db;
}
const void CLine1::printCLine1()const
{
    cout<<"A:("<<_A.getCPoint1Ax()<<","<<_A.getCPoint1Ay()<<")"<<endl;
    cout<<"B:("<<_B.getCPoint1Ax()<<","<<_B.getCPoint1Ay()<<")"<<endl;
}
const void CLine1::printCLine1()
{
    cout<<"A:("<<_A.getCPoint1Ax()<<","<<_A.getCPoint1Ay()<<")"<<endl;
    cout<<"B:("<<_B.getCPoint1Ax()<<","<<_B.getCPoint1Ay()<<")"<<endl;
}
const float& CLine1::lengthCLine1()const
{
    float dx = _A.getCPoint1Ax()-_B.getCPoint1Ax();
    float dy = _A.getCPoint1Ay()-_B.getCPoint1Ay();
    float dis = powf(dx,2)+powf(dy,2);
    static float shu =sqrtf(dis) ;
    return shu;
}
const float& CLine1::lengthCLine1()
{
    float dx = _A.getCPoint1Ax()-_B.getCPoint1Ax();
    float dy = _A.getCPoint1Ay()-_B.getCPoint1Ay();
    float dis = powf(dx,2)+powf(dy,2);
    static float shu =sqrtf(dis) ;
    return shu;
}

CLine1::~CLine1()
{
    cout<<"销毁成功"<<endl;
}
