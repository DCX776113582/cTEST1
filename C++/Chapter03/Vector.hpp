//
//  Vector.h
//  Chapter03
//
//  Created by mac on 18/2/7.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter03__Vector__
#define __Chapter03__Vector__

#include <iostream>
#include "string.hpp"
using namespace std;
class Vector1{
    STRING* p;
    int size;
public:
    Vector1(int si=0);
    Vector1(const Vector1&p1):p(p1.p),size(p1.size){}
public:
    int get_size( ) const;
    STRING& getP()const;
    STRING* getP();
    const Vector1& operator=(const Vector1& p1);
    friend ostream& operator<<(ostream& out,Vector1&p1);
public:
    ~Vector1(){
        if (this->p!=NULL) {
            delete []p;
            p=NULL;
        }
    }
};
bool operator==(const Vector1&a,const Vector1&b);
#endif /* defined(__Chapter03__Vector__) */
