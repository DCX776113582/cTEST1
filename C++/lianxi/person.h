//
//  person.h
//  lianxi
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __lianxi__person__
#define __lianxi__person__

#include <iostream>
using namespace std;
class Person{
protected:
    char * name;
    int age;
public:
    Person(const char* _name = "",int _age = 0);
    void print();
};
/*已知：Person类：name,age,print()；*/
#endif /* defined(__lianxi__person__) */
