/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Fri 06 Jun 2014 20:25:23 BST
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

#define MAX_POW 20
#define MAX_TEST 100000

using namespace std;

uint64_t digits_sum(uint64_t a)
{
  vector<int> digits;
  uint64_t sum;
  while(a) {
    digits.push_back(a % 10);
    a /= 10;
  }

  sum = 0;
  for(auto i = digits.cbegin(); i != digits.cend(); i++) {
    sum+= *i;
  }
  return sum;
}

int accept(uint64_t a)
{
  for(auto i = 2; i < MAX_POW; i++) {
    uint64_t p = pow(a, i);
    uint64_t d = digits_sum(p);
    if(a == d) {
      return i;
    }
  }
  return 0;
}

int main(int argc, char **argv)
{
  if(argc == 2 and strcmp(argv[1], "test") == 0) {
    run_tests();
    exit(EXIT_SUCCESS);
  }

  auto count = 0;
  for(auto i = 2; count < 30 and i < MAX_TEST; i++) {
    auto a = accept(i);
    if(a != 0) {
      count++;
      cout << count << ": " << i << " to the " << a << " = " << pow(i, a) << endl;
    }
  }

  return 0;
}
