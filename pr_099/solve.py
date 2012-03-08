#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 13-10-2011
#
#* Last Modified : Thu 08 Mar 2012 09:03:49 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


import math

def main():
    f = open( "base_exp.txt", "r" )
    m=0
    numbers = f.readlines()
    for (i,x) in enumerate(numbers):
        x0,x1 = map(int,x.split(','))
        nm = x1*math.log(x0)
        if m < nm:
            m = nm
            mi = i
    print mi+1



if __name__=="__main__":
    main()

