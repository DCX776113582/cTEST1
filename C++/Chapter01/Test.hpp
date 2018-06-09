//
//  Test.h
//  Chapter01
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter01__Test__
#define __Chapter01__Test__

#include <iostream>
using namespace std;
class Test1
{
public:
    Test1() {
        cout<< "hello world"<<endl;
    }
    //函数定义写在类体内部。
    
    //前面没有new，后面就不用delete
    ~Test1() {
        cout<< "goodbye world"<<endl;
    }
};
class Test
{
public:
    Test()
    {
        _pVar = new int[10];
        //手工分配内存；动态内存分配
        for(int i=0; i<10; ++i)
        {
            _pVar[i] = i;
        }
        cout<< "hello world"<<endl;
    }
    
    ~Test()
    {
        if(_pVar)
        {
            //手工回收内存，
            //以数组的形式删除指针，把new分配的10个整数空间全部收回。
            //如果不加[]？内存泄露
            
            delete [] _pVar;
            _pVar = NULL;//指针本身置0
        }
        
        cout<<"goodbye world"<<endl;
    }
    //在构造函数里通过指针类型的成员变量来new出的内存，一定要记得在析构函数里delete掉，
    //然后指针赋值NULL。
    
    void print()
    {
        for(int i=0; i<10; ++i)
            cout<<_pVar[i]<<endl;
    }
    
private:
    int* _pVar;
};
class Test2
{
private:
    int *pVar;    
public:
    Test2();
    ~Test2();
public:
    void printTest2();
};


#endif /* defined(__Chapter01__Test__) */
