//
//  STR.hpp
//  STR
//
//  Created by mac on 18/4/27.
//  Copyright © 2018年 duanchuanxin. All rights reserved.
//

#ifndef STR_hpp
#define STR_hpp

#include <iostream>
using namespace std;
#include <string>
#include <assert.h>
//自定义String类,系统是string类
class String
{
public:
    String();                              //默认构造函数,用于创建空字符串
    ~String();                             //析构函数
    String(const char*const cstr);           //构造函数,带一个参数用来初始化字符串
    String(const String &rs);              //复制构造函数,默认是浅层复制,需重载
    char& operator[](unsigned int length); //重载下标运算符[]
    char operator[](unsigned int length)const; //重载下标运算符[](const版本)
    const char&at(int index)
    {
        assert(index<len&&index>=0);
        return str[index];
    }
    String &operator=(const String &rs);     //重载复制运算符=，用于两个字符串之间的赋值
    String operator+(const String &rs);    //重载加法运算符+
    String operator+=(const String &rs);     //重载组合运算符+=
    friend ostream &operator<<(ostream &output, const String &str); //重载输出流运算符<<
    friend istream &operator>>(istream &input, String &str);        //重载输入流运算符>>
    friend bool operator<(const String&str1,const String &str2);    //重载小于运算符<
    friend bool operator>(const String&str1,const String &str2);    //重载大于运算符>
    friend bool operator==(const String&str1,const String &str2);   //重载等于运算符==
    
    unsigned int getlen()const;            //获取字符串长度
    const char*getstr()const;              //获取字符串
    
    //int operator++(){cout<<"++i\n";tmp++;return tmp;}    //int的重载自加运算符
    //int operator++(int){cout<<"i++\n";int tmp=rs;rs++;return tmp;}
protected:
private:
    unsigned int len;
    char *str;
};

#endif /* STR_hpp */
