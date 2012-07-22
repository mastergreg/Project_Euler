#!/usr/bin/env python
# -*- coding: utf-8
#
#* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
# File Name : solve.py
# Creation Date : 02-04-2012
# Last Modified : Sun 22 Jul 2012 05:16:36 PM EEST
# Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/

def find_top_bottom(i):
    k = 100
    while k*k < i:
        k*=2
    return (k,k/2)

def accept(i,dig=10):
    c = 0
    i = i*i
    i -= 1020304050607080900
    if i < 0:
        return 0
    while i > 0:
        if i%10 != 0:
            return c
        i /= 100
        c += 1
    return c

def main():
    bottom = 1010101010
    top = 1389026624
    remaining = top-bottom


    dig = 10
    step = 10
    m = 0
    print bottom,top, step, dig
    for curr in xrange(bottom,top,step):
        print "\r",curr,
        nm = accept(curr)
        if nm > m:
            print "Found",curr, curr*curr, "with", nm
            m = nm



if __name__=="__main__":
    main()

