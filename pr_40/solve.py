#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 02-10-2011
#
#* Last Modified : Sun 02 Oct 2011 08:42:32 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/


def main():
  i = 0
  mystring=""
  while len(mystring)<1000002:
    mystring+=str(i)
    i=i+1
  print mystring[1],mystring[10],mystring[100],mystring[1000],mystring[10000],mystring[100000],mystring[1000000]
  print int(mystring[1])*int(mystring[10])*int(mystring[100])*int(mystring[1000])*int(mystring[10000])*int(mystring[100000])*int(mystring[1000000])


if __name__=="__main__":
  main()

