//
//  Header.h
//  Chapter05_Demo1
//
//  Created by mac on 18/3/8.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef Chapter05_Demo1_Header_h
#define Chapter05_Demo1_Header_h

#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;
typedef set<int> Set;
typedef map<int, string> Map1;
typedef pair<int, string> Map;
typedef multiset<int> Mult;
typedef set<int>::iterator IT;
typedef map<int, string>::iterator IT1;
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
//自定义结构比较函数
template <typename T>
struct mySort{
    bool operator()(const T& k1,const T& k2)const
    {
        return k1 > k2;//大->小
    }
};
//对于关联容器——map，实现copy算法对两个容器中的内容拷贝必须重新定义和调用pair类型
//map中的数据类型就是pair<M, U>
template<typename M,typename U>
struct newPair
{
    M first;
    U second;
    newPair():first(M()),second(U()){}
    
    template<typename T1,typename T2>
    newPair(const pair<T1,T2>& p):first(p.first),second(p.second)
    {}
};
//重定义<<pair数据的输出：Map/MultiMap
//copy-->顺序容器：位置访问，不能用于关联容器：使用key访问
template<typename M,typename U>
ostream& operator<<(ostream& os, const newPair<M,U>& p)
{
    os << p.first << "->" << p.second;
    return os;
}
#endif
