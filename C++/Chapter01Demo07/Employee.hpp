//
//  Employee.h
//  Chapter01Demo07
//
//  Created by mac on 18/2/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter01Demo07__Employee__
#define __Chapter01Demo07__Employee__

#include <iostream>
using namespace std;
class Employee{
private:
    char name[50];
    int id;
    static int next_id;
    static float total_pay;
public:
    Employee(char * name_str);
    int getId();
    static void acc_total(float f);
    void print();
};
#endif /* defined(__Chapter01Demo07__Employee__) */
