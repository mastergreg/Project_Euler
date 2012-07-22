#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 13-10-2011
#
#* Last Modified : Mon 12 Mar 2012 01:25:34 AM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


import sys

roman={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
roman_let=['I','V','X','L','C','D','M']

def roman2int(st):
    prVal = 0
    b = 0
    value = 0
    for c in st:
        cVal = roman[c]
        if prVal == cVal:
            b += cVal
        elif cVal > prVal:
            value += cVal - b
            prVal = cVal
            b = 0
        elif cVal < prVal:
            value += b
            prVal = cVal
            b = 0
    return value+b

mapping = [ ('I'*1000, 'M'),
            ('I'*900, 'CM'),
            ('I'*800, 'CCM'),
            ('I'*500, 'D'),
            ('I'*400, 'CD'),
            ('I'*100, 'C'),
            ('I'*90, 'XC'),
            ('I'*80, 'XXC'),
            ('I'*50, 'L'),
            ('I'*40, 'XL'),
            ('I'*10, 'X'),
            ('I'*9, 'IX'),
            ('I'*8, 'IIX'),
            ('I'*5, 'V'),
            ('I'*4, 'IV')]


def countem(roman):
    start = roman2int(roman)*'I'
    for m in mapping:
        start = start.replace(m[0],m[1])
    print start
    return len(roman)-len(start)

def int2roman(num):
    start = num*'I'
    for m in mapping:
        start = start.replace(m[0],m[1])
    return start



def main():
    f = sys.stdin
    numbers = map(lambda x:x.strip(),f.readlines())
    diffs = map(countem,numbers)
    for i in xrange(1,4000):
        if not roman2int(str(int2roman(i))) == i:
            k = int2roman(i)
            print "Failed at",i,k,roman2int(k)
    print sum(diffs)


if __name__=="__main__":
    main()

