//
//  main.cpp
//  Chapter04_Demo8
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "test.h"
void test1()
{
    const A a1;
    cout<<a1.x<<endl;
    A* a2 = const_cast<A*>(&a1);
    a2->x=200;
    cout<<a2->x<<endl;
    A& a3 = const_cast<A&>(a1);
    a3.x = 300;
    cout<<a3.x<<endl;
}
void test2()
{
    B b;
    C c;
    const B * b1;
    const C * c1;
    A* a[2]= {&b,&c};
    for (int i = 0; i<2; ++i) {
        if ((b1=dynamic_cast<B*>(a[i]))) {
            cout<<"b1->b A* 被转型为 B*！向下转型（安全）"<<endl;
            b1->print();
            b1->outB();
        }
        if ((c1=dynamic_cast<C*>(a[i]))) {
            cout<<"c1->c A* 被转型为 C*！向下转型（安全）"<<endl;
            c1->print();
            c1->outC();
        }
    }
}
int main(int argc, const char * argv[]) {
    test2();
    return 0;
}
