#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 30-09-2011
#
#* Last Modified : Tue 04 Oct 2011 08:28:16 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


def filterAllPrimes(p1):
  p2 = []
  for i in range(len(p1)):
    if p1[i]>1000:
      p2.extend(p1[i:])
      break
  return p2

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

def is_perm(prime1,prime2):
  p1 = "".join(sorted(str(prime1)))
  p2 = "".join(sorted(str(prime2)))
  return p1==p2

def findPerms(primeList):
  perms = []
  length = len(primeList)
  for i1 in range(length-2):
    prime1 = primeList[i1]
    for i2 in range(i1+1,length):
      prime2 = primeList[i2]
      if  is_perm(prime1,prime2):
        for i3 in range(i2+1,length):
          prime3 = primeList[i3]
          if is_perm(prime1,prime3):
            if prime1 - prime2 == prime2 - prime3:
              perms.append((prime1,prime2,prime3))
  return perms




def main():
  p1 = get_allPrimes(10000)
  p2 = filterAllPrimes(p1)
  perms = findPerms(p2)
  print perms

if __name__=="__main__":
  main()
