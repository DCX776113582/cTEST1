//
//  main.cpp
//  C++复习
//
//  Created by mac on 18/3/10.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

//#include <iostream>
//using namespace std;

#define DOUBLE(x) x+x
//分析下面程序的运行结果
#include <iostream>
using namespace std;
/*class B{
public:
    B(){}
    B(int i){b = i;}
    virtual void virfun()
    {
        cout<<"B::virfun()called.\n";
    }
private:
    int b;
};
class D:public B{
public:
    D(){}
    D(int i,int j):B(i){d = j;}
private:
    int d;
    void virfun()
    {
        cout<<"D::virfun()called.\n";
    }
};
void fun(B*obj)
{
    obj->virfun();
}
 */
class B{
public:
    B(){
        cout<<"default constructor"<<endl;
    }
    ~B(){
        cout<<"destructed"<<endl;
    }
    B(int i):data(i){
        cout<<"constructed by parameter"<<data<<endl;
    }
private:
    int data;
};
B play(B b){
    return b;
}
int main()
{
    B pd;
    play(pd);
    return 0;
}
//void Func(char str[])
//{
//    printf("%d\n",sizeof(str));
//}
//void *p = malloc(100);
//int main(int argc, const char * argv[]) {
//    char array[100];
//    Func(array);
//    int i;
//    i = 5*DOUBLE(5);
//    cout<<i<<endl;
//    cout<<sizeof(p)<<endl;
//    return 0;
//}
