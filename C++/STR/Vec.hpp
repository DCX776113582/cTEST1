//
//  Vec.hpp
//  STR
//
//  Created by mac on 18/4/25.
//  Copyright © 2018年 duanchuanxin. All rights reserved.
//

#ifndef Vec_hpp
#define Vec_hpp

#include <iostream>
using namespace std;
template <class T>
class Vector {
private:
    T* rep;
    int capacity;
    int size;
    Vector<T>&shrink();
public:
    Vector();//默认带参函数
    Vector(T* p,int s);//带参的构造函数
    Vector(const Vector<T>& v);//拷贝构造函数
    ~Vector();//析构函数
    const Vector<T>& operator=(const Vector<T>& v);//赋值重载
    const T& operator[](int index)const;//下标重载const版本
    T& operator[](int index);//下标重载
    int get_capacity()const;//获取容量大小const版本
    int get_size()const;//获取实际数量const版本
    Vector<T>& add(const T& t);//添加
    T* search(const T* t)const;//搜索const版本
    Vector<T>& remove(const T& t);//带参数的删除
    Vector<T>& remove();//删除
};
//输出重载
template <class T>
ostream& operator<<(ostream& out,const Vector<T>& v)
{
    for (int i = 0; i < v.get_size(); ++i) {
        out<<v[i]<<endl;
    }
    return out;
}
//缩容
template <class T>
Vector<T>& Vector<T>::shrink() {
    capacity = capacity*3/4;
    T* temp = new T[capacity];
    for (int i = 0; i<size; ++i) {
        temp[i] = rep[i];
    }
    delete [] rep;
    rep = temp;
    return *this;
}
//默认构造函数
template <class T>
inline Vector<T>::Vector():capacity(0),size(0),rep(NULL) {
    
}
//析构函数
template <class T>
inline Vector<T>::~Vector() {
    delete [] rep;
    rep = NULL;
}
//带参数的构造函数
template <class T>
Vector<T>::Vector(T* p,int s):capacity(s),size(s),rep(new T[s]) {
    for (int i = 0; i<s; ++i) {
        rep[i] = p[i];
    }
}
//拷贝构造函数
template <class T>
Vector<T>::Vector(const Vector<T>& v):capacity(v.capacity),size(v.size),rep(new T[v.capacity]) {
    for (int i = 0; i<size; ++i) {
        rep[i] = v.rep[i];
    }
}
//赋值运算符重载函数
template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T> &v) {
    if (rep != v.rep) {
        delete [] rep;
        capacity = v.capacity;
        size = v.size;
        rep = new T[capacity];
        for (int i = 0; i<size; ++i) {
            rep[i] = v.rep[i];
        }
    }
    return *this;
}
//下标运算符重载函数const版本
template <class T>
inline const T& Vector<T>::operator[](int index)const {
    return rep[index];
}
//下标运算符重载函数非const版本
template <class T>
inline T& Vector<T>::operator[](int index) {
    return rep[index];
}
//获取容量值
template <class T>
inline int Vector<T>::get_capacity()const {
    return capacity;
}
//获取实际值
template <class T>
inline int Vector<T>::get_size()const {
    return size;
}
//添加元素
template <class T>
Vector<T>& Vector<T>::add(const T &t) {
    if (size == capacity) {
        capacity = 2*capacity+1;
        T* temp = new T[capacity];
        for (int i = 0; i<size; ++i) {
            temp[i] = rep[i];
        }
        delete [] rep;
        rep = temp;
    }
    rep[size++] = t;
    return *this;
}
//搜索元素
template <class T>
T* Vector<T>::search(const T *t)const {
    T* p = rep;
    int i = 0;
    while (i == size && p != t) {
        ++i;
        ++p;
    }
    if (i == size) {
        p = NULL;
    }
    return p;
}
//指定元素删除
template <class T>
Vector<T>& Vector<T>::remove(const T &t) {
    T* p = search(t);
    if (p) {
        for (int i = int(p - rep); i<size-1; ++i) {
            rep[i] = rep[i+1];
        }
        --size;
        if (size<capacity/2) {
            shrink();
        }
    }
    return *this;
}
//删除元素——从后向前删除
template <class T>
Vector<T>& Vector<T>::remove() {
    --size;
    if (size<capacity/2) {
        shrink();
    }
    return *this;
}
template <class T>
bool operator==(const Vector<T>& v1,const Vector<T>& v2) {
    bool yes = true;
    if (v1.get_capacity() != v2.get_capacity()||v1.get_size() != v2.get_size()) {
        yes = false;
    }else{
        int i = 0;
        int s = v1.get_size();
        while (i<s&&v1[i] == v2[i++]) {
            if (i<s) {
                yes = false;
            }
        }
    }
    return yes;
}
#endif /* Vec_hpp */
