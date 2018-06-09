//
//  PControl.cpp
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "PControl.hpp"
PControl::PControl()//默认构造
{
    capacity = 4;
    num = 0;
    p = new Plane*[capacity];
    for (int i = 0; i<capacity; ++i) {
        p[i] = NULL;
    }
    index = 0;
}
PControl::PControl(int _capacity,Plane** _p,int _num,int _index):num(_num),index(_index),capacity(_capacity)//普通构造
{
    p = new Plane*[_capacity];
    for (int i = 0; i<_capacity; ++i) {
        p[i] = NULL;
    }
}
PControl::PControl(PControl&pc1)//拷贝构造
{
    capacity = pc1.capacity;
    num = pc1.num;
    p = new Plane*[pc1.capacity];
    for (int i = 0; i<pc1.capacity; ++i) {
        p[i] = NULL;
    }
    index = pc1.index;
}
PControl& PControl::operator=(PControl& pc1)
{
    if (this!=&pc1) {
        capacity = pc1.capacity;
        num = pc1.num;
        if (p!=NULL) {
            delete [] p;
            p = new Plane*[pc1.capacity];
            for (int i = 0; i<pc1.capacity; ++i) {
                p[i] = pc1.p[i];
            }
        }
        index = pc1.index;
    }
    return *this;
}
int& PControl::getNum()
{
    return num;
}
int& PControl::getIndex()
{
    return index;
}
Plane** PControl::getP()
{
    return this->p;
}
void PControl::addPlane(Plane& p1)//添加飞机
{
    this->p[num++]= &p1;
}
Plane& PControl::destroyPlane()//删除飞机
{
    Plane * per = this->p[--num];
    return *per;
}
void PControl::play_print(Plane& p1)//打印传递给它的飞机的信息。
{
    p1.printInfo();
}
void PControl::plane_fly(Plane& p1)//传递给它的飞机起飞的方式
{
    cout<<p1.fly()<<endl;
}
void PControl::plane_land(Plane& p1)//传递给它的飞机着陆方式
{
    cout<<p1.land()<<endl;
}
void PControl::plane_modal(Plane& p1)//传递给它的飞机查询型号
{
    cout<<p1.modal()<<endl;
}
PControl::~PControl()//析构函数
{
    if (p!=NULL) {
        delete [] p;
        p = NULL;
    }
}
