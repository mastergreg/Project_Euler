#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Fri 14 Oct 2011 07:51:29 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys
from heapq import nlargest, itemgetter


def accept(c):
  return c >= 32 and c <= 126


def decode(letters,key):
  counter = 0
  for i in range(len(letters)):
    c = letters[i] ^ key[i % 3]
    if accept(c):
      counter+=c
    else:
      return False
  print counter,key
  return True



def find_most_common(letters):
  letter_count_map={}
  for l in letters:
    letter_count_map[l]=letters.count(l)
  return nlargest(10, letter_count_map.iteritems(), itemgetter(1))




def main():
  f = sys.stdin
  letters = map(int,f.readline().split(','))
  mc = find_most_common(letters)
  key = []
  print mc
  for m,c in mc:
    key.append(m^32)
  print key
   

if __name__=="__main__":
  main()

