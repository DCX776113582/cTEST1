//
//  heroset.cpp
//  GameDrive
//
//  Created by mac on 18/3/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "heroset.h"
HeroSet::HeroSet(){
    Name = "name";
    Size=0;
    Capacity=4;
    Index=0;
    Element=new Hero*[Capacity];
    for (int i = 0; i<this->Capacity; ++i) {
        this->Element[i] = NULL;
    }
}
HeroSet:: HeroSet(string _Name,Hero** _element,int _capacity,int _size,int _index):Capacity(_capacity),Element(new Hero*[_capacity]),Size(_size),Index(_index),Name(_Name)
{
    for (int i = 0; i<this->Capacity; ++i) {
        this->Element[i] = NULL;
    }
}
HeroSet:: HeroSet(const HeroSet& set)
{
    this->Capacity = set.Capacity;
    this->Element = new Hero*[set.Capacity];
    for (int i = 0; i<set.Capacity; ++i) {
        this->Element[i] = set.Element[i];
    }
    this->Size = set.Size;
    this->Index = set.Index;
}
Hero& HeroSet::operator[](int _index)
{
    return *(this->Element[_index]);
}
Hero& HeroSet::operator[](int _index)const
{
    return *(this->Element[_index]);
}

//设置函数
void HeroSet:: setCapacity(int _capacity)
{
    this->Capacity = _capacity;
}
void HeroSet:: setElement(Hero** _element)
{
    if (this->Element!=NULL) {
        delete [] this->Element;
        this->Element = new Hero*[this->Capacity];
        for (int i = 0; i<this->Capacity; ++i) {
            this->Element[i] = _element[i];
        }
    }
}
void HeroSet:: setSize(int _size)
{
    this->Size = _size;
}
void HeroSet:: setIndex(int _index)
{
    this->Index = _index;
}
void HeroSet::setName(string _Name)
{
    this->Name = _Name;
}

//访问函数
int HeroSet:: getCapacity()const
{
    return this->Capacity;
}
Hero** HeroSet:: getElement()const
{
    return this->Element;
}
int HeroSet:: getSize()const
{
    return this->Size;
}
int HeroSet:: getIndex()const
{
    return this->Index;
}
const string& HeroSet::getName()const
{
    return this->Name;
}

ostream& operator<<(ostream& out,const HeroSet& set)
{
    out<<"Capacity:"<<set.Capacity<<"    Size:"<<set.Size<<endl;
    out<<"Element:"<<endl;
    if (set.Size == 0) {
        out<<"容器为空"<<endl;
    }else{
        for (int i = 0; i<set.Size; ++i) {
            out<<(set.Element[i]);
        }
    }
    return out;
}
istream& operator>>(istream& in,HeroSet& set)
{
    cout<<"Capacity:";
    in>>set.Capacity;
    cout<<"SetName:";
    in>>set.Name;
    return in;
}
//析构函数
HeroSet:: ~HeroSet()
{
    if (this->Element != NULL) {
        delete [] this->Element;
        this->Element = NULL;
    }
}

void HeroSet:: add(Hero& hero)
{
    //是否需要扩容
    if (this->Size>this->Capacity/2) {
        Hero** temp = this->Element;
        this->Element = new Hero*[this->Capacity*2];
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
    this->Element[Size++]= &hero;
}
Hero& HeroSet:: remove()//删除
{
    Hero * per = this->Element[--Size];
    //是否需要缩容
    if (this->Size<this->Capacity/2) {
        Hero** temp = this->Element;
        this->Element = new Hero*[this->Capacity/2];
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
Hero& HeroSet:: remove(int _index)//删除指定元素
{
    Hero * per = this->Element[_index];
    for (int i = _index;i<Size ; ++i) {
        this->Element[i] = this->Element[i+1];
    }
    Size--;
    //是否需要缩容
    if (this->Size<this->Capacity/2) {
        Hero** temp = this->Element;
        this->Element = new Hero*[this->Capacity/2];
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
Hero& HeroSet:: next()//遍历
{
    if(Index>Size){
        Index=0;
    }
    return *(this->Element[Index++]);
}
void HeroSet:: reset()//复位
{
    this->Index = 0;
}


