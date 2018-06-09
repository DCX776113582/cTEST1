//
//  person.h
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo2__person__
#define __Chapter04_Demo2__person__

#include <iostream>
using namespace std;
class Person{
protected:
    int ID;
    char * name;
public:
    Person(int _ID = 0,const char * _name = " ");
    Person(const Person& p);
    ~Person();
    void print();
    Person& operator=(const Person& p);
};

#endif /* defined(__Chapter04_Demo2__person__) */
