//
//  Complex.h
//  Chapter02
//
//  Created by mac on 18/2/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter02__Complex__
#define __Chapter02__Complex__

#include <iostream>
using namespace std;
class Complex{
private:
    int _real;
    int _imag;
public:
    Complex();
    Complex(int real, int imag);
    void print() //打印复数
    {
        cout<<"复数为："<<_real<<"+"<<_imag<<"i"<<endl;
    }
    int getReal();
    int getImag();
    int setReal(int x);
    int setImag(int y);
    //重载运算符函数
    Complex operator+(const Complex & c1);
    Complex operator-(const Complex & c1);
    Complex operator*(const Complex & c1);
    Complex operator/(const Complex & c1);
    
    /*friend Complex operator+(const Complex & c1,const Complex & c2);
    friend Complex operator-(const Complex & c1,const Complex & c2);
    friend Complex operator*(const Complex & c1,const Complex & c2);
    friend Complex operator/(const Complex & c1,const Complex & c2);*/
    //重载输出/输入函数
    friend ostream& operator<<(ostream& out,const Complex & c1);
    friend istream& operator>>(istream& in,Complex & c1);

};
#endif /* defined(__Chapter02__Complex__) */
