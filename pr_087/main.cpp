/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Fri 16 May 2014 08:08:52 PM BST
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

#define MAX_PRIME 50000000
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

  return 0;
}
