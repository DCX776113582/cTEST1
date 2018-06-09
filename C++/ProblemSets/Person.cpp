//
//  Person.cpp
//  ProblemSets
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Person.hpp"
#include <string.h>
int Person::index = 0;
Person r1;
Person:: Person():_id(index+1),date(2018,1,1)
{
    _name=new char[strlen("name")+1];
    strcpy(_name, "name");
    _email_address=new char[strlen("email")+1];
    strcpy(_email_address, "email");
    this->index++;
}
Person:: Person(const char *name,const char *email,const int& year,const int& month,const int& day):_id(index+1),date(year,month,day)
{
    _name=new char[strlen(name)+1];
    strcpy(_name, name);
    _email_address=new char[strlen(email)+1];
    strcpy(_email_address, email);
    this->index++;
}
Person::Person(const char *name,const char *email,const Date BirthDate):_id(index+1)
{
    _name=new char[strlen(name)+1];
    strcpy(_name, name);
    _email_address=new char[strlen(email)+1];
    strcpy(_email_address, email);
    this->date = BirthDate;
    this->index++;
}
const long Person::getId()
{
    return this->_id;
}
const long Person::getId()const
{
    return this->_id;
}
char* Person::GetName()
{
    return this->_name;
}
char* Person::GetEmailAddress()
{
    return this->_email_address;
}
Date Person::GetBirthDate()
{
    return this->date;
}
const char* Person::GetName()const
{
    return this->_name;
}
const char* Person::GetEmailAddress()const
{
    return this->_email_address;
}
const Date& Person::GetBirthDate()const
{
    return this->date;
}
ostream& operator<<(ostream& out,Person& a)
{
    if ((a._name!=NULL)&&(a._email_address!=NULL)) {
         out<<"编号："<<a._id<<" "<<"名字："<<a._name<<" "<<"邮箱："<<a._email_address<<" "<<"生日:("<<a.date.getYear()<<"."<<a.date.getMonth()<<"."<<a.date.getDay()<<")"<<endl;
    }
    return out;
}
istream& operator>>(istream& in,Person& a)
{
    a._name = new char;
    a._email_address = new char;
    cout<<"请输入姓名:";
    in>>a._name;
    cout<<"请输入邮箱地址:";
    in>>a._email_address;
    cout<<"请输入生日:";
    in>>a.date.getYear()>>a.date.getMonth()>>a.date.getDay();
    return in;
}
Person& Person::setName(char name[])
{
    if (strlen(name)>strlen(this->_name)) {
        if (_name!=NULL) {
            delete [] _name;
            _name = new char(strlen(name)+1);
            strcpy(this->_name,name);
        }
    }else{
    strcpy(this->_name,name);
    }
    return (*this);
}
Person& Person::setEmailAddress(char email[])
{
    if (strlen(email)>strlen(this->_email_address)) {
        if (_name!=NULL) {
            delete [] _email_address;
            _email_address = new char(strlen(email)+1);
            strcpy(this->_name,email);
        }
    }else{
        strcpy(this->_name,email);
    }
    return (*this);
}
Date& Person::setBirthDate(int year,int month,int day)
{
    Date d(year,month,day);
    date =d;
    return date;
}
Date& Person::setBirthDate(Date one)
{
    this->date=one;
    return date;
}
Person& Person::operator=(const Person& a)
{
    strcpy(this->_name,a._name);
    strcpy(this->_email_address,a._email_address);
    this->date=a.date;
    return *this;
}
const Person& Person::Print()const
{
    cout<<"编号："<<this->_id<<" "<<"名字："<<this->_name<<" "<<"邮箱："<<this->_email_address<<" "<<"生日:("<<this->date.getYear()<<"."<<this->date.getMonth()<<"."<<this->date.getDay()<<")"<<endl;
    return (*this);
}
Person& Person::Print()
{
    this->Print();
    return *this;
}

void CreatDate(Person r[])
{
    for(int i = 0;i<N;i++){
    cout<<"请输入第"<<i+1<<"个学生信息："<<"姓名 "<<"邮箱 "<<"生日（年月日）"<<endl;
        cin>>r[i];
    }
}
void PrintDate(Person r[])
{
    for (int i = 0; i<N; ++i) {
        cout<<r[i];
    }
    
}
void ModifyDate(Person r[])
{
    int i = 0;
    cout<<"请选择修改编码：";
    cin>>i;
    if (i<N) {
        cout<<"请选择修改项：1、姓名；2、邮箱；3、年月日"<<endl;
        int xz;
        cin>>xz;
        switch (xz) {
            case 1:
                char na[10];
                cin>>na;
                r[i].setName(na);
                break;
            case 2:
                char em[20];
                cin>>em;
                r[i].setEmailAddress(em);
                break;
            case 3:
                int ye,mom,day;
                cin>>ye>>mom>>day;
                r[i].setBirthDate(ye,mom,day);
                break;
            default:
                break;
        }
    }
    else{
        cout<<"无此号码信息"<<endl;
    }
//    r1[i] = r[i];
}
void DeleteDate(Person r[])
{
    int i = 0;
    cout<<"请选择删除编码：";
    cin>>i;
    if (i<N) {
        Person x;
        r[i]=x;
    }
    else{
        cout<<"无此号码信息"<<endl;
    }
//    r1[i]=r[i];
}
void exi()
{
    for (int i = 0; i<N; ++i) {
        delete r1.GetName();
        delete  r1.GetEmailAddress();
    }
}
Person::~Person()
{
    if ((this->_name!=NULL)&&(this->_email_address!=NULL)) {
        delete [] _name;
        _name=NULL;
        delete [] _email_address;
        _email_address=NULL;
    }
}