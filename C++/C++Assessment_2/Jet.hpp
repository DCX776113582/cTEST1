//
//  Jet.h
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __C__Assessment_2__Jet__
#define __C__Assessment_2__Jet__

#include "Plane.hpp"
/*创建喷气式飞机类（派生类）（20分）
 属性：
 行为：构造喷气式飞机，起飞（fly），着陆（land），查询型号（modal），打印飞机信息（printInfo）
 其他行为：三大件
*/
class Jet:public Plane{
public:
    Jet(const char* _modal="J1",const char* _No="J-15",const char* _name="JK");//默认构造函数
    Jet(const Jet&p1);//拷贝构造函数
    Jet& operator=(Jet&c1);//赋值运算符重载
    const char* fly();//起飞
    const char* land();//着陆
    char* modal();//查询型号
    void printInfo();//打印飞机信息
    ~Jet();//析构函数
};

#endif /* defined(__C__Assessment_2__Jet__) */
