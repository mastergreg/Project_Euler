/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 03-06-2014
* Last Modified : Tue 03 Jun 2014 04:27:49 BST
* Created By : Greg Lyras <greglyras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/

#define MAX_POWER 1e6

#include <map>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

map<int, int> power_cache;

int calc_powers(int a, int b)
{
  int ans = 0;
  for(int i = a; i <= b; i++) {
    ans += i*i;
  }
  return ans;
}

bool is_palindrome(int a)
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

void run_tests(void)
{
  test_595();
  test_4164();

  test_palindrome();
}

int main(int argc, char **argv)
{
  if(argc == 1) {
    run_tests();
  }



  return 0;
}
