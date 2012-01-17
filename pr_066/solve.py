#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : myfile.py
#
#* Purpose :
#
#* Creation Date : 18-10-2011
#
#* Last Modified : Tue 18 Oct 2011 05:42:19 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from math import sqrt


def solve(D):
  x=1
  y=1
  print D
  while True:
    print x
    f = x*x -D*y*y - 1
    if f > 0:
      y+=1
    elif f < 0:
      x+=max(1,-f/2)
    else:
      return (x,D)


def main():
  solutions = []
  for i in range(2,100):
    j = sqrt(i)
    if j == int(j):
      continue
    else:
      solutions.append(solve(i))

if __name__=="__main__":
  main()

