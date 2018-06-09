//
//  person.cpp
//  project02
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "person.hpp"
int Person::totalPersons = 0;
Person::Person(string _name,int _age,float _salary):name(_name),age(_age),salary(_salary),id(totalPersons+1)
{
    totalPersons++;
}
Person& Person::operator=(Person& p1)
{
    if (this!=&p1) {
        name = p1.name;
        age = p1.age;
        salary = p1.salary;
    }
    return *this;
}
string Person::getName()const
{
    return name;
}
int Person::getAge()const
{
    return age;
}
int Person::getID()const
{
    return id;
}
float Person::getSalary()const
{
    return salary;
}
void Person::setAge(int _age)
{
    age = _age;
}
void Person::setSalary(float _salary)
{
    salary = _salary;
}
void Person::setName(string _name)
{
    name = _name;
}
void Person::print()const
{
    cout<<"选民"<<id<<"号信息："<<"Name:"<<name<<" Age:"<<age<<"   Salary:"<<salary<<endl;
}
ostream& operator<<(ostream& out,const Person& p1)
{
    out<<"选民"<<p1.id<<"号信息："<<"Name:"<<p1.name<<" Age:"<<p1.age<<"   Salary:"<<p1.salary<<endl;
    return out;
}
istream& operator>>(istream& in, Person& p1)
{
    cout<<"姓名：";
    cin>>p1.name;
    cout<<"年龄：";
    cin>>p1.age;
    cout<<"薪资：";
    cin>>p1.salary;
    return in;
}
Person::~Person(){cout<<"~Person()"<<endl;}
