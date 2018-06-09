//
//  person.cpp
//  lianxi
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "person.h"
Person:: Person(const char* _name,int _age):name(new char[strlen(_name)+1]),age(_age)
{
    strcpy(name, _name);
}
void Person:: print()
{
    cout<<"Person::Name:"<<name<<"  Age:"<<age<<endl;
}
