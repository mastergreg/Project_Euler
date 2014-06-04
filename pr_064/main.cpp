/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Mon 12 May 2014 09:56:27 AM EEST
* Created By : Greg Lyras <greglyras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <cmath>
#include <cassert>

#define L 1500000

using namespace std;


class fraction {
  protected:
    int num;
    int denom;
    static inline int gcd(int a, int b);
  public:
    fraction(void);
    fraction(int a, int b);
    fraction &operator+(const fraction &a);
    void simplify(void);
    void inverse(void);
};

void fraction::inverse(void)
{
  int temp = denom;
  denom = num;
  num = temp;
}

fraction & fraction::operator+(const fraction &a)
{
  num = num*a.denom + a.num*denom;
  denom *= a.denom;
  return *this;
}

void fraction::simplify(void)
{
  int g = gcd(num, denom);
  num /= g;
  denom /= g;
}

fraction::fraction(void)
{
}

fraction::fraction(int a, int b)
{
  num = a;
  denom = b;
  simplify();
}

inline int fraction::gcd(int a, int b)
{
  int temp = 0;
  if(a < b) {
    temp = a;
    a = b;
    b = temp;
  }
  while(b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

class continued_fraction : public fraction {
  private:
    list<int> integer;
    void simplify(void);
  public:
    continued_fraction(double a);
    void continuation(void);
};

continued_fraction::continued_fraction(double a)
{
  int cnt;
  integer.push_back((int) a);
  cnt = 1;
  a -= (int) a;
  while(fmod(a, 1) != 0)
  {
  cout << (int) a << " " << a << endl;
    a*=10;
    cnt *=10;
  }
  num = a;
  denom = cnt;
  simplify();
}

void continued_fraction::simplify(void)
{
  fraction::simplify();
  if(num > denom) {
    integer.push_back(num/denom);
    num -= denom * integer.back();
  }
}

void continued_fraction::continuation(void)
{
  while(num != 0)
  {
    inverse();
    simplify();
  }
}


int main(void)
{
  continued_fraction(3.245);
  return 0;
}
