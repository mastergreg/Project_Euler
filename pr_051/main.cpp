/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Fri 16 May 2014 02:17:38 PM BST
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

#define MAX_PRIME 1000000
#define FAMILY_TARGET 7

using namespace std;

list<int> primes;
map<int, bool> primes_check;

map<int, map<int, list<int> > > masks;

bool is_prime(int i)
{
  if(primes.back() >= i) {
    return primes_check[i];
  }
  else {
    for(int p : primes) {
      if(i % p == 0) {
        return false;
      }
      else if(p >= sqrt(i)) {
        return true;
      }
    }
    return true;
  }
}

int match(int a, int b)
{
  int d = 0;
  int tmp = 0;
  int diff = abs(a - b);
  if(a < 10 || b < 10 || a == b || ceil(log10(a)) != ceil(log10(b))) {
    return 0;
  }
  while(a > 0 && b > 0) {
    int ta = a % 10;
    int tb = b % 10;

    if((tmp = ta - tb) != 0) {
      if(d == 0) {
        d = tmp;
      }
      else if (d != tmp) {
        return 0;
      }
    }

    a /= 10;
    b /= 10;
  }

  return diff / d;
}

int topD(int a, int b)
{
  int diff = abs(a - b);
  int d = diff / (pow(10, ((int) log10(diff))));
  return d;
}

int main(void)
{
  primes.push_back(2);
  primes_check[2] = true;
  for(int i = 3; i < MAX_PRIME; i+=2) {
    if(is_prime(i)) {
      primes.push_back(i);
      primes_check[i] = true;
    }
  }
  cout << primes.size() << endl;

  assert(match(1111, 1001) == 110);
  assert(match(1111, 1421) == 0);

  primes.remove_if([](int n){ return n < 100000; });
  cout << primes.size() << endl;

  for(int x : primes) {
    cout << x << "\r" << flush;
    for(int y : primes) {
      int msk = match(x, y);
      if(msk > 0) {
        masks[x][msk].push_back(y);
        masks[y][msk].push_back(x);
        if(masks[x][msk].size() >= FAMILY_TARGET || masks[x][msk].size() >= FAMILY_TARGET) {
          cout << endl << "Found " << x << " " << y << endl;
          cout << *min_element(masks[x][msk].cbegin(), masks[x][msk].cend()) << endl;
          for(int i : masks[x][msk]) {
            cout << i << ", ";
          }
          cout << "Mask: " << match(x, y) << endl;
        }
      }
    }
  }


  return 0;
}
