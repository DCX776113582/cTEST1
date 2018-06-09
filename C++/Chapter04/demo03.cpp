//
//  demo03.cpp
//  Chapter04
//
//  Created by mac on 18/2/25.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "demo03.hpp"
int Base:: get_priv()
{
    return priv;
}
Base:: Base():priv(0),prot(0),publ(0)
{}
Base:: Base(int a,int b,int c):priv(a),prot(b),publ(c)
{}
int Base:: get_prot()
{
    return prot;
}
int Base:: get_publ()
{
    return publ;
}


Derived1:: Derived1(int a,int b,int c):Base(a,b,c)
{}
int Derived1::get1_priv()
{
    return get_priv();
}
int Derived1::get1_prot()
{
    return get_prot();
}
int Derived1::get1_publ()
{
    return get_publ();
}
Derived2::Derived2(int a, int b, int c):Base(a, b, c)
{}
Derived3::Derived3(int a, int b, int c):Base(a, b, c)
{}
int Derived3::get3_priv()
{
    return get_priv();
}


Leaf1::Leaf1(int a, int b, int c):Derived1(a, b, c)
{}
void Leaf1::print( )
{
    // get_priv虽然在爷爷类里是protected类型，但是在父类里变成private类型，所以不能在孙子类里直接访问。
    // cout << get_priv() << get_prot() << publ ;	//不能访问
    
    cout << "Leaf1 members: " << get1_priv() << " " << get1_prot() << " " << get1_publ() << endl;
}

Leaf2::Leaf2(int a, int b, int c):Derived2(a, b, c)
{}
void Leaf2::print()
{
    cout << "Leaf2 members: "
    << get_priv( ) << " "
    << prot << " "
    << publ << endl;
    
    //	cout << priv << endl; //不能访问
}

Leaf3::Leaf3(int a, int b, int c):Derived3(a, b, c)
{}
void Leaf3::print( )
{
    cout << "Leaf3 members: " << get_priv( ) << " "
    << prot << " "
    << publ << endl;
    
    //    cout << priv << " "	<< endl; //不能访问
}

