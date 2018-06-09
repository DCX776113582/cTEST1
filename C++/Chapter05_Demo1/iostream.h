//
//  iostream.h
//  Chapter05_Demo1
//
//  Created by mac on 18/3/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef Chapter05_Demo1_iostream_h
#define Chapter05_Demo1_iostream_h
#include <iostream>//使用系统定义命名空间
using namespace std;
//自定义名字空间:独立定义在.h文件，没有对应的.cpp文件，否则链接错误
namespace My_space {
    int rider=78;
    const int size = 20;
    void print()
    {
        cout<<"My_space::print  "<<rider<<"   "<<size<<endl;
    }
    class Base{
    public:
        virtual void print() = 0;
    };
    class Derived:public Base{
    public:
        void print()
        {
            cout<<"Derived:"<<endl;
        }
    };
    //内部名字空间
    namespace inner{
        int rider = 100;
        const int size = 200;
        void print()
        {
            cout<<"inner::print "<<rider<<"   "<<size<<endl;
        }
        class Base{
        public:
            virtual void print() = 0;
        };
        class Derived:public Base{
        public:
            void print()
            {
                cout<<"Derived Action:"<<endl;
            }
        };
    };
};
//extern int rider;
//extern const int size;
extern void print();//全局函数
//class Base{
//    virtual void print() = 0;
//};
//class Derived:public Base{
//    void print()
//    {
//        cout<<"Derived:"<<endl;
//    }
//};

#endif
