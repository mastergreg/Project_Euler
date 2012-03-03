#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 13-10-2011
#
#* Last Modified : Thu 01 Mar 2012 04:54:39 PM EET
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

mapping = [ ('IIIIIIIIII','X'),
            ('IIIIIIIII','IX'),
            ('IIIIIIII','IIX'),
            ('IIIII'    ,'V' ),
            ('IIII'    ,'IV'),
            ('XXXXXXXXXX','C'),
            ('XXXXXXXXX','XC'),
            ('XXXXXXXX','XXC'),
            ('XXXXX'    ,'L' ),
            ('XXXX'    ,'XL'),
            ('CCCCCCCCCC','M'),
            ('CCCCCCCCC','CM'),
            ('CCCCCCCC','CCM'),
            ('CCCCC'    ,'D' ),
            ('CCCC'    ,'CD')]
def main():
    f = sys.stdin
    numbers = map(roman2int,map(lambda x:x.strip(),f.readlines()))
    counter=0
    print counter,numbers,len(numbers)



if __name__=="__main__":
    main()

