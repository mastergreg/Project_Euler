#!/usr/bin/env python
# -*- coding: utf-8
#
#* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
# File Name : solve.py
# Creation Date : 22-07-2012
# Last Modified : Sun 22 Jul 2012 12:53:47 PM EEST
# Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/

from itertools import permutations
from decimal import *
from sys import stderr

def calc(l):
    k = 0
    for i in l:
        k *= 10
        k += i
    return k

def thdroot(x):
    minprec = 27
    if len(x) > minprec: getcontext().prec = len(x)
    else:                getcontext().prec = minprec
    x = Decimal(x)
    power = Decimal(1)/Decimal(3)
    answer = x**power
    return answer

def find_invpow(x,n):
    """Finds the integer component of the n'th root of x,
    an integer such that y ** n <= x < (y + 1) ** n.
    """
    high = 1
    while high ** n < x:
        high *= 2
    low = high/2
    while low < high:
        mid = (low + high) // 2
        if low < mid and mid**n < x:
            low = mid
        elif high > mid and mid**n > x:
            high = mid
        else:
            return mid
    return mid + 1

def iscube(l):
    c = calc(l)
    n = find_invpow(c,3)
    if n*n*n == c:
        return True
    return False


def permcubes(num):
    digits = map(int,str(num))
    ans = filter(iscube,set(permutations(digits)))
    return ans


checked = {}

def check(i):
    c = calc(sorted(map(int,str(i*i*i)), reverse=True))
    try:
        checked[c].append(i)
    except KeyError:
        checked[c] = [i]
    return checked[c]





def main():
    for i in xrange(50000):
        xc =  check(i)

        if len(xc) == 5:
            i = min(xc)
            print xc, i*i*i
            exit(0)


if __name__=="__main__":
    main()

