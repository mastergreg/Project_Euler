/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 18-10-2011

 * Last Modified : Tue 18 Oct 2011 08:44:14 PM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/
#include <iostream>
#include <cmath>
using namespace std;
unsigned long long solve(int D);
bool is_sq(int D);

int main()
{
  long long m = 0;
  int mD = 0;
  long long temp = 0;
  int d=0;
  for (d=1;d<1000;d++)
  {
    if (is_sq(d))
    {
      continue;
    }
    else
    {
      cout << d << endl;
      temp = solve(d);
      if (temp> m)
      {
        mD = d;
        m = temp;
        cout << m << endl;
      }
    }
  }


}
bool is_sq(int D)
{
  double sq = sqrt(D);
  if (sq == (int) sq)
  {
    return true;
  }
  else
  {
    return false;
  }
}
unsigned long long solve(int D)
{
  unsigned long long x=1;
  unsigned long long y=1;
  unsigned long long f=1;
  unsigned long long counter=0;

  while(f != 0 && counter < 10000000000)
  {

    f = x - D*y - 1;
    if (f > 0)
    {
      y=(x-1)/D;
    }
    else if (f < 0)
    {
      x=-f-x;
    }
    counter++;
  }
  cout <<  D << " " << x << endl;
  return x;
}
