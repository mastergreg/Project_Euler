#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 10-10-2011
#
#* Last Modified : Mon 10 Oct 2011 08:23:03 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from fractions import Fraction , gcd


def is_resilient(num,denum):
  return gcd(num,denum)==1

def resilience(denum):
  counter = 0
  for i in range(1,denum):
    if is_resilient(i,denum):
      counter+=1
  return Fraction(counter,denum-1)


def main():
  limit = Fraction(15499,94744)
  i = 94744;
  while True:
    if resilience(i)<limit:
      return 0
    print i
    i+=1

if __name__=="__main__":
  main()

