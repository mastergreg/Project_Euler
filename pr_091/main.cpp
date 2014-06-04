/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Sun 11 May 2014 08:42:27 PM EEST
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

map<int, int> right_triangles;

inline int gcd(int a, int b)
{
  int temp;
  while(b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main(void)
{
  assert(gcd(12, 8) == 4);
  assert(gcd(7, 3) == 1);
  for(int m = 1; m < 866; m++) {
    for(int n = 1; n < m; n++) {
      if(((m - n) % 2 == 1) && gcd(m, n) == 1) {
        int p = 2 * m * (m + n);
        int new_p = p;
        while(new_p <= L) {
          cout << new_p << endl;
          right_triangles[new_p]++;
          new_p += p;
        }
      }
      else {
        cout << "Discarded" << endl;
      }
    }
  }
  cout << endl;
  int count = 0;
  for(pair<int, int> perim : right_triangles) {
    if(perim.second == 1) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
