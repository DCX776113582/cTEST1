//
//  derived.cpp
//  Chapter04_Demo4
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "derived.h"
void Derived:: fun()
{
    cout<<"Derived class function."<<endl;
}
void Animal:: what_Am_I()
{
    cout<<"I am a Animal."<<endl;
}
Animal:: ~Animal()
{
    cout << "Animal destructor" << endl;
}