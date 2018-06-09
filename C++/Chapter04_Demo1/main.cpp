//
//  main.cpp
//  Chapter04_Demo1
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Inheritance.hpp"
#include "demo03.hpp"
int main(int argc, const char * argv[]) {
    /*Person p1;
     p1.print();
     student s1;
     s1.print();
     
     Base a(2);
     Derived b(3, 4);
     
     a.print( );
     b.print( );
     
     //用子类对象调用被子类覆盖的父类版本的成员函数。
     cout << "base part of b is ";
     b.Base::print( );*/
    Derived1 d1(1, 2, 3);
    Derived2 d2(4, 5, 6);
    Derived3 d3(7, 8, 9);
    
    //    	cout << d1.publ;		//不能访问
    //    	cout << d1.get_priv();	//不能访问
    cout << d1.get1_priv();
    cout << d1.get1_prot();
    cout << d1.get1_publ();
    //    	cout << d2.publ;		//不能访问
    //    	cout << d2.get_priv();	//不能访问
    cout << d3.publ<<endl;		// OK
    cout << d3.get_prot()<<endl;	// OK
    cout << d3.get3_priv()<<endl;
    Leaf1 lf1(1, 2, 3);
    Leaf2 lf2(4, 5, 6);
    Leaf3 lf3(7, 8, 9);
    //     	cout << lf1.publ << endl; //不能访问
    cout << lf1.get1_publ() << endl;
    cout << lf1.get1_prot() << endl;
    cout << lf1.get1_priv() << endl;
    lf1.print();
    lf2.print();
    lf3.print();
    //     	cout << lf2.publ << endl; //不能访问
    
    cout << lf3.publ << endl; 		// OK
    cout << lf3.get_prot() << endl;
    cout << lf3.get3_priv() << endl;
    return 0;
}
