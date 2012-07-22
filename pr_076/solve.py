#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#* File Name : solve.py
#* Purpose :
#* Creation Date : 14-10-2011
#* Last Modified : Sun 22 Jul 2012 04:29:35 PM EEST
#* Created By : Greg Liras <gregliras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/

import collections

ways=collections.defaultdict(lambda : 0)


def main():
    ways[0]=1
    for i in range(1,100):
        for j in range(i,101):
            ways[j] += ways[j-i]
    print ways[100]



if __name__=="__main__":
  main()

