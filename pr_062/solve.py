#!/usr/bin/env python
# -*- coding: utf-8
#
#* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
# File Name : solve.py
# Creation Date : 22-07-2012
# Last Modified : Sun 22 Jul 2012 12:54:38 PM EEST
# Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/

from sys import stderr


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

