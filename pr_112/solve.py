#!/usr/bin/env python
# -*- coding: utf-8
#
#* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
# File Name : solve.py
# Creation Date : 22-07-2012
# Last Modified : Sun 22 Jul 2012 05:43:13 PM EEST
# Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/

def calc(s):
    return int("".join(map(str,s)))

def reverse(s):
    s.reverse()
    return s
def accept(num):
    sn = sorted(map(int,str(num)))
    if calc(sn) == num:
        return 0
    elif calc(reverse(sn)) == num:
        return 0
    else:
        return 1
    

def main():
    start = 21780
    bouncy = 19602
    curr = start
    perc = 0
    while perc < 99:
        curr += 1
        bouncy += accept(curr)
        perc = bouncy*100/curr
        print "\r",curr,perc,



if __name__=="__main__":
    main()

