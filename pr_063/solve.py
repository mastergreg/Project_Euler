#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Fri 09 Mar 2012 11:24:24 AM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from math import *


def calc_nth_ndig(num):
    k=0
    for i in xrange(1,10):
        x = int(ceil(log10(i**num)))
        if  x == num:
            k+=1
    return k


def main():
    k=1
    for i in range(1,1000):
        k+=calc_nth_ndig(i)
    print k


if __name__=="__main__":
  main()

