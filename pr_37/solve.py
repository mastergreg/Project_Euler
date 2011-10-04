#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 30-09-2011
#
#* Last Modified : Sun 02 Oct 2011 08:03:37 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

def rotations(prime):
  pr = str(prime)
  rotList=list()
  for i in range(len(pr)):
    rotList.append(int(pr[i:]+pr[:i]))
  return rotList

def isPrime(contestant,primeList):
  return contestant in primeList

def truncableRL(prime,primeList):
  buf = str(prime)[:-1]
  if not buf:
    return False
  while buf:
    if isPrime(int(buf),primeList):
      buf = buf[:-1]
      continue
    else:
      return False
  return True

def truncableLR(prime,primeList):
  buf = str(prime)[1:]
  if not buf:
    return False
  while buf:
    if isPrime(int(buf),primeList):
      buf = buf[1:]
      continue
    else:
      return False
  return True
    
def truncable(prime,primeList):
  return truncableRL(prime,primeList) and truncableLR(prime,primeList)
  
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
  
def get_allPrimes_2():
  pList=[2,3,5,7,11]
  truncPrimesList=[]
  i = 11
  truncPrimes = 0
  while truncPrimes < 11:
    i = i+2
    isprime = True
    for prime in pList:
      if i % prime == 0:
        isprime = False
        break
      else:
        continue
    if isprime:
      pList.append(i)
      if truncable(i,pList):
        truncPrimesList.append(i)
        truncPrimes+=1
        print i
    else:
      continue
  return truncPrimesList

def testAll(primeList):
  n = 0
  while primeList:
    print len(primeList)
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
  p1 = get_allPrimes_2()
  print len(p1)
  print p1

if __name__=="__main__":
  main()
