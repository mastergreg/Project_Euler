/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Sun 18 May 2014 11:40:05 AM BST
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

using namespace std;

class sudoku {
  private:
    int id;
    int grid[9][9];
    int zeros;
    list<int> probables[9][9];
    void cleanRows(int i, int j);
    void cleanColumns(int i, int j);
    void cleanBlocks(int i, int j);
  public:
    sudoku(void);
    void solve(void);
    void setGridElement(int, int, int);
    friend istream &operator >>(istream &is, sudoku &s);
    friend ostream &operator <<(ostream &os, sudoku &s);
};

ostream &operator<<(ostream &os, sudoku &s)
{
  cout << "Grid " << s.id << endl;
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cout << s.grid[i][j] << ":{";
        for(int p: s.probables[i][j]) {
          cout << p << ",";
        }
        cout << "} ";
    }
    cout << endl;
  }
  return os;
}

istream &operator>>(istream &is, sudoku &s)
{
  is.ignore(256, ' ');
  is >> s.id;
  is.ignore(256, '\n');
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      s.setGridElement(i, j, is.get() - '0');
    }
    is.get();
  }
  return is;
}

void sudoku::solve(void)
{

  while(zeros > 0) {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        if(probables[i][j].size() == 1) {
          setGridElement(i, j, probables[i][j].front());
        }
      }
    }
  }
}

sudoku::sudoku(void)
{
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      for(int k = 1; k < 10; k++) {
        probables[i][j].push_back(k);
      }
    }
  }
  zeros = 81;
}

void sudoku::setGridElement(int i, int j, int v)
{
  grid[i][j] = v;
  if(v != 0) {
    probables[i][j].clear();
    cleanRows(i, j);
    cleanColumns(i, j);
    cleanBlocks(i, j);
    zeros--;
  }
}

void sudoku::cleanRows(int i, int j)
{
  for(int k = 0; k < 9; k++)
  {
    probables[i][k].remove(grid[i][j]);
  }
}

void sudoku::cleanColumns(int i, int j)
{
  for(int k = 0; k < 9; k++)
  {
    probables[k][j].remove(grid[i][j]);
  }
}

void sudoku::cleanBlocks(int i, int j)
{
  const int offI = i - i % 3;
  const int offJ = j - j % 3;
  for(int k = offI; k < offI + 3; k++)
  {
    for(int l = offJ; l < offJ + 3; l++)
    {
      probables[k][l].remove(grid[i][j]);
    }
  }
}



int main(void)
{
  while(!cin.eof()) {
    sudoku s;
    cin >> s;
    cout << s;
    s.solve();
    cout << s;
  }
  return 0;
}
