#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 13-10-2011
#
#* Last Modified : Fri 09 Mar 2012 03:51:33 AM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from bigfloat import *

def main():
    setcontext(precision(50000000))
    print int((28433*pow(2,7830457)+1)%100000000000)

if __name__=="__main__":
    main()

