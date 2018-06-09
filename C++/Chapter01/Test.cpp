//
//  Test.cpp
//  Chapter01
//
//  Created by mac on 18/1/31.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Test.hpp"
Test2::Test2()
{
    cout << "Test2::默认构造" << endl;
    this->pVar = new int[5];//pVar指向堆空间
    for (int i=0; i<5; ++i)
    {
        *(pVar + i) = i+1;//pVar[i]=i+1;
    }
    this->printTest2();
    cout << "Test2::构造完成" << endl;
}
Test2::~Test2()
{
    if (this->pVar!=NULL) {//先释放pVar指向的堆内存
        delete [] this->pVar;
        this->pVar = NULL;
    }
    cout << "Test2::销毁完成" << endl;
}
void Test2::printTest2()
{
    for (int i = 0; i<5;++i) {
        cout<<pVar[i]<<endl;//隐式访问
        cout<<(*this).pVar[i]<<endl;
        cout<<this->pVar[i]<<endl;
    }
}
