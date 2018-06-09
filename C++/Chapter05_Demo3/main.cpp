//
//  main.cpp
//  Chapter05_Demo3
//
//  Created by mac on 18/3/7.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdexcept>//异常情况处理
#include <iterator>//迭代器
#include <list>
using namespace std;
#define Size 6
template <typename T>
void outPut(T & v)
{
    typename T::iterator itor;
    for (itor = v.begin(); itor!=v.end(); ++itor) {
        cout<<*itor<<" ";
    }
    cout<<endl;
}
template <typename T>
void outPutBack(T & v)
{
    typename T::reverse_iterator itor;
    for (itor = v.rbegin(); itor!=v.rend(); ++itor) {
        cout<<*itor<<" ";
    }
    cout<<endl;
}
void testVector()
{
    int a[Size] = {1,2,3,4,5,6};
    
    //定义vector对象
    vector<int> v(a,a+Size);
    
    //使用下标遍历容器中的元素
    for (int i = 0; i<Size; ++i) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"元素个数："<<v.size()<<endl;
    cout<<"容量大小："<<v.capacity()<<endl;
    
    //使用迭代器遍历容器中的元素
    outPut(v);
    outPutBack(v);
    //访问容器中的首元素和尾元素
    cout<<v.at(0)<<" "<<v.at(5)<<endl;
    cout<<v[0]<<" "<<v[5]<<endl;
    cout<<v.front()<<" "<<v.back()<<endl;
    vector<int>::iterator itor;
    itor = v.begin();
    cout<<*itor<<" ";
    itor = --v.end();
    cout<<*itor<<endl;
    
    //访问、修改元素
    v[0] = 7;
    v.at(2) = 10;
    outPut(v);
    //修改全部元素
    v.assign(3,12);
    outPut(v);
    v.assign(a, a+Size);
    outPut(v);
    
    //插入元素，其后元素依次后移
    v.insert(v.begin()+1, 22);
    outPut(v);
    v.insert(v.begin(), 2, 1);//在指定位置处添加两个数据为1的元素
    outPut(v);
    //元素个数&容量大小
    cout<<"元素个数："<<v.size()<<endl;
    cout<<"容量大小："<<v.capacity()<<endl;
    cout<<"最大元素个数："<<v.max_size()<<endl;
    //尾部插入元素
    v.push_back(12);
    outPut(v);
    //查找find()
    vector<int>::iterator location;
    location = find(v.begin(), v.end(), 12);
    if (location!=v.end()) {
        cout<<"找到此元素，位置为："<<location-v.begin()<<endl;
        cout<<"第"<<location-v.begin()+1<<"个元素！"<<endl;
    }else{
        cout<<"未找到此元素!"<<endl;
    }
    //异常处理，安全检查
    try {
        v.at(1) = 123;
    } catch (out_of_range e) {
        cout << "越界访问Exception: " << e.what()<<endl;//信息
    }
    outPut(v);
    //删除元素
    v.erase(v.begin()+4);
    outPut(v);
    //    v.erase(v.begin()+2, v.begin()+6);
    //    outPut(v);
    vector<int>::iterator first = find(v.begin(), v.end(), 22);
    vector<int>::iterator last = find(v.begin(), v.end(), 4);
    v.erase(first, last+1);
    outPut(v);
    //    v.clear();
    //容器是否为空
    v.clear();//v.erase(v.begin(), v.end());
    v.empty()?cout<<"v is Empty!"<<endl:cout<<"!Empty"<<endl;
    //给容器插入数据
    v.insert(v.begin(), 0);
    v.insert(v.begin()+1, 21);
    v.insert(v.begin()+2, 13);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.insert(v.end(),2,6);//在指定位置插入的两个数据均为6
    outPut(v);
    v.insert(v.end(),a,a+Size);//指定位置插入范围的数据(a位置开始~a+Size位置结束)
    v.empty()?cout<<"v is Empty!"<<endl:cout<<"!Empty"<<endl;
    //    v.pop_back();
    outPut(v);
    v.reserve(6);
    //    cout<<v.size()<<endl;
    outPut(v);
}
bool moop(int first,int second)
{
    return first>second;
}

//给类型取别名为IntList
typedef list<int> IntList;
void testlist()
{
    int a[Size] = {1,3,2,3,4,1};
    list<int> c0; //空链表
    list<int> c1(3,0); //建一个含三个默认值是0的元素的链表
    outPut(c1);
    list<int> c2(5,2); //建一个含五个元素的链表，值都是2
    outPut(c2);
    list<int> c4(c2); //建一个c2的copy链表
    outPut(c4);
    list<int> c5(c1.begin(),c1.end());//c5含c1一个区域的元素[_First, _Last)。
    outPut(c5);
    //	成员函数
    
    list<int> c(a,a+Size); //空链表
    /*{
     c.begin();//返回指向链表第一个元素的迭代器。
     cout<<"first:"<<c.front()<<endl;
     cout<<"last:"<<c.back()<<endl;
     c.end();//返回指向链表最后一个元素之后的迭代器。
     c.rbegin();//返回逆向链表的第一个元素,即c链表的最后一个数据。
     c.rend();//返回逆向链表的最后一个元素的下一个位置,即c链表的第一个数据再往前的位置。
     c.assign(2,2);//将n个num拷贝赋值给链表c。
     c.assign(a,a+Size);// 将[beg,end]区间的元素拷贝赋值给链表c。
     c.front();//返回链表c的第一个元素。
     c.back();//返回链表c的最后一个元素。
     c.empty();//判断链表是否为空。
     cout<<c.size()<<endl;//返回链表c中实际元素的个数。
     cout<<c.max_size()<<endl;//返回链表c可能容纳的最大元素数量。
     c.clear();//清除链表c中的所有元素。
     c.insert(c.begin(),13);//在pos位置插入元素num。
     outPut(c);
     c.insert(c.begin(),2,3);//在pos位置插入n个元素num。
     outPut(c);
     c.insert(c.end(),c.begin(),c.end());//在pos位置插入区间为[beg,end)
     outPut(c);
     c.erase(--c.end());//删除pos位置的元素。
     outPut(c);
     c.push_back(123);//在末尾增加一个元素。
     outPut(c);
     c.pop_back();//删除末尾的元素。
     outPut(c);
     c.push_front(323);//在开始位置增加一个元素。
     outPut(c);
     c.pop_front();//删除第一个元素。
     outPut(c);
     c.resize(10);//从新定义链表的长度,超出原始长度部分用0代替,小于原始部分删除。
     outPut(c);
     c.resize(5,10);//从新定义链表的长度,超出原始长度部分用num代替。
     outPut(c);
     }*/
    c1.swap(c2);//将c1和c2交换
    outPut(c1);
    outPut(c2);
        swap(c1,c2);//将c1和c2交换
    //    outPut(c1);
    c1.merge(c2);//合并2个有序的链表并使之有序,从新放到c1里,释放c2。
    outPut(c2);
    outPut(c1);
    //    c1.merge(c2,moop);//合并2个有序的链表并使之按照自定义规则排序之后从新放到c1中,释放c2。
    //    outPut(c);
    c1.splice(c1.begin(),c2);//将c2连接在c1的beg位置,释放c2
    outPut(c1);
    c1.splice(c1.begin(),c4,c4.begin());//将c4的beg位置的元素连接到c1的beg位置，并且在c4中施放掉beg位置的元素
    outPut(c1);
    c1.splice(c1.begin(),c2,c2.begin(),c2.end());//将c2的[beg,end)位置的元素连接到c1的beg位置并且释放c2的[beg,end)位置的元素
    outPut(c1);
//    c1.remove(2);//删除链表中匹配num的元素。
//    outPut(c1);
    c1.reverse();//反转链表
    outPut(c1);
    c1.sort();//将链表排序，默认升序
    outPut(c1);
    c1.sort(moop);//将链表排序，降序
    outPut(c1);
    c1.unique();//删除相同的元素;相邻的重复数据，只保留一个
    outPut(c1);
    //    c1.remove_if(myFun);//删除条件满足的元素,参数为自定义的
    /*{IntList lst; //创建一个list容器类的对象
    for( int i = 0; i < 5; i++ )
    {
        lst.push_front(i); //在容器首部添加元素i
        lst.push_back(i); //在容器list尾部添加元素i
    }
    //定义一个迭代器
    IntList::iterator itor = lst.begin();
    while(itor != lst.end())
    {
        cout << *itor++ << " ";
    }
    cout << endl;
    //remove什么呢？移除所有值为0的元素。
    lst.remove(0); //删除容器中内容为“0”的元素
    itor = lst.begin();//重新指向容器中的首元素
    for(int i = 0; i < lst.size(); i++)
    {
        cout << *itor++ << " ";
    }
    cout << endl;
    }*/
}
int main(int argc, const char * argv[]) {
//    testVector();
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    list<int> l2;
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);
//    l1.merge(l2);
//    l1.merge(l2, moop);
    outPut(l1);
    outPut(l2);
    if (l1<=l2) {
        outPut(l1);
    }
    if (l1>=l2) {
        outPut(l2);
    }
    if (l1==l2) {
        outPut(l1);
    }
    if (l1<l2) {
        outPut(l1);
    }
    if (l1>l2) {
        outPut(l1);
    }
    if (l1!=l2) {
        outPut(l1);
    }

//    testlist();
    return 0;
}
