#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 09-03-2012
#
#* Last Modified : Sat 10 Mar 2012 05:10:57 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from fractions import Fraction

def main():
    dlim = Fraction(1,7)
    ulim = Fraction(3,7)
    ls = []
    for i in  xrange(2,1000001):
        border = int(dlim*i)
        uborder = int(ulim*i)+1
        for j in xrange(border,uborder):
            ndlim = Fraction(j,i)
            if ndlim < ulim:
                dlim = max(dlim,ndlim)
                print dlim
    print dlim


if __name__=="__main__":
    main()

