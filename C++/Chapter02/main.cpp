//
//  main.cpp
//  Chapter02
//
//  Created by mac on 18/2/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <iostream>
#include "Boy.hpp"
#include "Complex.hpp"
#include "Vector.hpp"
void test01()//测试运算符+、-、*、/、%、<<、>>重载
{
    Int a;
    Int b;
    cout<<"输入a的值：";
    cin>>a;
    cout<<"输入b的值：";
    cin>>b;
    cout<<a;
    cout<<b;
    
    cout<<(a+b);
    //    (a+b).printInt();
    //    a.operator+(b).printInt();
    //    operator+(a,b).printInt();
    //     a.setA(3);
    cout<<(a-b);
    //    (a-b).printInt();
    //    a.operator-(b).printInt();
    //    operator-(a,b).printInt();
    a.setA(3);
    cout<<(a*b);
    //    (a*b).printInt();
    //    a.operator*(b).printInt();
    //    operator*(a,b).printInt();
    a.setA(3);
    cout<<(a%b);
    //    (a%b).printInt();
    //    operator%(a,b).printInt();
    //    a.operator%(b).printInt();
    a.setA(3);
    cout<<(a/b);
    //    (a/b).printInt();
    //    a.operator/(b).printInt();
    //    operator/(a,b).printInt();
    a.setA(3);
    //    (a=b).printInt();
    //    a.operator=(b).printInt();
}
Complex operator+(Complex& c1,Complex& c2)
{
    Complex temp;
    int sum = c1.getReal() +c2.getReal();
    int sum1 = c1.getImag()+c2.getImag();
    temp.setReal(sum);
    temp.setImag(sum1);
    return temp;
}
Complex operator-(Complex & c1,Complex & c2)
{
    int sum = c1.getReal()-c2.getReal();
    int sum1 = c1.getImag()-c2.getImag();
    Complex temp;
    temp.setReal(sum);
    temp.setImag(sum1);
    return temp;
}
Complex operator*(Complex & c1,Complex & c2)
{
    int sum = (c1.getReal()*c2.getReal())-(c1.getImag()*c2.getImag());
    int sum1 = (c1.getImag()*c2.getReal())+(c1.getReal()*c2.getImag());
    Complex temp;
    temp.setReal(sum);
    temp.setImag(sum1);
    return temp;
}
Complex operator/(Complex & c1,Complex & c2)
{
    int sum = ((c1.getReal()*c2.getReal())+(c1.getImag()*c2.getImag()))/((c2.getReal()*c2.getReal())+(c2.getImag()*c2.getImag()));
    int sum1 = ((c1.getImag()*c2.getReal())-(c1.getReal()*c2.getImag()))/((c2.getReal()*c2.getReal())+(c2.getImag()*c2.getImag()));
    Complex temp;
    temp.setReal(sum);
    temp.setImag(sum1);

    return temp;
}
void test02()
{
    Complex c1(5,5);
    Complex c2(1,1);
    (c1+c2).print();
    (c1-c2).print();
    (c1*c2).print();
    (c1/c2).print();
    cout<<"类内成员函数："<<endl;
    c1.operator+(c2).print();
    c1.operator-(c2).print();
    c1.operator*(c2).print();
    c1.operator/(c2).print();
    cout<<"友元函数："<<endl;
    cout<<operator+(c1,c2);
    cout<<operator-(c1,c2);
    cout<<operator*(c1,c2);
    cout<<operator/(c1,c2);
    cout<<"请输入第一个复数：";
    cin>>c1;
    cout<<"请输入第二个复数：";
    cin>>c2;
    cout<<c1;
    cout<<c2;
    cout<<"运算符<<重载："<<endl;
    cout<<(c1+c2);
    cout<<(c1-c2);
    cout<<(c1*c2);
    cout<<(c1/c2);
}
void boy()
{
    Boy b1((char*)"d1",(char*) "12345678910", 2);
    cout<<b1;//b1.print();
    
    Boy b2((char*)"d2",(char*) "10987654321", 3);
    cout<<b2;//b2.print();
    
    b2 = b1;
    b2.print();
    
    b2.setName((char*)"d3");
    b2.print();
    //    cout<<b2;
    b2.setTel((char*)"17832149989");
    //    b2.print();
    cout<<b2;
}
//Boy类对象相等运算符重载
bool operator==(const Boy & b1, const Boy & b2)
{
    bool yes = true;
    
    //对象是否相等：对象中数据成员变量的内容是否相等
    //1、字符串name是否相等
    if (0!=strcmp(b1.getName(), b2.getName())) {
        printf("name不相等");
        yes = false;
    }
    //2、字符串TelPhone是否相等
    if (0!=strcmp(b1.getTelephone(), b2.getTelephone())) {
        printf("Telephone不相等");
        yes = false;
    }
    //3、值变量Phone是否相等
    if (b1.getPhone()!=b2.getPhone()) {
        printf("Phone不相等");
        yes = false;
    }
    return yes;
}
/*bool operator==(const Vector&v1,const Vector&v2)
{
    bool yes = true;
    if (v1.size<v2.size) {
        yes = false;
    }else{
        int index = 0;
        int s= v1.size;
        
        while (index<s&&v1.rep[index]==v2.rep[index]) {
            ++index;
        }
        if (index<s) {
            yes=false;
        }
    }
    return yes;
}*/
//Vector相等运算符重载
bool operator==(const Vector & v1, const Vector & v2)
{
    bool yes = true;
    //1、先判段容器实际大小是否相等
    if (v1.getSize() != v2.getSize()) {
        yes = false;
    } else {
        //2、若相等，再判断容器中的内容是否相等
        int index;
        for (index = 0; index<v1.getSize(); ) {
            //boy1 == boy2
            if ((v1.rep[index]) == (v2.rep[index])) {
                ++index;
            } else {
                break;
            }
        }
        if (index<v1.getSize()) {
            yes = false;
        }
    }
    return yes;
}
int main(int argc, const char * argv[]) {
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {1,2,3,4,5};
    Vector vec1(5, array1);
    Vector vec2(5, array2);
    if (vec1==vec2) {
        cout<<"vec1==vec2"<<endl;
    }else{
        cout<<"vec1!=vec2"<<endl;
    }
    Integer a(13);
    Integer b(12);
//    a.operator+(b).print();
//    a.operator|=(b).print();
//    a.operator-(b).print();
//    a.operator--().print();
    a++;
    a.print();
    --a;
    a.print();
    a--;
    a.print();
    ++a;
    a.print();
//    vec1.print();
//    vec2.print();
//    vec1 = vec2;
//    vec1.print();
//    vec2.print();
//    vec2.rep[8] = 999;
//    vec1.print();
//    vec2.print();
    return 0;
}
