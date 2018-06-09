//
//  string.cpp
//  Chapter03
//
//  Created by mac on 18/2/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "String.hpp"
ostream& operator<<(ostream& out,STRING&p1)
{
    out<<p1.p<<endl;
    return out;
}
const int& STRING:: getSize()const
{
    return this->size;
}
char* STRING::getPA()
{
    return this->p;
}