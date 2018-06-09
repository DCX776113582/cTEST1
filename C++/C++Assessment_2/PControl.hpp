//
//  PControl.h
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __C__Assessment_2__PControl__
#define __C__Assessment_2__PControl__

#include "Plane.hpp"
/*创建飞机控制类（飞机的容器类）（30分）
 属性：指向飞机的飞机类指针（Plane** p），飞机个数（int num），飞机索引（int index）
 行为：构造飞机控制类，三大件实现，添加飞机（void addPlane(Plan& p)）功能，删除飞机（Plane& destroyPlane()）功能
 以及如下普通功能
 a、用一个成员函数play_print(Plane& p),它负责打印传递给它的飞机的信息。
 a、用一个成员函数plane_fly(Plane& p),它负责让传递给它的飞机起飞的方式。
 b、用一个成员函数plane_land(Plane& p),它负责让传递给它的飞机着陆方式。
 c、用一个成员函数plane_modal(Plane& p),它负责让传递给它的飞机查询型号。
*/
class Plane;
class PControl{
private:
    int capacity;
    Plane** p;//指向飞机的飞机类指针
    int num;//飞机个数
    int index;//飞机索引
public:
    PControl();//默认构造
    PControl(int _capacty,Plane** _p,int _num,int _index);//普通构造
    PControl(PControl&pc1);//拷贝构造
    PControl& operator=(PControl& pc1);//赋值运算符重载
    ~PControl();//析构函数
    //获取函数
    int& getNum();
    int& getIndex();
    Plane** getP();
    //功能函数
    void addPlane(Plane& p1);//添加飞机
    Plane& destroyPlane();//删除飞机
    void play_print(Plane& p1);//打印传递给它的飞机的信息。
    void plane_fly(Plane& p1);//传递给它的飞机起飞的方式
    void plane_land(Plane& p1);//传递给它的飞机着陆方式
    void plane_modal(Plane& p1);//传递给它的飞机查询型号
};
#endif /* defined(__C__Assessment_2__PControl__) */
