//
//  TestGN.h
//  ProblemSets
//
//  Created by mac on 18/2/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __ProblemSets__TestGN__
#define __ProblemSets__TestGN__

#include <iostream>
#include "Person.hpp"
#define NW 100 //N作为最大职工总数
int f=0; //f作为开关

using namespace std;
class personlist{
private:
    Person r1[NW];
    int NUM; //用来计算职工数目
    int count; //用来暂时记录当前操作第几个职工
public:
    void add(); //职工信息录入
//    void sort(); //职工信息排序
    void search(); //职工信息查找
    void dele(); //职工信息删除
    void modify(); //职工信息修改
//    void save(); //职工信息以文件形式保存
    void showworker();//显示职工信息在屏幕上
//    personlist(){
//        for (int i = 0; i<NW; ++i) {
//            ;
//        }
//        NUM=0;
//        count=0;
//    }
};
void domain() ;
#endif /* defined(__ProblemSets__TestGN__) */
