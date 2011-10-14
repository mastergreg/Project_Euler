/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : main.cpp

* Purpose :

* Creation Date : 13-10-2011

* Last Modified : Thu 13 Oct 2011 06:23:53 PM EEST

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int i)
{
  int limit = floor(sqrt(i));
  int j;
  for (j = 2;j<=limit;j++)
  {
    if (i % j == 0)
    {
      return false;
    }
  }
  return true;

}

int main()
{
  int i=3,j=3,found=0,ratio;

  while (true)
  {
    for(;j<i*i;j+=i-1)
    {
      if (is_prime(j))
      {
        found++;
      }
    }
    ratio = (100*found) / (2*i-1);
    if (ratio < 10)
    {
      cout << i << endl;
      break;
    }
    i+=2;
  }

  return 0;
}
