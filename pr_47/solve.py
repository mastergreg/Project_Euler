#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 06-10-2011
#
#* Last Modified : Thu 06 Oct 2011 12:24:56 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from math import sqrt
primes=[]

def CountPrimeFactors(num):
  global primes
  factors = []
  i = 0
  curr = primes[i]
  while num>1:
    if num % curr == 0:
      factors.append(curr)
      num /= curr
    else:
      i +=1
      curr = primes[i]
  return len(list(set(factors)))


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

def found(num):
  return CountPrimeFactors(num) == 4 

def foundAll(num):
  return CountPrimeFactors(num+1) == 4 and CountPrimeFactors(num+2) == 4 and CountPrimeFactors(num+3) == 4
def main():
  global primes
  primes = get_allPrimes(1000000)
  num = 647
  while True:
    if found(num):
      print num
      if foundAll(num):
        print num,num+1,num+2,num+3
        break
    num +=4



if __name__=="__main__":
  main()

