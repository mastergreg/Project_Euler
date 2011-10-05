/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 04-10-2011

 * Last Modified : Tue 04 Oct 2011 06:36:18 PM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

int pentagonal(int n);
bool is_pentagonal(int p);

using namespace std;

int main()
{
  int i,j;
  unsigned long long suma , dif , minima = -1;
  int pI,pJ;
  for (i = 1 ; i <= 100000 ; i++)
  {
    for (j=1 ; j < i ; j ++)
    {
      pI = pentagonal(i);
      pJ = pentagonal(j);
      suma = pI + pJ;
      if (is_pentagonal(suma))
      {
        dif = pI - pJ;
        if (is_pentagonal(dif))
        {
          if (dif < minima)
          {
            minima = dif;
            cout << minima << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << minima << endl;

}

bool is_pentagonal(int p)
{
  double n = (1+sqrt(24*p+1))/6.;
  if (n == (int) n)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int pentagonal(int n)
{
  return n*(3*n-1)/2;
}
