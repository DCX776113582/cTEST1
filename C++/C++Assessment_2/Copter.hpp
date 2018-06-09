//
//  Copter.h
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __C__Assessment_2__Copter__
#define __C__Assessment_2__Copter__

#include "Plane.hpp"
/*创建直升机类（派生类）（20分）
 属性：
 行为：构造直升机，起飞（fly），着陆（land），查询型号（modal），打印飞机信息（printInfo）
 其他行为：三大件
*/
class Copter:public Plane{
public:
    Copter(const char* _modal="C1",const char* _No="C-15",const char* _name="MA");//默认构造函数
    Copter(const Copter&p1);//拷贝构造函数
    Copter& operator=(Copter&c1);//赋值运算符重载
    const char* fly();//起飞
    const char* land();//着陆
    char* modal();//查询型号
    void printInfo();//打印飞机信息
    ~Copter();//析构函数
};
#endif /* defined(__C__Assessment_2__Copter__) */
