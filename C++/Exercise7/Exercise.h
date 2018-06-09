//
//  Exercise.h
//  lianxi
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __lianxi__Exercise__
#define __lianxi__Exercise__

#include <iostream>
using namespace std;
/*1. Person为基类：虚函数为 dailywork() ~Person()
 定义三个子类：Student Doctor(char* label) Driver(char* label)
 主函数：	定义基类指针数组，动态创建子类对象，调用对应的成员函数实现多态的特性（每个人均需要表现出各自的所有日常事务情况），删除创建的对象。
 主要功能： 学生的每日任务是学习；附加任务为体育活动；
 医生的每日任务是看病救人，附加任务为早晚都要洗澡；
 司机的每日任务是开车；附加任务是每天检修汽车
 
*/
#define N 10
class Person {
public:
    virtual void dailywork()=0;
    /*{
        cout<<"Person's dailywork:人类活动"<<endl;
    }*/
    virtual ~Person()
    {
        cout<<"~Person()"<<endl;
    }
};
class Student:public Person {
public:
    void dailywork()
    {
        cout<<"Student's dailywork:Study."<<endl;
    }
    void Additionalwork()
    {
        cout<<"Student's Additionalwork:Sports activities."<<endl;
    }
    ~Student()
    {
        cout<<"~Student()"<<endl;
    }
};
class Doctor:public Person{
    char* label;
public:
    Doctor(const char * _label = "A")
    {
        label = new char[strlen(_label)+1];
        strcpy(label, _label);
    }

    void dailywork()
    {
        cout<<"Doctor's dailywork:看病救人."<<endl;
    }
    void Additionalwork()
    {
        cout<<"Doctor's Additionalwork:早晚都要洗澡."<<endl;
        cout<<"  评语："<<label<<endl;
    }
    ~Doctor()
    {
        if (label != NULL) {
            delete [] label;
            label = NULL;
        }
        cout<<"~Doctor()"<<endl;
    }
};
class Driver:public Person {
    char* label;
public:
    Driver(const char * _label = "A")
    {
        label = new char[strlen(_label)+1];
        strcpy(label, _label);
    }
    void dailywork()
    {
        cout<<"Driver's dailywork:Driving a car"<<endl;
    }
    void Additionalwork()
    {
        cout<<"Driver's Additionalwork:每天检修汽车."<<endl;
        cout<<"  评语："<<label<<endl;
    }
    ~Driver()
    {
        if (label != NULL) {
            delete [] label;
            label = NULL;
        }
        cout<<"~Driver()"<<endl;
    }
};
class Vector{
private:
    Person ** ptr;
    int size;
    int index;
public:
    Vector(int s = 0):size(s),index(0)
    {
        ptr = new Person*[s];
        for (int i = 0; i<size; ++i) {
            ptr[i]=NULL;
        }
    }
    Vector(const Vector& set):size(set.size)
    {
        ptr = new Person*[set.size];
        for (int i = 0; i<size; ++i) {
            ptr[i]=set.ptr[i];
        }
    }
    const Vector& operator=(const Vector& set)
    {
        if (this != &set) {
            this->size = set.size;
            delete [] this->ptr;
            ptr = new Person*[set.size];
            for (int i = 0; i<size; ++i) {
                ptr[i]=set.ptr[i];
            }
        }
        return *this;
    }
    Person& remove();//删除
    Person& remove(int _index);//删除指定元素
    ~Vector()
    {
        if (this->ptr!=NULL) {
            delete [] ptr;
            ptr = NULL;
        }
    }
    //cout<<set;
    friend ostream& operator<<(ostream& out, const Vector& set)
    {
        for (int i=0; i<set.size; ++i) {
            set.ptr[i]->dailywork(); //父类的指针调用虚函数->多态
        }
        return out;
    }
    Person* operator[](int _index)
    {
        return this->ptr[_index];
    }
    Person* operator[](int _index) const
    {
        return this->ptr[_index];
    }
    void add(Person& t) //动态绑定——>多态
    {
        ptr[index++] = &t;
    }
    int getSize() const
    {
        return this->size;
    }
    int getIndex() const
    {
        return this->index;
    }

};
void menu();
void chakan();
void ckzdl();//查看指定类
#endif /* defined(__lianxi__Exercise__) */
