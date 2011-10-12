/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 10-10-2011

 * Last Modified : Tue 11 Oct 2011 10:10:19 AM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <algorithm>
#include <deque>


#define NUM_LIMIT 15499
#define DENOM_LIMIT 94744

using namespace std;
class Fraction
{
  public:
    unsigned long long numerator;
    unsigned long long denominator;
    Fraction();
    Fraction(unsigned long long n,unsigned long long d);
    friend bool operator>(Fraction fr1,Fraction fr2);
    friend bool operator<(Fraction fr1,Fraction fr2);
    friend bool operator==(Fraction fr1,Fraction fr2);
    friend ostream& operator<<(ostream& cout,Fraction ob);
};

ostream& operator<<(ostream& cout,Fraction ob)
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


bool is_resilient( unsigned long long b , unsigned long long a)
{
  unsigned long long buff;
  while(b !=0 )
  {
    buff = a;
    a = b;
    b = buff % b;
  }
  if (a==1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Fraction resilience(unsigned long long i)
{
  unsigned long long c,j;
  c=1;
  for (j=2;j<i;j++)
  {
    if (is_resilient(j,i))
    {
      c++;
    }
  }
  return Fraction(c,j);

}
int main()
{
  Fraction r;
  Fraction limit = Fraction(NUM_LIMIT,DENOM_LIMIT);
  cout << limit << endl;
  unsigned long long i;

  for (i=115987;;i++)
  {
    r = resilience(i);
    cout << i << "\r" << flush;
    if (r<limit)
    {
      cout << endl <<r << " " << i << endl;
      break;
    }
  }

  return 0;
}
