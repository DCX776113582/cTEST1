//
//  main.cpp
//  Chapter01
//
//  Created by mac on 18/1/29.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <iostream>//c++标准库中的输入与输出操作流（类）
#include "Circle.hpp"
#include <math.h>
#include <iomanip>
#include "Thing.hpp"
#include "Point.hpp"
#include "Test.hpp"
using namespace std;
static void dummy();
double PI =3.14;
namespace myNamespace  {
    double PI = 3.15;
    void printPI()//名字空间的函数
    {
        std::cout<<"PI = "<<PI<<std::endl;
    }
};
void test1()
{
    // std 全局名字空间
    // ::运算符（全局域运算符）
    //系统实例化出两个对象：输入对象 cin；输出对象 cout
    //系统定义的两个运算符：输入运算符 >>;输出运算符 <<
    std::cout << "Hello, World!\n";
    std::cout << PI <<"\n";//全局变量
    std::cout << myNamespace::PI<<"\n";
    myNamespace::printPI();
    
    int a;
    printf("输入：");
    scanf("%d",&a);
    printf("a:%d\n",a);
    std::cout<<"a++输入:";
    std::cin>>a;
    std::cout<<"a:"<<a<<"\n";
    //    std::cout
}
void test2()
{
    Circle c1;//类类型 对象
    c1.setCircle(10, 1, 1, 1);
    c1.printCircle();
    std::cout<<std::endl;
    Circle c2;//对象
    c2.setCircle(10, 2, 3, 2);
    c2.printCircle();
    std::cout<<std::endl;
    Circle *p2 = &c2;//对象指针
    p2->setCircle(5, 1, 3, 5);
    c2.printCircle();
    Circle cs[10];//对象数组
    for (int i = 0; i<10; ++i) {
        cs[i].setCircle(i+5, i-i, i-i, 2);
        cs[i].printCircle();
        std::cout<<std::endl;
    }
}
void test3()//Demo01
{
    Circle2 c1;
    Circle2 c[3];
    c[1].setCircle(1.0,0.0,0.0);
    c[2].setCircle(1.0,1.0,1.0);
    c[0].setCircle(1.0,0.0,27.0);
    cout<<"c[0]’s radius is "<<c[0].getRadius()<<endl;//c[0]‘s radius is 1
    cout<<"c[0]’s center x is "<<c[0].getCentreX ()<<endl;
    cout<<"c[0]’s center y is "<<c[0].getCentreY  ()<<endl;
    cout<<"the distance between the centres is "<< c[1].distance(c[2])<< "  units\n";
    cout<<"the distance between the centres is "<< c[1].distance(c[0])<< "  units\n";
    cout<<"\nThe end\n";
}
void test4()//Demo1
{
    Circle1 c[3];//创建c[0],c[1],c[2]初始化
    for (int i = 0; i<3; ++i) {
        c[i].printCircle();
    }
    for (int i = 0; i<3; ++i) {
        cout<<"设置第"<<i+1<<"个圆的信息："<<endl;
        float r,x,y;
        cout<<"半径：";
        cin>>r;
        cout<<"X：";
        cin>>x;
        cout<<"Y：";
        cin>>y;
        c[i].setCircle(r, x, y);
    }
    for (int j = 0; j<3; ++j) {
        cout<<"打印第"<<j+1<<"个圆的信息："<<endl;
        c[j].printCircle();
        cout<<"圆的面积为："<<c[j].area()<<endl;
        cout<<"圆的周长为："<<c[j].perimeter()<<endl;
    }
    cout<<"圆1与圆2的距离："<<setiosflags(ios::fixed) << setprecision(2)<<c[0].distance(c[1])<<endl;
    cout<<"圆2与圆3的距离："<<setiosflags(ios::fixed) << setprecision(2)<<c[1].distance(c[2])<<endl;
    cout<<"圆1与圆3的距离："<<setiosflags(ios::fixed) << setprecision(2)<<c[0].distance(c[2])<<endl;
    
    Circle1 c1(2,1,1);
    c1.printCircle();
}
void test5()//带参与不带参默认构造函数
{
    int a = 10;
    int &b = a;//引用类型变量b：是a变量的引用（别名）
    b=100;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<&a<<endl;
    cout<<&b<<endl;
    
    Thing t;
    Thing t1(10);
    Thing t2(10,20);
    Thing t3(10,20,30);
    t.printThing();
    t1.printThing();
    t2.printThing();
    t3.printThing();
    t3.setThing(32, 12, 23);
    t3.printThing();

}
void test6()//DEmo05
{
    Circle3 c;
    //定义一个对象，调用两个构造函数：先Circle，后Point先构造了point，再构造c
    //当创建复合类的对象时，不仅调用复合类本身的构造函数，
    //还将调用复合类的类类型的成员变量的默认构造函数。
    c.printCircle();
    
    Point p(5,7);
    p.printPoint();
    
    c.setCircle(10,p);
    c.printCircle();
    
    Circle3 c2(33.0,44.0,55.0);
    c2.printCircle();
    
    //关于const成员函数增加的代码
    const Circle3 c3( 1, 2, 3 );
    //const对象，只能调用const修饰的成员函数,const位于函数小括号后面。
    //普通对象，可以调用const和非const成员函数。
    c3.printCircle();
    
    const Circle3 & c4 = c3;
    //const对象，只能赋值给const类型的引用，而不能赋值给普通引用。
    c4.printCircle();
    
    const int a = 10;
    const int & b = a;
    cout<<b<<endl;
    //指向常量的指针，即指针指向对象的值不能修改，但可以指向别的对象。
    const Circle3 * c5 = &c2;
    c5->printCircle();
    
    //指针常量，c6不能指向别的对象，但是可以修改指向对象的值。
    Circle3 * const c6 = &c;
    c6->printCircle();
    //根据const的位置，区分哪个是常量：const后面紧跟着的那个就是常量。
}
void test7()
{
    Point1 p;//默认构造
    p.printPoint1();
    Circle4 c;//默认构造
    c.printCircle4();
    
    Point1 p1(1,1);//普通构造
    p1.printPoint1();//普通构造
    Circle4 c1(1,2,2);
    c1.printCircle4();
    
    Point1 p2(10,10);
    c1.setPoint(p2);
    c1.printCircle4();
}
void test8()//指针指向对象
{
    const Point1 p2;//const对象
    Point1 p1;//非const对象
    
    //指针可变（常量指针）
    Point1 * ptr = &p1;//指向非const对象
    ptr->printPoint1();//调用非const函数。（*ptr）类型
    const Point1 * ptr1 = &p2;//常量指针指向普通对象/const对象
    ptr1->printPoint1();//const函数
    ptr1 = &p1;//指向非const对象
    ptr1->printPoint1();//const函数
    
    //指针指向不可变（指针常量）
    const Point1 * const ptr2 = &p2;//指向const对象
    ptr2->printPoint1();//const函数
    Point1 * const ptr3 = &p1;//指向非const对象
    ptr3->printPoint1();//非const函数
    const Point1 * const ptr4 = &p1;//指向非const对象
    ptr4->printPoint1();//const函数
}
void exchange(int& a,int& b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void test9()//const修饰函数返回值类型
{
    int x = 1,y = 2;
    cout<<"Before:"<<x<<","<<y<<endl;
    exchange(x,y);
    cout<<"After:"<<x<<","<<y<<endl;
    
    const Point1 p2(2,2);//const对象
    const Circle4 c1(1,p2);//const对象
    Point1 p1(1,1);//非const对象
    Circle4 c2(2,p1);//非const对象
    
    //引用
    //    const Point1 &p3 = p1;
    //    p3.printPoint1();//调用const函数
    //    p1.printPoint1();//调用非const函数
    cout<<"("<<p1.getXPoint()<<","<<p1.getYPoint()<<")"<<endl;
    cout<<"("<<p2.getXPoint()<<","<<p2.getYPoint()<<")"<<endl;
    const float &s1 = p2.getXPoint();
    const float &s2 = p2.getYPoint();
    cout<<"("<<s1<<","<<s2<<")"<<endl;
    
    c1.printCircle4();
    c2.printCircle4();
}
void test10()//析构函数
{
    //c语言语法
    Point1*p=(Point1*)malloc(sizeof(Point1));
    p->printPoint1();
    free(p);
    p=NULL;
    
    Circle4*p1=(Circle4*)malloc(sizeof(Circle4));
    p1->printCircle4();
    free(p1);
    p1=NULL;
    //c++语法
    Point1 *p2 = new Point1();//申请堆空间
    p2->printPoint1();
    delete p2;//释放堆空间
    p2=NULL;
    
    Circle4 *p3=new Circle4();
    p3->printCircle4();
    delete p3;
    p3=NULL;
}
void test11()//DEmo06
{
    //Test t; //t是局部变量，本身分配在栈上。
    //t的成员_pVar是个指针，里面存储的是地址。
    //指针_pVar指向的new出来的堆空间，不是t的成员。
    
    Test t1,t2,t3;
    //构造函数的调用顺序：t1,t2,t3（压栈）
    //析构函数的调用顺序：t3,t2,t1（出栈）先进后出。
}
void test12(Test2 t)
{
    cout<<"test12被调用"<<endl;
}//析构
Test2 test13(Test2& t)
{
    return t;
}
void test14()//DEmo07-浅拷贝
{
//    Test2 t;
//    Test2 t1;
    //对象与对象之间的赋值
    //1、对象2 = 对象1
//    t1 = t; 	//这种方式造成二次删除和内存泄漏
    //2、传值
//    test12(t1);//t=t1 这种方式造成二次删除
    //3、返回值
//    test13(t1);//临时对象 =t1；t=临时对象
    //4、指针指向堆
    Test2 * t = new Test2;
    delete t;
    t = NULL;//空间释放问题，仔细分析。
}
void test15()//函数链
{
    Circle5 c1;
    Circle5 c2(1,0,0);
    
    c1.printCircle();
    c2.printCircle();
    
    c1=c2;
    c1.printCircle();
    cout<<&c2<<endl;
    //    c2.setRadius(10)->setXCentre(10)->setYCentre(10);
    //    c2.printCircle();
    c2.setRadius(15).setXCentre(15).setYCentre(15);
    
    c2.printCircle();
    //    c.setXCentre(20).setYCentre(20);
}
static int y;//静态全局变量（只作用在本文件内）
static void dummy()//静态函数
{
    static int x;//静态局部变量
    x++;
    cout<<"x="<<x<<endl;
}
void show_average(const double& x)
{
    static int number = 0;
    static double sum = 0;
    number++;
    sum+=x;
    cout<<"number="<<number<<" "<<"Average:"<<sum/number<<endl;
}
void test16()
{
//    for (int i = 0; i<3; ++i) {
//        cout<<"第"<<i+1<<"次"<<endl;
//        dummy();
//    }
    int i = 0;
    for (; ; ) {
        double num;
        cout<<"第"<<i+1<<"次输入"<<endl;
        cin>>num;
        if (num<0) {
            break;
        }
        show_average(num);
        ++i;
    }
}
int main(int argc, const char * argv[]){
    //面向对象，实现测试

    test16();
    return 0;

}
