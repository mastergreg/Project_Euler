/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 03-06-2014
* Last Modified : Tue 03 Jun 2014 16:31:13 BST
* Created By : Greg Lyras <greglyras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/

#define MAX_POWER 10000

#include <map>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

int power_cache[MAX_POWER+1];
map<int, bool> checked;
map<int, bool> checked_small;

uint64_t calc_powers(int a, int b)
{
  uint64_t ans = 0;
  for(int i = a; i <= b; i++) {
    ans += power_cache[i];
  }
  return ans;
}

bool is_palindrome(uint64_t a)
{
  vector<int> digits;
  while(a) {
    digits.push_back(a % 10);
    a /= 10;
  }
  auto i = digits.cbegin();
  for(auto j = digits.crbegin(); i != digits.cend(); i++, j++) {
    if(*i != *j) {
      return false;
    }
  }
  return true;
}

void test_595(void)
{
  assert(calc_powers(6, 12) == 595);
}

void test_4164(void)
{
}

void test_palindrome(void)
{
  assert(is_palindrome(0) == true);
  assert(is_palindrome(1) == true);
  assert(is_palindrome(2) == true);
  assert(is_palindrome(3) == true);
  assert(is_palindrome(4) == true);
  assert(is_palindrome(5) == true);
  assert(is_palindrome(6) == true);
  assert(is_palindrome(7) == true);
  assert(is_palindrome(8) == true);
  assert(is_palindrome(9) == true);
  assert(is_palindrome(11) == true);
  assert(is_palindrome(22) == true);
  assert(is_palindrome(33) == true);
  assert(is_palindrome(44) == true);
  assert(is_palindrome(55) == true);
  assert(is_palindrome(66) == true);
  assert(is_palindrome(77) == true);
  assert(is_palindrome(88) == true);
  assert(is_palindrome(99) == true);
  assert(is_palindrome(101) == true);
  assert(is_palindrome(11) == true);
  assert(is_palindrome(1) == true);
  assert(is_palindrome(121) == true);
  assert(is_palindrome(131) == true);
  assert(is_palindrome(141) == true);
  assert(is_palindrome(151) == true);
  assert(is_palindrome(161) == true);
  assert(is_palindrome(171) == true);
  assert(is_palindrome(181) == true);
  assert(is_palindrome(191) == true);
  assert(is_palindrome(202) == true);
}

void test_small(void)
{
  uint64_t count = 0;
  for(auto i = 1; i <= 40; i++) {
    for(auto j = i+1; j <= 40; j++) {
      uint64_t n = calc_powers(i, j);
      if(n > 0 and n < 1000) {
        if(is_palindrome(n) and checked_small[n] == false) {
          count += n;
          checked_small[n] = true;
        }
      }
    }
  }
  assert(count == 4164);
}


void run_tests(void)
{
  test_595();
  test_4164();

  test_palindrome();

  test_small();
}

int main(int argc, char **argv)
{
  uint64_t count = 0;

  for(auto i = 1; i <= MAX_POWER; i++) {
    power_cache[i] = i*i;
  }
  cout << "cache built" << endl;

  if(argc == 2) {
    run_tests();
  }
  else {
    for(auto i = 1; i <= MAX_POWER; i++) {
      for(auto j = i+1; j <= MAX_POWER; j++) {
        uint64_t n = calc_powers(i, j);
        if(n > 0 and n < 100000000) {
          if(is_palindrome(n) and checked[n] == false) {
            count += n;
            checked[n] = true;
            cout << count << endl;
          }
        }
      }
    }
  }




  return 0;
}
