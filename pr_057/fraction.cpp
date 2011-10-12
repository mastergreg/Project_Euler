/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : fraction.cpp

* Purpose :

* Creation Date : 12-10-2011

* Last Modified : Wed 12 Oct 2011 01:05:04 PM EEST

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include "fraction.h"

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
  unsigned long long buff;
  if (a > b)
  {
    buff = a;
    a = b;
    b = buff;
  }
  while(b !=0 )
  {
    buff = a;
    a = b;
    b = buff % b;
  }
  return a;
}


std::ostream& operator<<(std::ostream& cout,Fraction ob)
{
  cout << ob.numerator << " / " << ob.denominator;
  return cout;
}
Fraction::Fraction()
{
  numerator=0;
  denominator=1;
}
Fraction::Fraction(unsigned long long n,unsigned long long d)
{
  numerator=n;
  denominator=d;
  reduce();
}
bool operator>(Fraction fr1,Fraction fr2)
{
  return fr1.numerator*fr2.denominator > fr2.numerator*fr1.denominator;
}
bool operator<(Fraction fr1,Fraction fr2)
{
  return fr1.numerator*fr2.denominator < fr2.numerator*fr1.denominator;
}
bool operator==(Fraction fr1,Fraction fr2)
{
  return fr1.numerator*fr2.denominator == fr2.numerator*fr1.denominator;
}
void Fraction::reduce()
{
  unsigned long long c;
  while ((c=gcd(numerator,denominator))!=1)
  {
    numerator /=c;
    denominator /=c;
  }
}
Fraction operator+(Fraction fr1, Fraction fr2)
{
  return Fraction(fr1.numerator*fr2.denominator+fr2.numerator*fr1.denominator,fr1.denominator*fr2.denominator);
}
Fraction operator+(Fraction fr1, unsigned long long i)
{
  return Fraction(fr1.numerator+i*fr1.denominator,fr1.denominator);
}
Fraction operator+(unsigned long long i,Fraction fr1)
{
  return Fraction(fr1.numerator+i*fr1.denominator,fr1.denominator);
}
Fraction operator/(unsigned long long i,Fraction fr1)
{
  return Fraction(i*fr1.denominator,fr1.numerator);
}

