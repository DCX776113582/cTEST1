//
//  hero.h
//  Chapter04_Demo4
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04_Demo4__hero__
#define __Chapter04_Demo4__hero__

#include <iostream>
using namespace std;
class Hero{
protected:
    char * name;//姓名
    char * high;//身高
    char * wight;//体重
public:
    Hero(const char * _name,const char * _high,const char * _wight);//构造
    virtual void print()=0;
};
class Ultra:public Hero{
protected:
    int age;
public:
    Ultra(const char * _name = "Ultra",const char * _high="50m",const char * _wight="7.5t",int _age = 10000);
    void print();
};
class Karmen:public Hero{
private:
    int age;
public:
    Karmen(const char * _name = "Rider",const char * _high= "2.1m",const char * _wight = "1.2t",int _age=20);
    void print();
};
class Atm:public Ultra{
public:
    void print();
};
/*class HERO{
private:
    Hero hero;
public:
    HERO(const char * _name="name",const char * _high="high",const char * _wight="wight");//构造
    Hero& location();
};*/
#endif /* defined(__Chapter04_Demo4__hero__) */
