#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : main.py
#
#* Purpose :
#
#* Creation Date : 18-01-2012
#
#* Last Modified : Wed 18 Jan 2012 05:16:25 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys

def main():
    f = sys.stdin
    length = int(f.readline())
    ls=[]
    for i in range(length):
        ls.append(map(lambda x : int(x),f.readline().split()))
    ls = zip(*ls[::-1])
    ls = map(list,ls)

    dyntable = list(ls)





if __name__=="__main__":
    main()

