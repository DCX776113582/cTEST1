//
//  main.cpp
//  lianxi
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "student.h"
int main(int argc, const char * argv[]) {
    Student s1;
    Student1 s2;
    Student2 s3;
    s1.print();
    s1.Person::print();
    s2.print();
//    s2.Person::print();
    s3.print();
//    s3.Person::print();
    return 0;
}
