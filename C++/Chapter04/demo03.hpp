//
//  demo03.h
//  Chapter04
//
//  Created by mac on 18/2/25.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter04__demo03__
#define __Chapter04__demo03__

#include <iostream>
using namespace std;
class Base{
private:
    int priv;
protected:
    int prot;
    int get_priv();
public:
    int publ;
public:
    Base();
    Base(int a,int b,int c);
    int get_prot();
    int get_publ();
};

class Derived1:private Base{
public:
    Derived1(int a,int b,int c);
    int get1_priv();
    int get1_prot();
    int get1_publ();
};

class Leaf1 : public Derived1{
public:
    Leaf1(int a, int b, int c);
    void print();
};

class Derived2 : protected Base{
public:
    Derived2(int a, int b, int c);
    int get2_priv();
    int get2_prot();
    int get2_publ();
};
class Derived3 : public Base{
public:
    Derived3(int a, int b, int c);
    int get3_priv();
};

class Leaf2 : public Derived2{
public:
    Leaf2(int a, int b, int c);
    void print();
};
class Leaf3 : public Derived3{
public:
    Leaf3(int a, int b, int c);
    void print();
};

#endif /* defined(__Chapter04__demo03__) */
