//
//  Thing.h
//  Chapter01
//
//  Created by mac on 18/1/30.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter01__Thing__
#define __Chapter01__Thing__

//#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Thing{
private:
    int x;
    int &y;
    const int z;
    char k[10];
public:
    Thing(int a=1, int b=2, int c=3,char const *p="NICEDRIVE");
//    {
//        x=a;
//        y=b;
//        z=c;
//        strcpy(k, p);
//    }
    void printThing();
//    {
//        std::cout<<"x="<<x<<" y="<<y<<" z="<<z<<" k="<<k<<std::endl;
//    }
    inline void setThing(int a, int b, int c)
    {
        x=a;
        y=b;
//        z=c;
    }

};
/*class Thing{
public:
    Thing():x(75),y(99),z(66) {  }
    Thing(int a, int b):x(a),y(b) {}
    Thing(int a, int b, int c);
    Thing(int a);
    
    void printThing () const {std:: cout<<"x="
        <<x<<"y="<<y<<" z="<<z <<std:: endl;}
private:
    int x; int y; int z;
};*///DEmo04
class Point
{
public:
    Point() {x=0; y=0;}
    Point(float x_centre, float y_centre)
    {
        x = x_centre;
        y = y_centre;
    }
    
    void printPoint() const {
        cout << "  x=" << x <<
        " y=" << y << endl;
    }
    //const成员函数：成员函数体内，不能直接修改这个类的成员变量的值。
    
private:
    float x;
    float y;
};



#endif /* defined(__Chapter01__Thing__) */
