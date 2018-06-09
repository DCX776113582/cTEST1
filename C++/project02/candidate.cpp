//
//  candidate.cpp
//  project02
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "candidate.hpp"
#include "voter.hpp"
extern PersonSet voters;
extern PersonSet candidates;
int Candidate::numCandidates=0;
PersonSet& Candidate::getPersonSet(){
    return VotorSet;
}
Candidate:: Candidate(string _name,int _age,double _salary):Person(_name,_age,_salary),ID(numCandidates+1)
{
    numCandidates++;
}//构造
Candidate:: Candidate(Candidate&c1):Person(c1),ID(numCandidates)//拷贝构造
{
    numCandidates++;
}
int Candidate:: getVotesNum(){
    int size= VotorSet.getSize();
    return size;
}
void Candidate:: AddVoter(Voter& aVoter){
    VotorSet.add(aVoter);
}
double Candidate:: getAverageVotersAge(double&a){
    int sumAge=0;
    VotorSet.reset();
    for(int i=0;i<a;i++){
        sumAge+=VotorSet[i].getAge();
    }
    average_age=sumAge/a;
    return average_age;
}
double Candidate:: getAverageVotersSalary(double&a){
    double sumSalary=0;
    VotorSet.reset();
    for(int i=0;i<a;i++){
        sumSalary+=VotorSet[i].getSalary();
    }
    average_salary = sumSalary/a;
    return average_salary;
}
int Candidate::getID()const
{
    return ID;
}
int Candidate:: Candidates()
{
    return numCandidates;
}

Candidate& Candidate::operator=(Candidate&c1)
{
    if (this!=&c1) {
        Person::operator=(c1);
        VotorSet = c1.VotorSet;
        average_age = c1.average_age;
        average_salary = c1.average_salary;
        numCandidates = c1.numCandidates;
    }
    return *this;
}

bool operator<(Candidate& a,Candidate& b){
    bool flag=true;
    if(a.getVotesNum()>b.getVotesNum()){
        flag=false;
    }
    return flag;
}
void Candidate::print()const
{
    cout<<"候选人"<<ID<<"号 姓名："<<getName()<<"  年龄："<<getAge()<<"    薪资："<<getSalary()<<endl;
}
ostream& operator<<(ostream& out,Candidate& c1){
    if(c1.getVotesNum()==0){
        cout<<"There are no voters !!!!"<<endl;
    }
    out<<"候选人"<<c1.ID<<"号  姓名："<<c1.getName()<<"  年龄："<<c1.getAge()<<"    薪资："<<c1.getSalary()<<endl;
    return out;
}
Candidate::~Candidate(){cout<<"~Candidate()"<<endl;}