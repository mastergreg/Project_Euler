#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 06-10-2011
#
#* Last Modified : Sat 08 Oct 2011 08:55:27 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys

def get_input():
  f = sys.stdin
  all_ints = []
  for i in range(80):
    line = map(int,f.readline().split())
    all_ints.extend(line)
  for integer in all_ints:
    print integer


def main():
  get_input()

if __name__=="__main__":
  main()

