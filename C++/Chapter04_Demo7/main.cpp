//
//  main.cpp
//  Chapter04_Demo7
//
//  Created by mac on 18/3/1.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "thingSet.hpp"
//定义容器（自定义容器）
ThingSet thingSet(10);

void isPerosn()
{
    bool yes = false;
    cout<<"容器中的Person2类信息是："<<endl;
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        Person2 * p2 = NULL;
        //判断容器中的对象类型是不是要找的匹配类型
        if ((p2 = dynamic_cast<Person2*>(thingSet[i])) !=NULL) {
            yes = true;
            p2->what_am_i(); //Thing* --> Person2* (向下转型)
        }
    }
    if (yes==false) {
        cout<<"未找到"<<endl;
    }
}

void isAnimal()
{
    bool yes = false;
    cout<<"容器中的Animal1类信息是："<<endl;
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        Animal1 * p2 = NULL;
        //判断容器中的对象类型是不是要找的匹配类型
        if ((p2 = dynamic_cast<Animal1*>(thingSet[i])) !=NULL) {
            yes = true;
            p2->what_am_i(); //Thing* --> Animal1* (向下转型)
        }
    }
    if (yes==false) {
        cout<<"未找到"<<endl;
    }
}

void isVehicle()
{
    bool yes = false;
    cout<<"容器中的Vehicle3类信息是："<<endl;
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        Vehicle3 * p2 = NULL;
        //判断容器中的对象类型是不是要找的匹配类型
        if ((p2 = dynamic_cast<Vehicle3*>(thingSet[i])) !=NULL) {
            yes = true;
            p2->what_am_i(); //Thing* --> Vehicle* (向下转型)
        }
    }
    if (yes==false) {
        cout<<"未找到"<<endl;
    }
}

void isBus()
{
    bool yes = false;
    cout<<"容器中的Bus类信息是："<<endl;
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        Bus * p2 = NULL;
        //判断容器中的对象类型是不是要找的匹配类型
        if ((p2 = dynamic_cast<Bus*>(thingSet[i])) !=NULL) {
            yes = true;
            p2->what_am_i(); //Thing* --> Bus* (向下转型)
            p2->passengers();
        }
    }
    if (yes==false) {
        cout<<"未找到"<<endl;
    }
}

//测试多态——抽象类以及纯虚函数
void testPolymorphism1()
{
    //定义对象
    Animal1* a = new Animal1();
    Cat* c = new Cat();
    Dog* d = new Dog();
    Person2 * p = new Person2();
    Teacher2* t2 = new Teacher2();
    Student2* s2 = new Student2();
    Vehicle3* v3 = new Vehicle3();
    Car* car = new Car();
    YellowBike* b = new YellowBike();
    Bus* bus = new Bus();
    
    Thing* array[10] = {a,c,d,p,t2,s2,v3,car,b,bus};
    
    
    for( int i = 0; i < thingSet.getSize(); i++ )
    {
        thingSet.add(*array[i]) ;//给容器中添加元素
    }
    cout<<"容器中的信息是："<<endl;
    cout<<thingSet<<endl;
    
    //运行时类型识别:dynamic_cast<子类*>(父类*)——动态类型转换
    //1、解决多态性中潜在的向下转型的不安全问题；
    //（父类的指针/父类的引用类型 向下转型 为子类的指针/子类的引用类型）
    //2、对多态中的相关不同子类的特性进行筛选/查找（想要的）信息
loop:
    int chose;
    cout<<"请选择：";
    cout<<"1、Perosn    2、Animal    3、Vehicle   4、Bus"<<endl;
    cin>>chose;
    switch (chose) {
        case 1:
            isPerosn();
            break;
        case 2:
            isAnimal();
            break;
        case 3:
            isVehicle();
            break;
        case 4:
            isBus();
            break;
        default:{
            cout<<"输入错误,请重新选择！"<<endl;
            goto loop;
            break;
        }
    }
    cout<<"Y/N？"<<endl;
    char s = '\0';
    cin>>s;
    if (s=='Y' || s=='y') {
        goto loop;
    }
    for (int i = 0; i<thingSet.getSize(); ++i) {
        delete array[i];
    }
}

//重新转换类型运算符：32bit的任意转换（不适合非32bit的实例）
void test_ReinterPret_cast()
{
    long a = 10;//64bit == !32bit
    long * p = &a;
    int j = reinterpret_cast<int>(p);
    long* i = reinterpret_cast<long *>(j);
    cout<<j<<endl;
    cout<<*i<<endl;
}

//静态类型转换运算符：与显示类型转换作用一致（发生在程序的编译期间）
void test_static_cast()
{
    char o = '0';
    cout<<(int)o<<endl;
    cout<<static_cast<int>(o)<<endl;
    
    Person2* pb = new Person2();
    Student2* pd = new Student2();
    pb->what_am_i();//Person2::what_am_i()
    pd->what_am_i();//Student2::what_am_i()
    
    //向下转型：
    //问题： pd=pb;  // 语法错误Error
    //解决办法：强制转换/静态类型转换方式->向下转型
    //遗留问题：父类指针始终指向父类对象时，此时仍然调用的是父类的虚函数，不能体现出子类的特征（不能实现多态性）；
    //解决遗留问题？？？：只能使用动态类型转换方式
    pd=(Student2*)pb;//(父类->子类)
    pd->what_am_i();
    
    ((Student2*)pb)->what_am_i();	//向下转型：pb被转换为派生类类型 不安全
    //等价于
    dynamic_cast< Student2 *>(pb)->what_am_i();//向下转型
    
    //解决方案：
    Student2 * s = dynamic_cast< Student2 *>(pb);//向下转型：不成功
    if (s!=NULL) {
        s->what_am_i(); // Student2::what_am_i();
    } else {
        cout<<"真实对象的类型不是子类，无法打印"<<endl;
    }
    pb->what_am_i(); //what_am_i()为虚函数 调用Person2::what_am_i()
}

//const_cast():常量类型转换：去除const的作用
void test_const_cast()
{
    const int a = 10;
    
    //	int b = (const_cast<int&>(a) = 100); //const类型转换：const->非const
    //	cout<<"b="<<b<<endl;
    //	cout<<a<<endl;
    //  等价于下面的形式：
    cout<<(const_cast<int&>(a)=100)<<endl;
    //a = 100; //定义本质类型不能被修改
    cout<<a<<endl;
}

int main(int argc, const char * argv[]) {
    //	testPolymorphism1();
    //	test_ReinterPret_cast();
    //	test_static_cast();
    test_const_cast();
    return 0;
}