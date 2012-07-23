#!/usr/bin/env python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#* File Name : solve.py
#* Purpose :
#* Creation Date : 12-03-2012
#* Last Modified : Mon 23 Jul 2012 08:52:21 PM EEST
#* Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/
from itertools import ifilter, imap
from multiprocessing import Process, Queue


def accept(s):
    if(s%10==0):
        return False
    s = s + int(str(s)[::-1])
    for i in imap(int,str(s)):
        if i&1 == 0:
            return False
    return True
    
def solve(q, start, lim, step):
    k = 0
    for i in ifilter(accept,xrange(start,lim+1,step)):
        k+=1
    q.put(k)

def main():
    lim = 1000000001
    q1 = Queue()
    q2 = Queue()
    q3 = Queue()
    q4 = Queue()

    p1 = Process(target=solve,args=(q1, 10, lim, 4))
    p2 = Process(target=solve,args=(q2, 11, lim, 4))
    p3 = Process(target=solve,args=(q3, 12, lim, 4))
    p4 = Process(target=solve,args=(q4, 13, lim, 4))

    p1.start()
    p2.start()
    p3.start()
    p4.start()

    p1.join()
    p2.join()
    p3.join()
    p4.join()
    a1 = q1.get()
    a2 = q2.get()
    a3 = q3.get()
    a4 = q4.get()
    print a1,a2,a3,a4
    print "Answer is: {0}".format(a1+a2+a3+a4)





if __name__=="__main__":
    main()

