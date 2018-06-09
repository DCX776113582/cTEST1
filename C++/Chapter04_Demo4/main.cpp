//
//  main.cpp
//  Chapter04_Demo4
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "derived.h"
#include "multiple.h"
void foo(Base& b)
{
    b.fun();//父类对象的引用或指针来调用虚函数
}
void test1()
{
    Base b;
    Derived d;
    b.fun();
    d.fun();
    foo(b);
    /*动态绑定的概念：
     发生在执行期间：才能够证实所传递的对象的真实类型，根据真实的类型来调用匹配的函数——动态绑定
    要求：
        1、继承关系：子类必须继承父类
        2、子类必须重写/覆盖父类的虚函数
        3、父类中被子类重写的函数必须为虚函数（virtual）
        4、应用：必须满足父类的引用/父类的指针指向子类对象（将子类的对象赋值给父类的引用/指针），父类的引用/父类的指针直接调用虚函数。
    目的：实现多态。
            */
    foo(d);
}
void testVirtual()
{
    Thing* p = new Thing;
    Animal* s = new Animal;
    
    Thing* array[2] = {p,s};
    for (int i = 0; i<2; ++i) {
        array[i]->what_Am_I();
    }
    
    delete array[0];
    delete array[1];
}
void testMultiple()
{
    Derive d;
    d.f1();
    Base1 *b1 = &d;
    Base2 &b2 = d;
    Base3 *b3 = &d;
    b1->f(); //Derive::f()
    b2.f(); //Derive::f()
    b3->f();
    b1->g(); //Base1::g()
    b2.g(); //Base2::g()
    b3->g();
}
int main(int argc, const char * argv[]) {
//    testVirtual();
//    Thing t;
//    cout<<sizeof(t)<<endl;
    testMultiple();
    return 0;
}
