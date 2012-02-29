#!/usr/bin/python2.6
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 09-02-2012
#
#* Last Modified : Wed 29 Feb 2012 02:48:03 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/
import psyco

psyco.full()

from fractions import Fraction,gcd
def main():
    ans = set()
    for j in range(1,12001):
        print j
        for i in range(j/3-3,j/2+2):
            if i*3 > j and i*2 < j:
                g = gcd(i,j)
                ans.add((i/g,j/g))
    print len(list(ans))



if __name__=="__main__":
    main()

