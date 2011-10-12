#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 04-10-2011
#
#* Last Modified : Wed 05 Oct 2011 01:45:03 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import itertools
from math import sqrt
def all_pandigital(n):
  digit_list = ['1','2','3','4','5','6','7','8','9']
  return list(itertools.permutations(digit_list[:n]))

def is_prime(integer):
  for i in range(2,int(sqrt(integer))+1):
    if integer % i == 0:
      return False
  return True

def main():
  for n in range(9,1,-1):
    allPan = all_pandigital(n)
    print n , len(allPan)
    for i in range(len(allPan)-1,0,-1):
      curr = int("".join(allPan[i]))
      if is_prime(curr):
        print "Found it > ",curr
        return 0

if __name__=="__main__":
  main()

