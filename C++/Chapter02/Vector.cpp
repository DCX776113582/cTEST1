//
//  Vector.cpp
//  Chapter02
//
//  Created by mac on 18/2/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Vector.hpp"
Vector::Vector(int s, int array[]):size(s),rep(new int[s])
{
    for (int i = 0; i<size; ++i) {
        rep[i]=array[i];
    }
}
const Vector&Vector:: operator=(const Vector& x)
{
    if (this != &x) {
        this->size=x.size;
        delete []rep;
        this->rep=new int[size];
        for (int i = 0; i<size; ++i) {
            this->rep[i]=x.rep[i];
        }
    }
    return *this;
}
void Vector::print()
{
    cout<<size<<endl;
    for (int i = 0; i<size; ++i) {
        cout<<rep[i]<<" ";
    }
    cout<<endl;
}
Vector::~Vector()
{}
