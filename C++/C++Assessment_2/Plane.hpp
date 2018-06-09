//
//  Plane.h
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __C__Assessment_2__Plane__
#define __C__Assessment_2__Plane__

#include <iostream>
using namespace std;
/*创建飞机类（基类）：作为抽象基类（10分）
 属性：型号（char* fModal），编码（char* fNo）,驾驶员（char* fName）
 行为：构造飞机； 起飞（fly），着陆（land），查询型号（modal），打印飞机信息（printInfo）均为纯虚函数
 其他行为：三大件*/
class Plane{
protected:
    char* fModal;//型号
    char* fNo;//编码
    char* fName;//驾驶员
public:
    Plane(const char* _modal="",const char* _No="",const char* _name="");//默认构造函数
    Plane(const Plane&p1);//拷贝构造函数
    virtual const char* fly()=0;//起飞
    virtual const char* land()=0;//着陆
    virtual char* modal()=0;//查询型号
    virtual void printInfo()=0;//打印飞机信息
    Plane& operator=(Plane&p1);//赋值运算符重载
    virtual ~Plane();//析构函数
};
#endif /* defined(__C__Assessment_2__Plane__) */
