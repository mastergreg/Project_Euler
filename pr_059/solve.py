#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 13-10-2011
#
#* Last Modified : Thu 13 Oct 2011 06:35:41 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys


chars = [ 97, 99, 100, 101, 103, 104, 105, 106, 107, 110, 111, 113, 115, 116, 117, 118, 119, 121, 122] 

def main():
  f = sys.stdin
  letters = map(int,f.readline().split(','))
  print len(letters)

if __name__=="__main__":
  main()

