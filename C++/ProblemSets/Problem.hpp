//
//  Problem.h
//  ProblemSets
//
//  Created by mac on 18/1/30.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __ProblemSets__Problem__
#define __ProblemSets__Problem__

#include <iostream>
/*1. 从键盘输入两个点的坐标值，计算两点间距离。
 要求：1)定义一个CPoint类，属性包括X，Y坐标值;功能包括构造点对象、设置点的各个坐标、获取点的各个坐标、打印点坐标的信息。
	2)添加功能实现计算两点之间的距离。
	3)类定义中必须有自定义默认构造函数和普通的带参数的构造函数、使用初始化列表实现
*/
class CPoint{
    float xCPoint;
    float yCPoint;
public:
    CPoint();
    CPoint(float x,float y);
//    CPoint(float x=1,float y=1);
    ~CPoint();
public:
    void setCPoint(float x,float y);
    float getCPointAx();
    float getCPointAy();
public:
    void printCPoint();
    float distance(CPoint c1);
};
/*
 2. 计算一个线段长度，两个端点的坐标值分别为 A（100，200）、B（200，300）。
 要求：1)定义一个CLine类，属性包括两个断点的坐标_ACentreX、_ACentreB、_BCentreX、_BCentreY；功能包括构造一个线对象、设置点的各个坐标、获取各个点的坐标、打印各个点的坐标信息。
	2)添加功能实现计算线长。
	3)类定义中必须有自定义默认构造函数和普通的带参数的构造函数、使用初始化列表实现
 */
class CLine{
    float _ACentreX;
    float _ACentreY;
    float _BCentreX;
    float _BCentreY;
public:
    CLine();
    CLine(float Ax,float Ay,float Bx,float By);
    ~CLine();
public:
    void setCLine(float Ax,float Ay,float Bx,float By);
    float getCLineAx();
    float getCLineBx();
    float getCLineAy();
    float getCLineBy();
public:
    void printCLine();
    float lengthCLine();
};
/* 1. 计算一个线段长度，两个端点的坐标值分别为 A（100，200）、B（200，300）。
 要求：1)定义一个CLine类，属性是CPoint类的对象。使用复合类的形式完成
 2）为类中的成员函数可以添加const的地方均添加上const的修饰；
 3）其余功能均与Exercise1.txt中一致不变进行测试
*/
class CPoint1{
    float xCPoint1;
    float yCPoint1;
public:
    CPoint1();
    CPoint1(const float& x,const float& y);
public:
    void setCPoint1(const float& x,const float& y);
    const float& getCPoint1Ax();
    const float& getCPoint1Ay();
    const float& getCPoint1Ax()const;
    const float& getCPoint1Ay()const;
public:
    const void printCPoint1()const;
    const void printCPoint1();
    const float distance(CPoint1 c1)const;
    const float distance(CPoint1 c1);
public:
    ~CPoint1();
};
class CLine1{
    CPoint1 _A;
    CPoint1 _B;
public://构造函数
    CLine1();
    CLine1(const CPoint1& da,const CPoint1& db);
    CLine1(const CLine1&a):_A(a._A),_B(a._B){}
public://
    const CPoint1& getAPoint1();
    const CPoint1& getBPoint1();
    const CPoint1& getAPoint1()const;
    const CPoint1& getBPoint1()const;
public://设置函数
    void setCLine1(const CPoint1& da,const CPoint1& db);
public://功能函数
    const void printCLine1()const;
    const void printCLine1();
    const float& lengthCLine1()const;
    const float& lengthCLine1();
public://析构函数：对象离开作用域调用
    ~CLine1();
};
#endif /* defined(__ProblemSets__Problem__) */
