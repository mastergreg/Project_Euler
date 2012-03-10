#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Sat 10 Mar 2012 10:45:57 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from fractions import Fraction
from math import sqrt
from itertools import *

primes = [2]


def phi(n):
    global primes
    ans = n
    for i in primes:
        if i > n:
            break
        if n%i == 0:
            ans = (ans/i)*(i-1)
    return ans

def isPrime(n):
    global primes
    lim = sqrt(n)
    for i in primes:
        if i > lim:
            primes.append(i)
            return True
        if n%i == 0:
            return False
    primes.append(i)
    return True
def main():
    global primes
    limit = 100
    for i in ifilter(isPrime,xrange(3,limit,2)):
        print i



if __name__=="__main__":
  main()

