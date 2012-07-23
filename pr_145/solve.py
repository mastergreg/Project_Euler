#!/bin/env python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#* File Name : solve.py
#* Purpose :
#* Creation Date : 12-03-2012
#* Last Modified : Mon 23 Jul 2012 07:42:56 PM EEST
#* Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/
from itertools import ifilter, imap


def accept(s):
    if(s%10==0):
        return False
    s = s + int(str(s)[::-1])
    for i in imap(int,str(s)):
        if i&1 == 0:
            return False
    return True
    
def solve(lim):
    k = 0
    for i in ifilter(accept,xrange(10,lim+1)):
        k+=1
        print "\r",i,
    print "The answer is: {0}".format(k)

def main():
    solve(1000)
    solve(1000000001)



if __name__=="__main__":
    main()

