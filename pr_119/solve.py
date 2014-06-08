#!/usr/bin/env python
# -*- coding: utf-8
#
#* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
# File Name : solve.py
# Creation Date : 08-06-2014
# Last Modified : Sun 08 Jun 2014 01:26:22 BST
# Created By : Greg Lyras <greglyras@gmail.com>
#_._._._._._._._._._._._._._._._._._._._._.*/


max_n = 512

def accept(i):
  for j in xrange(1, 10):
    p = i**j
    if p > 9:
      s = sum(map(int, str(p)))
      if s == i:
        return (True, j, p)
  else:
    return (False, 0, 0)


def main():
  probable = []
  for i in xrange(2, max_n):
    (ans, j, p) = accept(i)
    if ans:
      probable.append((p, j, i))
      if len(probable) > 30:
        break
  probable.sort()
  print "a[{0}]: {1}".format(30, probable[22])



if __name__=="__main__":
    main()

