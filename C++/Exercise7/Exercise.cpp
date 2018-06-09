//
//  Exercise.cpp
//  lianxi
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Exercise.h"
/*Vector::Vector(Person* _element,int _capacity,int _size,int _index):Capacity(_capacity),Element(new Person[_capacity]),Size(_size),Index(_index)
{
    for (int i = 0; i<this->Capacity; ++i) {
    this->Element[i] = NULL;
    }
}
void Vector::add(Person& person)//添加
{
    //是否需要扩容
    if (this->Size>this->Capacity/2) {
        Person** temp = this->Element;
        this->Element = new Person*[this->Capacity*2];
        for (int i = 0; i<Size; ++i) {
            this->Element[i] = temp[i];
        }
        this->Capacity *= 2;
        for (int i = Size; i<this->Capacity; ++i) {
            this->Element[i] = NULL;
        }
        //释放旧容器内存
        delete [] temp;
    }
    this->Element[Size++]= &person;
}*/
Person& Vector:: remove()//删除
{
    Person * per = this->ptr[--size];
    return *per;
}
/*
ostream& operator<<(ostream& out,const Vector& set)
{
    out<<"Capacity:"<<set.Capacity<<"    Size:"<<set.Size<<endl;
    out<<"Element:"<<endl;
    if (set.Size == 0) {
        out<<"容器为空"<<endl;
    }else{
        for (int i = 0; i<set.Size; ++i) {
            out<<*(set.Element[i]);
        }
    }
    return out;
}*/
Person& Vector:: remove(int _index)//删除指定元素
{
    Person * per = this->ptr[_index];
    for (int i = _index;i<size ; ++i) {
        this->ptr[i] = this->ptr[i+1];
    }
    size--;
    return *per;
}
