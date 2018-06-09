//
//  personSet.cpp
//  project02
//
//  Created by mac on 18/3/3.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "personSet.hpp"
#include "person.hpp"
PersonSet::PersonSet()//默认构造
{
    Size=0;
    Capacity=4;
    Index=0;
    Element=new Person*[Capacity];
    for (int i = 0; i<this->Capacity; ++i) {
        this->Element[i] = NULL;
    }
}
PersonSet:: PersonSet(Person** _element,int _capacity,int _size,int _index):Capacity(_capacity),Element(new Person*[_capacity]),Size(_size),Index(_index)
{
    for (int i = 0; i<this->Capacity; ++i) {
        this->Element[i] = NULL;
    }
}
PersonSet:: PersonSet(const PersonSet& set)//拷贝构造
{
    this->Capacity = set.Capacity;
    this->Element = new Person*[set.Capacity];
    for (int i = 0; i<set.Capacity; ++i) {
        this->Element[i] = set.Element[i];
    }
    this->Size = set.Size;
    this->Index = set.Index;
}
Person& PersonSet::operator[](int _index)
{
    return *(this->Element[_index]);
}
Person& PersonSet::operator[](int _index)const
{
    return *(this->Element[_index]);
}

//设置函数
void PersonSet:: setCapacity(int _capacity)
{
    this->Capacity = _capacity;
}
void PersonSet:: setElement(Person** _element)
{
    if (this->Element!=NULL) {
        delete [] this->Element;
        this->Element = new Person*[this->Capacity];
        for (int i = 0; i<this->Capacity; ++i) {
            this->Element[i] = _element[i];
        }
    }
}
void PersonSet:: setSize(int _size)
{
    this->Size = _size;
}
void PersonSet:: setIndex(int _index)
{
    this->Index = _index;
}
//访问函数
int PersonSet:: getCapacity()const
{
    return this->Capacity;
}
Person** PersonSet:: getElement()const
{
    return this->Element;
}
int PersonSet:: getSize()const
{
    return this->Size;
}
int PersonSet:: getIndex()const
{
    return this->Index;
}
void PersonSet:: printset() const
{
    if (this->Size == 0) {
        cout<<"容器为空"<<endl;
    }else{
        for (int i = 0; i<this->Size; ++i) {
//            cout<<*(this->Element[i])<<endl;
            this->Element[i]->print();
        }
    }
}
PersonSet& PersonSet:: operator=(const PersonSet& set)
{
    if (this != &set) {
        this->Capacity = set.Capacity;
        if (this->Element != NULL) {
            delete [] this->Element;
            this->Element = new Person*[set.Capacity];
            for (int i = 0; i<set.Capacity; ++i) {
                this->Element[i] = set.Element[i];
            }
        }
        this->Size = set.Size;
        this->Index = set.Index;
    }
    return (*this);
}
ostream& operator<<(ostream& out,const PersonSet& set)
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
}
istream& operator>>(istream& in,PersonSet& set)
{
    cout<<"Capacity:";
    in>>set.Capacity;
    return in;
}
//析构函数
PersonSet:: ~PersonSet()
{
    if (this->Element != NULL) {
        delete [] this->Element;
        this->Element = NULL;
    }
    cout<<"~PersonSet()"<<endl;
}

void PersonSet:: add(Person& person)
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
}
Person& PersonSet:: remove()//删除
{
    Person * per = this->Element[--Size];
    //是否需要缩容
    if (this->Size<this->Capacity/2) {
        Person** temp = this->Element;
        this->Element = new Person*[this->Capacity/2];
        for (int i = 0; i<Size; ++i) {
            this->Element[i] = temp[i];
        }
        this->Capacity /= 2;
        for (int i = Size; i<this->Capacity; ++i) {
            this->Element[i] = NULL;
        }
        //释放旧容器内存
        delete [] temp;
    }
    return *per;
}
Person& PersonSet:: remove(int _index)//删除指定元素
{
    Person * per = this->Element[_index];
    for (int i = _index;i<Size ; ++i) {
        this->Element[i] = this->Element[i+1];
    }
    Size--;
    //是否需要缩容
    if (this->Size<this->Capacity/2) {
        Person** temp = this->Element;
        this->Element = new Person*[this->Capacity/2];
        for (int i = 0; i<Size; ++i) {
            this->Element[i] = temp[i];
        }
        this->Capacity /= 2;
        for (int i = Size; i<this->Capacity; ++i) {
            this->Element[i] = NULL;
        }
        //释放旧容器内存
        delete [] temp;
    }
    return *per;
}
Person& PersonSet:: next()//遍历
{
    if(Index>Size){
        Index=0;
    }
    return *(this->Element[Index++]);
}
void PersonSet:: reset()//复位
{
    this->Index = 0;
}

