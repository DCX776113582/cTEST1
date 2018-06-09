//
//  TestGN.cpp
//  ProblemSets
//
//  Created by mac on 18/2/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "TestGN.hpp"
#include "Person.hpp"
#include "Data.hpp"
#include <fstream>
string p; //p作为接收菜单选项的字符串
void menu() //显示菜单
{
    cout<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"**   **"<<endl;
    cout<<"** 职工信息管理系统主菜单 **"<<endl;
    cout<<"**   **"<<endl;
    cout<<"** 1.职工信息添加  **"<<endl;
    cout<<"** 2.职工信息修改  **"<<endl;
    cout<<"** 3.职工信息删除  **"<<endl;
    cout<<"** 4.职工信息排序  **"<<endl;
    cout<<"** 5.职工信息查找  **"<<endl;
    cout<<"** 6.职工信息显示  **"<<endl;
    cout<<"** 7.职工信息保存  **"<<endl;
    cout<<"** 0.退出  **"<<endl;
    cout<<"**   **"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
}
/*void personlist::save() //职工信息保存函数实现
{
    if(NUM<=0)
    {
        cout<<"没有职工信息存入，系统将返回主菜单"<<endl;
        menu();
    }
    else
    {
        ofstream fout;
        fout.open("worker.txt",ios::out);
        cout<<"文件正在保存......请稍候！！"<<endl;
        cout<<"数据保存成功！！！"<<endl;
        fout<<"已保存员工信息如下："<<endl;
        for(int i=0;i<count;i++)
        {
            fout<<"***********************************************"<<endl;
            fout<<r1[i];
            fout<<"***********************************************"<<endl;
        }
        cout<<"系统返回主菜单："<<endl;
        menu();
        fout.close();
    }
}*/
void personlist::showworker() //职工信息显示函数实现
{
    if(NUM<=0)
    {
        cout<<"没有职工信息存入，系统将返回主菜单"<<endl;
        menu();
    }
    else
        cout<<"已保存的职工信息如下："<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<"***********************************************"<<endl;
        cout<<r1[i];
        cout<<"***********************************************"<<endl;
    }
}
void domain() //主菜单函数实现
{
    
    personlist wl;
    while(1)
    {
//        system("cls");
        menu();
        cout<<"请选择数字编号0~7"<<endl;
        int i1;
        cin>>i1;
        while(!(i1>=0&&i1<=7))
        {
            cout<<"输入有误，请重新输入："<<endl;
            cin>>i1;
        }
        switch(i1)
        {
            case 1:wl.add();break;
            case 2:wl.modify();break;
            case 3:wl.dele();break;
//            case 4:
//                wl.sort();
//                break;
            case 5:wl.search();break;
            case 6:wl.showworker();break;
//            case 7:wl.save();break;
            case 0:cout<<"系统退出！！"<<endl;
                exit(0);
            default:
                break;
        }
        cout<<"是否返回主菜单? Y/N"<<endl;
        cin>>p;
        if(p=="n"||p=="N")
        {
            cout<<"系统退出！！"<<endl;
            exit(0);
        }
    }
}
/*void personlist::sort() //职工信息排序功能实现
{
    if(NUM<=0)
    {
        cout<<"没有职工信息存入，系统将返回主菜单"<<endl;
        menu();
    }
    else
        cout<<"***********************************************"<<endl;
    cout<<"** 请选择排序方式： **"<<endl;
    cout<<"** 1.按日期排序（升序） **"<<endl;
    cout<<"** 2.按日期排序（降序） **"<<endl;
    cout<<"** 0.返回主菜单  **"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
    cout<<"请选择数字编号0~2"<<endl;
    int i5;
    cin>>i5;
    while(i5<0||i5>2)
    {
        cout<<"输入有误，请重新输入："<<endl;
        cin>>i5;
    }
    if(i5==1)
    {
        for(int i=0;i<count-1;i++)
            for(int j=0;j<count-i-1;j++)
                
//                if(r1[j].GetBirthDate()>r1[j+1].GetBirthDate())
//                {
//                    Person temp;
//                    temp=r1[j];
//                    r1[j]=r1[j+1];
//                    r1[j+1]=temp;
//                }
        cout<<"按日期升序后的信息如下："<<endl;
        for(int i=0;i<count;i++)
        {
            cout<<"***********************************************"<<endl;
            cout<<r1[i];
            cout<<"***********************************************"<<endl;
        }
    }
    else if(i5==2)
    {
        for(int i=0;i<count-1;i++)
            for(int j=0;j<count-i-1;j++)
//                if(r1[j].GetBirthDate()<r1[j+1].GetBirthDate())
//                {
//                    Person temp;
//                    temp=r1[j];
//                    r1[j]=r1[j+1];
//                    r1[j+1]=temp;
//                }
        cout<<"按工资降序后的信息如下："<<endl;
        for(int i=0;i<count;i++)
        {
            cout<<"***********************************************"<<endl;
            cout<<r1[i];
            cout<<"***********************************************"<<endl;
        }
    }
    else if(i5==0)
        menu();
}*/

void personlist::add() //职工信息添加函数实现
{
    cout<<"请输入人员信息:"<<endl;
    cout<<"编号:";
    int num;
    cin>>num;
    for(int i=0;i<NUM;i++)
        while(num==r1[i].getId())
        {
            cout<<"此员工编号已存在，请重新输入："<<endl;
            cout<<"编号:";
            cin>>num;
        }
    r1[NUM].getINde()=num;
    cin>>r1[NUM];
    ++NUM;
    count=NUM;
}
void personlist:: modify() //职工信息修改函数实现
{
    if(NUM<=0)
    {
        cout<<"没有职工信息存入，系统将返回主菜单"<<endl;
        menu();
    }
    cout<<"请输入需要修改信息职工的工号："<<endl;
    int num1;
    cin>>num1;
    int j=0,k = 0;
    int flag=1;
    while(flag)
    {
        for(;j<count;j++)
        {
            if(num1==r1[j].getId())
            {
                flag=0;
                k=j;
                break;
            }
        }
        if(flag)
        {
            cout<<"不存在此员工，请重新输入："<<endl;
            j=0;
            cin>>num1;
        }
    }
    cout<<"你选择的职工的信息为："<<endl;
    cout<<r1[k];
    cout<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"** 1.修改姓名  **"<<endl;
    cout<<"** 2.修改邮箱  **"<<endl;
    cout<<"** 3.修改日期  **"<<endl;
    cout<<"** 0.返回主菜单  **"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
    cout<<"请选择数字编号0~3"<<endl;
    int i3;
    cin>>i3;
    while(i3<0||i3>3)
    {
        cout<<"输入有误，请重新输入："<<endl;
        cin>>i3;
    }
    switch(i3)
    {
        case 1:
            cout<<"请输入新的职工姓名:";
            cin>>r1[k].GetName();
            cout<<"修改信息已保存，现返回主菜单："<<endl;
            menu();
            break;
        case 2:
            cout<<"请输入新的职工邮箱:";
            cin>>r1[k].GetEmailAddress();
            cout<<"修改信息已保存，现返回主菜单："<<endl;
            menu();
            break;
        case 3:{
            cout<<"请输入新的日期:";
            Date da;
            cin>>da.getYear()>>da.getMonth()>>da.getDay();
            r1[k].setBirthDate(da);
            cout<<"修改信息已保存，现返回主菜单："<<endl;
            break;}
        case 0:
            menu();
        default:
            break;
    }
}
void personlist::search() //职工信息查询函数实现
{
    if(NUM<=0)
    {
        cout<<"没有职工信息存入，系统将返回主菜单"<<endl;
        menu();
    }
    else
        cout<<"***********************************************"<<endl;
    cout<<"** 请选择查找方式： **"<<endl;
    cout<<"** 1.按编号查找  **"<<endl;
    cout<<"** 2.按姓名查找  **"<<endl;
    cout<<"** 0.返回主菜单  **"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
    cout<<"请选择数字编号0~2"<<endl;
    int i4;
    cin>>i4;
    while(i4<0||i4>2)
    {
        cout<<"输入有误，请重新输入："<<endl;
        cin>>i4;
    }
    if(i4==1)
    {
        int num2;
        cout<<"请输入要查询的职工的工号："<<endl;
        cin>>num2;
        int j=0,k;
        int flag=1;
        while(flag)
        {
            for(;j<count;j++)
            {
                if(num2==r1[j].getId())
                {
                    flag=0;
                    k=j;
                    cout<<"查询的职工信息如下："<<endl;
                    cout<<r1[k];
                    break;
                }
            }
            if(flag)
            {
                flag=0;
                cout<<"不存在此职工!!\n返回主菜单"<<endl;
                break;
            }
        }
    }
    else if(i4==2)
    {
        string name2;
        cout<<"请输入要查询的职工的姓名："<<endl;
        cin>>name2;
        int j2=0,k2;
        int flag2=1;
        while(flag2)
        {
            for(;j2<count;j2++)
            {
                if(name2==r1[j2].GetName())
                {
                    flag2=0;
                    k2=j2;
                    cout<<"查询的职工信息如下："<<endl;
                    cout<<r1[k2];
                    break;
                }
            }
            if(flag2)
            {
                flag2=0;
                cout<<"不存在此职工!!\n返回主菜单"<<endl;
                break;
            }
        }
        
    }
    else if(i4==0)
        menu();
}
void personlist::dele() //职工信息删除函数实现
{
    if(NUM<=0)
    {
        cout<<"没有职工信息存入，系统将返回主菜单"<<endl;
        menu();
    }
    cout<<"请输入需要删除信息职工的工号："<<endl;
    int num3;
    cin>>num3;
    int j=0,k = 0;
    int flag=1;
    while(flag)
    {
        for(;j<count;j++)
        {
            if(num3==r1[j].getId())
            {
                flag=0;
                k=j;
                break;
            }
        }
        if(flag)
        {
            cout<<"不存在此员工，请重新输入："<<endl;
            j=0;
            cin>>num3;
        }
    }
    cout<<"你选择的职工的信息为："<<endl;
    cout<<r1[j];
    cout<<endl;
    cout<<"确认删除请输入Y，返回主菜单请输入N "<<endl;
    string p;
    cin>>p;
    while(1)
    {
        if(p=="y"||p=="Y")
        {
            cout<<"员工信息已删除！"<<endl;
            for(int i=0;i<count;i++){
                if(r1[i].getId()==num3)
                    int j=i;}
            for(;j<=count-1;j++)
                r1[j]=r1[j+1];
            count--;
            break;
        }
        else if(p=="n"||p=="N")
        {
            menu();
        }
        else
        {
            cout<<"输入有误，请重新输入：";
            cin>>p;
        }
    }
}

/*PERSON * head = NULL;
int n;
void Creatlink()
{
    PERSON * s = head;
    PERSON * NEW;
    int i = 0;
    cout<<"请输入人数：";
    cin>>n;
    while (i<n) {
        NEW = new PERSON;
        if (0==i) {
            head=NEW;
        }else{
            s->pNEXT=NEW;
        }
        s=NEW;
        NEW->pNEXT=NULL;
        ++i;
    }
    PERSON * p = head;
    for(int i = 0;i<n;i++){
        cout<<"请输入第"<<i+1<<"个学生信息："<<"姓名 "<<"邮箱 "<<"生日（年月日）"<<endl;
        cin>>p->r1;
        p=p->pNEXT;
    }
}
void personlist::show() //职工信息显示函数实现
{
    cout<<"工号:"<<num<<endl;
    cout<<"姓名:"<<name<<endl;
    cout<<"性别:"<<sex<<endl;
    cout<<"学历:"<<edu<<endl;
    cout<<"年龄:"<<age<<endl;
    cout<<"工资:"<<salary<<endl;
    cout<<"地址:"<<address<<endl;
    cout<<"电话:"<<tel<<endl;
    cout<<endl;
}
void PrintDate(PERSON*p)
{
    if (p==NULL) {
        cout<<"无内容"<<endl;
    }else{
        while (p!=NULL) {
            cout<<p->r1;
            p=p->pNEXT;
        }
    }
}
void FreeDate(PERSON * p)
{
    while (head!=NULL) {
        PERSON * s = head;
        head = s->pNEXT;
        free(s);//释放
        s = NULL;
    }
    if (head==NULL) {
        cout<<"释放成功！无内存问题！"<<endl;
    }
}
void search(PERSON * p)//查询
{
    int find=0;
    if (p==NULL) {//链表为空
        cout<<"数据为空！"<<endl;
    }
    else
    {//链表不为空
        long id;
        cout<<"请输入要查询的编号："<<endl;
        cin>>id;
        PERSON * s = p;
        while (NULL!=s) {
            if (id == s->r1.getId()) {
                cout<<s->r1;
                find = 1;
            }
            s = s->pNEXT;
        }
    }
    if (1 == find) {
        cout<<"查找成功！"<<endl;
    }
    else
    {
        cout<<"查找失败，不存在此数据！"<<endl;
    }
}
void xiugai(PERSON * p)//查询
{
    int find=0;
    if (p==NULL) {//链表为空
        cout<<"链表为空！"<<endl;
    }
    else
    {//链表不为空
        long id;
        cout<<"请输入要修改的人员编号："<<endl;
        cin>>id;
        PERSON * s = p;//搜索指针
        //情况一:头结点
        if(id == s->r1.getId()){
            cout<<p->r1;
            find = 1;
            cout<<"请输入修改信息"<<endl;
            cin>>p->r1;
        }
        else
        {//情况二:非头结点
            while (NULL!=s&&NULL!=s->pNEXT) {
                if (id == s->pNEXT->r1.getId()) {//若存在，则打印本条信息
                    cout<<s->r1;
                    find = 1;
                    cout<<"请输入修改信息"<<endl;
                    cin>>p->r1;
                }
                s = s->pNEXT;//向后搜索
            }
        }
        n--;
    }
    if (1 == find) {
        cout<<"修改成功！"<<endl;
    }
    else
    {
        cout<<"修改失败，不存在此数据！"<<endl;
    }
}
void PersonDeleteLinkLable(PERSON * p)//删除
{
    int find=0;
    if (p==NULL) {//链表为空
        cout<<"链表为空！"<<endl;
    }
    else
    {//链表不为空
        long id;
        cout<<"请输入要删除的人员编号："<<endl;
        cin>>id;
        PERSON * s = p;//搜索指针
        //情况一:头结点
        if(id == s->r1.getId()){
            cout<<p->r1;
            find = 1;
            head = head->pNEXT;
            free(s);
            s = NULL;
        }
        else
        {//情况二:非头结点
            while (NULL!=s&&NULL!=s->pNEXT) {
                if (id == s->pNEXT->r1.getId()) {//若存在，则打印本条信息
                    cout<<s->r1;
                    find = 1;
                    //删除，建立链接
                    PERSON * t = s->pNEXT;//标记被删除的结点
                    s->pNEXT = t->pNEXT;//建立新的链接
                    free(t);            //释放被标记的结点
                    t = NULL;
                }
                s = s->pNEXT;//向后搜索
            }
        }
        n--;
    }
    if (1 == find) {
        cout<<"删除成功！"<<endl;
    }
    else
    {
        cout<<"删除失败，不存在此数据！"<<endl;
    }
}
void insertlink(PERSON*p)//插入元素
{
    if(head==NULL) {//链表为空
        cout<<"链表为空！"<<endl;
    }
    else
    {//链表不为空
        cout<<"请选择要插入的方式：1、首部插入、2、指定位置处插入、3、尾部插入"<<endl;
        int c;
        cin>>c;
        switch (c) {
            case 1:
            {
                cout<<"你选择的是首部插入数据，请输入："<<endl;
                //创建链表
                PERSON* NEW = new PERSON;//申请
                NEW->pNEXT = p;//链接
                p = NEW;//更新头结点
                head = p;
                //初始化数据域
                cout<<"请输入人员信息："<<"姓名 "<<"邮箱 "<<"生日（年月日）"<<endl;
                cin>>NEW->r1;
                break;
            }
            case 2:
            {
                cout<<"你选择的是指定位置插入数据，请输入要插入的具体位置："<<endl;
                int index;
            loop:
                cin>>index;//2(第一个元素的后面进行插入)
                if(index>1&&index<=n)
                {
                    int i = 1;
                    PERSON * s = p;
                    while (i<index-1) {
                        s=s->pNEXT;//s指向当前位置的前一个元素（上一个结点）
                        i++;
                    }
                    PERSON* NEW = new PERSON;//申请
                    NEW->pNEXT = s->pNEXT;//链接
                    s->pNEXT = NEW;//更新结点
                    //初始化数据域
                    cout<<"请输入人员信息："<<"姓名 "<<"邮箱 "<<"生日（年月日）"<<endl;
                    cin>>NEW->r1;

                }
                else
                {
                    cout<<"重新输入："<<endl;
                    goto loop;
                }
                break;
            }
            case 3:
            {
                puts("你选择的是尾部插入数据，请输入：");
                PERSON * s = p;
                while (s->pNEXT!=NULL) {
                    s=s->pNEXT;
                }
                PERSON* NEW = new PERSON;//申请

                NEW->pNEXT = s->pNEXT;//链接
                s->pNEXT = NEW;//更新尾结点
                cout<<"请输入学生信息："<<"姓名 "<<"邮箱 "<<"生日（年月日）"<<endl;
                cin>>NEW->r1;

                break;
            }
            default:
                break;
        }
        n++;
        PrintDate(p);
    }
}*/

