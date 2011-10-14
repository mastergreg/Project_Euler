#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 13-10-2011
#
#* Last Modified : Thu 13 Oct 2011 11:47:27 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


import sys

roman={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
roman_let=['I','V','X','L','C','D','M']



def calculate(i):
  ls = list(i)
  ans=0
  for l in ls:
    ans+=roman[l]
  return ans

def calculate_R(i):
  ans=""
  j = 6
  while(i>0):
    letter = roman_let[j]
    value = roman[letter]
    if i>=value:
      ans+=letter
      i-=roman[letter]
    else:
      j-=1
  return ans
    



def main():
  f = sys.stdin
  lines = []
  for i in range(1000):
    lines.extend(f.readline().split())
  counter=0
  for l in lines:
    counter+=len(l)-len(calculate_R(calculate(l)))
  print counter



if __name__=="__main__":
  main()

