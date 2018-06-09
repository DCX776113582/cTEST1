//
//  Vector.cpp
//  ProblemSets
//
//  Created by mac on 18/2/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Vector.hpp"
#include "Person.hpp"
extern Person r1;
PersonSet::PersonSet (int initial_size):_size(initial_size),_capacity(0),_index(0)
{
    name=new char[strlen("name")+1];
    strcpy(name, "name");
    _elements=new Person*[_size];
    for (int i = 0; i<_size; ++i) {
        _elements[i]=NULL;
    }
}
PersonSet::PersonSet(const PersonSet&q1):_size(q1._size),_capacity(q1._capacity),_index(q1._index)
{
    Person a;
    name=new char[strlen(q1.name)+1];
    strcpy(name, q1.name);
    _elements=new Person*[q1._size];
    *_elements=&a;
}
void PersonSet:: AddElement( Person& aPerson ) {
    
    if ( _size == _capacity ) {
        Person** temp = _elements;
        _elements = new Person*[_capacity*2];
        for( int i=0; i<_size; i++ )
        {
            _elements [i] = temp[i];
        }
        _capacity*= 2;
        delete [] temp;
    }
    _elements[_size+1] = &aPerson;
}
Person & PersonSet::NextElement()
{
    if (_index==_size) {
        _index=0;
    }
    return *_elements[_index++];
}
Person& PersonSet::RemoveElement(int index) {
    _size--;
    Person* p = _elements[_size]; //shrink the container
    if(_size < _capacity/2)
    {
        cout << "shrinking\n";
        Person** temp = _elements;
        _elements = new Person*[_capacity/2];
        for ( int i=0; i<_size; i++ )
        {
            _elements [i] = temp[i];
        }
        _capacity /= 2;
        delete [] temp;
        for (int i =_index-1; i<_size-1; ++i) {
            _elements[i]=_elements[i+1];
        }
    }
    _size--;
    return *p;
}
Person& PersonSet::RemoveElement() {
    _size--;
    Person* p = _elements[_size]; //shrink the container
    if(_size < _capacity/2)
    {
        cout << "shrinking\n";
        Person** temp = _elements;
        _elements = new Person*[_capacity/2];
        for ( int i=0; i<_size; i++ )
        {
            _elements [i] = temp[i];
        }
        _capacity /= 2;
        delete [] temp;
    }
    return *p;
}
int PersonSet::Size()const
{
    return _size;
}
void PersonSet::Print()const
{
    cout<<this->_elements<<endl;
    cout<<this->_capacity<<endl;
    cout<<this->_index<<endl;
    cout<<this->_size<<endl;
}
void PersonSet::Print()
{
    cout<<this->_elements<<endl;
    cout<<this->_capacity<<endl;
    cout<<this->_index<<endl;
    cout<<this->_size<<endl;
}
ostream& operator<<(ostream& out,PersonSet& cp1)
{
    for (int i= 0; i<cp1._size; ++i) {
       out<<"编号:"<<cp1._size<<cp1._elements[i]<<endl;
    }
    return out;
}
//istream& operator>>(istream& in,PersonSet& cp1)
//{in>>cp1._elements;
//    return in;}
void CReat()
{
    PersonSet p1;
}
