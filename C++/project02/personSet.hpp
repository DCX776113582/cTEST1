//
//  personSet.h
//  project02
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __project02__personSet__
#define __project02__personSet__

#include <iostream>
using namespace std;
class Person;
class PersonSet{
private://成员变量
    int Capacity;//容器的容量
    Person ** Element;//指向容器（数组）元素的指针
    int Size;//容器的实际容量/大小
    int Index;//访问容器元素的位置
public://成员函数
    //构造函数
    PersonSet();
    PersonSet(Person** _element,int _capacity,int _size,int _index);
    PersonSet(const PersonSet& set);
    //析构函数
    ~PersonSet();
    //设置函数
    void setCapacity(int _capacity);
    void setElement(Person** _element);
    void setSize(int _size);
    void setIndex(int _index);
    //访问函数
    int getCapacity()const;
    Person** getElement()const;
    int getSize()const;
    int getIndex()const;
    //普通功能函数
    void printset() const;
    //赋值运算符重载
    PersonSet& operator=(const PersonSet& set);
    Person& operator[](int _index);
    Person& operator[](int _index)const;
    //输出重载函数
    friend ostream& operator<<(ostream& out,const PersonSet& set);
    //输入重载函数
    friend istream& operator>>(istream& in,PersonSet& set);
    //容器特殊功能函数
    void add(Person& person);//添加
    Person& remove();//删除
    Person& remove(int _index);//删除指定元素
    Person& next();//遍历
    void reset();//复位
};

#endif /* defined(__project02__personSet__) */
