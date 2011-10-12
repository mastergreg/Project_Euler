#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 30-09-2011
#
#* Last Modified : Wed 05 Oct 2011 03:11:57 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from math import sqrt

def get_allPrimes(limit):
  pList=[2]
  oddComp=[]
  for i in range(3,limit,2):
    isprime = True
    root = sqrt(i)
    for prime in pList:
      if prime > root:
        break
      elif i % prime == 0:
        isprime = False
        break
      else:
        continue
    if isprime:
      pList.append(i)
    else:
      oddComp.append(i)
      continue
  return (pList,oddComp)


def check(odd_compisite_number,primeList):
  for prime in primeList:
    if prime > odd_compisite_number:
      return False
    else:
      n = sqrt((odd_compisite_number-prime)/2.)
      if n == int (n) :
        return True
  return False

def main():
  (pL,odC) = get_allPrimes(10000)
  print len(pL)
  print len(odC)
  for odd in odC:
    if not check(odd,pL):
      print odd
      return 0


if __name__=="__main__":
  main()
