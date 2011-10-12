#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 12-10-2011
#
#* Last Modified : Wed 12 Oct 2011 10:29:45 AM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/




def digital_sum(a,b):
  return sum(map(int,(list(str(a**b)))))


def main():
  m = 0
  for a in range(100):
    for b in range(100):
      m = max(digital_sum(a,b),m)
  print m


if __name__=="__main__":
  main()

