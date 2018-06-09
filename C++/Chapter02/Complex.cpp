//
//  Complex.cpp
//  Chapter02
//
//  Created by mac on 18/2/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Complex.hpp"
Complex::Complex():_real(0),_imag(0)
{}
Complex::Complex(int real, int imag):_real(real),_imag(imag)
{}
int Complex::getReal()
{
    return this->_real;
}
int Complex::getImag()
{
    return this->_imag;
}
int Complex::setReal(int x)
{
    this->_real=x;
    return this->_real;
}
int Complex::setImag(int y)
{
    this->_imag=y;
    return this->_imag;
}
Complex Complex::operator+(const Complex & c1)
{
    int sum = this->_real+c1._real;
    int sum1 = this->_imag+c1._imag;
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}
Complex Complex::operator-(const Complex & c1)
{
    int sum = this->_real-c1._real;
    int sum1 = this->_imag-c1._imag;
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}
Complex Complex::operator*(const Complex & c1)
{
    int sum = (this->_real*c1._real)-(this->_imag*c1._imag);
    int sum1 = (this->_imag*c1._real)+(this->_real*c1._imag);
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}
Complex Complex::operator/(const Complex & c1)
{
    int sum = ((this->_real*c1._real)+(this->_imag*c1._imag))/((c1._real*c1._real)+(c1._imag*c1._imag));
    int sum1 = ((this->_imag*c1._real)-(this->_real*c1._imag))/((c1._real*c1._real)+(c1._imag*c1._imag));
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}
/*Complex operator+(const Complex & c1,const Complex & c2)
{
    int sum = c1._real+c2._real;
    int sum1 = c1._imag+c2._imag;
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}
Complex operator-(const Complex & c1,const Complex & c2)
{
    int sum = c1._real-c2._real;
    int sum1 = c1._imag-c2._imag;
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}
Complex operator*(const Complex & c1,const Complex & c2)
{
    int sum = (c1._real*c2._real)-(c1._imag*c2._imag);
    int sum1 = (c1._imag*c2._real)+(c1._real*c2._imag);
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}
Complex operator/(const Complex & c1,const Complex & c2)
{
    int sum = ((c1._real*c2._real)+(c1._imag*c2._imag))/((c2._real*c2._real)+(c2._imag*c2._imag));
    int sum1 = ((c1._imag*c2._real)-(c1._real*c2._imag))/((c2._real*c2._real)+(c2._imag*c2._imag));
    Complex temp;
    temp._real = sum;
    temp._imag = sum1;
    return temp;
}*/
ostream& operator<<(ostream& out,const Complex & c1)
{
    out<<"复数为："<<c1._real<<"+"<<c1._imag<<"i"<<endl;
    return out;
}
istream& operator>>(istream& in,Complex & c1)
{
    in>>c1._real>>c1._imag;
    return in;
}

