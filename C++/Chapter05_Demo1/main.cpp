
//
//  main.cpp
//  Chapter05_Demo1
//
//  Created by mac on 18/3/2.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

//#include "test"//使用自定义名字空间
//using namespace My_space;
#include "myString.h"
using namespace myString;
#include <string>
/*void test01()
{
    ::print();
    My_space::print();
    inner::print();
    Base* pb = new Derived();
    pb->print();
    inner::Base * pd = new inner::Derived();
    pd->print();
    const char * a = "first string";
    print(a);
    char x = 'a';
    print(&x);
    print("second string");
    String b = "bad initialization";
    print(b);
    String c(a);//只创建1个对象，效率高。
    print(c);
    string s = "asbcbsa";
    string s1;
    s1.assign(s.rbegin(), s.rend());
    cout<<s<<endl;
    //    reverse(s.begin(), s.end());
    cout<<s1<<endl;
    int r = s.compare(0, 2,s1,0,2);
    if (r==0) {
        cout<<"对称串"<<endl;
    }else if(r<0){
        cout<<"不是对称串"<<endl;
    }else {
        cout<<"不是对称串"<<endl;
    }
}
 */
void test02()
{
    string s1 = "BuiuB";
    int i = 0;
    int re = 0;
    for (; i<s1.length(); ++i) {
        re = s1.compare(i, 1, s1,s1.length()-i-1,1);
        if (re!=0) {
            cout<<"不对称"<<endl;
            break;
        }
    }
    if (i==s1.length()) {
        cout<<"对称"<<endl;
    }
    string s2("kaigan");
    string s3("drive");
    if (s2.empty()) {
        cout<<"s2为空串"<<endl;
    }else{
        cout<<"s2不是空串"<<endl;
    }
    cout<<s2<<endl; //"kaigan"
    cout<<s3<<endl; //"drive"
    s2.swap(s3);    //string类中的交换函数
    cout<<s2<<endl; //"drive"
    cout<<s3<<endl<<endl; //"kaigan"
    
    const char * p = s2.c_str();//将C++字符串对象转换为C_String，包括'\0'
    cout<<p<<endl;
    p = s2.data();//字符串对象中的有效内容，不包括'\0'
    cout<<p<<endl;
    const char * p1 = s3.c_str();
    cout<<p1<<endl;
    
    string s4 = "this is a string!";
    string s5;
    s5.assign(s4,2,-1);
    cout<<s4<<endl;
    cout<<s5<<endl;
    s5.assign("faiz is a string!",5);
    cout<<s4<<endl;
    cout<<s5<<endl;
    //    s5.assign(s4,5);
    
    s5.assign(s4);
    cout<<s5<<endl;

}
int main(int argc, const char * argv[]) {
    // insert code here...
    String s1;//默认构造函数
    cout<<s1<<endl;
    const char*c1 = "Type Drive Speed!";
    String s2(c1);//类型转换构造函数
    cout<<s2<<endl;
    String s3(s2);//拷贝构造函数
    cout<<s3<<endl;
    String s4("Hyper Dai Hei Shen!");//类型转换构造函数
    cout<<s4<<endl;
    s1 = s4;//赋值运算符重载
    cout<<s1<<endl;
    s1 = "Kaigan Ghost!";//缺点：额外创建一个临时对象
    //String newS1("Kaigan Ghost!");先调用“类型转换构造函数”
    //s1=newS1;再调用“赋值运算符重载”
    cout<<s1<<endl;
    cout<<s1[12]<<endl;
    s1[0] = 'L';
    s1.at(0) = 'k';
    cout<<s1.at(0)<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.length()<<endl;
    cout<<s1<<endl;
    s1.clear();
    cout<<s1.size()<<endl;
    cout<<s1.length()<<endl;
    cout<<s1<<endl;
    s2.append(s4);
    cout<<s2<<endl;
    s2.assign("Type Drive Weild!");
    cout<<s2<<endl;
    cout<<s2.compare(s1)<<endl;
    s2.assign("Type Drive Weild!", 5);//保留前n个元素
    s2.replace(2, 4, "Nico's Name");
    cout<<s2<<endl;
    s2.push_back('L');
    cout<<s2<<endl;
    s2.insert(s2.size(), "kuuga");
    cout<<s2<<endl;
    s2.assign(s4, 6);//删除前n个元素
    cout<<s2<<endl;
    s2.assign(s4, 5);
    cout<<s2<<endl;
    s2.erase(3, 2);
    cout<<s2<<endl;
    cout<<s2.compare(0,3,s2,0,3)<<endl;
    s2.erase();
    cout<<s2<<endl;
    return 0;
}
