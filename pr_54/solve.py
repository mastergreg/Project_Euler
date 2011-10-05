#!/usr/bin/python

#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : solve.py
#
#* Purpose :
#
#* Creation Date : 05-10-2011
#
#* Last Modified : Wed 05 Oct 2011 07:27:57 PM EEST
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys

cards = ['2','3','4','5','6','7','8','9','T','J','Q','K','A']
def rF(hand):
  sign = hand[0][1]
  c0 = 'T'+sign
  c1 = 'J'+sign
  c2 = 'Q'+sign
  c3 = 'K'+sign
  c4 = 'A'+sign
  return c0 in hand and c1 in hand and c2 in hand and c3 in hand and c4 in hand
def sF(hand):
  sign = hand[0][1]
  start = hand[0][0]
  first = cards.index(start)
  if first < 8:
    c0 = cards[first]+sign
    c1 = cards[first+1]+sign
    c2 = cards[first+2]+sign
    c3 = cards[first+3]+sign
    c4 = cards[first+4]+sign
    return c0 in hand and c1 in hand and c2 in hand and c3 in hand and c4 in hand
  else:
    return False

def four(hand):
  num0 = hand[0][0]
  num1 = hand[1][0]
  num2 = hand[2][0]
  num3 = hand[3][0]
  num4 = hand[4][0]
  return num1 == num2 and num2 == num3 and (num0 == num1 or num3 == num4)

def full_house(hand):
  num0 = hand[0][0]
  num1 = hand[1][0]
  num2 = hand[2][0]
  num3 = hand[3][0]
  num4 = hand[4][0]
  return num0 == num1 and num3 == num4 and (num2 == num1 or num2 == num3)

def flush(hand):
  sign0 = hand[0][1]
  sign1 = hand[1][1]
  sign2 = hand[2][1]
  sign3 = hand[3][1]
  sign4 = hand[4][1]
  return sign0 == sign1 and sign1 == sign2 and sign2 == sign3 and sign3 == sign4

def straight(hand):
  index0 = cards.index(hand[0][0])
  index1 = cards.index(hand[1][0])
  index2 = cards.index(hand[2][0])
  index3 = cards.index(hand[3][0])
  index4 = cards.index(hand[4][0])
  if index0 < 8:
    return index1 == index0+1 and index2 == index1+1 and index3 == index2+1 and index4 == index3+1
  else:
    return False

def three_of_a_kind(hand):
  num0 = hand[0][0]
  num1 = hand[1][0]
  num2 = hand[2][0]
  num3 = hand[3][0]
  num4 = hand[4][0]
  return (num0 == num1 and num1 == num2 ) or (num1 == num2 and num2 == num3 ) or (num2 == num3 and num3 == num4)

def two_pairs(hand):
  num0 = hand[0][0]
  num1 = hand[1][0]
  num2 = hand[2][0]
  num3 = hand[3][0]
  num4 = hand[4][0]
  return (num0 == num1 and (num2 == num3 or num3 == num4)) or (num1 == num2 and num3 == num4)

def one_pair(hand):
  num0 = hand[0][0]
  num1 = hand[1][0]
  num2 = hand[2][0]
  num3 = hand[3][0]
  num4 = hand[4][0]
  return num0 == num1 or num1 == num2 or num2 == num3 or num3 == num4

def find_pair_value(hand):
  for i in range(len(hand)-1):
    if hand[i][0]==hand[i+1][0]:
      return cards.index(hand[i][0])
  return 0


def rank(hand):
  if rF(hand):
    return 900
  elif sF(hand):
    return 800+cards.index(hand[4][0])
  elif four(hand):
    return 700+cards,index(hand[2][0])
  elif full_house(hand):
    return 600+cards.index(hand[2][0])
  elif flush(hand):
    return 500+cards.index(hand[4][0])
  elif straight(hand):
    return 400+cards.index(hand[4][0])
  elif three_of_a_kind(hand):
    return 300+cards.index(hand[2][0])
  elif two_pairs(hand):
    return 200+cards.index(hand[3][0])+(cards.index(hand[1][0])/100.)
  elif one_pair(hand):
    return 100+find_pair_value(hand)
  else:
    return 0



def pl1_wins(game):
  pl1 = sorted(list(game[:5]),key = lambda x : cards.index(x[0]))
  pl2 = sorted(list(game[5:]),key = lambda x : cards.index(x[0]))
  rp1 = rank(pl1)
  rp2 = rank(pl2)
  i=4
  while( rp1 == rp2):
    rp1 = cards.index(pl1[i][0])
    rp2 = cards.index(pl2[i][0])
    i-=1
  if rp1 > rp2:
    return True
  else:
    return False


def main():
  f = sys.stdin
  c=0
  for i in range(1000):
    game = f.readline().split()
    if pl1_wins(game):
      c+=1
  print c


if __name__=="__main__":
  main()

