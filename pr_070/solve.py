#!/usr/bin/python3
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#* File Name : solve.py
#* Purpose :
#* Creation Date : 14-10-2011
#* Last Modified : Sun 22 Jul 2012 11:09:08 PM EEST
#* Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/


from fractions import Fraction
from math import sqrt

primes = []


def phi(n):
    global primes
    accepted = filter(lambda x: n%x == 0 and x < n, islice(primes,n))
    ans = n
    for i in accepted:
        ans = (ans/i)*(i-1)
    return ans

def isPrime(n):
    global primes
    lim = sqrt(n)
    for i in primes:
        if i > lim:
            primes = filter(lambda x: x%n == 0 and x>n,primes)
            return True
        if n%i == 0:
            primes = filter(lambda x: x%n == 0 ,primes)
            return False
    primes = filter(lambda x: x%n == 0 and x>n,primes)
    return True

def main():
    limit = 100
    global primes
    primes = range(2,limit)
    for i in filter(isPrime,range(3,limit,2)):
        print(i)



if __name__=="__main__":
  main()

