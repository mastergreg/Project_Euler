/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 04-10-2011

 * Last Modified : Tue 04 Oct 2011 07:28:56 PM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

bool is_trig(unsigned long long t);
bool is_pentagonal(unsigned long long p);
bool is_hexagonal (unsigned long long h);
unsigned long long triangle(unsigned long long n);
unsigned long long pentagonal(unsigned long long n);
unsigned long long hexagonal (unsigned long long n);

using namespace std;

int main()
{
  unsigned long long i;
  unsigned long long nhex=0;
  for (i=144;;i++)
  {
    cout << i << "\t" << nhex << "\r" << flush;
    nhex = hexagonal(i);
    if(is_pentagonal(nhex))
    {
      if (is_trig(nhex))
      {
        cout << endl << nhex << endl;
        return 0;
      }
    }

  }
}

bool is_pentagonal(unsigned long long p)
{
  double n = (1+sqrt(24*p+1))/6.;
  if (n == (unsigned long long) n)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool is_hexagonal (unsigned long long h)
{
  double n = (1+sqrt(8*h+1))/4.;
  if (n == (unsigned long long) n)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool is_trig (unsigned long long t)
{
  double n = (-1+sqrt(8*t+1))/2.;
  if (n == (unsigned long long) n)
  {
    return true;
  }
  else
  {
    return false;
  }

}
unsigned long long triangle(unsigned long long n)
{
  return n*(n+1)/2;
}

unsigned long long pentagonal(unsigned long long n)
{
  return n*(3*n-1)/2;
}
unsigned long long hexagonal(unsigned long long n)
{
  return n*(2*n-1);
}
