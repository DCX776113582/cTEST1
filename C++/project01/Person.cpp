//
//  Person.cpp
//  project01
//
//  Created by mac on 18/2/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Person.hpp"
/*Person:: Person()
{
    this->name = new char[5];
    strcpy(this->name, "name");
    
    this->emailAddress = new char[12];
    strcpy(this->emailAddress, "name@qq.com");
    
//    this->birthday.setYear(2000);
//    this->birthday.setMonth(1);
//    this->birthday.setDay(1);
    
    Date date;
    this->birthday = date;
}
*/
Person:: Person():name(new char[5]),emailAddress(new char[12]),birthday()
{
    strcpy(this->name, "name");
    strcpy(this->emailAddress, "name@qq.com");
}
/*Person:: Person(char * _name,char * _emailAddress,Date& _birthday)
{
    this->name = new char[strlen(_name)+1];
    strcpy(this->name, _name);
    
    this->emailAddress = new char[strlen(_emailAddress)+1];
    strcpy(this->emailAddress, _emailAddress);
    
    this->birthday = _birthday;
}
 */
Person:: Person(const char * _name,const char * _emailAddress,Date& _birthday):name(new char[strlen(_name)+1]),emailAddress(new char[strlen(_emailAddress)+1]),birthday(_birthday)
{
    strcpy(this->name, _name);
    strcpy(this->emailAddress, _emailAddress);
}
/*Person:: Person(char * _name,char * _emailAddress,int _year,int _month,int _day)
{
    this->name = new char[strlen(_name)+1];
    strcpy(this->name, _name);
    
    this->emailAddress = new char[strlen(_emailAddress)+1];
    strcpy(this->emailAddress, _emailAddress);

//    this->birthday.setYear(_year);
//    this->birthday.setMonth(_month);
//    this->birthday.setDay(_day);
    Date date(_year,_month,_day);
    this->birthday = date;
}
*/
Person:: Person(const char * _name,const char * _emailAddress,int _year,int _month,int _day):name(new char[strlen(_name)+1]),emailAddress(new char[strlen(_emailAddress)+1]),birthday(_year,_month,_day)
{
    strcpy(this->name, _name);
    strcpy(this->emailAddress, _emailAddress);
}
/*Person:: Person(const Person & per)
{
    this->name = new char[strlen(per.name)+1];
    strcpy(this->name, per.name);
    this->emailAddress = new char[strlen(per.emailAddress)+1];
    strcpy(this->emailAddress, per.emailAddress);
    this->birthday = per.birthday;
}
 */
Person:: Person(const Person & per):name(new char[strlen(per.name)+1]),emailAddress(new char[strlen(per.emailAddress)+1]),birthday(per.birthday)
{
    strcpy(this->name, per.name);
    strcpy(this->emailAddress, per.emailAddress);
}
void Person:: print()
{
    cout<<"Name:"<<this->name<<"  EmailAddress📬:"<<this->emailAddress<<"  Birthday🎂:"<<this->birthday;
}
void Person:: setName(const char * _name)
{
    if (this->name!=NULL) {
        delete [] this->name;
        this->name = new char[strlen(_name)+1];
        strcpy(this->name, _name);
    }
}
void Person:: setEmailAddress(const char * _emailAddress)
{
    if (this->emailAddress!=NULL) {
        delete []  this->emailAddress;
        this->emailAddress = new char[strlen(_emailAddress)+1];
        strcpy(this->emailAddress, _emailAddress);
    }
}
void Person:: setBirthday(Date & _birthday)
{
    this->birthday = _birthday;
}
void Person:: setBirthday(int _year,int _month,int _day)
{
    this->birthday.setYear(_year);
    this->birthday.setMonth(_month);
    this->birthday.setDay(_day);
}
//访问函数
char * Person:: getName()
{
    return this->name;
}
char * Person:: getEmailAddress()
{
    return this->emailAddress;
}
Date & Person:: getBirthday()
{
    return this->birthday;
}
Person& Person:: operator=(Person& person)
{
    if (this!=&person) {
        if (this->name != NULL) {
            delete [] this->name;
            this->name = new char[strlen(person.name)+1];
            strcpy(this->name, person.name);
        }
        if (this->emailAddress!=NULL) {
            delete []  this->emailAddress;
            this->emailAddress = new char[strlen(person.emailAddress)+1];
            strcpy(this->emailAddress, person.emailAddress);
        }
        this->birthday = person.birthday;
    }
    return (*this);
}
ostream& operator<<(ostream& out,const Person& per)
{
    out<<"Name:"<<per.name<<"  EmailAddress📬:"<<per.emailAddress<<"  Birthday🎂:"<<per.birthday;
    return out;
}
istream& operator>>(istream& in,Person& per)
{
    cout<<"Name:";
    in>>per.name;
    cout<<"Email:";
    in>>per.emailAddress;
    cout<<"Birthday:"<<endl;
    in>>per.birthday;
    return in;
}
Person::~Person()
{
    if (this->name!=NULL) {
        delete [] this->name;
        this->name = NULL;
    }
    if (this->emailAddress!=NULL) {
        delete [] this->emailAddress;
        this->emailAddress = NULL;
    }
}
