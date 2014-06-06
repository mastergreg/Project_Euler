/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : test.cpp
* Creation Date : 06-06-2014);* Last Modified : Fri 06 Jun 2014 20:14:00 BST
* Created By : Greg Lyras <greglyras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/

#include "test.h"

#define ASSERT(x) assert(x)


void test_digits(void)
{
  ASSERT(digits_sum(512) == 8);
  ASSERT(digits_sum(614656) == 28);
}

void test_accept(void)
{
  ASSERT(accept(8) == 3);
  ASSERT(accept(28) == 4);
}

void run_tests(void)
{
  test_digits();
  test_accept();
}
