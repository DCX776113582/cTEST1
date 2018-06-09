//
//  Vector.cpp
//  Chapter03
//
//  Created by mac on 18/2/7.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Vector.hpp"
#include <string.h>
Vector1::Vector1(int si):size(si){
    if (size<=0) {
        p=NULL;
    }else{
        p=*new STRING*[size];
        for (int count = 0; count < size; ++count)
        {
            
        }
    }
}
STRING* Vector1::getP()
{
    return this->p;
}
STRING& Vector1::getP()const
{
    return *this->p;
}

int Vector1::get_size( ) const
{
    return size;
}
const Vector1& Vector1:: operator=(const Vector1& p1){
    if ( this != &p1 ) {
        delete []p;
        this->size = p1.size;
        p = new STRING[size];
        for (int count = 0; count < size; ++count)
            p[count] = p1.p[count];
    }
    return *this;
}

ostream& operator<<(ostream& out,Vector1&p1)
{
    out<<"size:"<<p1.size<<endl;
    for (int i= 0; i<p1.size; ++i) {
        out<<p1.p[i]<<endl;
    }
    return out;
}
/*bool operator==(const Vector1& a, const Vector1& b)
{
    bool yes = true;
    if (a.get_size( ) != b.get_size( )) {
        yes = false;
    } else {
        int s, index = 0;
        s = a.get_size();
        while (index < s && a.getP()==b.getP())
        {
            ++index;
        }
        if (index < s) {
            yes = false;
        }
    }
    return yes;
}*/
