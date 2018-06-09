//
//  Jet.cpp
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Jet.hpp"
Jet::Jet(const char* _modal,const char* _No,const char* _name):Plane(_modal,_No,_name)//默认构造函数
{}
Jet::Jet(const Jet&p1):Plane(p1)//拷贝构造函数
{
   /* fModal = new char[strlen(p1.fModal)+1];
    strcpy(fModal, p1.fModal);
    fNo = new char[strlen(p1.fNo)+1];
    strcpy(fNo, p1.fNo);
    fName = new char[strlen(p1.fName)+1];
    strcpy(fName, p1.fName);
    */
}
Jet& Jet::operator=(Jet&c1)//赋值运算符重载
{
    if (this!=&c1) {
        /*if (fModal!=NULL) {
            delete [] fModal;
            fModal = new char[strlen(c1.fModal)+1];
            strcpy(fModal, c1.fModal);
        }
        if (fNo!=NULL) {
            delete [] fNo;
            fNo = new char[strlen(c1.fNo)+1];
            strcpy(fNo, c1.fNo);
        }
        if (fName!=NULL) {
            delete [] fName;
            fName = new char[strlen(c1.fName)+1];
            strcpy(fName, c1.fName);
        }
         */
        Plane::operator=(c1);
    }
    return *this;
}
const char* Jet::fly()//起飞
{
    const char * fly = "Jet::喷气式飞机起飞方式";
    return fly;
}
const char* Jet::land()//着陆
{
    const char* land = "Jet::喷气式飞机着陆方式";
    return land;
}
char* Jet::modal()//查询型号
{
    return fModal;
}
void Jet::printInfo()//打印飞机信息
{
    cout<<"型号："<<fModal<<endl;
    cout<<"编码："<<fNo<<endl;
    cout<<"驾驶员："<<fName<<endl;
    cout<<"起飞方式："<<fly()<<endl;
    cout<<"着陆方式："<<land()<<endl;
}
Jet::~Jet(){}//析构函数
