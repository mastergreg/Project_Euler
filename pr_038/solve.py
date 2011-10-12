#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 04-10-2011
#
#* Last Modified : Wed 05 Oct 2011 01:20:37 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import itertools
def all_pandigital():
  return list(itertools.permutations(['1','2','3','4','5','6','7','8','9']))
def can_be(number):
  for i in range(1,5):
    my_num = list(number)
    integer = int("".join(my_num[:i]))
    current_index = i
    flag = True
    for j in range(2,9/i+1):
      current_candidate = str(integer*j)
      if not current_candidate == "".join(my_num[current_index:current_index+len(current_candidate)]):
        flag = False
      current_index = i + len(current_candidate)
    if flag:
      return True
    else:
      continue
  return False




def main():
  allPan = all_pandigital()
  maxPan = 0
  for i in allPan:
    if can_be(i):
      num = int("".join(i)) 
      if num > maxPan:
        maxPan = num
  print num


if __name__=="__main__":
  main()

