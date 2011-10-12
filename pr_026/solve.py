#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 03-10-2011
#
#* Last Modified : Mon 03 Oct 2011 02:56:22 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/



def div_cycle(d):
  remainders=[]
  divr=10
  while True:
    r1=divr % d
    divr=r1*10
    if r1 in remainders:
      break
    else:
      remainders.append(r1)
      continue
  return len(remainders)


def main():
  myDictionary={}
  for i in range(1,1000):
    myDictionary[i]=div_cycle(i)
  for key, value in sorted(myDictionary.iteritems(), key=lambda (k,v): (v,k)):
        print "%s: %s" % (key, value)






if __name__=="__main__":
  main()
