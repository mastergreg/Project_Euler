#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 12-10-2011
#
#* Last Modified : Wed 12 Oct 2011 05:05:54 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from fractions import Fraction

def add_all(i,lst):
  ans = Fraction(lst[i-1],1)
  for j in range(i-2,-1,-1):
    ans = (1/ans)+lst[j]
  return ans


def make_lst(i):
  ls=[2]
  i=i/3+1
  for i in range(1,i):
    ls.extend([1,2*i,1])
  return ls

def main():
  ls = make_lst(100)
  num = add_all(100,ls).numerator
  print sum(map(int,list(str(num))))


if __name__=="__main__":
  main()

