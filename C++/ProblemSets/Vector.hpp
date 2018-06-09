//
//  Vector.h
//  ProblemSets
//
//  Created by mac on 18/2/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __ProblemSets__Vector__
#define __ProblemSets__Vector__

#include <iostream>
using namespace std;
class Person;
class PersonSet {
private:
    Person ** _elements;
    int _capacity;
    int _size;
    int _index;
    char*name;
public:
    
    PersonSet (int initial_size = 0);
    PersonSet(const PersonSet&q1);
    ~ PersonSet (void)
    {}
public:
    friend ostream& operator<<(ostream& out,PersonSet& cp1);
//    friend istream& operator>>(istream& out,PersonSet& cp1);
public:
    Person**getELE()
    {
        return _elements;
    }
    int& getSize()
    {
        return _size;
    }
    int& getInde()
    {
        return _index;
    }
    char*getNAME()
    {
        return name;
    }
    void setName(char*nam){
        if (strlen(name)<strlen(nam)) {
            delete []name;
            name=new char[strlen(nam)+1];
            strcpy(name, nam);
        }else{
            strcpy(name, nam);
        }
    }
    void setELE(Person* q1)
    {
        *_elements=q1;
    }
    void AddElement(Person & element) ;
    Person & NextElement();
    Person & RemoveElement();
    Person & RemoveElement( int index );
    int Size()const;
    void Print()const;
    void Print();
    void Reset(){
        this->_capacity=0;
    }
    Person& operator[](int offset)
    {
        return *_elements[offset];
    }
};
void CReat();
#endif /* defined(__ProblemSets__Vector__) */
