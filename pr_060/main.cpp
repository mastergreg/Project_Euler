/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Sun 11 May 2014 05:09:25 AM EEST
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

#define MAX_PRIME 10000

using namespace std;

list<int> primes;
map<int, bool> primes_check;

map<int, map<int, bool> > pairs;
map<int, list<int> > pair_values;

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

inline int int_concat(int a, int b)
{
  return a+b*pow(10, ceil(log10(a)));
}

inline bool accept(int a, int b)
{
  return is_prime(int_concat(a,b)) && is_prime(int_concat(b,a));
}

bool accept(int x, int y, int z, int w)
{
  return accept(x, y) && accept(x, z) && accept(x, w) && accept(y, z) && accept(y, w) && accept(z, w);
}

/* checks only the last value against the previous ones */
bool cached_accept(int x, int y)
{
  return pairs[x][y];
}

/* checks only the last value against the previous ones */
bool cached_accept(int x, int y, int z)
{
  return pairs[x][z] && pairs[y][z];
}

/* checks only the last value against the previous ones */
bool cached_accept(int x, int y, int z, int w)
{
  return pairs[x][w] && pairs[y][w] && pairs[z][w];
}


int main(void)
{
  primes.push_back(2);
  primes_check[2] = true;
  for(int i = 3; i < MAX_PRIME; i+=2)
  {
    if(is_prime(i))
    {
      primes.push_back(i);
      primes_check[i] = true;
    }
  }
  cout << primes.size() << endl;
  assert(accept(3, 7) == true);
  assert(accept(3, 109) == true);
  assert(accept(3, 673) == true);
  assert(accept(7, 109) == true);
  assert(accept(7, 673) == true);
  assert(accept(109, 673) == true);


  for(int x : primes) {
    for(int y : primes) {
      if(x < y && accept(x, y)) {
        pair_values[x].push_back(y);
        pairs[x][y] = true;
      }
    }
  }

  cout << primes.size() << endl;

  assert(cached_accept(2, 7) == false);
  assert(cached_accept(3, 7) == true);
  assert(cached_accept(3, 109) == true);
  assert(cached_accept(3, 673) == true);
  assert(cached_accept(7, 109) == true);
  assert(cached_accept(7, 673) == true);
  assert(cached_accept(109, 673) == true);

  for(pair<int, list<int> > x : pair_values) {
    if(x.second.size() >= 4) {
      for(int y : x.second) {
        for(int z : x.second) {
          if(z > y && cached_accept(y, z)) {
            for(int w : x.second) {
              if(w > z && cached_accept(y, z, w)) {
                for(int v : x.second) {
                  if(v > w && cached_accept(y, z, w, v)) {
                    cout << x.first << " " << y << " " << z << " " << w << " " << v << endl;
                    cout << x.first + y + z + w + v << endl;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
