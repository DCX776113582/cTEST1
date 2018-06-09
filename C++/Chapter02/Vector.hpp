//
//  Vector.h
//  Chapter02
//
//  Created by mac on 18/2/5.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter02__Vector__
#define __Chapter02__Vector__

#include <iostream>
using namespace std;
class Boy;
class Vector
{
public:
    int *rep;
    int size;
public:
    Vector(int s, int array[]);
    ~Vector();
public:
    int getSize()const{return size;}
    const int& getRep()const{return *rep;}
    const Vector& operator=(const Vector& x);
    void print();
};
class Integer
{ public:
    Integer(int ival) : value(ival) {}
    Integer(const Integer& iobj) : value(iobj.value) {}
    // operator int() { return value; } //conversion to built-in int
    Integer operator+() const { return Integer(value); }
    Integer operator-() const { return Integer(-value); }
    Integer operator+(const Integer& rhs) const { return Integer(value + rhs.value); }
    Integer operator-(const Integer& rhs) const { return Integer(value - rhs.value); }
    Integer operator*(const Integer& rhs) const { return Integer(value * rhs.value); }
    Integer operator/(const Integer& rhs) const { return Integer(value / rhs.value); }
    Integer operator%(const Integer& rhs) const { return Integer(value % rhs.value); }
    // prefix
    Integer operator++() { return Integer(++value); }
    Integer operator--() { return Integer(--value); }
    // suffix
    Integer operator++(int) { int old = value; value++; return Integer(old); }
    Integer operator--(int) { int old = value; value--; return Integer(old); }
    // compare:
    bool operator<(const Integer& rhs) const { return value < rhs.value; }
    bool operator>(const Integer& rhs) const { return value > rhs.value; }
    bool operator==(const Integer& rhs) const { return value == rhs.value; }
    bool operator!=(const Integer& rhs) const { return value != rhs.value; }
    bool operator<=(const Integer& rhs) const { return value <= rhs.value; }
    bool operator>=(const Integer& rhs) const { return value >= rhs.value; }
    // bit operations:
    Integer operator~() const { return Integer(~value); }
    Integer operator<<(unsigned n) const { return Integer(value << n); }
    Integer operator>>(unsigned n) const { return Integer(value >> n); }
    Integer operator&(const Integer& rhs) const { return Integer(value & rhs.value); }
    Integer operator|(const Integer& rhs) const { return Integer(value | rhs.value); }
    Integer operator^(const Integer& rhs) const { return Integer(value ^ rhs.value); }
    // assignment:
    Integer operator=(const Integer& rhs) { return value = rhs.value; }
    // compound assignment:
    Integer operator+=(const Integer& rhs) { return value += rhs.value; }
    Integer operator-=(const Integer& rhs) { return value -= rhs.value; }
    Integer operator*=(const Integer& rhs) { return value *= rhs.value; }
    Integer operator/=(const Integer& rhs) { return value /= rhs.value; }
    Integer operator%=(const Integer& rhs) { return value %= rhs.value; }
    Integer operator&=(const Integer& rhs) { return value &= rhs.value; }
    Integer operator|=(const Integer& rhs) { return value |= rhs.value; }
    Integer operator^=(const Integer& rhs) { return value ^= rhs.value; }
    Integer operator<<=(const Integer& rhs) { return value <<= rhs.value; }
    Integer operator>>=(const Integer& rhs) { return value >>= rhs.value; }
    void print(){cout<<value<<endl;}
private:
    int value; };
template <typename T>
class Pointer
{
public:
    Pointer() : ptr_(0) {} Pointer(T* ptr) : ptr_(ptr) {}
    // operator T*() { return ptr_; } // implicit conversion.
    T* get() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const {
        return ptr_;
        printf("operator->()\n");
    }
    T& operator[](int offset) const { return ptr_[offset]; }
    Pointer<T> operator++() { return Pointer(++ptr_); } // prefix Pointer<T> operator--() { return Pointer(--ptr_); } // prefix
    Pointer<T> operator++(int) { return Pointer(ptr_++); } // suffix Pointer<T> operator--(int) { return Pointer(ptr_--); } // suffix
    Pointer<T> operator+=(int off) { return Pointer(ptr_ += off); }
    Pointer<T> operator-=(int off) { return Pointer(ptr_ -= off); }
    Pointer<T> operator+(int off) const { return Pointer(ptr_ + off); }
    Pointer<T> operator-(int off) const { return Pointer(ptr_ - off); }
private:
    T * ptr_;
};
#endif /* defined(__Chapter02__Vector__) */
