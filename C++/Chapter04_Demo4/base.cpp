//
//  base.cpp
//  Chapter04_Demo4
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "base.h"
void Base:: fun()
{
    cout<<"Base class function."<<endl;
}
void Thing:: what_Am_I()
{
    cout<<"I am a Thing."<<endl;
}
Thing:: ~Thing()
{
    cout << "Thing destructor" << endl;
}
