//
//  Person.cpp
//  Chapter01Demo07
//
//  Created by mac on 18/2/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Person.hpp"
#include <string.h>
int Person:: index = 0; //类的静态成员变量必须在类外单独初始化

Person::Person():_id(index+1),_name("name"),_age(20),_sex('n')
{
    this->index++;
}
Person::Person(const char name[],const int& age,const char&sex):_id(index+1),_age(age),_sex(sex)
{
    this->index++;
    strcpy(this->_name,name);
}
Person::~Person()
{
    cout<<"Person::析构函数"<<endl;
}
void Person::printPerson()
{
    cout<<"信息如下："<<endl;
    cout<<"编号："<< this->_id <<endl;
    cout<<"姓名："<< this->_name <<endl;
    cout<<"年龄："<< this->_age <<endl;
    cout<<"性别："<< this->_sex <<endl;
}
void Person::printPerson()const
{
    cout<<"信息如下："<<endl;
    cout<<"编号："<< this->_id <<endl;
    cout<<"姓名："<< this->_name <<endl;
    cout<<"年龄："<< this->_age <<endl;
    cout<<"性别："<< this->_sex <<endl;
}
int Person::total() //静态的成员函数：只能访问类中的静态成员
{
    //	return this->index; //类静态成员函数内不能使用this指针
    return Person::index;
}
