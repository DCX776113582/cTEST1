//
//  KarmenRiderWDrive.h
//  GameDrive
//
//  Created by mac on 18/1/30.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __GameDrive__KarmenRiderWDrive__
#define __GameDrive__KarmenRiderWDrive__

#include <iostream>
using namespace std;
class Driver {
    
public:
    void print()
    {
        cout<<"Driver"<<endl;
    }
};
class Memory{
    char * J;
public:
    Memory(const char * _J="Memory");
    ~Memory();
};
#endif /* defined(__GameDrive__KarmenRiderWDrive__) */
