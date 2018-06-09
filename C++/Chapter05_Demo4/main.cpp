//
//  main.cpp
//  Chapter05_Demo4
//
//  Created by mac on 18/3/8.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Header.h"
void testSet()
{
    Set s1;//不可重复
    //    Mult s1;//可重复
    s1.insert(10);
    s1.insert(-5);
    s1.insert(8);
    s1.insert(10);
    int key;
    cout<<"请输入数据：";
    cin>>key;
    //    s1.insert(key);
    IT itor = s1.find(key);
    if (itor != s1.end( )) {
        cout << key << " is in this set.\n";
    } else {
        cout << key << " is not in this set.\n";
    }
    cout<<s1.max_size()<<endl;
    outPut(s1);
    s1.erase(s1.begin());//删除指定位置元素
    outPut(s1);
    s1.erase(10);//删除指定元素
    outPut(s1);
    s1.insert(13);
    outPut(s1);
}
void testMap()
{
    Map m1(1,"kuuga");//pair对象
    cout<<m1.first<<endl;
    cout<<m1.second<<endl;
    Map m2(2,"agito");
    Map m3(3,"ruki");
    Map1 M1;//创建空容器M1
    M1.insert(m1);//给容器添加元素：pair
    M1.insert(m2);
    M1.insert(m3);
    cout<<"M1:"<<M1.size()<<endl;
    for (auto item:M1) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //创建并初始化容器M2
    Map1 M2{{1,"ultraman"},{2,"Seven"},{3,"jack"}};
    cout<<"M2:"<<M2.size()<<endl;
    for (auto item:M2) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //创建并初始化容器M3
    Map1 M3{m1,m2,Map(3,"ultraman"),Map(4,"Seven")};
    cout<<"M3:"<<M3.size()<<endl;
    for (auto item:M3) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //拷贝
    Map1 M4(M3);
    cout<<"M4:"<<M4.size()<<endl;
    for (auto item:M4) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //一段数据
    Map1 M5(M3.begin(),M3.end());
    cout<<"M5:"<<M5.size()<<endl;
    for (auto item:M5) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    M5[1] = "hibiki";//添加元素，如果key存在，则覆盖
    cout<<M5.find(1)->first<<":";
    cout<<M5.find(1)->second<<endl;
    M5[2] = "kabuto";
    M5[5] = "deno";//添加元素，key不存在，则添加
    cout<<M5.find(2)->first<<":";
    cout<<M5.find(2)->second<<endl;
    cout<<M5.find(5)->first<<":";
    cout<<M5.find(5)->second<<endl;
    cout<<"M5:"<<M5.size()<<endl;
    //范围for循环：遍历关联容器
    for (auto item:M5) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //迭代器遍历方式
    IT1 itor;
    for (itor = M5.begin(); itor != M5.end(); ++itor) {
        cout<<itor->first<<":"<<itor->second<<endl;
    }
    //使用count函数来判断关键字是否出现,返回值0/1
    if (M5.count(5)==0) {
        cout<<"key为5的元素不存在"<<endl;
    }else{
        cout<<"key为5的元素存在,为："<<M5[5]<<endl;
        cout<<"key为5的元素存在,为："<<M5.find(5)->second<<endl;
    }
    //使用find()函数定位数据出现的位置，当key值存在时，返回对应位置的迭代器，否则返回end()函数返回的迭代器；
    itor = M5.find(3);
    if (itor!=M5.end()) {
        cout<<"key为3的元素存在,为："<<M5[3]<<endl;
        cout<<"key为3的元素存在,为："<<M5.find(3)->second<<endl;
    }else{
        cout<<"key为3的元素不存在"<<endl;
    }
    //删除元素:erase(key),erase(itor)
    if (M5.count(2)) {
        M5.erase(2);
        cout<<"删除成功"<<endl;
    }else{
        cout<<"删除失败"<<endl;
    }
    for (auto item:M5) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    if (itor!=M5.end()) {
        M5.erase(itor);
        cout<<"删除成功"<<endl;
    }else{
        cout<<"删除失败"<<endl;
    }
    for (auto item:M5) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //范围删除
    M5.erase(M5.begin(), --M5.end());
    for (auto item:M5) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //排序：系统greater<int> 大->小
    map<int, string,greater<int>>M6;
    M6[1] = m1.second;
    M6[2] = m2.second;
    M6[3] = m3.second;
    M6[5] = M5.find(5)->second;
    M6[4] = M4.find(3)->second;
    cout<<"排序之后"<<endl;
    for (auto item:M6) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //排序：自定义函数实现大->小
    map<int, string,mySort<int>> M7;
    M7[1] = m1.second;
    M7[2] = m2.second;
    M7[3] = m3.second;
    M7[5] = M5.find(5)->second;
    M7[4] = M4.find(3)->second;
    cout<<"自定义函数排序之后"<<endl;
    for (auto item:M7) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    //其他功能函数
    //正序：返回第一个key>=4的元素的位置；逆序：返回第一个key<=4的位置
    itor = M7.lower_bound(4);
    if (itor!=M7.end()) {
        cout<<itor->first<<":"<<itor->second<<endl;
        cout<<"返回成功"<<endl;
    }else{
        cout<<"返回失败"<<endl;
    }
    //正序：返回第一个key>2的元素的位置；逆序：返回第一个key<2的元素的位置
    itor = M7.upper_bound(2);
    if (itor!=M7.end()) {
        cout<<itor->first<<":"<<itor->second<<endl;
        cout<<"返回成功"<<endl;
    }else{
        cout<<"返回失败"<<endl;
    }
}
void test_stack()
{
    deque<int> mydeque(2,100);
    outPut(mydeque);
    vector<int> myvector(2,200);
    outPut(myvector);
    
    stack<int> first;
    stack<int> second(mydeque);
    
    stack< int, vector<int> > third;
    stack< int, vector<int> > fourth(myvector);
    
    cout << "size of first: " << (int) first.size() << endl;
    cout << "size of second: " << (int) second.size() << endl;
    cout << "size of third: " << (int) third.size() << endl;
    cout << "size of fourth: " << (int) fourth.size() << endl;
}
void testCopy()
{
    int array[5] = {1,2,3,4,5};
    vector<int> v0(array,array+5);//原始容器v0
    for (auto item:v0) {
        cout<<item<<" ";
    }
    cout<<endl;
    vector<int> v1;//新容器v1
    v1.resize(5);//设置大小为5
    copy(v0.begin(),v0.end(),v1.begin());//copy算法
    cout<<"copy之后"<<endl;
    for (auto item:v1) {
        cout<<item<<" ";
    }
    cout<<endl;
    Map1 ma1;
    ma1[1] = "ginga";
    ma1[3] = "aikesi";
    ma1[2] = "vector";
    ma1[5] = "nice";
    ma1[4] = "ghost";
    for (auto item:ma1) {
        cout<<item.first<<":"<<item.second<<endl;
    }
    cout<<"copy之后"<<endl;
    Map1 ma2;
    copy(ma1.begin(), ma1.end(), ostream_iterator<newPair<int, string>>(cout<<" "));
    cout<<endl;
}
void callFun(const int& a,const int& b)
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"a + b = "<<a+b<<endl;
}
int add(int a,int b)
{
    return a+b;
}
auto sub = [](int a,int b)->int{
    return a-b;
};
struct dived{
    int operator()(int a,int b){
        return a/b;
    }
};
void testauto()
{
    //1、auto:自动类型修饰符
    auto a = 1;
    cout<<a<<endl;
    auto a1 = "string";
    cout<<a1<<endl;
    auto a2 = 12.32f;
    cout<<a2<<endl;
    //2、类型推断运算符    decltype(表达式)
    decltype("string") s2 = "hello!";//声明并初始化
    cout<<s2<<endl;
    decltype(1.3) a3 = 13.3;
    cout<<a3<<endl;
    //3、auto:范围循环
    string s1[3] = {"a1","a2","a3"};
    for (auto item:s1) {
        cout<<item<<endl;
    }
    //4、override:增加可读性 final：函数不可被重写、类不可被继承
    class Base{
    public:
        virtual void print(){cout<<"Base"<<endl;}
    };
    class B:public Base{
    public:
       virtual void print()override{cout<<"B::"<<endl;}
    };
    Base*b1 = new B;
    b1->print();
    //5、类型重命名：typedef；using 类型别名 = 原始类型；新方法
    //typedef int Int；传统方法
    using Int = int;
    Int a4 = 10;
    cout<<a4<<endl;
    using IntV = vector<int>;
    Int a5[5] = {1,2,3,4,5};
    IntV v = {a5,a5+5};
    outPut(v);
    //6、lambda表达式：目的提高运行效率，作用与函数相同，替换内联函数
    auto fun = []()->int {return 50;};
    cout<<fun() <<endl;//调用表达式
    Int a6 = 10;
    Int a7 = 20;
    //[=]:值捕获，不可修改外部变量值；[&]:引用形式捕获，可修改外部变量值
    auto r = [&a6,&a7](int c)mutable->int
    {//mutable修饰表达式的捕获列表中的方式为 = 时，能够在内部被使用，但是 = 不能修改外部变量本身的值。
        a6 += 100;
        a7 = 200;
        return a6+a7+c;
    };
    cout<<"a6="<<a6<<",a7="<<a7<<endl;
    cout<<"r="<<r(300)<<endl;
    cout<<"Afyer:a6="<<a6<<",a7="<<a7<<endl;
    //7、bind()：函数适配器->适配器对象:函数的绑定调用（链接调用）
    auto newCall = bind(callFun,100,placeholders::_2);
    newCall(10,20);//调用适配器对象，进行传参
    //8、FUNCTION 类型对象：便于后期对容器中元素的维护
    function<int (int ,int )>f1 = add;
    function<int (int ,int )>f2 = sub;
    function<int (int ,int )>f3 = dived();
    map<string,function<int (int ,int )>>m;
    m.insert({"+",f1});
    m.insert({"-",f2});
    m.insert({"/",f3});
    for (auto item:m) {
        cout<<item.first<<":"<<item.second(10,20)<<endl;
    }
    //9、空指针初始化
    int * ptr = nullptr;
    //10、列表初始化方式：变量的初始化
    string s{"naic"};//s = "naic"
    cout<<s<<endl;
    
    Int iarray[5]{1,2,3,4,5};
    for (auto item:iarray) {
        cout<<item<<endl;
    }
    //11、智能指针-容器中的迭代器类型的对象
    shared_ptr<string> p1;
    p1 = make_shared<string>("Drive");
    cout<<p1<<endl;
    cout<<*p1<<endl;
}
int main(int argc, const char * argv[]) {
//    test_stack();
//    testCopy();
    testauto();
    return 0;
}
