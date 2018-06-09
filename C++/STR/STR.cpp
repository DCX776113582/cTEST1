//
//  STR.cpp
//  STR
//
//  Created by mac on 18/4/27.
//  Copyright © 2018年 duanchuanxin. All rights reserved.
//

#include "STR.hpp"
String::String()                              //默认构造函数,用于创建空字符串
{
    len = 0;
    str = new char[len+1];
    str[0] = '\0';
}
String::~String()                             //析构函数
{
    delete [] str;
    str = NULL;
}
String:: String(const char*const cstr)           //构造函数,带一个参数用来初始化字符串
{
    len = (int)strlen(cstr);
    str = new char[len+1];
    strcpy(str,cstr);
}
String::String(const String &rs)              //复制构造函数,默认是浅层复制,需重载
{
    len = rs.len;
    str = new char[len+1];
    strcpy(str,rs.str);
}
char& String::operator[](unsigned int length) //重载下标运算符[]
{
    return str[length];
}
char String::operator[](unsigned int length)const //重载下标运算符[](const版本)
{
    return str[length];
}
String& String::operator=(const String &rs)     //重载复制运算符=，用于两个字符串之间的赋值
{
    len = rs.len;
    if (str!=NULL) {
        delete [] str;
        str = new char[len+1];
        strcpy(str,rs.str);
    }
    return *this;
}
String String::operator+(const String &rs)    //重载加法运算符+
{
    String sp;
    sp.len = len+rs.len;
    delete [] sp.str;
    sp.str = new char[sp.len+1];
    strcpy(sp.str,strcat(str,rs.str));
    return sp;
}
String String::operator+=(const String &rs)     //重载组合运算符+=
{
    len += rs.len;
    strcat(str,rs.str);
    return *this;
}
ostream &operator<<(ostream &output, const String &str) //重载输出流运算符<<
{
    output<<"len:"<<str.len<<" str:"<<str.str<<endl;
    return output;
}
istream &operator>>(istream &input, String &str)        //重载输入流运算符>>
{
    input>>str.len>>str.str;
    return input;
}
bool operator<(const String&str1,const String &str2)    //重载小于运算符<
{
    bool yes = false;
    if (strcmp(str1.str,str2.str)<0) {
        yes = true;
    }
    return yes;
}
bool operator>(const String&str1,const String &str2)    //重载大于运算符>
{
    bool yes = false;
    if (strcmp(str1.str,str2.str)>0) {
        yes = true;
    }
    return yes;
}
bool operator==(const String&str1,const String &str2)   //重载等于运算符==
{
    bool yes = false;
    if (strcmp(str1.str,str2.str)==0) {
        yes = true;
    }
    return yes;
}
unsigned int String::getlen()const            //获取字符串长度
{
    return len;
}
const char*String::getstr()const              //获取字符串
{
    return str;
}