//
//  string.h
//  Chapter03
//
//  Created by mac on 18/2/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter03__string__
#define __Chapter03__string__

#include <iostream>
#include <string.h>
using namespace std;
class STRING{
    char * p;
    int size;
public:
    const int& getSize()const;
    char* getPA();
    STRING():size(0){
        p=new char[strlen("string")+1];
        p=(char*)"string";
    }
    STRING(STRING&p1):p(p1.p){}
public:
    STRING operator=(STRING& p1){
        if (strlen(p)<strlen(p1.p)) {
            delete [] p;
            p = new char[strlen(p1.p)+1];
            strcpy(p, p1.p);
        }else{
            strcpy(p, p1.p);
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out,STRING&p1);
public:
    ~STRING(){
        if (p!=NULL) {
            delete []p;
            p=NULL;
        }
    }
};

#endif /* defined(__Chapter03__string__) */
