//
//  demo.h
//  Chapter05_Demo1
//
//  Created by mac on 18/3/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter05_Demo1__demo__
#define __Chapter05_Demo1__demo__

#include <iostream>
using namespace std;

template <class T>		//类模版
class Vector
{
private:
    T* rep;      	// 一个动态数组(T)
    int capacity;   	// 动态数组的大小
    int size;        // 数组中的成员的数量
    Vector<T>& shrink();	// 缩小了四分之一的容量
public:
    Vector();           	// 默认构造函数
    Vector(T* p, int s);// 构造函数
    Vector(const Vector<T>& v); // 拷贝构造函数
    ~Vector();                	// 析构函数
    const Vector<T>& operator=(const Vector<T>& v);		// 赋值运算符重载
    const T& operator[] (int index) const;      			// 下标运算符重载const
    T& operator[] (int index);     // 下标运算符重载 [ ]
    int get_capacity() const;      // 恢复能力
    int get_size() const;  // 返回的大小
    Vector<T>& add(const T& t); // 添加一个新的成员
    T* search(const T& t) const; // 返回一个指向t
    // 如果未找到或NULL
    Vector<T>& remove(const T& t); // 删除从一个向量对象t
    Vector<T>& remove();	//删除最后一个元素
};

template <class T>
ostream& operator<<(ostream& out, const Vector<T>& v)
{
    for (int i = 0; i < v.get_size(); ++i)
    { out << v[i] << endl; }
    return out;
}

template <class T>
Vector<T>& Vector<T>::shrink()	//容器收缩
{
    capacity = capacity * 3 / 4; // 缩小了四分之一的容量
    T * temp = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
        temp[i] = rep[i];
    }
    delete [ ] rep;
    rep = temp;
    return *this;
}

template <class T>
inline Vector<T>::Vector( ) : capacity(0), size(0), rep(NULL)
{}

template <class T>
inline Vector<T>::~Vector( )
{
    delete [ ] rep;
    rep = NULL;
}

template <class T>
Vector<T>::Vector(T* p, int s) : capacity(s), size(s), rep(new T[s])
{
    for (int i = 0; i < s; ++i)
    {
        rep[i] = p[i];
    }
}

template<class T>
Vector<T>::Vector(const Vector<T>& v): capacity(v.capacity), size(v.size), rep(new T[v.capacity])
{
    for (int i = 0; i < size; ++i)
    {
        rep[i] = v.rep[i];
    }
}

template<class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if (rep != v.rep)//if(this != &v)
    {
        delete [ ] rep;
        capacity = v.capacity;
        size =v.size;
        rep = new T[capacity];
        for (int i = 0; i < size; ++i)
        {
            rep[i] = v.rep[i];
        }
    }
    return *this;
}

template <class T>
inline const T& Vector<T>::operator[ ] (int index) const
{
    return rep[index];
}

template <class T>
inline T& Vector<T>::operator[ ] (int index)
{
    return rep[index];
}

template <class T>
inline int Vector<T>::get_capacity( ) const
{
    return capacity;
}

template <class T>
inline int Vector<T>::get_size( ) const
{
    return size;
}

template<class T>
Vector<T>& Vector<T>::add(const T& t)
{
    if (size == capacity)
    {
        capacity = 2 * capacity + 1;
        T* temp = new T[capacity];	// 创建一个更大的数组
        for (int i = 0; i < size; ++i)
        {
            temp[i] = rep[i];
        }
        delete [ ] rep;//删除旧容器
        rep = temp;
    }   			// 旧的数组复制到新位置
    rep[size++] = t;	// 添加新成员
    return *this;
}

template<class T>
T* Vector<T>::search(const T& t) const	//迭代器（遍历查询）
{
    T* p = rep;
    int i = 0;
    
    while (i < size && *p != t)
    {
        ++i;
        ++p;
    }
    if (i == size)
    {
        p = NULL;
    }
    return p;
}

template <class T>
Vector<T>& Vector<T>::remove(const T& t)
{
    T* p = search(t);
    if (p)
    {
        for (int i = int(p - rep); i < size - 1; ++i)
        {
            rep[i] = rep[i + 1];
        }
        --size;
        if (size < capacity / 2)
        {
            shrink( );
        }
    }
    return *this;
}

template <class T>
Vector<T>& Vector<T>::remove( )
{
    --size;
    if (size < capacity / 2)
    {
        shrink( );
    }
    return *this;
}

template <class T>
bool operator==(const Vector<T>& v1, const Vector<T>& v2)
{
    bool yes = true;
    
    if (v1.get_capacity( ) != v2.get_capacity( )
        || v1.get_size( ) != v2.get_size( ))
    {
        yes = false;
    }
    else
    {
        int i = 0;
        int s = v1.get_size( );
        while (i < s && v1[i] == v2[i++]){};
        if (i < s)
        {
            yes = false;
        }
    }
    return yes;
}

// 堆栈的抽象基类
template <class T>
class Stack	//类模版
{
public:
    virtual bool empty( ) = 0;
    virtual bool full( ) = 0;
    virtual Stack& push(T& new_member) = 0;
    virtual Stack& pop( ) = 0;
    virtual T& top( ) = 0;
};
// 使用向量实现一个具体的堆栈类
template <class T>
class VecStack : public Stack<T>, private Vector<T*>//类模版
{
public:
    bool empty( )
    {
        return this->get_size( ) == 0;
    }
    bool full( )
    {
        return this->get_size() == this->get_capacity();
    }
    Stack<T>& push(T& new_member)
    {
        this->add(&new_member);
        return *this;
    }
    Stack<T>& pop( )
    {
        if (!empty( ))
        {
            this->remove( );
        }
        return *this;
    }
    T& top( )
    {
        return *(*this)[ this->get_size( ) - 1];
    }
};

#endif /* defined(__Chapter05_Demo1__demo__) */
