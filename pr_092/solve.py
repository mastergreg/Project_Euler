#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 12-10-2011
#
#* Last Modified : Wed 12 Oct 2011 04:38:07 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


def sq(i):
  n = int(i)
  return n*n

def next(i):
  return sum(map(sq,list(str(i))))

def chain(i):
  n=i
  while True:
    n = next(n)
    if n==1:
      return False
    elif n==89:
      return True


def main():
  counter=0
  for i in range(1,10000000):
    if i%10000 == 0:
      print i/10000
    if chain(i):
      counter+=1
  print counter


if __name__=="__main__":
  main()

