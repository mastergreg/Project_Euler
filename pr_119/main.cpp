/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Sun 08 Jun 2014 03:53:44 AM BST
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
#include <gmp.h>

#include "test.h"

#define MAX_N 256
#define MAX_POW MAX_N
#define MAX_TEST MAX_N

using namespace std;

char *my_powl(uint64_t a, uint32_t i)
{
  mpz_t rop;
  mpz_init(rop);
  mpz_ui_pow_ui(rop, a, i);
  char *ans = mpz_get_str(NULL, 10, rop);
  mpz_clear(rop);
  return ans;
}

uint64_t digits_sum(char *a)
{
  uint64_t sum;
  sum = 0;
  while(*a != '\0') {
    sum += *a - '0';
    a++;
  }
  return sum;
}

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
    sum += *i;
  }
  return sum;
}

int accept(uint64_t a)
{
  for(auto i = 2; i < MAX_POW; i++) {
    char *p = my_powl(a, i);
    uint64_t d = digits_sum(p);
    delete p;
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

  for(auto i = 2; i < MAX_TEST; i++) {
    auto p = accept(i);
    if(p != 0) {
      cout << i << "^" << p << " = " << my_powl(i, p) << endl;
    }
  }

  return 0;
}
