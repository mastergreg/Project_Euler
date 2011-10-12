#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 04-10-2011
#
#* Last Modified : Wed 05 Oct 2011 02:00:00 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import itertools
def all_pandigital():
  digit_list = ['0','1','2','3','4','5','6','7','8','9']
  return list(itertools.permutations(digit_list))


def prop1(num):
  cand = int("".join([num[1],num[2],num[3]]))
  return cand % 2 == 0
def prop2(num):
  cand = int("".join([num[2],num[3],num[4]]))
  return cand % 3 == 0
def prop3(num):
  cand = int("".join([num[3],num[4],num[5]]))
  return cand % 5 == 0
def prop4(num):
  cand = int("".join([num[4],num[5],num[6]]))
  return cand % 7 == 0
def prop5(num):
  cand = int("".join([num[5],num[6],num[7]]))
  return cand % 11 == 0
def prop6(num):
  cand = int("".join([num[6],num[7],num[8]]))
  return cand % 13 == 0
def prop7(num):
  cand = int("".join([num[7],num[8],num[9]]))
  return cand % 17 == 0

def prop(num):
  return prop1(num) and prop2(num) and prop3(num) and prop4(num) and prop5(num) and prop6(num) and prop7(num)


def main():
  allPan = all_pandigital()
  print len(allPan)
  ans = 0
  for i in allPan:
    if prop(i):
      print i
      ans += int("".join(i))
  print ans 

if __name__=="__main__":
  main()

