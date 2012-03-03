#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 09-02-2012
#
#* Last Modified : Wed 29 Feb 2012 03:45:43 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from fractions import gcd
from itertools import combinations,ifilter
def main():
    alls = ifilter(lambda x: gcd(x[0],x[1])==1 ,combinations(range(1,1000001),2))
    print len(list(alls))



if __name__=="__main__":
    main()

