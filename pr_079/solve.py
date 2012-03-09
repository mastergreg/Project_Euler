#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 08-03-2012
#
#* Last Modified : Fri 09 Mar 2012 03:49:55 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/
import sys
from itertools import *
from math import ceil

def accept(password,attempts):
    for c in attempts:
        ni = 0
        for letter in c:
            try:
                ni = password[ni:].index(letter)
            except ValueError:
                return False
    return True




def main():
    f = open("keylog.txt","r")
    lines = map(lambda x:x.strip(),f.readlines())
    f.close()
    lines = sorted(lines)
    chars = "".join(list((set(list("".join(lines))))))
    #lines = map(list,lines)
    #print lines

    for i in xrange(len(chars),25):
        print i
        passwords = permutations(chars*int(ceil(i/len(chars))), i)
        for password in passwords:
            password = "".join(password)
            #print password
            if accept(password,lines):
                print "Found it:",password
                return 0
    return 0


if __name__=="__main__":
    main()

