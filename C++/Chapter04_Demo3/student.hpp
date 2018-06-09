//
//  student.h
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo2__student__
#define __Chapter04_Demo2__student__

#include "person.hpp"
class Student:public Person{
private:
    float score;
    char * lable;
public:
    Student(int _ID = 0,const char * _name = "",float s = 0.0,const char * l = "");
    Student(const Student& s);
    ~Student();
    Student& operator=(Student& s);
    void print();
};
#endif /* defined(__Chapter04_Demo2__student__) */
