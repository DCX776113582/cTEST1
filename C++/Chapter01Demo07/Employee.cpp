//
//  Employee.cpp
//  Chapter01Demo07
//
//  Created by mac on 18/2/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Employee.hpp"
int Employee::next_id = 0;
float Employee::total_pay=0;
Employee::Employee(char * name_str): id(++next_id)
{
    strcpy(name, name_str);
    cout<<name<<" id is "<<id<<endl;
}
int Employee::getId()
{
    return id;
}
void Employee::acc_total(float f)
{
    total_pay += f;
    cout<<"total is "<<total_pay<<endl;
}
void Employee::print()
{
    cout<<name<<" id is "<<id<<endl;
    cout<<name<<" total is "<<total_pay<<endl;
}