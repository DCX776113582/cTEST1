//
//  main.cpp
//  STR
//
//  Created by mac on 18/4/25.
//  Copyright © 2018年 duanchuanxin. All rights reserved.
//

#include <iostream>
//#include <stdio.h>
//#include "String.hpp"
using namespace std;
//#include <string.h>
//#include <stdlib.h>
//#include "Vec.hpp"
#include "STR.hpp"
/***linux下一个中文占用三个字节,windows占两个字节***/
/*void chinese_or_english(char *str)
{
    char chinese[4] = {0};
    for (int i = 0; i < strlen(str); i++) {
        //if (str[i] >= 0 && str[i] <= 127) {      //ascII
        if ((str[i] & 0x80) == 0) {   //chinese:the top is 1
            cout<<"alpha:"<<str[i]<<endl;
        }
        //else if (str[i] < 0){
        else {
            chinese[0] = str[i];
            chinese[1] = str[i + 1];
            chinese[2] = str[i + 2];
            i++;    //skip one more
            i++;
            printf("chinese:%s\n", chinese);  
        }  
    }  
}
 */
/*void test()
{
    String str1;                  //默认构造函数
    String str2(NULL);            //带参构造函数
    String str3("helloworld");    //带参构造函数
    cout<<"str3="<<str3.getstr()<<endl;
    
    String str4(str3);            //复制构造函数
    //String str4 = str3;         //复制构造函数
    cout<<"str4="<<str4.getstr()<<endl;
    
    
    const String str5("tai");     //重载下标运算符[](const版本)
    cout<<"str5[0]="<<str5[0]<<endl;
    
    String str6;
    str6 = str3;                  //重载复制运算符=
    cout<<"str6="<<str6.getstr()<<endl;
    
    String str7 = str3 + str5;    //重载加法运算符+
    cout<<"str7="<<str7.getstr()<<endl;
    
    String str8("123");
    str8 += str7;                 //重载组合运算符+=
    cout<<"str8="<<str8.getstr()<<endl;
    
    String str9;
    cin>>str9;                    //重载输入流运算符>>
    cout<<"str9="<<str9<<endl;    //重载输出流运算符<<
    
    String str10("compare String");
    String str11("compare string");
    int comp = str10 > str11;
    cout<< "str10大于str11:" << comp <<endl;
}
 */
/*void test1()
{
    char* str = "tai太阳yang";
    cout<<strlen(str)<<endl;
    //    chinese_or_english(str);
    Vector<char*> st1;
    st1.add(str);
    st1.add(str);
    st1.add(str);
    st1.add(str);
    cout<<st1.get_capacity()<<endl;
    cout<<st1.get_size()<<endl;
    cout<<st1<<endl;
    Vector<char*> st2(st1);
    cout<<st2.get_capacity()<<endl;
    cout<<st2.get_size()<<endl;
    cout<<st2<<endl;
    char* const str1 = "kar";
    Vector<char*> st3(&str,1);
    st3.add(str);
    st3.add(str);
    st3.add(str1);
    st3.add(str1);
    st3.remove();
    cout<<st3.search(&str1)<<endl;
    cout<<st3.get_capacity()<<endl;
    cout<<st3.get_size()<<endl;
    cout<<st3<<endl;

}
 */
void test2()
{
    String s1("zhangsan");//传参普通构造函数
    cout<<s1<<endl;//输出重载
    String s2("lisi");
    cout<<s2<<endl;
    String s3(s1);//拷贝构造函数
    cout<<s3<<endl;
    String s4;//默认构造函数
    cout<<s4<<endl;
    String s5 = s2+s2;//赋值运算符重载、加法运算符重载
    cout<<s5<<endl;
    s2+=s3;//+=重载
    cout<<s2<<endl;
    cout<<s2[11]<<endl;//下标运算符[]重载
    cout<<s2.at(11)<<endl;//下标运算符at()重载
    if (s1 == s3) {
        cout<<"相等"<<endl;
    }else{
        cout<<"不相等"<<endl;
    }
}
int main(int argc, const char * argv[]) {
    test2();
    return 0;
}
