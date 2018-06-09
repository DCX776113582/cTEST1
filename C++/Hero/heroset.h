//
//  heroset.h
//  GameDrive
//
//  Created by mac on 18/3/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __GameDrive__heroset__
#define __GameDrive__heroset__

#include "ultraman.h"
class HeroSet{
private:
    string Name;
    int Capacity;//容器的容量
    Hero ** Element;//指向容器（数组）元素的指针
    int Size;//容器的实际容量/大小
    int Index;//访问容器元素的位置
public:
    //构造函数
    HeroSet();
    HeroSet(string _Name,Hero** _element,int _capacity,int _size,int _index);
    HeroSet(const HeroSet& set);
    //析构函数
    ~HeroSet();
    //设置函数
    void setCapacity(int _capacity);
    void setElement(Hero** _element);
    void setSize(int _size);
    void setIndex(int _index);
    void setName(string _Name);
    //访问函数
    int getCapacity()const;
    Hero** getElement()const;
    int getSize()const;
    int getIndex()const;
    const string& getName()const;
    
    Hero& operator[](int _index);
    Hero& operator[](int _index)const;
    
    //输出重载函数
    friend ostream& operator<<(ostream& out,const HeroSet& set);
    //输入重载函数
    friend istream& operator>>(istream& in,HeroSet& set);
    //容器特殊功能函数
    void add(Hero& person);//添加
    Hero& remove();//删除
    Hero& remove(int _index);//删除指定元素
    Hero& next();//遍历
    void reset();//复位
};
#endif /* defined(__GameDrive__heroset__) */
