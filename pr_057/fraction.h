/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : fraction.h

* Purpose :

* Creation Date : 12-10-2011

* Last Modified : Wed 12 Oct 2011 01:05:07 PM EEST

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>

class Fraction
{
  private:
    void reduce();
  public:
    unsigned long long numerator;
    unsigned long long denominator;
    Fraction();
    Fraction(unsigned long long n,unsigned long long d);
    friend bool operator>(Fraction fr1,Fraction fr2);
    friend bool operator<(Fraction fr1,Fraction fr2);
    friend bool operator==(Fraction fr1,Fraction fr2);
    friend Fraction operator+(Fraction fr1,Fraction fr2);
    friend Fraction operator+(Fraction fr1,unsigned long long i);
    friend Fraction operator+(unsigned long long i,Fraction fr1);
    friend Fraction operator/(unsigned long long i,Fraction fr1);
    friend std::ostream& operator<<(std::ostream& cout,Fraction ob);
};
