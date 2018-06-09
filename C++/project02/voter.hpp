//
//  voter.h
//  project02
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __project02__voter__
#define __project02__voter__

#include "person.hpp"
class PersonSet;
class Candidate;
class Voter:public Person{
private:
    const int Id;
    int polingStation;
public:
    static int totalNumVoters; //参加选举的人数
public:
    //默认构造函数
    Voter(string _name="name",int _age=20,double _salary=10000,int _polingStation=0);
    //三大件
    Voter(Voter&v1);//拷贝构造
    ~Voter();//析构函数
    Voter& operator=(Voter&v1);//赋值运算符重载
    //设置函数
    void set_polingStation(int newPolingStation);//修改投票站编号
    //获取函数
    int get_PolingStation()const;//获取投票站编号
    int getID()const;//获取选民ID
    //功能函数
    void print()const;//打印
    static int Voters();//返回所给候选人投票的人数
    Person& SelectCadidate(PersonSet& cadidates);//随机获取候选人
    void Vote(Candidate& aCandidate );//选民添加到候选人
    //友元函数
    friend bool operator==(Voter& a,Voter& b);//相等运算符重载
};
#endif /* defined(__project02__voter__) */
