#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Sun 11 Mar 2012 09:24:58 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


def factorial(n):
    an = 1
    for i in xrange(2,n+1):
        an*=i
    return an

def chainit(num):
    ans = 0
    while( num > 0 ):
        b = num % 10
        num/=10
        ans += factorial(b)
    return ans

def main():
    print chainit(999999)
    computed = {}
    counter = 0
    for i in xrange(1,1000000):
        if i not in computed:
            b = chainit(i)
            tml = [i]
            while b not in tml:
                tml.append(b)
                b = chainit(b)
            computed[i] = len(tml)
        if computed[i] == 60:
            counter+=1
            print i,counter
    print counter

        



    



if __name__=="__main__":
    main()

