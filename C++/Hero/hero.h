//
//  hero.h
//  GameDrive
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __GameDrive__hero__
#define __GameDrive__hero__

#include <iostream>
#include <string>
using namespace std;
class Hero {
protected:
    string name;//姓名
    string high;//身高
    string wight;//体重
public:
    Hero(string _name="name",string _high="high",string _wight="wight");//构造
    virtual ~Hero();//析构
    virtual void print() = 0;//虚函数
};

#endif /* defined(__GameDrive__hero__) */
