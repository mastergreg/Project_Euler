#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 30-09-2011
#
#* Last Modified : Tue 04 Oct 2011 08:34:38 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/



def is_perm(prime1,prime2):
  p1 = "".join(sorted(str(prime1)))
  p2 = "".join(sorted(str(prime2)))
  return p1==p2


def main():
  i = 1;
  while True:
    if is_perm(i,2*i) and is_perm(i,3*i) and is_perm(i,4*i) and is_perm(i,5*i) and is_perm(i,6*i):
      print i
      break
    else:
      i+=1


if __name__=="__main__":
  main()
