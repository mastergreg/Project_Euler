#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Fri 09 Mar 2012 03:08:36 AM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from fractions import Fraction
from math import sqrt
from itertools import ifilterfalse

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
            return True
        if n%i == 0:
            return False
    return True
def main():
    global primes
    k=(30030,5760)
    limit = 1000001
    for i in xrange(3,limit,2):
        if isPrime(i):
            primes.append(i)
    for i in xrange(30031,limit,2):
        nk = (i,phi(i))
        print i,nk,k
        if k[0]*nk[1] < k[1]*nk[0]:
            k = nk
    print k




if __name__=="__main__":
  main()

