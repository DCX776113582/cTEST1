//
//  demo1.h
//  Chapter05_Demo1
//
//  Created by mac on 18/3/6.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef Chapter05_Demo1_demo1_h
#define Chapter05_Demo1_demo1_h

#include <iostream>
using namespace std;
//函数重载
/*void printArray(int *array,int size)//打印整型数组
 {
 for (int i = 0; i<size; ++i) {
 cout<<array[i]<<" ";
 if (i==size-1) {
 cout<<endl;
 }
 }
 }
 void printArray(float *array,int size)//打印浮点型数组
 {
 for (int i = 0; i<size; ++i) {
 cout<<array[i]<<" ";
 if (i==size-1) {
 cout<<endl;
 }
 }
 }
 void printArray(const char* *array,int size)//打印字符串数组
 {
 for (int i = 0; i<size; ++i) {
 cout<<array[i]<<" ";
 if (i==size-1) {
 cout<<endl;
 }
 }
 }
 */
//自定义函数模板:类型Mytype1是虚拟类型（不确定类型）——printArray函数模板
template <typename Mytype1>
void printArray(Mytype1 *array,int size) {
    for (int i = 0; i<size; ++i) {
        cout<<array[i]<<" ";
        if (i==size-1) {
            cout<<endl;
        }
    }
}
/*int maxNum(int a,int b)
 {
 return a>b?a:b;
 }
 float maxNum(float a,float b)
 {
 return a>b?a:b;
 }
 string maxNum(string a,string b)
 {
 return a>b?a:b;
 }
 */
template <typename T1>
T1 maxNum(T1 a,T1 b) {
    return a>b?a:b;
}
void testFunTemplate()
{
    const int max = 5;
    int iArray[max] = {10,20,30,40,50};
    float fArray[max] = {1.1,1.2,1.3,1.4,1.5};
    const char* cArray[max] = {"one","two","three","four","five"};
    for (int i = 0; i<max; ++i) {
        cout<<iArray[i]<<" ";
        if (i==max-1) {
            cout<<endl;
        }
    }
    for (int i = 0; i<max; ++i) {
        cout<<fArray[i]<<" ";
        if (i==max-1) {
            cout<<endl;
        }
    }
    for (int i = 0; i<max; ++i) {
        cout<<cArray[i]<<" ";
        if (i==max-1) {
            cout<<endl;
        }
    }
    cout<<endl;
    //被调用时，传递给函数模板真实数据类型时，编译器才会将模板实例化为一个具体的函数，实现函数的调用——模板函数。
    printArray(iArray, max);//发生在执行阶段
    printArray(fArray, max);
    printArray(cArray, max);
    cout<<endl;
    cout<<maxNum(10, 20)<<endl;
    cout<<maxNum(12.1f,12.13f)<<endl;
    cout<<maxNum("okk", "oKk")<<endl;
}
#include <stack>//栈类模板
//自定义类模板：通用的类
template <class T>
class Vector {
private:
    int size;
    T* rep;
    int index;
    int capacity;
public:
    Vector();
    void print();
    ~Vector();
    Vector<T>& push(T data);
    T& pop();
};
template <class T>//类模板：成员函数均为——函数模板
Vector<T>::Vector()
{
    capacity = 5;
    size = 0;
    rep = new T[size+1];
    for (int i = 0; i<size; ++i) {
        rep[i] = '\0';
    }
    index = 0;
}
template <class T>//类模板：成员函数均为——函数模板
void Vector<T>::print()
{
    if (size==0) {
        cout<<"容器为空"<<endl;
    }else{
        for (int i = 0; i<size; ++i) {
            cout<<rep[i]<<endl;
        }
    }
}
template <class T>//类模板：成员函数均为——函数模板
T& Vector<T>::pop()
{
    if (size<=0) {
        cout<<"容器已空"<<endl;
    }
    return rep[--size];
}
template <class T>
Vector<T>& Vector<T>::push(T data)
{
    if (size<capacity) {
        rep[size++] = data;
    }else{
        cout<<"容器已满"<<endl;
    }
    return *this;
}
template <class T>//类模板：成员函数均为——函数模板
Vector<T>::~Vector()
{
    if (rep!=NULL) {
        delete [] rep;
        rep = NULL;
    }
}
void testInt()
{
    //定义容器类
    Vector<int> v1;
    int iArray[5] = {10,20,30,40,50};
    //给容器 添加元素
    for (int i = 0; i < 5; ++i) {
        v1.push(iArray[i]);
    }
    v1.print();
    //移除容器元素
    for (int i = 0; i < 5; ++i) {
        cout<< v1.pop()<<endl;
    }
    v1.print();
}
void testFloat()
{
    //定义容器类
    Vector<float> v2;
    float fArray[5] = {1.1,1.2,1.3,1.4,1.5};
    //给容器 添加元素
    for (int i = 0; i < 5; ++i) {
        v2.push(fArray[i]);
    }
    v2.print();
    //移除容器元素
    for (int i = 0; i < 5; ++i) {
        cout<< v2.pop()<<endl;
    }
    v2.print();
}
void testStr()
{
    //定义容器类
    Vector<string> v3;
    string cArray[5] = {"one","two","three","four","five"};
    //给容器 添加元素
    for (int i = 0; i < 5; ++i) {
        v3.push(cArray[i]);
    }
    v3.print();
    //移除容器元素
    for (int i = 0; i < 5; ++i) {
        cout<< v3.pop()<<endl;
    }
    v3.print();
}
/*
 template <class T>
 class Stack 	//栈（存储不同类型的数据）：先进后出
 {
 public:
 Stack(int s = 100); //default constructor
 ~Stack() {delete [] stackPtr;} //destructor
 int push(const T&);	//往容器里面存数据
 int pop(T&);		//从容器里面取数据
 int isEmpty() const {return (top == -1);} //1 if empty
 int isFull() const {return (top == (size-1));} //1 if full
 void printOn(ostream& output);
 private:
 int size;	//栈中元素的个数
 int top; 	//栈顶的标记(以数组元素的下标)
 T *stackPtr;	//不确定类型的指针
 };
 template <class T>
 Stack<T>::Stack(int s) //default constructor
 {
 size = (s > 0 && s < 1000) ? s : 10;
 top = -1;
 stackPtr = new T[size];//size*sizeof(T)
 for (int i = 0; i<size; i++)
 {
 stackPtr[i]=NULL;
 }
 }
 template <class T>
 void Stack<T>::printOn(ostream& output)
 {
 output << "Stack( ";
 for (int i=0; i<=top; i++)
 {
 output << stackPtr[i] << ", ";
 }
 output << ")\n";
 }
 template <class T>
 int Stack<T>::push(const T& item)
 { //push
 if (!isFull())
 {
 stackPtr[++top] = item;
 return 1; //push successful
 }
 
 return 0; //push unseccessful
 }
 template <class T>
 int Stack<T>::pop(T& item)
 { //pop
 if (!isEmpty())
 {
 item = stackPtr[top--];
 return 1; //pop successful
 }
 return 0; //pop unseccessful
 }
 void testStack()
 {
 //通过类模板实例化一个具体的类（模板类）：Stack<int>，通过具体的类创建一个对象stack
 Stack<int> stack;
 for (int i=0; i<5; i++)
 {
 stack.push(i*10);	//0  10  20  30 40
 stack.printOn(cout);
 }
 Stack<float> stack1;//用类模板来实例化具体的类（模板类）来实例化对象
 for (int i=0; i<5; i++)
 {
 stack1.push(i*1.1);
 stack1.printOn(cout);
 }
 const char *cArray[5] = {"one", "two", "three", "four", "five"};
 Stack<const char*> stack2;	//用类模板来实例化具体的类（模板类）来实例化对象
 for (int i=0; i<5; i++)
 {
 stack2.push(cArray[i]);
 stack2.printOn(cout);
 }
 }
 */
template <class T, int max_size>
class Stack {
public:
    Stack(); //default constructor
    ~Stack() {delete [] stackPtr;} //destructor
    int push(const T&);
    int pop(T&);
    int isEmpty() const {return top == -1;} //1 if empty
    int isFull() const {return top == size - 1;} //1 if full
    void printOn(ostream& output);
private:
    int size;
    int top;
    T *stackPtr;
};
template <class T, int max_size>
Stack<T, max_size>::Stack()
{ //default constructor
    size = max_size;
    top = -1;
    stackPtr = new T[size];
}
template <class T, int max_size>
void Stack<T, max_size>::printOn(ostream& output)
{
    output << "Stack( ";
    for (int i=0; i<=top; i++)
    {
        output << stackPtr[i] << ", ";
    }
    output << ")\n";
}
template <class T, int max_size>
int Stack<T, max_size>::push(const T& item)
{ //push
    if (!isFull())
    {
        stackPtr[++top] = item;
        return 1; //push successful
    } else {
        cout<<"stack is full!"<<endl;
        return 0;
    }
    return 0; //push unseccessful
}
template <class T, int max_size>
int Stack<T, max_size>::pop(T& item)
{ //pop
    if (!isEmpty())
    {
        item = stackPtr[top--];
        return 1; //pop successful
    } else {
        cout<<"stack is empty!"<<endl;
        return 0;
    }
    return 0; //pop unseccessful
}

void testStack2()
{
    Stack<float, 5> stack;
    for (int i=0; i<6; i++)
    {
        stack.push(i*1.1);
        stack.printOn(cout);
    }
    for (int i = 0; i < 6; ++i) {
        float f;
        stack.pop(f);
        cout<<f<<" output from stack!"<<endl;
        cout<<"stack now is: ";
        stack.printOn(cout);
        if (stack.isEmpty())
        {
            stack.pop(f);
            return;
        }
    }
}

#endif
