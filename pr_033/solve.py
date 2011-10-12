#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 30-09-2011
#
#* Last Modified : Fri 30 Sep 2011 03:34:01 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

from fractions import Fraction



def trivial(num,denom,num2,denom2):
  try:
    if Fraction(num,denom)==Fraction(num2,denom2):
      return True
    else:
      return False
  except (ZeroDivisionError):
    return False

def main():
  myList=list()
  for common in range(1,10):
     for num in range(10):
       for denum in range(num+1,10):
         n1=common+10*num
         n2=10*common+num
         d1=common+10*denum
         d2=10*common+denum
         if trivial(n1,d1,num,denum):
           myList.append((n1,d1))
         if trivial(n1,d2,num,denum):
           myList.append((n1,d2))
         if trivial(n2,d1,num,denum):
           myList.append((n2,d1))
         if trivial(n2,d2,num,denum):
           myList.append((n2,d2))
  print myList
  numinator=1
  denominator=1
  for (a,b) in myList:
    numinator*=a
    denominator*=b
  print Fraction(numinator,denominator)



if __name__ == "__main__":
  main()
