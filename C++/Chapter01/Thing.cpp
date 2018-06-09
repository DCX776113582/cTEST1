//
//  Thing.cpp
//  Chapter01
//
//  Created by mac on 18/1/30.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Thing.hpp"
Thing::Thing(int a, int b, int c,char const *p):z(c),y(x)
{
    x=a;
//    y=b;
//    z=c;
    strcpy(k,p);
}
void Thing:: printThing()
{
    std::cout<<"x="<<x<<" y="<<y<<" z="<<z<<" k="<<k<<std::endl;
}

/*Thing::Thing(int a):x(a)
{
}

Thing::Thing(int a, int b, int c): x(a),y(b),z(c)
{
}
*/