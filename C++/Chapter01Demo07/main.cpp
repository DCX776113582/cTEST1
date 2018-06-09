//
//  main.cpp
//  Chapter01Demo07
//
//  Created by mac on 18/2/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
#include "Employee.hpp"
using namespace std;
void test01()
{
    for (int i=0; i<10; ++i) {
        Person p;
        p.printPerson();
        cout << "当前人数：" << Person::total() << endl;
        cout << "当前人数：" << p.total() << endl;
    }
}
void test02()
{
    Employee Jack((char*)"Jack");
    Employee Tom((char*)"Tom");
    Employee Jacky((char*)"Jacky");
    Employee Lina((char*)"Lina");
    
    cout<<Jack.getId()<<endl;
    Jack.acc_total(1000);
    Jack.print();
    cout<<Tom.getId()<<endl;
    Tom.acc_total(1000);
    Tom.print();
    cout<<Jacky.getId()<<endl;
    Jacky.acc_total(1000);
    Jacky.print();
    cout<<Lina.getId()<<endl;
    Lina.acc_total(1000);
    Lina.print();
    
}
int main(int argc, const char * argv[]) {
    test02();
    return 0;
}
