//
//  person.cpp
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "person.hpp"
Person::Person(int _ID,const char * _name)
{
    ID = _ID;
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
}
Person::Person(const Person& p)
{
    ID = p.ID;
    name = new char[strlen(p.name)+1];
    strcpy(name, p.name);
}
Person::~Person()
{
    if (this->name!=NULL) {
        delete [] this->name;
        this->name = NULL;
    }
}
void Person::print()
{
    cout<<"ID:"<<ID<<"  Name:"<<name<<endl;
}
Person& Person::operator=(const Person& p)
{
    if (this!=&p) {
        ID = p.ID;
        delete [] name;
        name = new char[strlen(p.name)+1];
        strcpy(name, p.name);
    }
    return *this;
}
