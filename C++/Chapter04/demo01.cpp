//
//  demo01.cpp
//  Chapter04
//
//  Created by mac on 18/2/25.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "demo01.hpp"
Base::Base(int i) : b_number (i) {}

int Base::get_number()
{
    return b_number;
}

void Base::print()
{
    cout << b_number << endl;
}
//调用父类的构造函数构造父类的成员变量，构造函数没有继承
Derived::Derived(int i, int j):Base(i), d_number(j) {}

//覆盖。子类重新实现了父类中已有的成员函数。
void Derived::print()
{
    //在子类中，可以直接调用继承自父类的公有成员函数。
    cout << get_number() << " ";
    
    //cout <<　b_number << endl;//子类中不能直接访问父类的私有成员变量
    
    cout << d_number << endl;
}

