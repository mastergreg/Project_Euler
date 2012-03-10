#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Sat 10 Mar 2012 10:58:25 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from fractions import Fraction
from math import sqrt
from itertools import *

primes = []


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
            primes = ifilter(lambda x: x%n == 0 and x>n,primes)
            return True
        if n%i == 0:
            primes = ifilter(lambda x: x%n == 0 ,primes)
            return False
    primes = ifilter(lambda x: x%n == 0 and x>n,primes)
    return True

def main():
    limit = 1000000
    global primes
    primes = xrange(2,limit)
    for i in ifilter(isPrime,xrange(3,limit,2)):
        print i



if __name__=="__main__":
  main()

