#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : main.py
#
#* Purpose :
#
#* Creation Date : 18-01-2012
#
#* Last Modified : Thu 08 Mar 2012 08:22:41 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys

ls = []

def calc(i,j):
    global ls
    r=[ls[i-1][j]]
    if j > 0:
        r.append(ls[i][j-1])
    if j < len(ls[0])-1:
        for k in range(j+1,len(ls[0])):
            r.append(sum(ls[i][j+1:k+1])+ls[i-1][k])
    return min(r)
    


def main():
    global ls
    f = sys.stdin
    lines = map( lambda y: y.strip().split(','), f.readlines())
    for l in lines:
        ls.append(map( lambda x: int(x), l ))
    ls = zip(*ls[::-1])
    ls = map(list,ls)

    ls = map(list,ls)
    for i in ls:
        print i
    for i in range(1,len(ls)):
        for j in range(len(ls[0])):
            ls[i][j]+=calc(i,j)
    print 10*"--"
    for i in ls:
        print i
    print min(ls[-1])





if __name__=="__main__":
    main()

