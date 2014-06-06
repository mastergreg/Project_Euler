/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Fri 06 Jun 2014 19:27:13 BST
* Created By : Greg Lyras <greglyras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <cmath>
#include <cstring>

#include "test.h"

#define MAX_PRIME 10000
#define MAX_CEIL 50000000
#define SND_CEIL 7072
#define THRD_CEIL 869
#define FRTH_CEIL 85

using namespace std;

list<int> primes;
map<int, bool> primes_check;
map<int, bool> checked;

map<int, map<int, list<int> > > masks;

bool is_prime(int i)
{
  if(primes.back() >= i) {
    return primes_check[i];
  }
  else {
    for(auto p : primes) {
      if(i % p == 0) {
        return false;
      }
      else if(p >= sqrt(i)) {
        primes_check[i] = true;
        return true;
      }
    }
    primes_check[i] = true;
    return true;
  }
}



int main(int argc, char **argv)
{
  primes.push_back(2);
  primes_check[2] = true;
  for(int i = 3; i < MAX_PRIME; i+=2) {
    if(is_prime(i)) {
      primes.push_back(i);
    }
  }

  if(argc == 2 and strcmp(argv[1], "test") == 0) {
    run_tests();
    exit(EXIT_SUCCESS);
  }

  cout << primes.size() << endl;
  int count = 0;

  for(auto x : primes) {
    if(x <= SND_CEIL) {
      for(auto y : primes) {
        if(y <= THRD_CEIL) {
          for(auto z : primes) {
            if(z <= FRTH_CEIL) {
              uint64_t sum = x*x + y*y*y + z*z*z*z;
              if(sum > 0 and sum < MAX_CEIL and checked[sum] == false) {
                checked[sum] = true;
                count++;
                cout << x << " " << y << " " << z << " " << sum << endl;
              }
            }
          }
        }
      }
    }
  }
  cout << count << endl;

  return 0;
}
