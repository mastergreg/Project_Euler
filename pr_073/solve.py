#!/usr/bin/python2.6
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 09-02-2012
#
#* Last Modified : Fri 10 Feb 2012 03:46:00 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/
import psyco

psyco.full()

from fractions import Fraction
def main():
    ans = Fraction(1,4)
    lim = Fraction(3,7)
    for j in range(1000001,1,-1):
        print ans
        for i in range(int(ans*j)-1,j/2+1):
            k = Fraction( i, j)
            if k < lim and k > ans:
                ans = k
    print ans



if __name__=="__main__":
    main()

