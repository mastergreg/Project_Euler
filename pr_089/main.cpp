/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Sun 18 May 2014 09:05:36 PM BST
* Created By : Greg Lyras <greglyras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <cmath>
#include <cassert>

#define ROMAN_MAX 1066

using namespace std;

map<char, int> basicValues = {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}
};

int toDec(string inpt)
{
  int ret = 0;
  int previous = 0;
  for(auto c = inpt.rbegin(); c != inpt.rend(); c++) {
    if(basicValues[*c] < previous) {
      ret -= basicValues[*c];
    }
    else {
      previous = basicValues[*c];
      ret += basicValues[*c];
    }
  }
  return ret;
}

string toRoman(int inpt)
{
  string ret = "";
  while(inpt >= 1000) {
    ret+= "M";
    inpt-= 1000;
  }
  if(inpt >= 900) {
    ret += "CM";
    inpt -= 900;
  }
  if(inpt >= 500) {
    ret += "D";
    inpt -= 500;
  }
  if(inpt >= 400) {
    ret += "CD";
    inpt -= 400;
  }
  while(inpt >= 100) {
    ret += "C";
    inpt -= 100;
  }
  if(inpt >= 90) {
    ret += "XC";
    inpt -= 90;
  }
  if(inpt >= 50) {
    ret += "L";
    inpt -= 50;
  }
  if(inpt >= 40) {
    ret += "XL";
    inpt -= 40;
  }
  while(inpt >= 10) {
    ret += "X";
    inpt -= 10;
  }
  if(inpt == 9) {
    ret += "IX";
    inpt -= 9;
  }
  if(inpt >= 5) {
    ret += "V";
    inpt -= 5;
  }
  if(inpt == 4) {
    ret += "IV";
    inpt -= 4;
  }
  while(inpt >= 1) {
    ret += "I";
    inpt -= 1;
  }
  return ret;
}


int main(void)
{
  string num;
  int cnt = 0;
  while(!cin.eof()) {
    cin >> num;
    cnt += num.size() - toRoman(toDec(num)).size();
    if(num.size() < toRoman(toDec(num)).size()) {
      cout << num << " -> " << toRoman(toDec(num)) << endl;
    }
  }
  cout << cnt << endl;
  return 0;
}
