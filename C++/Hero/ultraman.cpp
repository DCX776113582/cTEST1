//
//  ultraman.cpp
//  GameDrive
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "ultraman.h"
Ultraman::Ultraman(string _name,string _high,string _wight,int _age,string _address):Hero(_name,_high,_wight),age(_age),address(_address)//构造函数
{}
Ultraman::~Ultraman()//析构函数
{}
void Ultraman::print()//函数重写
{
    cout<<"Hero's information:\nName:"<<name<<endl;
    cout<<"High:"<<high<<endl;
    cout<<"Wight:"<<wight<<endl;
    cout<<"Ultraman::Age:"<<age<<"  Address:"<<address<<endl;
}
Ultraman& Ultraman::operator=(Ultraman& u1)//赋值运算符重载
{
    if (this!=&u1) {
        name = u1.name;
        high = u1.high;
        wight = u1.wight;
        age = u1.age;
        address = u1.address;
    }
    return *this;
}
//输出/输入运算符重载
ostream& operator<<(ostream& out,const Ultraman& u1)
{
    out<<"Hero's information:\nName:"<<u1.name<<endl;
    out<<"High:"<<u1.high<<endl;
    out<<"Wight:"<<u1.wight<<endl;
    out<<"Age:"<<u1.age<<endl;
    out<<"Address:"<<u1.address<<endl;
    return out;
}
istream& operator>>(istream& in,Ultraman& u1)
{
    cout<<"Name:";
    in>>u1.name;
    cout<<"High:";
    in>>u1.high;
    cout<<"Wight:";
    in>>u1.wight;
    cout<<"Age:";
    in>>u1.age;
    cout<<"Address:";
    in>>u1.address;
    return in;
}


/*ultraman::ultraman(string _name,string _high,string _wight,int _age,string _address):Ultraman(_name,_high,_wight,_age,_address)//构造函数
{}
ultraman::~ultraman()//析构函数
{}
void ultraman::print()//函数重写
{
    cout<<"Hero's information:\nName:"<<name<<endl;
    cout<<"High:"<<high<<endl;
    cout<<"Wight:"<<wight<<endl;
    cout<<"Ultraman::Age:"<<age<<"  Address:"<<address<<endl;
}
ultraman& ultraman::operator=(ultraman& u1)//赋值运算符重载
{
    if (this!=&u1) {
        name = u1.name;
        high = u1.high;
        wight = u1.wight;
        age = u1.age;
        address = u1.address;
    }
    return *this;
}
//输出/输入运算符重载
ostream& operator<<(ostream& out,const ultraman& u1)
{
    out<<"Hero's information:\nName:"<<u1.name<<endl;
    out<<"High:"<<u1.high<<endl;
    out<<"Wight:"<<u1.wight<<endl;
    out<<"Age:"<<u1.age<<endl;
    out<<"Address:"<<u1.address<<endl;
    return out;
}
istream& operator>>(istream& in,ultraman& u1)
{
    cout<<"Name:";
    in>>u1.name;
    cout<<"High:";
    in>>u1.high;
    cout<<"Wight:";
    in>>u1.wight;
    cout<<"Age:";
    in>>u1.age;
    cout<<"Address:";
    in>>u1.address;
    return in;
}
*/