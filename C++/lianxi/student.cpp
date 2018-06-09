//
//  student.cpp
//  lianxi
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "student.h"
Student:: Student(const char* _name,int _age,int _score,const char * _label):Person(_name,_age),score(_score),label(new char[strlen(_label)+1]){}
void Student:: print()
{
    Person::print();
    cout<<"Student::Score:"<<score<<"    Label:"<<label<<endl;
}
Student1:: Student1(const char* _name,int _age,int _score,const char * _label):Person(_name,_age),score(_score),label(new char[strlen(_label)+1]){}
void Student1:: print()
{
    Person::print();
    cout<<"Student1::Score:"<<score<<"    Label:"<<label<<endl;
}
Student2:: Student2(const char* _name,int _age,int _score,const char * _label):Person(_name,_age),score(_score),label(new char[strlen(_label)+1]){}
void Student2:: print()
{
    Person::print();
    cout<<"Student2::Score:"<<score<<"    Label:"<<label<<endl;
}

