//
//  person.h
//  lianxi
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __lianxi__person__
#define __lianxi__person__

#include <iostream>
using namespace std;
class Person1{
public:
    Person1(const char *_name="",int age=0){
        name = new char[strlen(_name)+1];
        strcpy(name, _name);
        this->age=age;
    }
    virtual void dailywork()
    {
        cout<<"姓名："<<name<<"  年龄："<<age;
    }
    virtual ~Person1(){cout<<"Person1 destructor"<<endl;}
private:
    char *name;
    int age;
};
class Student1:public Person1 {
public:
    Student1(const char *n="",int a=0,const char *c=""):Person1(n,a)
    {
        label = new char[strlen(c)+1];
        strcpy(label, c);
    }
    void dailywork(){
        Person1::dailywork();
        cout<<"  学生";
        cout<<"  评语："<<label<<endl;
    }
    ~Student1(){
        if (label != NULL) {
            delete [] label;
            label = NULL;
        }
        cout<<"Stuent1 destructor"<<endl;}
private:
        char *label;
};
class Driver1:public Person1 {
public:
    Driver1(const char *n="",int a=0,const char *c=""):Person1(n,a)
    {
        label = new char[strlen(c)+1];
        strcpy(label, c);
    }
    void dailywork(){
        Person1::dailywork();
        cout<<"  司机";
        cout<<"  评语："<<label<<endl;
    }
    ~Driver1(){
        if (label != NULL) {
            delete [] label;
            label = NULL;
        }
        cout<<"Driver1 destructor"<<endl;}
private:
    char *label;
};
class Doctor1:public Person1 {
public:
    Doctor1(const char *n="",int a=0,const char *c=""):Person1(n,a)
    {
        label = new char[strlen(c)+1];
        strcpy(label, c);
    }
    void dailywork(){
        Person1::dailywork();
        cout<<"  医生";
        cout<<"  评语："<<label<<endl;
    }
    ~Doctor1(){
        if (label != NULL) {
            delete [] label;
            label = NULL;
        }
        cout<<"Doctor1 destructor"<<endl;}
private:
    char *label;
};

#endif /* defined(__lianxi__person__) */
