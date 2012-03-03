#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 10-10-2011
#
#* Last Modified : Sat 03 Mar 2012 08:12:38 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from fractions import gcd

from math import sqrt


def resilience(denum):
    old = denum
    counter = 0
    i = 2
    while i < denum:
        if denum % i == 0:
            denum /= i
            counter += denum
        i+=1
    return (old-counter,old-1)




def main():
  limit = (15499,94744)
  i = 2
  print resilience(12)
  #while not resilience(i,limit):
  #  (k,l) = resilience(i)
  #  if k*l1 < l*l0:
  #    return 0
  #  i**=2
  #  print i," noth"

if __name__=="__main__":
  main()

