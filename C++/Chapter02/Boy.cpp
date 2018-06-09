//
//  Boy.cpp
//  Chapter02
//
//  Created by mac on 18/2/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Boy.hpp"
Boy::Boy(char *n, char *g, int p):phone(p)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    strcpy(telephone, g);
}
void Boy::setName(char *newName)
{
    //this->name=newName;
    if (strlen(newName) > strlen(name)) {
        if (name!=NULL) {
            delete [] name;
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        }
    } else {
        strcpy(name, newName);
    }
}
void Boy::setTel(char *newTel)
{
    //this->telephone = newTel;
    strcpy(telephone, newTel);
}
Boy::~Boy()
{
    if (name) {
        delete [] name;
        name = NULL;
    }
}
void Boy::print()
{
//    cout << "name = " << name << endl;
//    cout << "telephone = " << telephone << endl;
//    cout << "phone = " << phone << endl;
    cout<<*this;//自动调用输出运算符重载
}
void Boy::print()const
{
    cout << "name = " << name << endl;
    cout << "telephone = " << telephone << endl;
    cout << "phone = " << phone << endl;
}
const Boy&Boy:: operator=(const Boy& b)
{
    if (this!=&b) {//地址是否相同
        if (this->name!=NULL) {
            //释放原内存
            delete [] this->name;
        }
        //申请新内存
        this->name = new char[strlen(b.name)+1];
        //内容拷贝：先指针再其他
        strcpy(this->name, b.name);
        strcpy(this->telephone, b.telephone);
        this->phone= b.phone;
    }
    //返回对象本身
    return *this;
}
ostream& operator<<(ostream& out,const Boy& c1)
{
    out << "name = " << c1.name << endl;
    out << "telephone = " << c1.telephone << endl;
    out << "phone = " << c1.phone << endl;
    return out;
}



Int Int::operator+(Int& i)
{
    int sum = this->a + i.a;
    Int temp;
    temp.setA(sum);
    return temp;
}
Int Int::operator-(Int& i)
{
    int sum = this->a - i.a;
    this->a = sum;
    return *this;
}
Int Int::operator*(Int& i)
{
    int sum = this->a * i.a;
    this->a = sum;
    return *this;
}
Int Int::operator/(Int& i)
{
    if (i.a==0) {
        cout<<"分母为0，无法运算"<<endl;
    }else{
        int sum = this->a / i.a;
        this->a = sum;
    }
    return *this;
}
Int Int::operator%(Int& i)
{
    if (i.a==0) {
        cout<<"分母为0，无法运算"<<endl;
    }else{
        int sum = this->a % i.a;
        this->a = sum;
    }
    return *this;
}
Int& Int:: operator=(Int&i)
{
    this->a = i.a;
    return *this;
}
//类的友元函数
/*Int operator+(Int& a,Int& b)
{
    Int temp;
    temp.a=a.a+b.a;
    return temp;
}
Int operator-(Int& a,Int& b)
{
    Int temp;
    temp.a=a.a-b.a;
    return temp;
}
Int operator*(Int& a,Int& b)
{
    Int temp;
    temp.a=a.a*b.a;
    return temp;
}
Int operator/(Int& a,Int& b)
{
    Int temp;
    if (b.a==0) {
        cout<<"分母为0，无法运算"<<endl;
    }else{
    temp.a=a.a/b.a;
    }
    return temp;
}
Int operator%(Int& a,Int& b)
{
    Int temp;
    if (b.a==0) {
        cout<<"分母为0，无法运算"<<endl;
    }else{
    temp.a=a.a%b.a;
    }
    return temp;
}*/
ostream& operator<<(ostream& out,const Int& a)//out==cout的引用
{
    out<<a.a<<endl;
    return out;
}
istream& operator>>(istream& in,Int& a)
{
    in>>a.a;
    return in;
}

