/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : main.cpp

* Purpose :

* Creation Date : 12-10-2011

* Last Modified : Wed 12 Oct 2011 01:51:22 PM EEST

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include "fraction.h"



Fraction den(unsigned long long i)
{
  if (i == 0)
  {
    return Fraction(2,1);
  }
  else
  {
    return 2+1/den(i-1);
  }
}

using namespace std;
int main()
{
  unsigned long long i=0,counter=0;
  Fraction a ;
  unsigned digits_num,digits_denom;
  for (i=0;i<100;i++)
  {
    a = 1+1/den(i);
    digits_num = floor(log10((double) a.numerator));
    digits_denom = floor(log10((double) a.denominator));
    if (digits_num > digits_denom)
    {
      cout << a <<" "<< digits_num <<" "<< digits_denom<< endl;
      counter++;
    }
  }
  cout << counter << endl;
  return 0;
}
