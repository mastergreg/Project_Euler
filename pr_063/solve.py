#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 14-10-2011
#
#* Last Modified : Fri 14 Oct 2011 01:40:18 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


from math import pow,log10


def nth_power_n_digits(i):
  if log10(pow(2,i))+1>i :
    return False
  t = 1.0
  j = 1
  for j in range(1,10):
    t = pow(j,i)
    if (log10(t) + 1) >= i:
      return True



def main():
  counter=0
  i=2
  while nth_power_n_digits(i):
    counter+=1
    print counter,i
    i+=1
  print counter

if __name__=="__main__":
  main()

