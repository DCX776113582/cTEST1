//
//  main.cpp
//  Chapter04_Demo6
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "point.h"
#include "hero.h"
void pointtest()
{
    Circle c(1, 2, 3);
    Square s(4, 5, 6);
    Figure *f = &c;
    Figure &g = s;
    
    //纯虚函数
    f->draw( );
    
    //在普通成员move函数内，调用子类虚函数。
    f->move(Point(2, 2));
    
    //纯虚函数
    g.draw( );//多态体现——子类正方形特性
    g.rotate(1);//多态体现——子类正方形特性
    
    //父类的普通成员函数中，调用纯虚函数
    g.move(Point(1,1));
    
    s.vertices( );
    
    //不能通过一个指向子类对象的父类引用，调用子类自己扩展的成员函数。
    //     g.vertices();

}
void test()
{
    long d = 100;
    long * p = &d;
    int i = reinterpret_cast<int>(p);
    char * j = reinterpret_cast<char*>(i);
    char q = '0';
    //静态类型转换运算符：static_cast<<#type#>>(<#expression#>)与显示类型转换作用一致
    cout<<static_cast<int>(q)<<endl;
    cout<<static_cast<char>(d)<<endl;
    cout<<i<<endl;
    cout<<*j<<endl;
    
    const int q1 = 10;//定义的本质类型不变
    cout<<(const_cast<int&>(q1)=100)<<endl;;
    cout<<q1<<endl;
}
int main(int argc, const char * argv[]) {
    Ultra *u1 = new Ultra;
    Karmen *k1 = new Karmen;
    Atm * a1 = new Atm;
//    u1->print();
//    cout<<endl;
//    k1->print();
//    cout<<endl;
//    a1->print();
//    cout<<endl;
    /*向下转型：
     问题：pd=pb；语法错误
     解决办法：强制转换、静态类型转换方式->向下转型
     遗留问题：父类指针始终指向父类对象时，此时任然调用的是父类的虚函数，不能体现出子类的特征（不能实现多态性）
     解决遗留问题：只能使用动态类型转换方式
     如果父类指针、引用指向子类对象时，则安全（体现出子类的特征，能实现多态性）
     */
//    u1 = a1;//向上转型
//    u1->print();
//    cout<<endl;
    a1 = (Atm*)u1;//向下转型
    Atm*a2 = dynamic_cast<Atm*>(u1);
    cout<<a2<<endl;
    cout<<endl;
    Hero * h1[3] = {u1,k1,a1};
    for (int i = 0; i<3; ++i) {
        h1[i]->print();
        cout<<endl;
    }
    cout<<endl;
    test();
    return 0;
}
