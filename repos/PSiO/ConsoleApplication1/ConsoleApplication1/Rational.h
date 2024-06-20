#pragma once
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Rational {
public:
    Rational(int num = 0, int den = 1); // default constructor

    void set(int num, int den); // sets numerator and denominator
    int num() const; // gets numerator
    int den() const; // gets denominator
    void set_num(int num); // sets numerator
    void set_den(int den); // sets denominator
    //it's always better to not change the local variable and return new variable basing on local variables passed through const 
    //reference. If not, then just use reference and return *this (without const!)
    Rational operator+(const Rational& rhs) const; // rhs - Right Hand Side - prawy operand
    Rational operator-(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    operator double() const;
    void print() const; // prints number to console
    friend ostream& operator<<(ostream& str, const Rational& rhs);
    friend istream& operator>>(istream& str, Rational& rhs);
private:
    int num_, den_;
};
