//
//  student.h
//  lianxi
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __lianxi__student__
#define __lianxi__student__

#include "person.h"
/*1. 写一个学生类Student，要求从person类继承（继承方式分别从private、protected、public形式进行验证练习），增加的属性为成绩 int score;和评语 char* label（字符串）;。
 */
class Student:public Person{
private:
    int score;
    char * label;
public:
    Student(const char* _name = "",int _age = 0,int _score = 0,const char * _label = "");
    void print();
};
class Student1:protected Person{
private:
    int score;
    char * label;
public:
    Student1(const char* _name = "",int _age = 0,int _score = 0,const char * _label = "");
    void print();
};
class Student2:private Person{
private:
    int score;
    char * label;
public:
    Student2(const char* _name = "",int _age = 0,int _score = 0,const char * _label = "");
    void print();
};

#endif /* defined(__lianxi__student__) */
