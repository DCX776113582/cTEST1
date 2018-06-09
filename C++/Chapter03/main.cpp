//
//  main.cpp
//  Chapter03
//
//  Created by mac on 18/2/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <iostream>
#include "test.hpp"
#include "string.hpp"
using namespace std;
 A getA(){
    A a;
    return a;
}
void test00()
{
    A a1;cout<<a1;
    A a2(a1);cout<<a2;
    A *a3=new A(a2);cout<<*a3;
    A a4 = a1;cout<<a4;
    printA(a4);
    A a5=getA();
    cout<<a5;
}
void test01()
{
    B x;		//调用默认构造,x在栈上
    cout<<x;
    B y(x);	//调用拷贝构造函数
    cout<<y;
    B z = x; //调用的不是赋值运算符重载函数，而是拷贝构造函数。
    cout<<z;
    z = y;   //调用赋值运算符重载函数 。
    cout<<z;
    B* p = new B(x);//new出来的对象是没有名字的，p只是指向该对象的指针。但是这个对象也是x的copy
    cout<<*p;
    delete p;
    p = NULL;
}
void test02()
{
    Vector vec1;
    vec1.print();
    int array[5] = {1,2,3,4,5};
    Vector vec2( array, 5 );
    vec2.print();
    Vector vec3( vec2 );
    vec3.print();
    if(vec3.size==vec2.size)
    {
        cout<<"The vector3 is equal to vector2"<<endl;
    }
    Vector vec4;
    vec4 = vec3;
    vec4.print();
}
void test03()
{
    Demo a(2); // Default constructor called
    {
        Demo b(a);	// Default constructor called
//        b = foo(a);// x:Copy constructor called
        // b: Assignment operator used
        // temp: Destructor called
    }//b: Destructor called
    Demo c = a;//c: Copy constructor called
}
void test04()
{
    STRING s1;
    STRING s2 = s1;
    cout<<s2<<endl;
    
    STRING s3;
    s3=s2;
    cout<<s3<<endl;
    
    STRING * p = new STRING(s1);
    cout<<*p<<endl;
    delete p;
    p=nullptr;
}
int main(int argc, const char * argv[]) {
    test04();
    return 0;
}
