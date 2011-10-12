#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 12-10-2011
#
#* Last Modified : Wed 12 Oct 2011 02:05:28 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys
sys.setrecursionlimit(1500)
from fractions import Fraction
from math import log10
def den(i):
  if i==0:
    return Fraction(2,1)
  else:
    return 2+1/den(i-1)


def main():
  counter=0
  for i in range(1000):
    print i
    a = 1+1/den(i)
    numd = int(log10(a.numerator))
    denomd = int(log10(a.denominator))
    if numd > denomd:
      counter+=1
  print counter

if __name__=="__main__":
  main()

