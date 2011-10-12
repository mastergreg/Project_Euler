#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 03-10-2011
#
#* Last Modified : Mon 03 Oct 2011 03:33:10 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/



def is_palindrome(string):
  lmax = len(string)/2
  for i in range(lmax):
    if not string[i]==string[-i-1]:
      return False
  return True

def Denary2Binary(n):
  '''convert denary integer n to binary string bStr'''
  bStr = ''
  if n < 0: raise ValueError, "must be a positive integer"
  if n == 0: return '0'
  while n > 0:
    bStr = str(n % 2) + bStr
    n = n >> 1
  return bStr

def main():
  dec_pal=[]
  for i in range(1,1000000):
    if is_palindrome(str(i)):
      dec_pal.append(i)
  print len(dec_pal)
  pals=[]
  for dec in dec_pal:
    if is_palindrome(Denary2Binary(dec)):
      pals.append(dec)
  print len(pals)
  print sum(pals)

if __name__=="__main__":
  main()

