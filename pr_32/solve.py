#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 04-10-2011
#
#* Last Modified : Tue 04 Oct 2011 10:17:48 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import itertools
def all_pandigital():
  return list(itertools.permutations(['1','2','3','4','5','6','7','8','9']))

def is_related(number):
  retls = []
  for i in range(1,8):
    multiplicand = int("".join(number[:i]))
    for j in range(i+1,9):
      multiplier = int("".join(number[i:j]))
      product = int("".join(number[j:]))
      if multiplier*multiplicand == product:
        retls.append(product)
  return retls

def main():
  allPan = all_pandigital()
  suma = []

  for i in allPan:
    suma.extend(is_related(i))
  suma = list(set(suma))
  ans = sum(suma)
  print ans

if __name__=="__main__":
  main()

