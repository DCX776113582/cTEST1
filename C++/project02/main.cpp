//
//  main.cpp
//  project02
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//
#include "person.hpp"
#include "personSet.hpp"
#include "voter.hpp"
#include "candidate.hpp"
#include <time.h>
void persontest()//测试Person
{
    Person p1;
    Person*p2=new Person;
    cout<<p1;
    p1.print();
    p2->print();
    delete p2;
}
void test()//测试函数
{
    //创建选举人
    Voter *v1 = new Voter("kuuga",20,2000.0,1);
    Voter *v2 = new Voter("agito",21,2200.0,1);
    Voter *v3 = new Voter("ruki",23,2343.0,2);
    Voter *v4 = new Voter("faiz",19,2888.0,3);
    Voter *v5 = new Voter("blade",24,6000.0,1);
    Voter v6;
    v6 = *v5;
    v6.print();
    //创建候选人
    Candidate *c1 = new Candidate("April", 67, 9600.0 );
    Candidate *c2 = new Candidate("May", 40, 29600.0);
    Candidate *c3 = new Candidate("June", 40, 29600.0);
    srand((unsigned)time(NULL));
    PersonSet voters;
    voters.add(*v1);
    voters.add(*v2);
    voters.add(*v3);
    voters.add(*v4);
    voters.add(*v5);
    
    PersonSet candidates;
    candidates.add(*c1);
    candidates.add(*c2);
    candidates.add(*c3);
    int numVoters = voters.getSize();
    cout << "number of voters = " << numVoters << "\n";
    voters.reset();
    for(int i = 0; i<numVoters; i++)
    {
        Voter& voter = static_cast<Voter&>(voters.next());
        cout << voter << "\n";
    }
    voters.reset();  // Set the index zero
    cout << "voting = \n";
    for(int i = 0; i<numVoters; i++)
    {
        Voter& v = static_cast<Voter&>(voters.next());
        Candidate& chosenCandidate = static_cast<Candidate&>(v.SelectCadidate(candidates));
        v.Vote(chosenCandidate);
    }
    cout<<"April:"<<c1->getVotesNum()<<endl;
    c1->print();
    cout<<"May:"<<c2->getVotesNum()<<endl;
    c2->print();
    cout<<"June:"<<c3->getVotesNum()<<endl;
    c3->print();
    cout<<"voters.size()="<<voters.getSize()<<endl;
    cout<<"Voter::_totalNumVoters="<<Voter::totalNumVoters<<endl;
    
    
    if (voters.getSize() != Voter::totalNumVoters)
    {
        
        cout <<" Not all voters voted !!!!" << endl ;
    }
    else
    {
        cout <<" Success: 100% voted" << endl;
    }
    Candidate* winner = static_cast<Candidate*>(&candidates[0]);
    for ( int i=0; i<candidates.getSize(); i++ )
    {
        if ( *winner < *(static_cast<Candidate*>(&candidates[i]) ))
        {
            winner = static_cast<Candidate*>(&candidates[i]);
        }
    }
    if(winner->getVotesNum() == 2)
    {
        PersonSet ps;
        for(int i = 0 ; i < candidates.getSize() ; i++)
        {
            Candidate * p;
            if((p = &static_cast<Candidate&>(candidates[i]))->getVotesNum() == 2)
            {
                ps.add(*p);
            }
        }
        for(int j=0;j<numVoters;j++){
            Voter& v = static_cast<Voter&>(voters.next());
            Candidate& chosenCandidate = static_cast<Candidate&>(v.SelectCadidate(ps));
            v.Vote(chosenCandidate);
        }
        cout<<"twice Vote:"<<endl;
        Candidate* winner = static_cast<Candidate*>(&ps[0]);
        for ( int i=0; i<ps.getSize(); i++ )
        {
            if ( *winner < *(static_cast<Candidate*>(&ps[i]) ))
            {
                winner = static_cast<Candidate*>(&ps[i]);
            }
        }
        cout << " the winner is : " << *winner<<endl;
        cout<<"winner:"<<winner->getVotesNum()-2<<endl;
    }else{
        cout << " the winner is : " << *winner<<endl;
    }
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete c1;
    delete c2;
    delete c3;
}
PersonSet voters;//存放选民
PersonSet candidates;//存放候选人
void ADDVoter()//添加选民
{
    if (voters.getSize()==5) {
        cout<<"选民添加完毕"<<endl;
        return;
    }else{
        Voter * v1 = new Voter;
        cout<<"选民ID号码："<<v1->getID()<<endl;
        cin>>*v1;
    kj:cout<<"共5个投票站：1：北京 2：上海 3：广州 4：香港 5：澳门"<<endl;
        cout<<"StationID:";
        int x;
        cin>>x;
        if (x>5||x<0) {
            cout<<"无此投票站，请认准投票站编码"<<endl;
            goto kj;
        }else{
            v1->set_polingStation(x);
        }
        srand((unsigned)time(NULL));
        voters.add(*v1);
        cout<<"添加成功"<<endl;
    }
}
void ADDCandidate()//添加候选人
{
    if (candidates.getSize()==3) {
        cout<<"候选人添加完毕"<<endl;
        return;
    }else{
        if (voters.getSize()>0&&voters.getSize()<5) {
            cout<<"选民未添加完，请添加完选民"<<endl;
        }else{
            Candidate * c1 = new Candidate;
            cout<<"候选人编号："<<c1->getID()<<endl;
            cin>>*c1;
            candidates.add(*c1);
            cout<<"添加成功"<<endl;
        }
    }
}
void PrintVoter()//打印选民
{
    int numVoters = voters.getSize();//选民人数
    cout << "共有选民" << numVoters << "人"<<endl;
    voters.reset();
    for(int i = 0; i<numVoters; i++)
    {
        Voter& voter = static_cast<Voter&>(voters.next());//静态转换
        voter.print();//调用Voter里的打印函数
        cout<<endl;
    }
    cout<<"打印成功"<<endl;
}
void PrintCandidate()//打印候选人
{
    int numVoters = candidates.getSize();//候选人个数
    cout << "共有候选人" << numVoters << "人"<<endl;
    candidates.reset();//复位
    for(int i = 0; i<numVoters; i++)
    {
        Candidate & voter = static_cast<Candidate&>(candidates.next());//静态转换
        cout << voter<<endl;//调用Candidate输出重载函数
    }
    cout<<"打印成功"<<endl;
}
void Candidaterecord()//候选人记录/投票
{
    if (voters.getSize()==0||candidates.getSize()<3) {
        cout<<"未添加选民或候选人不足，不可投票"<<endl;
    }else{
    int numVoters = voters.getSize();//选民人数
    voters.reset();
    for(int i = 0; i<numVoters; i++)
    {
        Voter& v = static_cast<Voter&>(voters.next());//静态转换
        Candidate& chosenCandidate = static_cast<Candidate&>(v.SelectCadidate(candidates));//静态转换
        v.Vote(chosenCandidate);//随机投票
    }
    cout<<"投票成功"<<endl;
    }
}
void Candidateprint()//打印每个候选人获得的选民信息
{
    if (candidates.getSize()==0) {
        cout<<"无候选人"<<endl;
    }else{
        for (int i = 0; i<candidates.getSize(); ++i) {
            cout<<candidates[i].getName()<<":"<<endl;
            dynamic_cast<Candidate&>(candidates[i]).getPersonSet().printset();//动态转换
            cout<<endl;
        }
    }
}
void ADDmenu()//添加菜单
{
lkp:cout<<"¬¬¬¬¬¬¬¬添加菜单¬¬¬¬¬¬¬¬¬¬"<<endl;
    cout<<"     1:添加选民"<<endl;
    cout<<"     2:添加候选人"<<endl;
    cout<<"     3:返回上级菜单"<<endl;
    cout<<"¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬"<<endl;
lk:cout<<"请选择：";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:
            ADDVoter();
            break;
        case 2:
            ADDCandidate();
            break;
        case 3:
            menu();
            break;
        default:
            cout<<"输入错误，重新输入"<<endl;
            goto lk;
            break;
    }
    goto lkp;
}
void PRINTmenu()//打印菜单
{
lkp:cout<<"¬¬¬¬¬¬¬¬打印菜单¬¬¬¬¬¬¬¬¬¬"<<endl;
    cout<<"     1:打印选民"<<endl;
    cout<<"     2:打印候选人"<<endl;
    cout<<"     3:返回上级菜单"<<endl;
    cout<<"¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬"<<endl;
lk:cout<<"请选择：";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:
            PrintVoter();
            break;
        case 2:
            PrintCandidate();
            break;
        case 3:
            menu();
            break;
        default:
            cout<<"输入错误，重新输入"<<endl;
            goto lk;
            break;
    }
    goto lkp;
}
void Searchmenu()//查询菜单
{
loj:cout<<"≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈查询菜单≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈"<<endl;
    cout<<"        1:候选人获得的选民平均年龄"<<endl;
    cout<<"        2:候选人获得的选民平均薪资"<<endl;
    cout<<"        3:候选人个数"<<endl;
    cout<<"        4:候选人获得的选民个数"<<endl;
    cout<<"        5:候选人获得的选民信息"<<endl;
    cout<<"        6:选民是否全部投票"<<endl;
    cout<<"        7:上级菜单"<<endl;
    cout<<"≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈ç≈"<<endl;
lk:cout<<"请选择：";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:{
            if (candidates.getSize()==0) {
                cout<<"无候选人"<<endl;
            }else{
                for (int i = 0; i<candidates.getSize(); ++i) {
                    double pos = dynamic_cast<Candidate&>(candidates[i]).getVotesNum();
                    double age=0;
                    if (pos>0) {
                        age = dynamic_cast<Candidate&>(candidates[i]).getAverageVotersAge(pos);
                        cout<<candidates[i].getName()<<"获得选民平均年龄"<<age<<endl;
                    }else{
                        cout<<candidates[i].getName()<<"获得选民平均年龄"<<age<<endl;
                    }
                }
            }
            break;}
        case 2:{
            if (candidates.getSize()==0) {
                cout<<"无候选人"<<endl;
            }else{
                for (int i = 0; i<candidates.getSize(); ++i) {
                    double pos = dynamic_cast<Candidate&>(candidates[i]).getVotesNum();
                    double fa = 0;
                    if (pos>0) {
                        fa = dynamic_cast<Candidate&>(candidates[i]).getAverageVotersSalary(pos);
                        cout<<candidates[i].getName()<<"获得选民平均薪资"<<fa<<endl;
                    }else{
                        cout<<candidates[i].getName()<<"获得选民平均薪资"<<fa<<endl;
                    }
                }
            }
            break;}
        case 3:
            cout<<"候选人个数："<<candidates.getSize()<<endl;
            break;
        case 4:{
            if (candidates.getSize()==0) {
                cout<<"无候选人"<<endl;
            }else{
                for (int i = 0; i<candidates.getSize(); ++i) {
                    int pos = dynamic_cast<Candidate&>(candidates[i]).getVotesNum();
                    string name =dynamic_cast<Candidate&>(candidates[i]).getName();
                    cout<<"候选人"<<name<<"选民个数："<<pos<<endl;
                }
            }
            break;}
        case 5:{
            Candidateprint();
            break;}
        case 6:{
            if (voters.getSize() != Voter::totalNumVoters){
                cout <<" 不是所有人都投票" << endl ;
            }
            else if(voters.getSize()==5){
                cout <<"100%选民投票" << endl;
            }else{
                cout <<"选民不足，无法投票" << endl;
            }
            break;}
        case 7:
            menu();
        default:
            cout<<"输入错误，重新输入"<<endl;
            goto lk;
            break;
    }
    goto loj;
}
void chooseLeader()//选举领导人
{
    if (voters.getSize()==0||candidates.getSize()==0) {
        cout<<"没有选民或没有候选人"<<endl;
    }else{
        int numVoters = voters.getSize();//选民的个数
        Candidate* winner = static_cast<Candidate*>(&candidates[0]);//假设第一个候选人是领导
        for ( int i=0; i<candidates.getSize(); i++ )
        {   //用<运算符重载，候选人获得的选民个数为比较
            if ( *winner < *(static_cast<Candidate*>(&candidates[i]) ))
            {
                winner = static_cast<Candidate*>(&candidates[i]);//指向获得选民个数多的候选人
            }
        }
        if(winner->getVotesNum() == 2)//(选民总人数-淘汰者的选民人数)/现在候选人数
        {
                    PersonSet ps;//创建新容器
                    for(int i = 0 ; i < candidates.getSize() ; i++)
                    {
                        Candidate * p;
                        if((p = &static_cast<Candidate&>(candidates[i]))->getVotesNum() == 2)
                        {
                            ps.add(*p);
                        }
                    }
                    for(int j=0;j<numVoters;j++){
                        Voter& v = static_cast<Voter&>(voters.next());
                        Candidate& chosenCandidate = static_cast<Candidate&>(v.SelectCadidate(ps));
                        v.Vote(chosenCandidate);
                    }
                    cout<<"twice Vote:"<<endl;
                    Candidate* winner = static_cast<Candidate*>(&ps[0]);
                    for ( int i=0; i<ps.getSize()-1; i++ )
                    {
                        if ( *winner < *(static_cast<Candidate*>(&ps[i]) ))
                        {
                            winner = static_cast<Candidate*>(&ps[i+1]);
                            
                        }
                    }
                    cout << "The winner is : " << winner->getName()<<endl;
                    (*winner).getPersonSet().printset();//动态转换
                    cout<<endl;

                }
    else{
        cout<<"选举完毕："<<endl;
        cout << "The winner is : " << winner->getName()<<endl;//领导人
        (*winner).getPersonSet().printset();//动态转换
        cout<<endl;
        }
    }
}
void menu()
{
    cout<<"这里是假面骑士&超级战队的世界，首先假面骑士3位，分别是RiderIchigo，Decade，Ex-Aid;\n超级战队一方为Red、Blue、Yellow、Green、Pink;\n我们要选出最强的假面骑士，那么是谁呢，让超级战队的各位来决定.\n当然，这里是随机投票，O(∩_∩)O哈哈哈~！你来完成下面的任务吧！"<<endl;
loop:cout<<"ååååååååååååååååååååååååååååååååååå"<<endl;
    cout<<"å            1:添加菜单"<<endl;
    cout<<"å            2:打印菜单"<<endl;
    cout<<"å            3:投票"<<endl;
    cout<<"å            4:查询菜单"<<endl;
    cout<<"å            5:选举领导人结果"<<endl;
    cout<<"å            6:关于"<<endl;
    cout<<"å            0:退出"<<endl;
    cout<<"ååååååååååååååååååååååååååååååååååå"<<endl;
lk:cout<<"请选择：";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:
            ADDmenu();//添加菜单
            break;
        case 2:
            PRINTmenu();//打印菜单
            break;
        case 3:
            Candidaterecord();//候选人记录选民、投票
            break;
        case 4:
            Searchmenu();//查询菜单
            break;
        case 5:{
            chooseLeader();//选举领导人
            break;}
        case 6:{
            cout<<"制作人：段传鑫"<<endl;
            cout<<"制作时间：2018-3-1————2018-3-7"<<endl;
            cout<<"®版权所有©"<<endl;
            break;}
        case 0:
            for (int i =0; i<voters.getSize(); ++i) {
                delete &voters[i];
            }
            for (int i =0; i<candidates.getSize(); ++i) {
                delete &candidates[i];
            }
            exit(0);
            break;
        default:
            cout<<"输入错误，重新输入"<<endl;
            goto lk;
            break;
    }
    char yes;
    cout<<"是否继续操作[Y/N]：";
    cin>>yes;
    if (yes == 'y'||yes == 'Y') {
        goto loop;
    }else if (yes=='n'||yes=='N'){
        for (int i =0; i<voters.getSize(); ++i) {
            delete &voters[i];
        }
        for (int i =0; i<candidates.getSize(); ++i) {
            delete &candidates[i];
        }
        exit(0);
    }else{
        cout<<"输入错误，重新输入"<<endl;
        goto lk;
    }
}
int main(int argc, const char * argv[]) {
    menu();
//    test();
    return 0;
}
