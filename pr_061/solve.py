#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 18-10-2011
#
#* Last Modified : Tue 18 Oct 2011 04:46:25 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from itertools import permutations

def triangle(n):
  return n*(n+1)/2
def square(n):
  return n*n
def pentagonal(n):
  return n*(3*n-1)/2
def hexagonal(n):
  return n*(2*n-1)
def heptagonal(n):
  return n*(5*n-3)/2
def octagonal(n):
  return n*(3*n-2)


def getAll(fun):
  n=0
  m = str(fun(n))
  ret=[]
  while len(m)<5:
    n+=1
    m = str(fun(n))
    if len(m)==4:
      ret.append(m)
  return ret


def circ(ass,bss,css,dss,ess,fss):
  for a in ass:
    for b in bss:
      if a[2:]==b[:2]:
        for c in css:
          if b[2:]==c[:2]:
            for d in dss:
              if c[2:]==d[:2]:
                for e in ess:
                  if d[2:]==e[:2]:
                    for f in fss:
                      if e[2:]==f[:2] and f[2:]==a[:2]:
                        print a, b, c,d,e,f
                        print int(a)+int(b)+int(c)+int(d)+int(e)+int(f) 
                        return True
  return False

def main():
  trigs = getAll(triangle)
  squares = getAll(square)
  pents = getAll(pentagonal)
  hexs = getAll(hexagonal)
  hepts = getAll(heptagonal)
  octags = getAll(octagonal)
  allList = [trigs,squares,pents,hexs,hepts,octags]
  for p in permutations([0,1,2,3,4,5]):
    if circ(allList[p[0]],allList[p[1]],allList[p[2]],allList[p[3]],allList[p[4]],allList[p[5]]):
      print p

if __name__=="__main__":
  main()

