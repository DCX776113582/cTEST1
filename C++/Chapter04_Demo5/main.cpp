//
//  main.cpp
//  Chapter04_Demo5
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "derived.hpp"

//测试虚函数：动态绑定的原理
//void foo(Base& b)//传递Base 对象 //Derived 对象
//{
//	b.func();   //?
//}

//测试虚函数：动态绑定的原理
void test(Person& p)
{
    p.what_am_i();//父类对象的引用/指针来调用虚函数
}

//测试虚函数：动态绑定的原理
void test()
{
    Person p;
    p.what_am_i();
    
    Student s;
    s.what_am_i();
    
    Teacher t;
    t.what_am_i();
    
    test(s);//发生在执行期间：才能够证实所传递的对象的真实类型，根据真实的类型来调用匹配的函数——动态绑定
    /*
     //要求：
     1、继承关系：子类必须继承父类
     2、子类必须重写/覆盖父类的虚函数
     3、父类中被子类重写的函数必须为虚函数（virtual）
     4、应用：必须满足父类的引用/父类的指针指向子类对象（将子类的对象赋值给父类的引用/指针），通过父类的引用/父类指针直接调用虚函数。
     //目的：实现多态
     */
}

//测试虚析构（防止子类对象中的内存泄漏问题）
void testVirtual()
{
    Person* p = new Person;
    Student* s = new Student;
    Teacher* t = new Teacher;
    
    Person p1;
    cout<<sizeof(p1)<<endl;
    
    Person* array[3] = {p,s,t};
    for (int i = 0; i<3; ++i) {
        array[i]->what_am_i();
    }
    
    delete array[0];
    delete array[1];
    delete array[2];
}

#include "multiple.hpp"
//测试多重继承（无/有覆盖函数的情况）
void testMultipl()
{
    Derived d;
    d.f();
    d.Base1::f();
    d.Base2::f();
    d.Base3::f();
    
    Base1 & b1 = d;
    b1.f();
    
    Base2 & b2 = d;
    b2.f();
    
    Base3 & b3 = d;
    b3.f();
}

#include "thing.hpp"
#include "thingSet.hpp"
#include <vector> //系统定义的容器类
//测试多态
void testPolymorphism1()
{
    //定义容器（自定义容器）
    ThingSet thingSet(10);
    
    //定义对象
    Thing* t = new Thing();
    Animal1* a = new Animal1();
    Cat* c = new Cat();
    Dog* d = new Dog();
    Person2 * p = new Person2();
    Teacher2* t2 = new Teacher2();
    Student2* s2 = new Student2();
    Vehicle3* v3 = new Vehicle3();
    Car* car = new Car();
    YellowBike* b = new YellowBike();
    
    Thing* array[10] = {t,a,c,d,p,t2,s2,v3,car,b};
    
    
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        thingSet.add(*array[i]) ;//给容器中添加元素
    }
    
    //	cout<<thingSet;
    
//    for( int i = 0; i < thingSet.getSize(); i++ )
//    {
//        thingSet[i]->what_am_i() ;//给容器中添加元素
//    }
    bool yes = false;
    cout<<"容器中Animal1类的信息"<<endl;
    for (int i = 0; i<thingSet.getSize(); ++i) {
        Animal1 * p2 = NULL;
        if ((p2 = dynamic_cast<Animal1*>(thingSet[i]))!=NULL) {
            yes = true;
            p2->what_am_i();
        }
    }
    if (yes==false) {
        cout<<"未找到"<<endl;
    }
    for (int i = 0; i<thingSet.getSize(); ++i) {
        delete array[i];
    }
}

void testPolymorphism2()
{
    vector<Thing*> v;
    Thing* t = new Thing();
    Animal1* x = new Animal1();
    Thing* array[2];
    
    array[0] = t;
    array[1] = x;
    for( int i = 0; i < 2; i++ )
    {
        v.push_back(array[i]);//给容器中添加元素（按照入栈的形式）
    }
    
    for (int i = 0; i < v.size(); ++i) {
        (v[i])->what_am_i();
    }
    cout<<endl;
    delete array[0];
    delete array[1];
}
int main(int argc, const char * argv[]) {
    //	test();
    //	testVirtual();
    //	testMultipl();
    testPolymorphism1();
    return 0;
}

