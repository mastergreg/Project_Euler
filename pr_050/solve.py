#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 06-10-2011
#
#* Last Modified : Thu 06 Oct 2011 12:59:27 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from math import sqrt
primes=[]


def is_Prime(num):
  global primes
  return num in primes

def get_allPrimes(limit):
  pList=[2]
  for i in range(3,limit,2):
    isprime = True
    limit = sqrt(i)
    for prime in pList:
      if prime > limit:
        isprime = True
        break
      elif i % prime == 0:
        isprime = False
        break
      else:
        continue
    if isprime:
      pList.append(i)
    else:
      continue
  return pList

def main():
  global primes
  primes = get_allPrimes(1000000)
  length = len(primes)
  a = 1
  for i in range(length):
    for j in range(i+a,length):
      s = primes[i:j]
      ss = sum(s)
      ls = len(s)
      if ss > 1000000:
        break
      elif is_Prime(ss):
        if ls > a:
          a = ls
          maxP = ss
  print a , maxP



if __name__=="__main__":
  main()

