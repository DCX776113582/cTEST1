//
//  test.cpp
//  Chapter03
//
//  Created by mac on 18/2/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "test.hpp"
int Vector::get_size( ) const
{
    return size;
}
Vector::~Vector( )
{
    delete [ ] rep;
    rep = NULL;
}
Vector::Vector(int s) : size(s)
{
    if (size <= 0){
        rep = NULL;
    } else {
        rep = new int[size];
        for (int count = 0; count < size; ++count)
        {
            rep[count] = 0;
        }
    }
}
Vector::Vector(int* a, int s) : size(s), rep(new int[s])
{
    for (int count = 0; count < size; ++count)
    {
        rep[count] = a[count];
    }
}
Vector::Vector(const Vector& v)
{
    this->size = v.size;
    rep = new int[size];
    for (int count = 0; count < size; ++count)
        rep[count] = v.rep[count];
}
const Vector& Vector::operator=(const Vector& x)
{
    if ( this != &x ) {
        delete []rep;
        this->size = x.size;
        rep = new int[size];
        for (int count = 0; count < size; ++count)
            rep[count] = x.rep[count];
    }
    return *this;
}
void Vector::print()
{
    int s = get_size( );
    for (int i = 0; i < s; ++i)
    {
        cout << rep[i]<<endl;
    }
    cout << endl;
}
bool operator==(const Vector& a, const Vector& b)
{
    bool yes = true;
    if (a.get_size( ) != b.get_size( )) {
        yes = false;
    } else {
        int s, index = 0;
        s = a.get_size();
        while (index < s && a.rep[index] == b.rep[index])
        {
            ++index;
        }
        if (index < s) {
            yes = false;
        }
    }
    return yes;
}







Demo::Demo(int n):i(n)
{
    cout << "Default constructor called\n";
}
Demo::Demo(const Demo& a)
{
    i = a.i;
    cout << "Copy constructor called\n";
}
Demo::~Demo( )
{
    cout << "Destructor called\n";
}
const Demo& Demo::operator=(const Demo& a)
{
    this->i = a.i;
    
    cout << "Assignment operator used\n";
    return *this;
}
Demo& Demo::set_value(int n)
{
    i = n;
    return *this;
}
int Demo::get_value() const
{
    return i;
}
Demo foo(Demo x)
{
    Demo d; // Default constructor called
    return d; //temp: Copy constructor called
}//d: Destructor called
//x: Destructor called

