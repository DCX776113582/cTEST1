//
//  candidate.h
//  project02
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __project02__candidate__
#define __project02__candidate__

#include "person.hpp"
#include "personSet.hpp"
class Voter;
class Candidate:public Person{
protected:
    PersonSet VotorSet;//候选人的记录容器
    const int ID;//候选人的编号
    double average_age;//平均年龄
    double average_salary;//平均薪水
    static int numCandidates;//统计比赛中有多少候选人参加
public:
    Candidate(string _name="lisi",int _age=5,double _salary=0);//带参构造函数
    Candidate(Candidate&c1);//拷贝构造
    //获取函数
    int getVotesNum();//得到选举人所给的票，记住给当前候选人投票人的信息
    int getID()const;//获得候选人编号
    double getAverageVotersAge(double& a);//获取所有给当前候选人投票的所有选举人的平均年龄
    double getAverageVotersSalary(double& a);//获取所有给当前候选人投票的所有选举人的平均薪资
    PersonSet& getPersonSet();//PersonSet对象的get方法
    //功能函数
    void AddVoter(Voter& aVoter);//当前选举人所得到的票数
    static int Candidates();//获取所有的候选人个数（静态）
    void print()const;
    //运算符重载
    Candidate& operator=(Candidate&c1);//赋值运算符重载
    friend ostream& operator<<(ostream& out,Candidate& c1);//输出运算符重载函数
    friend bool operator<(Candidate& a,Candidate& b);//重载运算符，判断是否a<b
    ~Candidate();//析构函数
};

void ADDVoter();//添加选民
void ADDCandidate();//添加候选人
void PrintVoter();//打印选民
void PrintCandidate();//打印候选人
void ADDmenu();//添加菜单
void Searchmenu();//查询菜单
void menu();//总菜单
#endif /* defined(__project02__candidate__) */
