//
//  main.cpp
//  Exercise8
//
//  Created by mac on 18/2/28.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "test.h"
#include <vector>
int main(int argc, const char * argv[]) {
    Vector v1(5);
    Point p1(1,1);
    Square f1(&p1,0,0);
    Circle c1(&p1);
    Figure* q1[2]={&f1,&c1};
    v1.add(*q1[0]);
    v1.add(*q1[1]);
    v1[0]->draw();
    v1[1]->draw();
    return 0;
}
