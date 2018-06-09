//
//  main.cpp
//  Exercise7
//
//  Created by mac on 18/2/27.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Exercise.h"
#include "person.h"
/*主函数：	定义基类指针数组，动态创建子类对象，调用对应的成员函数实现多态的特性（每个人均需要表现出各自的所有日常事务情况），删除创建的对象。*/
void test()
{
    Student * s = new Student;
    Doctor * d = new Doctor;
    Driver * d1 = new Driver;
    Person * per[3] = {s,d,d1};
    for (int i = 0; i<3; ++i) {
        per[i]->dailywork();
    }
    cout<<endl;
    s->dailywork();
    s->Additionalwork();
    d->dailywork();
    d->Additionalwork();
    d1->dailywork();
    d1->Additionalwork();
    delete s;
    delete d;
    delete d1;
    s=NULL;
    d= NULL;
    d1=NULL;
}
void test2()
{
    Student1 *s=new Student1("张三",15,"好");
    Doctor1 *d1=new Doctor1("李四",45,"认真");
    Driver1 *d2=new Driver1("王五",35,"优秀");
    Person1 *array[3];
    array[0]=s;
    array[1]=d1;
    array[2]=d2;
    for(int i=0;i<3;i++)
        array[i]->dailywork();
    delete array[0];
    delete array[1];
    delete array[2];
}
void test3()
{
    Student * s = new Student;
    Doctor * d = new Doctor;
    Driver * d1 = new Driver;
    Vector v1;
    v1.add(*s);
    v1.add(*d);
    v1.add(*d1);
    cout<<"添加成功"<<endl;
    //定义容器（自定义容器）
    Vector thingSet(10);
    //定义对象
    Person* t = new Student();
    Person* a = new Doctor();
    Person* c = new Driver();
    Person* d2 = new Driver();
    Person * p = new Student();
    Person* t2 = new Doctor();
    Person* s2 = new Student();
    Person* v3 = new Driver();
    Person* car = new Doctor();
    Person* b = new Driver();
    
    Person* array[10] = {t,a,c,d2,p,t2,s2,v3,car,b};
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        thingSet.add(*array[i]) ;//给容器中添加元素
    }
    
//    	cout<<thingSet;
    
        for( int i = 0; i < thingSet.getSize(); i++ )
        {
            thingSet[i]->dailywork() ;//给容器中添加元素
        }
    bool yes = false;
    cout<<"容器中Student类的信息"<<endl;
    for (int i = 0; i<thingSet.getSize(); ++i) {
        Student * p2 = NULL;
        if ((p2 = dynamic_cast<Student*>(thingSet[i]))!=NULL) {
            yes = true;
            p2->dailywork();
        }
    }
    if (yes==false) {
        cout<<"未找到"<<endl;
    }
    for (int i = 0; i<thingSet.getSize(); ++i) {
        delete array[i];
    }

}
//定义容器（自定义容器）
Vector thingSet(N);
void Add()
{
    //定义对象
    Person* t = new Student();
    Person* a = new Doctor();
    Person* c = new Driver();
    Person* d2 = new Driver();
    Person * p = new Student();
    Person* t2 = new Doctor();
    Person* s2 = new Student();
    Person* v3 = new Driver();
    Person* car = new Doctor();
    Person* b = new Driver();
    Person* array[N] = {t,a,c,d2,p,t2,s2,v3,car,b};
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        thingSet.add(*array[i]) ;//给容器中添加元素
    }
    cout<<"添加完成"<<endl;
}
void ckzdl()//查看指定类
{
lk:cout<<"---------类别----------"<<endl;
    cout<<"     1:Student"<<endl;
    cout<<"     2:Doctor"<<endl;
    cout<<"     3:Driver"<<endl;
    cout<<"     4:Person"<<endl;
    cout<<"     5:Front"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"请选择类别：";
    int x;
    cin>>x;
    switch (x) {
        case 1:{
            bool yes = false;
            cout<<"容器中Student类的信息"<<endl;
            for (int i = 0; i<thingSet.getSize(); ++i) {
                Student * p2 = NULL;
                if ((p2 = dynamic_cast<Student*>(thingSet[i]))!=NULL) {
                    yes = true;
                    p2->dailywork();
                }
            }
            if (yes==false) {
                cout<<"未找到"<<endl;
            }
            break;}
        case 2:{
            bool yes = false;
            cout<<"容器中Doctor类的信息"<<endl;
            for (int i = 0; i<thingSet.getSize(); ++i) {
                Doctor * p2 = NULL;
                if ((p2 = dynamic_cast<Doctor*>(thingSet[i]))!=NULL) {
                    yes = true;
                    p2->dailywork();
                }
            }
            if (yes==false) {
                cout<<"未找到"<<endl;
            }
            break;}
        case 3:{
            bool yes = false;
            cout<<"容器中Driver类的信息"<<endl;
            for (int i = 0; i<thingSet.getSize(); ++i) {
                Driver * p2 = NULL;
                if ((p2 = dynamic_cast<Driver*>(thingSet[i]))!=NULL) {
                    yes = true;
                    p2->dailywork();
                }
            }
            if (yes==false) {
                cout<<"未找到"<<endl;
            }
            break;}
        case 4:{
            bool yes = false;
            cout<<"容器中Person类的信息"<<endl;
            for (int i = 0; i<thingSet.getSize(); ++i) {
                Person * p2 = NULL;
                if ((p2 = dynamic_cast<Person*>(thingSet[i]))!=NULL) {
                    yes = true;
                    p2->dailywork();
                }
            }
            if (yes==false) {
                cout<<"未找到"<<endl;
            }
            break;}
        case 5:{
            menu();
            break;}
        default:
            cout<<"输入出错，重新输入：";
            goto lk;
            break;
    }
    goto lk;
}
void chakan()
{
ll:cout<<"-----------查看菜单------------"<<endl;
    cout<<"         1:查看全部"<<endl;
    cout<<"         2:查看指定类"<<endl;
    cout<<"         3:上级菜单"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"请选择操作编号：";
    int x;
    cin>>x;
    switch (x) {
        case 1:
            if (thingSet.getSize()==0||thingSet.getIndex()==0) {
                cout<<"容器为空，没有可查看信息！"<<endl;
            }else{
                for( int i = 0; i < thingSet.getSize(); i++ )
                {
                    thingSet[i]->dailywork() ;//给容器中添加元素
                }
            }
            break;
        case 2:
            ckzdl();
            break;
        case 3:
            menu();
            break;
        default:
            cout<<"输入出错，重新输入："<<endl;
            goto ll;
            break;
    }
    goto ll;
}
void REMOVE()//删除
{
lo:cout<<"----------删除菜单-----------"<<endl;
    cout<<"        1:从后向前删除"<<endl;
    cout<<"        2:指定位置删除"<<endl;
    cout<<"        3:上级菜单"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"请选择操作:";
    int choose;
    cin>>choose;
    switch (choose) {
        case 1:{
            if (thingSet.getSize()==0) {
                cout<<"容器为空,删除失败"<<endl;
            }else{
                Person & d1 = thingSet.remove();
                delete &d1;
                cout<<"删除成功"<<endl;
            }
            break;}
        case 2:{
        mk:int index;
            cout<<"请输入删除位置:";
            cin>>index;
            if (index>thingSet.getIndex()||index<=0) {
                cout<<"错误，删除失败"<<endl;
                goto mk;
            }else if (thingSet.getSize()==0) {
                cout<<"容器为空,删除失败"<<endl;
            }else{
                Person & d2 = thingSet.remove(index-1);
                delete &d2;
                cout<<"删除成功"<<endl;
            }
            break;}
        case 3:{
            menu();
            break;
        }
        default:
            cout<<"输入出错，重新输入：";
            goto lo;
            break;
    }
    goto lo;
}
void menu()
{
loop:cout<<"----------菜单--------------"<<endl;
    cout<<"         1:添加（无内容时可添加）"<<endl;
    cout<<"         2:查看"<<endl;
    cout<<"         3:删除"<<endl;
    cout<<"         0:退出"<<endl;
    cout<<"----------------------------"<<endl;
vf:cout<<"请选择操作编号：";
    int x;
    cin>>x;
    switch (x) {
        case 1:
            Add();
            break;
        case 2:
            chakan();
            break;
        case 3:
            REMOVE();
            break;
        case 0:
            exit(0);
        default:
            cout<<"输入错误，请重输"<<endl;
            goto vf;
            break;
    }
    cout<<"是否继续[Y/N]:";
    char yes;
    cin>>yes;
    if ('y'==yes||'Y'==yes) {
        goto loop;
    }else if ('n'==yes||'N'==yes){
        exit(0);
    }else{
        cout<<"输入错误，重新输入："<<endl;
        goto loop;
    }
}
int main(int argc, const char * argv[]) {
    menu();
    return 0;
}
