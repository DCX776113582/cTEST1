//
//  voter.cpp
//  project02
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "voter.hpp"
#include "candidate.hpp"
#include "PersonSet.hpp"
#include <time.h>

int Voter::totalNumVoters=0;
Voter::Voter(string _name,int _age,double _salary,int _polingStation):
Person(_name,_age,_salary),polingStation(_polingStation),Id(totalNumVoters+1)
{
    totalNumVoters++;
}//构造函数
Voter::Voter(Voter&v1):Person(v1),Id(totalNumVoters+1),polingStation(v1.polingStation)
{
    totalNumVoters++;
}
void Voter::Vote(Candidate& aCandidate ){
    aCandidate.AddVoter(*this);
}

void Voter::set_polingStation(int newPolingStation){
    polingStation=newPolingStation;
}//设置

void Voter::print()const{
    
    cout<<"voter name is:"<<name<<endl;
    cout<<"voter polingStation id is:"<<polingStation<<endl;
    Person::print();
}//打印
Voter& Voter::operator=(Voter&v1)
{
    if (this!=&v1) {
        Person::operator=(v1);
        polingStation = v1.polingStation;
    }
    return *this;
}
bool operator==(Voter& a,Voter& b){
    
    bool flag=false;
    if(a.id==b.id){
        flag=true;
        return flag;
    }
    return flag;
}//
int Voter::get_PolingStation()const{
    return polingStation;
}//获取
int Voter::Voters(){
    //返回所给候选人投票的人数
    return totalNumVoters;
}
int Voter::getID()const
{
    return Id;
}
Person& Voter::SelectCadidate(PersonSet& candidates){
    int x=candidates.getSize();
    int r=rand()%x;
    return candidates[r];
}
Voter::~Voter(){cout<<"~Voter()"<<endl;}