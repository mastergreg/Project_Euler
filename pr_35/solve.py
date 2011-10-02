#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 30-09-2011
#
#* Last Modified : Sat 01 Oct 2011 09:44:12 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/




import random



def rotations(prime):
  pr = str(prime)
  rotList=list()
  for i in range(len(pr)):
    rotList.append(int(pr[i:]+pr[:i]))
  return rotList

def get_allPrimes(limit):
  pList=[2]
  for i in range(3,limit,2):
    isprime = True
    for prime in pList:
      if i % prime == 0:
        isprime = False
        break
      else:
        continue
    if isprime:
      pList.append(i)
    else:
      continue
  return pList

def testAll(primeList):
  n = 0
  while primeList:
    prime = primeList[0]
    circs = rotations(prime)
    found = n
    for rot in circs:
      for i in range(len(primeList)):
        buff = primeList[i]
        if rot > buff:
          continue
        elif rot==buff:
          primeList.pop(i)
          found=found+1
          break
        elif rot < buff:
          found = n
          break
        elif i == len(primeList)-1:
          found = n
          break
      if found == n:
        break
    n = found
  return n




def main():
  p1 = get_allPrimes(1000000)
  p2 = testAll(p1)
  print p2

if __name__=="__main__":
  main()
