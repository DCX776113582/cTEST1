//
//  person.h
//  project02
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __project02__person__
#define __project02__person__

#include <iostream>
using namespace std;
#include <string>
class Person{
protected:
    string name;//姓名
    int age;//年龄
    float salary;//薪资
    const int id;//编号
    static int totalPersons;//计数器
public:
    Person(string _name = "name",int _age = 18,float _salary = 10000);//带参数的默认构造函数
    //设置函数
    void setAge(int _age);//设置/修改年龄
    void setSalary(float _salary);//设置/修改薪资
    void setName(string _name);
    //获取函数
    string getName()const;
    int getAge()const;
    virtual int getID()const;
    float getSalary()const;
    //赋值运算符重载
    Person& operator=(Person& p1);
    //析构函数（虚析构）
    virtual ~Person();
    virtual void print()const;//打印
    //友元函数：输出运算符重载
    friend ostream& operator<<(ostream& out,const Person& p1);
    friend istream& operator>>(istream& in, Person& p1);
};

#endif /* defined(__project02__person__) */
