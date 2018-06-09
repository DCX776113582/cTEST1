//
//  Plane.cpp
//  C++Assessment_2
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Plane.hpp"
Plane::Plane(const char* _modal,const char* _No,const char* _name)//默认构造函数
{
    fModal = new char[strlen(_modal)+1];
    strcpy(fModal, _modal);
    fNo = new char[strlen(_No)+1];
    strcpy(fNo, _No);
    fName = new char[strlen(_name)+1];
    strcpy(fName, _name);
}
Plane::Plane(const Plane&p1)//拷贝构造函数
{
    fModal = new char[strlen(p1.fModal)+1];
    strcpy(fModal, p1.fModal);
    fNo = new char[strlen(p1.fNo)+1];
    strcpy(fNo, p1.fNo);
    fName = new char[strlen(p1.fName)+1];
    strcpy(fName, p1.fName);
}
Plane& Plane::operator=(Plane&p1)//赋值运算符重载
{
    if (this!=&p1) {
        if (fModal!=NULL) {
            delete [] fModal;
            fModal = new char[strlen(p1.fModal)+1];
            strcpy(fModal, p1.fModal);
        }
        if (fNo!=NULL) {
            delete [] fNo;
            fNo = new char[strlen(p1.fNo)+1];
            strcpy(fNo, p1.fNo);
        }
        if (fName!=NULL) {
            delete [] fName;
            fName = new char[strlen(p1.fName)+1];
            strcpy(fName, p1.fName);
        }
    }
    return *this;
}
Plane::~Plane()//析构函数
{
    if (fModal!=NULL) {
        delete [] fModal;
        fModal = NULL;
    }
    if (fNo!=NULL) {
        delete [] fNo;
        fNo = NULL;
    }
    if (fName!=NULL) {
        delete [] fName;
        fName = NULL;
    }
}
