//
//  main.cpp
//  Chapter04_Demo2
//
//  Created by mac on 18/2/26.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "point.hpp"
#include "cylinder.hpp"
#include "circle.hpp"
int main(int argc, const char * argv[]) {
    Point p1(1,1);
    Circle c1(1,1,1);
    Cylinder cy1(1,1,1,1);
    
    p1.print();
    c1.print();
    cy1.print();
    return 0;
}
