//
//  main.cpp
//  Chapter04_Demo3
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "student.hpp"

int main(int argc, const char * argv[]) {
    Student s1(1001,"kuuga",100,"A");
    Student s2(1002,"agito",90,"B");
    s1.print();
    s2.print();
    Student s3(s1);
    s3.print();
    Student s4;
    s4 = s3;
    s4.print();
    return 0;
}
