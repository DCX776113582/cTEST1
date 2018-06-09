//
//  main.cpp
//  project01
//
//  Created by mac on 18/2/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Date.hpp"
#include "Person.hpp"
#include "PersonSet.hpp"
void datetest()//日期测试
{
    Date date1;
    date1.setYear(2018);
    date1.setMonth(2);
    date1.setDay(24);
    date1.print();
    
    Date date2;
    Date date3;
    Date date4(date1);
    
    cin>>date2;
    cin>>date3;
    
    cout<<date2;
    cout<<date3;
    cout<<date4;
}
void persontest()//人测试
{
    Person p1;
    p1.setName("person1");
    p1.setEmailAddress("person1@qq.com");
    p1.setBirthday(2018, 2, 24);
    p1.print();
    
    Date date(2018,2,24);
    Person p2("person2","person2@qq.com",date);
    p2.print();
    
    Person p3("person3","person3@qq.com",2018,2,15);
    p3.print();
    
    Person p4;
    cin>>p4;
    cout<<p4;
    
    Person p5(p4);
    cout<<p5;
    
}
void personsettest1()//容器测试1
{
    PersonSet v1;
    //    v1.print();
    //    cin>>v1;
    //    cout<<v1;
    Person * p1 = new Person();
    Person * p2 = new Person();
    v1.setCapacity(8);
    Person** array = new Person*[8];
    array[0] = p1;
    array[1] = p2;
    for (int i = 2; i<8; ++i) {
        array[i]=NULL;
    }
    v1.setElement(array);
    v1.setSize(2);
    v1.setIndex(0);
    cout<<v1<<endl;
    PersonSet v2(v1);
    cout<<v2<<endl;
    PersonSet v3;
    v3 = v2;
    cout<<v3<<endl;
    delete p1;
    delete p2;
    delete [] array;
    p1 = NULL;
    p2 = NULL;
    array = NULL;
    
}
void personsettest2()//容器测试2
{
    PersonSet boys;
    Person * p1 = new Person();
    cin>>*p1;
    boys.add(*p1);
    Person * p2 = new Person();
    cin>>*p2;
    boys.add(*p2);
    Person * p3 = new Person();
    cin>>*p3;
    boys.add(*p3);
    Person * p4 = new Person();
    cin>>*p4;
    boys.add(*p4);
    boys.query(boys);
    boys.queryN(boys);
    boys.queryE(boys);
    //遍历
    for (int i = 0; i<boys.getSize(); ++i) {
        cout<<boys.next();
    }
    //删除
    Person & d1 = boys.remove();//从后向前删除
    delete &d1;
    cout<<boys;
    Person & d2 = boys.remove(1);//指定位置删除
    delete &d2;
    cout<<boys;
}
PersonSet boys;//容器
void ADD()//添加
{
    Person * p1 = new Person();
    cin>>*p1;
    boys.add(*p1);
    cout<<"添加成功"<<endl;
}
void REMOVE()//删除
{
    cout<<"----------------------------"<<endl;
    cout<<"        1:从后向前删除"<<endl;
    cout<<"        2:指定位置删除"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"请选择操作:";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:{
            if (boys.getSize()==0) {
                cout<<"容器为空,删除失败"<<endl;
            }else{
                Person & d1 = boys.remove();
                delete &d1;
                cout<<"删除成功"<<endl;
            }
            break;}
        case 2:{
            int index;
            cout<<"请输入删除位置:";
            cin>>index;
            if (index>boys.getSize()||index<boys.getSize()) {
                cout<<"容器为空，删除失败"<<endl;
            }else{
                Person & d2 = boys.remove(index-1);
                delete &d2;
                cout<<"删除成功"<<endl;
            }
            break;}
        default:
            break;
    }
}
void TRAVE()//遍历
{
    if (boys.getSize()==0) {
        cout<<"容器为空，无法遍历"<<endl;
    }else{
        if (boys.getIndex()==0) {
            for (int i = 0; i<boys.getSize(); ++i) {
                cout<<boys.next();
            }
            cout<<"遍历成功"<<endl;
        }else{
            boys.reset();
            for (int i = 0; i<boys.getSize(); ++i) {
                cout<<boys.next();
            }
            cout<<"遍历成功"<<endl;
        }
    }
}
void query()//查询菜单
{
    cout<<"----------查询方式------------"<<endl;
    cout<<"         1:编号"<<endl;
    cout<<"         2:姓名"<<endl;
    cout<<"         3:邮箱"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"请输入操作:";
    int cx;
    cin>>cx;
    switch (cx) {
        case 1:
            boys.query(boys);
            break;
        case 2:
            boys.queryN(boys);
            break;
        case 3:
            boys.queryE(boys);
            break;
        default:
            break;
    }
}
void Modify()//修改
{
    cout<<"请输入您要修改的位置:";
    int cha;
    cin>>cha;
    if (cha>boys.getSize()||boys.getSize()==0) {
        cout<<"查无此人,无法修改"<<endl;
    }else{
        for (int i = 0; i<boys.getSize();++i) {
            if (i == (cha-1)) {
                cout<<boys[cha-1];
            }
        }
        cout<<"----------修改方式------------"<<endl;
        cout<<"         1:整体修改"<<endl;
        cout<<"         2:修改姓名"<<endl;
        cout<<"         3:修改邮箱"<<endl;
        cout<<"         4:修改生日"<<endl;
        cout<<"-----------------------------"<<endl;
        int xuan;
        cout<<"请输入编号:";
        cin>>xuan;
        switch (xuan) {
            case 1:
                cin>>boys[cha-1];
                break;
            case 2:{
                char newName[15];
                cin>>newName;
                boys[cha-1].setName(newName);
                break;}
            case 3:{
                char newEmail[20];
                cin>>newEmail;
                boys[cha-1].setEmailAddress(newEmail);
                break;}
            case 4:{
                int x,y,z;
                cin>>x>>y>>z;
                boys[cha-1].setBirthday(x, y, z);
                break;}
            default:
                break;
        }
        cout<<"修改成功"<<endl;
    }
}
void PRINT()//打印
{
    cout<<boys;
    cout<<"打印成功"<<endl;
}
void menu()//菜单
{
loop:cout<<"*****************************************"<<endl;
    cout<<"                1:添加"<<endl;
    cout<<"                2:删除"<<endl;
    cout<<"                3:遍历"<<endl;
    cout<<"                4:查询"<<endl;
    cout<<"                5:打印"<<endl;
    cout<<"                6:修改"<<endl;
    cout<<"                7:关于"<<endl;
    cout<<"                0:退出"<<endl;
    cout<<"*****************************************"<<endl;
    int choose;
    cout<<"请选择操作编号:";
    cin>>choose;
    switch (choose) {
        case 1:
            ADD();//添加
            break;
        case 2:
            REMOVE();//删除
            break;
        case 3:
            TRAVE();//遍历
            break;
        case 4:
            query();//查询
            break;
        case 5:
            PRINT();//打印
            break;
        case 6:
            Modify();//修改
            break;
        case 7:
            cout<<"制作人：段传鑫"<<endl;
            cout<<"日期：2018-02-25"<<endl;
            cout<<"版权所有，套用请喊“BUILD UP!”"<<endl;
            break;
        case 0:
            for (int i =0; i<boys.getSize(); ++i) {
                delete &boys[i];
            }
            exit(0);
            break;
        default:
            cout<<"输入错误，重新输入"<<endl;
            goto loop;
            break;
    }
    char yes;
    getchar();
ls:cout<<"是否继续操作[Y(y)/N(n)]:";
    cin>>yes;
    if ('y' == yes || 'Y' == yes) {
        goto loop;
    }
    if ('n' == yes || 'N' == yes) {
        for (int i =0; i<boys.getSize(); ++i) {
            delete &boys[i];
        }
        exit(0);
    }
    else{
        cout<<"输入错误,重新输入"<<endl;
        goto ls;
    }
}
int main(int argc, const char * argv[]) {
    menu();
    return 0;
}
