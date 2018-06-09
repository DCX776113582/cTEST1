//
//  myString.h
//  Chapter05_Demo1
//
//  Created by mac on 18/3/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef Chapter05_Demo1_myString_h
#define Chapter05_Demo1_myString_h
#include <iostream>
using namespace std;
#include <string.h>
namespace myString {
    //自定义String类
    class String{
    private:
        int len;
        char*rep;
    public:
        //默认构造函数：
        String():len(0),rep(new char[len+1])
        {
            strcpy(rep,"");
        }
        //类型转换构造函数
        String(const char* s)
        {
            //判断s指针指向是否有效
            if (s==NULL) {//无效
                len = 0;
                rep = new char[len+1];
                strcpy(rep,"");
            }else{//有效
                len = strlen(s);
                rep = new char[len+1];
                strcpy(rep,s);
            }
        }
        //三大件——拷贝构造
        String(const String& s1)
        {
            len = s1.len;
            rep = new char[len+1];
            strcpy(rep,s1.rep);
        }
        //三大件——析构函数
        ~String()
        {
            if (rep!=NULL) {
                delete [] rep;
                rep = NULL;
            }
        }
        //三大件——赋值运算符重载
        const String& operator=(const String& s1)
        {
            if (this!=&s1) {
                delete [] rep;
                len = s1.len;
                rep = new char[len+1];
                strcpy(rep,s1.rep);
            }
            return *this;
        }
        //下标运算符重载
        char& operator[](int index)
        {
            return rep[index];
        }
        char& operator[](int index)const
        {
            return rep[index];
        }
        // str.at(0)
        char& at(int index)
        {
            if (index<0||index>len) {//判断越界性
                cout<<"下标越界"<<endl;
//                const char& p = '\0';
//                return const_cast<char&>(p);
                return rep[len];
            }
            return rep[index];
        }
        char& at(int index)const
        {
            if (index<0||index>len) {//判断越界性
                cout<<"下标越界"<<endl;
//                const char& p = '\0';
//                return const_cast<char&>(p);
                return rep[len];
            }
            return rep[index];
        }
        //有效字符个数：String str("hello");cout<<str.size()<<endl;
        int size()
        {
            return len;
        }
        //有效字符个数：String str("hello");cout<<str.length()<<endl;
        int length()
        {
            return size();
        }
        void clear()//清除容器
        {
//            for (int i = 0; i<len; ++i) {
//                rep[i]='\0';
//            }
            strcpy(rep,"");//重新赋值为'\0'
            len = 0;
        }
        //字符串追加功能
        String& append(const String&s1)
        {
            if (s1.rep!=NULL) {
                char * temp = rep;
                int size = len + s1.len + 1;
                rep = new char[size];
//                strcpy(rep, temp);
//                strcat(rep, s1.rep);
                //拷贝旧字符数据
                for (int i = 0; i<len; ++i) {
                    rep[i] = temp[i];
                }
                //拷贝追加字符数据，包括'\0'
                for (int i = len; i<size; ++i) {
                    rep[i] = s1.rep[i-len];
                }
                delete [] temp;//释放旧内存
                temp = NULL;
                len = size-1;//更新有效字符个数
            }
            return *this;
        }
        String& assign(const String&s1)
        {
            if (rep!=NULL) {
                delete [] rep;
            }
            rep = new char[strlen(s1.rep)+1];
            strcpy(rep, s1.rep);
            len = s1.len;
            return *this;
        }
        String& assign(const char* s1,int n)
        {
            if (rep!=NULL) {
                delete [] rep;
            }
            rep = new char[n+1];
            strcpy(rep, s1);
            rep[n]='\0';
            len = n;
            return *this;
        }
        /*String& assign(const String& s1,int n)
        {
            if (rep!=NULL) {
                delete [] rep;
            }
            rep = new char[n+1];
            strcpy(rep, s1.rep);
            rep[n]='\0';
            len = n;
            return *this;
        }*/
        String& assign(const String& s1,int n)
        {
            if (rep!=NULL) {
                delete [] rep;
            }
            rep = new char[(s1.len-n)+1];
            for (int i = n; i<s1.len; ++i) {
                rep[i-n] = s1.rep[i];
            }
            rep[s1.len-n] = '\0';
            len = s1.len-n;
            return *this;
        }
        int compare(const String& s1)
        {
            int r = 0;
            if (s1.rep!=NULL) {
                r = strcmp(rep,s1.rep);
            }
            return r;
        }
        int compare(int pos1,int n1,const String& s1,int pos2,int n2)
        {
            int r = 0;
            if (s1.rep!=NULL) {
                char p1[n1+1],p2[n2+1];
                for (int i = 0; i<n1; ++i) {
                    p1[i] = rep[pos1+i];
                }
                p1[n1] = '\0';
                for (int i = 0; i<n2; ++i) {
                    p2[i] = s1.rep[pos2+i];
                }
                p2[n2] = '\0';
                r = strcmp(p1, p2);
            }
            return r;
        }
        String& push_back(char c)
        {
            int last = len;
            char * temp = rep;
            rep = new char[last+2];
            strcpy(rep, temp);
            rep[last] = c;
            rep[last+1] = '\0';
            len += 1;
            delete [] temp;
            temp = NULL;
            return *this;
        }
        String& insert(int pos,const char* s)
        {
            //insert(有效位置)
            if (s==NULL) {
                cout<<"被插入的对象不存在"<<endl;
                return *this;
            }
            if (pos<0||pos>len) {
                cout<<"越界访问，插入失败！"<<endl;
                return *this;
            }else{
                char * temp = rep;
                rep = new char[len+strlen(s)+1];
                if (pos == 0) {
                    for (int i = 0; i<strlen(s); ++i) {
                        rep[i] = s[i-pos];
                    }
                    for (int j = (int)strlen(s); j<len+strlen(s); ++j) {
                        rep[j] = temp[j-strlen(s)];
                    }
                }
                if (pos>len) {
                    strcat(rep, s);
                }
                if (pos>0&&pos<=len) {
                    for (int i = 0; i<pos; ++i) {
                        rep[i] = temp[i];
                    }
                    for (int j = pos; j<pos+strlen(s); ++j) {
                        rep[j] = s[j-pos];
                    }
                    for (int k = pos+(int)strlen(s); k<len+strlen(s); ++k) {
                        rep[k] = temp[k-strlen(s)];
                    }
                }
                len += strlen(s);
                delete [] temp;
            }
            return *this;
        }
        //删除:erase可以指定位置删除内容
        String& erase(int pos, int n)
        {
            //erase...
            if (pos == 0) {
                for (int i = 0; i<n; ++i) {
                    rep[i] = '\0';
                }
                for (int j = n; j<len+n; ++j) {
                    rep[j-n] = rep[j];
                }
            }
            if (pos>len) {
                cout<<"越界访问，无法删除"<<endl;
            }
            if (pos>0&&pos<=len) {
                for (int i = 0; i<pos; ++i) {
                    rep[i] = rep[i];
                }
                for (int j = pos; j<pos+n; ++j) {
                    rep[j] = '\0';
                }
                for (int k = pos+n; k<len+n; ++k) {
                    rep[k-n] = rep[k];
                }
            }
            len -= n;
            return *this;
        }
        //erase:全部清除内容
        String& erase()
        {
            //erase...
            for (int i = 0; i<len; ++i) {
                rep[i]='\0';
            }
            len = 0;
            return *this;
        }
        //替换信息：删除后替换+添加原始位置之后的字符串
        String& replace(int pos, int n, const char * s)
        {
            //replace...
            char*p = rep;
            rep = new char[len-n+strlen(s)+1];
            if (pos == 0) {
                for (int i = 0; i<strlen(s); ++i) {
                    rep[i] = s[i];
                }
                for (int j = (int)strlen(s); j<len; ++j) {
                    rep[j] = p[j];
                }
            }
            if (pos>len) {
                cout<<"越界访问，无法替换"<<endl;
            }
            if (pos>0&&pos<=len) {
                for (int i = 0; i<pos; ++i) {
                    rep[i] = p[i];
                }
                for (int j = pos; j<pos+strlen(s); ++j) {
                    rep[j] = s[j-pos];
                }
                for (int k = pos+(int)strlen(s); k<len; ++k) {
                    rep[k-n] = p[k];
                }
            }
            len = len-n+(int)strlen(s);
            delete [] p;
            return *this;
        }

        //输出运算符重载
        friend ostream& operator<<(ostream&out,const String&s1);
    };
    ostream& operator<<(ostream&out,const String&s1)
    {
        out<<"字符个数："<<s1.len<<endl;
        out<<s1.rep<<endl;
        return out;
    }
};
#endif
