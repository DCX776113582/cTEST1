//
//  main.cpp
//  Chapter05_Demo2
//
//  Created by mac on 18/3/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//
#include "demo.h"
#include <vector>
#include <exception>
int main(int argc, const char * argv[]) {
//    testFloat();
//    testStack();
//    testStack2();
    VecStack<int> s;
    int one = 1, two = 2, three = 3;
    s.push(one).push(two).push(three);
    cout << s.top( ) << endl;
    s.pop( ).pop( );
    cout << s.top( ) << endl;
    s.pop( );
    if (!s.empty( ))
    {
        cout << "Error.\n";
    }else{
        cout << "Empty.\n";
    }
    return 0;
}
