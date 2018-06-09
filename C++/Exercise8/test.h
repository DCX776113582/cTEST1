//
//  test.h
//  lianxi
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __lianxi__test__
#define __lianxi__test__

#include <iostream>
using namespace std;
/*1. 修改类Figure，将Point对象指针作为属性组合进来，对Figure的子类中的相关函数也做相应的修改。
 系统测试：使用声明vector容器对象对Figure对象指针进行操作和管理，并进行多态性的测试！
 
 2、对 作业“C++_Exercise7.txt”中的多态性的设计Person使用抽象基类的形式，dailywork()作为子类中的接口来进行修改；添加Vector容器类；
 完成后继续测试：容器中添加多个子类对象，然后进行动态类型判断选择（使用菜单模式完成）！
 
 */

class Point
{
private:
    double x;
    double y;
    
public:
    Point(double i, double j);
    Point(const Point&p1);
    void print( ) const;
};
class Figure//图形类
{
private:
    //什么关系？ 组合
    Point* center;
    
public:
    Figure (Point*pp);
    Point& location();
    void move(Point p);
    
    //纯虚函数，没有函数体，不需要实现。在子类里实现纯虚函数的具体功能。
    //对于父类Figure来说，无法确定如何绘制， draw函数也就无法实现。
    virtual void draw() = 0;
    virtual void rotate(double d) = 0;
};
class Circle : public Figure
{
private:
    double radius;
    
public:
    Circle(Point*pp, double r = 0);
    void draw();
    void rotate(double d);
};
class Square : public Figure
{
private:
    double side;
    double angle;
    
public:
    Square(Point*pp, double d = 0, double a = 0);
    void draw();
    void rotate(double a);
    void vertices();
};
class Vector{
private:
    Figure ** ptr;
    int size;
    int index;
public:
    Vector(int s = 0):size(s),index(0)
    {
        ptr = new Figure*[s];
        for (int i = 0; i<size; ++i) {
            ptr[i]=NULL;
        }
    }
    Vector(const Vector& set):size(set.size)
    {
        ptr = new Figure*[set.size];
        for (int i = 0; i<size; ++i) {
            ptr[i]=set.ptr[i];
        }
    }
    const Vector& operator=(const Vector& set)
    {
        if (this != &set) {
            this->size = set.size;
            delete [] this->ptr;
            ptr = new Figure*[set.size];
            for (int i = 0; i<size; ++i) {
                ptr[i]=set.ptr[i];
            }
        }
        return *this;
    }
    Figure& remove();//删除
    Figure& remove(int _index);//删除指定元素
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
            set.ptr[i]->draw(); //父类的指针调用虚函数->多态
        }
        return out;
    }
    Figure* operator[](int _index)
    {
        return this->ptr[_index];
    }
    Figure* operator[](int _index) const
    {
        return this->ptr[_index];
    }
    void add(Figure& t) //动态绑定——>多态
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

#endif /* defined(__lianxi__test__) */
