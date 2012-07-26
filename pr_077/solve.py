#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#* File Name : solve.py
#* Purpose :
#* Creation Date : 14-10-2011
#* Last Modified : Thu 26 Jul 2012 05:41:02 PM EEST
#* Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/

import collections

ways=collections.defaultdict(lambda : 0)

def get_allPrimes(limit):
    pList=[2]
    for i in range(3,limit,2):
        isprime = True
        for prime in pList:
            if i % prime == 0:
                isprime = False
                break
        if isprime:
            pList.append(i)
    return pList

def main():
    ways[0]=1
    limit = 1000
    target = 5000
    primes = get_allPrimes(limit)
    for i in primes:
        ways[i] += 1
        for j in xrange(i+1,limit):
            ways[j] += ways[j-i]
    for i in range(limit):
        if ways[i] >= target:
            print i,ways[i]
            break



if __name__=="__main__":
    main()

