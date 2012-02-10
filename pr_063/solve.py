#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Mon 06 Feb 2012 12:32:37 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from math import *


def nth_power_n_digits(i):
  if log10(pow(2,i))+1>i :
    return False
  t = 1.0
  j = 1
  for j in range(1,10):
    t = pow(j,i)
    if (log10(t) + 1) >= i:
      return True

def has_power(num):
    i=1
    while(int(ceil(log10(i**num)))<num and i<=10 ):
        i=i+1

    if (int(ceil(log10(i**num))) == num ):
        return True
    else:
        return False


def main():
    k=0
    for i in range(10000):
        if(has_power(i)):
            k=k+1
    print k


if __name__=="__main__":
  main()

