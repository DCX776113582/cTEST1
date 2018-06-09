//
//  student.cpp
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "student.hpp"
Student::Student(int _ID,const char * _name,float s,const char * l):Person(_ID,_name)
{
    score = s;
    lable = new char[strlen(l)+1];
    strcpy(lable,l);
}
Student::Student(const Student& s):Person(s)
{
    score = s.score;
    lable = new char[strlen(s.lable)+1];
    strcpy(lable,s.lable);
}
Student::~Student()
{
    if (lable!=NULL) {
        delete [] lable;
        lable = NULL;
    }
}
Student& Student::operator=(Student& s)
{
    if (this != &s) {
        Person::operator=(s);
        score = s.score;
        delete [] lable;
        lable = new char[strlen(s.lable)+1];
        strcpy(lable,s.lable);
    }
    return *this;
}
void Student::print()
{
    Person::print();
    cout<<"成绩:"<<score<<"   评语:"<<lable<<endl;
}