//
//  main.cpp
//  ProblemSets
//
//  Created by mac on 18/1/30.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <iostream>
//#include "Problem.hpp"
//#include "Person.hpp"
#include "TestGN.hpp"
//#include "Vector.hpp"
using namespace std;
/*void test1()
{
    float x,y,X,Y;
    cout<<"坐标A：";
    cin>>x>>y;
    cout<<"坐标B：";
    cin>>X>>Y;
    CPoint c1(x,y);
    CPoint c2(X,Y);
    c1.printCPoint();
    c2.printCPoint();
    cout<<"长度为："<<c1.distance(c2)<<endl;
}
void test2()
{
    CLine c(100,200,200,300);
    c.printCLine();
    cout<<"长度为："<<c.lengthCLine()<<endl;
}
void test3()
{
//    float x,y,X,Y;
//    cout<<"坐标A：";
//    cin>>x>>y;
//    cout<<"坐标B：";
//    cin>>X>>Y;
    const CPoint1 c1(100,200);
    const CPoint1 c2(200,300);
    c1.printCPoint1();
    c2.printCPoint1();
    cout<<"长度为："<<c1.distance(c2)<<endl;
    
    const CLine1 c(c1,c2);
    const CPoint1 x1=c.getAPoint1();
    x1.printCPoint1();
    c.printCLine1();
    const float& t =c.lengthCLine1();
    cout<<"长度为："<<t<<endl;
}*/
/*
 *****************************
 请输入要执行的操作
 1添加数据
 2删除数据
 3修改数据
 4查看数据
 5关于
 0退出
 *****************************
 */
/*void xian(PersonSet& q1)
{
    if (q1.getSize()==0) {
        cout<<"当前的容器是空滴。。。"<<endl;
    }
    Person * p = new Person;
    cin>>*p;
    q1.AddElement(*p);
}
void add()
{
    PersonSet q1;
    Person p1;
lk:cout<<"input a person including name email year month day"<<endl;
    cin>>p1;
    q1.AddElement(p1);
    Date da=p1.GetBirthDate();
    if (da.getYear()>0&&da.getMonth()>0&&da.getMonth()<=12&&da.getDay()<=31&&da.getDay()>0) {
        cout<<p1;
    }else{
        cout<<"input error Date!,Please again!!"<<endl;
        goto lk;
    }
}
void ser()
{
    cout<<"input name what you want to select"<<endl;
    char*nam=new char;
    cin>>*nam;
    
    cout<<"没有当前这个人..."<<endl;
}
void rem()
{
    cout<<"input index what you want to move"<<endl;
    int i;
    cin>>i;
    cout<<"移除"<<i<<"的对象是:"<<endl;
}
void clea()
{
    cout<<"清空容器成功！！！"<<endl;
}
void siz(PersonSet&q1)
{
    cout<<"容器大小为："<<q1.getSize()<<endl;
}
void menu2()
{
    PersonSet q1;
    Person r1;
lo:cout<<"***********************************************"<<endl;
    cout<<"**********  1 显示容器内容           ************"<<endl;
    cout<<"**********  2 添加元素              ************"<<endl;
    cout<<"**********  3 移除最后一个元素       ************"<<endl;
    cout<<"**********  4 移除指定的元素         ************"<<endl;
    cout<<"**********  5 修改指定的元素         ************"<<endl;
    cout<<"**********  6 查看指定的元素         ************"<<endl;
    cout<<"**********  7 清空容器              ************"<<endl;
    cout<<"**********  8 容器大小              ************"<<endl;
    cout<<"**********  0 退出                 ************"<<endl;
    cout<<"***********************************************"<<endl;
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:{
            xian(q1);
            goto lo;}
        case 2:{
            add();
            goto lo;}
        case 3:{
            xian(q1);
            goto lo;}
        case 4:{
            rem();
            goto lo;}
        case 5:{
            xian(q1);
            goto lo;}
        case 6:{
            ser();
            goto lo;}
        case 7:{
            clea();
            goto lo;}
        case 8:{
            siz(q1);
            goto lo;}
        case 0:{
            exit(0);
            }
        default:
            break;
    }
}*/
/*extern Person r1;
PersonSet q1;
//extern PERSON*head;
Date p;
void menu()
{
loop:cout<<"*****************************"<<endl;
    cout<<"请输入要执行的操作"<<endl;
    cout<<"1添加数据"<<endl;
    cout<<"2删除数据"<<endl;
    cout<<"3修改数据"<<endl;
    cout<<"4查看数据"<<endl;
    cout<<"5关于"<<endl;
    cout<<"0退出"<<endl;
    cout<<"*****************************"<<endl;
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:{
        lok:cout<<"*****************************"<<endl;
            cout<<"您是想："<<endl;
            cout<<"1添加人员管理"<<endl;
            cout<<"2添加人员"<<endl;
            cout<<"3返回上级目录"<<endl;
            cout<<"0退出"<<endl;
            cout<<"*****************************"<<endl;
            int choose;
            cin>>choose;
            switch (choose) {
                case 1:{
                    cout<<"请输入人员管理的名称："<<endl;
                    char name[10];
                    cin>>name;
                    q1.setName(name);
                    q1.AddElement(r1);
                    goto lok;}
                case 2:
                    cout<<"您是想在哪个人员管理添加人员："<<endl;
                    for (int i = 0; i<=q1.getSize(); ++i) {
                        cout<<q1.getSize()+1<<":"<<q1.getNAME()<<endl;
                    }
                    int ix;
                    cin>>ix;
                    if (ix==q1.getSize()+1) {
                        for (int i = 0; i<=q1.getSize(); ++i) {
                            add();
                            q1.NextElement();
                        }
                    }else{
                        cout<<"没有人员管理，请先创建人员管理！"<<endl;
                    }
                    goto lok;
                case 3:
                    goto loop;
                case 0:
                    exit(0);
                default:
                    break;
            }
            //            Creatlink();
            cout<<"添加成功"<<endl;
            break;}
        case 2:{
        lop:cout<<"*****************************"<<endl;
            cout<<"您是想："<<endl;
            cout<<"1删除人员管理"<<endl;
            cout<<"2删除指定位置人员"<<endl;
            cout<<"3返回上级目录"<<endl;
            cout<<"0退出"<<endl;
            cout<<"*****************************"<<endl;
            int choose;
            cin>>choose;
            switch (choose) {
                case 1:{
                    cout<<"您是想删除哪个人员管理："<<endl;
                    for (int i = 0; i<=q1.getSize(); ++i) {
                        cout<<q1.getSize()<<":"<<q1.getNAME()<<endl;
                    }
                    goto lop;}
                case 2:{
                    for (int i = 0; i<q1.getInde(); ++i) {
                        cout<<q1.getInde()<<":"<<q1.getNAME()<<endl;
                    }
                    Person & boy = q1.RemoveElement();
                    cout<<boy;
                    delete &boy;
                    break;}
                case 3:
                    goto loop;
                    break;
                case 0:
                    exit(0);
                    break;
                    
                default:
                    break;
            }
            
            break;}
        case 3:
            ModifyDate(&r1);
//            xiugai(head);
            cout<<"修改成功"<<endl;
            break;
        case 4:{
            cout<<"*****************************"<<endl;
            cout<<"您是想："<<endl;
            cout<<"1查看全部人员"<<endl;
            cout<<"2查看全部人员管理"<<endl;
            cout<<"3查看指定人员管理的人员"<<endl;
            cout<<"4查看指定人员管理的指定人员"<<endl;
            cout<<"5返回上级目录"<<endl;
            cout<<"0退出"<<endl;
            cout<<"*****************************"<<endl;
            int choose;
            cin>>choose;
            switch (choose) {
                case 1:
                    for (int i = 0; i<=q1.getSize(); ++i) {
                        cout<<q1.getSize()<<":"<<q1.getNAME()<<endl;
                    }
                    
                    for (int i = 0; i<r1.getINde(); ++i) {
                            cout<<r1;
                    }
                    break;
                case 2:
                    for (int i = 0; i<q1.getInde(); ++i) {
                        cout<<q1.getInde()<<":"<<q1.getNAME()<<endl;
                    }
                    break;
                case 3:{
                    cout<<"您是想查看哪个人员管理："<<endl;
                    for (int i = 0; i<q1.getSize(); ++i) {
                        cout<<q1.getSize()<<":"<<q1.getNAME()<<endl;
                    }
                    int ix;
                    cin>>ix;
                    if (ix==q1.getSize()) {
                        for (int i = 0; i<(**q1.getELE())
                             .getINde(); ++i) {
                            cout<<**q1.getELE();
                        }
                    }else{
                        cout<<"没有人员管理，请先创建人员管理！"<<endl;
                    }

                    break;}
                case 4:
                    cout<<"您是想查看哪个人员管理的人员:"<<endl;
                    for (int i = 0; i<q1.getSize(); ++i) {
                        cout<<q1.getSize()<<":"<<q1.getNAME()<<endl;
                    }
                    int ix;
                    cin>>ix;
                    if (ix==q1.getSize()) {
                        for (int i = 0; i<(**q1.getELE())
                             .getINde(); ++i) {
                            cout<<q1.getELE();
                        }
                    }else{
                        cout<<"没有人员管理，请先创建人员管理！"<<endl;
                    }

                    break;
                case 5:
                    goto loop;
                    break;
                case 0:
                    exit(0);
                    break;
                    
                default:
                    break;
            }
            cout<<"打印成功"<<endl;
            goto loop;
            }
        case 5:{
            cout<<"制作者：KarmenRiderDrive"<<endl;
            cout<<"日期：2018-02-07"<<endl;
            cout<<"版权所有，套用请喊“申哥最帅!”"<<endl;
            goto loop;
            }
        case 0:{
            exit(0);
            }
        default:
            break;
    }
    goto loop;
}
void test4()
{
    //declare some const persons
    Person *p1 = new Person;
    cin>>*p1;
    cout<<*p1;
    Person *p2 = new Person("Frank","f123@chat.ca",1967,3,20);
    Person *p3 = new Person("Ann","ann@chat.ca",1960,8,20);
    PersonSet boys, girls;
    boys.AddElement( *p1);
    cout<<boys<<endl;
    //test to see if the same object is retrieved from the set.
    if (p1 != &boys.RemoveElement() ) {
        cout << "ERROR: the objects are different \n"; }
    else {
        cout << "Good, the objects are the same \n"; }
    boys.AddElement( *p1);
    boys.AddElement( *p2);
    girls.AddElement( *p3);
    boys.AddElement(*(new Person("John","f123@chat.ca",1967,3,20)));
    girls.AddElement(*(new Person("Sue","f123@chat.ca",1967,3,20)));
    boys.AddElement(*(new Person("Frank","frank@chat.ca",1958,4,25)));
    girls.AddElement(*(new Person("Mary","mary@chat.ca",1955,4,25)));
    boys.AddElement(*(new Person("John","johnchat.ca",1970,12,12)));
    //print all the boys using the removeSomeElement() method and delete //them
    int numberOfBoys = boys.Size();
    cout << "number of boys = " << numberOfBoys << "\n";
    for(int i = 0; i<numberOfBoys; i++) {
        Person & boy = boys.RemoveElement();
        boy.Print();
        delete &boy;
    }
    //print the girls using the << operator of the SetOfPersons class
    cout << "number of girls = " << girls.Size()<< "\n"; girls.Print();
    //print of the girls birthdays and using the someElement() method
    int numberOfGirls = girls.Size();
    girls.Reset();
//    for(int i = 0; i<numberOfGirls; i++)
//        const Date& d1= girls.NextElement().GetBirthDate();
//    
    
    //delete all the girls from the heap
    numberOfGirls = girls.Size();
    for(int i = 0; i<numberOfGirls; i++) {
        Person & her = girls.RemoveElement();
        girls.Print();
        delete &her;
    }
}*/
int main(int argc, const char * argv[]) {
 
//    test4();
//    menu2();
    domain();
    return 0;
}
