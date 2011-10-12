#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 12-10-2011
#
#* Last Modified : Wed 12 Oct 2011 10:24:23 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/



def is_palindrome(i):
  string = str(i)
  lmax = len(string)/2
  for i in range(lmax):
    if not string[i]==string[-i-1]:
      return False
  return True

def is_lychrel(i):
  n=i
  rn = int(str(i)[::-1])
  for j in range(50):
    n = n + rn
    if is_palindrome(n):
      return False
    rn = int(str(n)[::-1]) 
  return True



def main():
  lychrel=[]
  for i in range(10000):
    if is_lychrel(i):
      lychrel.append(i)
  print len(lychrel)
    
      

if __name__=="__main__":
  main()

