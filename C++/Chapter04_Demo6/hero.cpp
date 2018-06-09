//
//  hero.cpp
//  Chapter04_Demo4
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "hero.h"
Hero::Hero(const char * _name,const char * _high,const char * _wight)//构造
{
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    high = new char[strlen(_high)+1];
    strcpy(high, _high);
    wight = new char[strlen(_wight)+1];
    strcpy(wight, _wight);
}
/*void Hero:: print()
{
    cout<<"Hero's information:\nName:"<<name<<endl;
    cout<<"High:"<<high<<endl;
    cout<<"Wight:"<<wight<<endl;
}
 */
Ultra::Ultra(const char * _name,const char * _high,const char * _wight,int _age):Hero(_name,_high,_wight),age(_age){}
void Ultra::print()
{
    cout<<"Ultra::Name:"<<name<<endl;
    cout<<"Ultra::High:"<<high<<endl;
    cout<<"Ultra::Wigh:"<<wight<<endl;
    cout<<"Ultra::Age:"<<age<<endl;
}
Karmen::Karmen(const char * _name,const char * _high,const char * _wight,int _age):Hero(_name,_high,_wight),age(_age){}
void Karmen::print()
{
    cout<<"Karmen::Name:"<<name<<endl;
    cout<<"Karmen::High:"<<high<<endl;
    cout<<"Karmen::Wigh:"<<wight<<endl;
    cout<<"Karmen::Age:"<<age<<endl;
}
void Atm::print()
{
    cout<<"Atm::Name:"<<name<<endl;
    cout<<"Atm::High:"<<high<<endl;
    cout<<"Atm::Wigh:"<<wight<<endl;
    cout<<"Atm::Age:"<<age<<endl;
}