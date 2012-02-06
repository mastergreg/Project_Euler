#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Mon 06 Feb 2012 11:56:05 AM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys
import string
from itertools import product


def accept(c):
  return c >= 32 and c <= 126


def decode(letters,key):
  dec = []
  for i in range(len(letters)):
    c = letters[i] ^ key[i % 3]
    dec.append( chr( c ) )

  if (( string.find("".join(dec),"The")!= -1 ) and (string.find("".join(dec),"the") != -1)):
      print sum(map(ord,dec)),"".join(map(chr,key))
      return True
  else:
      return False



def main():
  f = sys.stdin
  letters = map(int,f.readline().split(','))
  keys = product(map(ord,string.ascii_lowercase),repeat=3)
  for key in keys:
      decode( letters, key )
   

if __name__=="__main__":
  main()

