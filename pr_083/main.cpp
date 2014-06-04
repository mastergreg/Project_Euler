/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.cpp
* Creation Date : 10-05-2014
* Last Modified : Sun 18 May 2014 10:30:14 PM BST
* Created By : Greg Lyras <greglyras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/
#include <iostream>
#include <algorithm>
#include <list>
#include <deque>
#include <map>
#include <iterator>
#include <cmath>
#include <cassert>

#define DIMENSION 80

using namespace std;

unsigned int grid[DIMENSION][DIMENSION];
unsigned int gridCurrent[DIMENSION][DIMENSION];

bool acceptValue(unsigned int i, unsigned int j, unsigned int v)
{
  return gridCurrent[i][j] == 0 or v < gridCurrent[i][j];
}
int main(void)
{
  deque<pair<int, int> > lifo;
  for(auto i = 0; i < DIMENSION; i++) {
    for(auto j = 0; j < DIMENSION; j++) {
      cin >> grid[i][j];
      gridCurrent[i][j] = 0;
      cin.ignore(1, ',');
    }
    cin.ignore(1, '\n');
  }

  gridCurrent[0][0] = grid[0][0];
  lifo.push_back(pair<int, int>(0,0));
  while(!lifo.empty()) {
    unsigned int v;
    auto c = lifo.front();
    auto i = c.first;
    auto j = c.second;
    lifo.pop_front();

    if(i > 0) {
      v = gridCurrent[i][j] + grid[i-1][j];
      if(acceptValue(i-1, j, v)) {
        gridCurrent[i-1][j] = v;
        lifo.push_back(pair<int, int>(i-1, j));
      }
    }

    if(i < DIMENSION-1) {
      v = gridCurrent[i][j] + grid[i+1][j];
      if(acceptValue(i+1, j, v)) {
        gridCurrent[i+1][j] = v;
        lifo.push_back(pair<int, int>(i+1, j));
      }
    }

    if(j > 0) {
      v = gridCurrent[i][j] + grid[i][j-1];
      if(acceptValue(i, j-1, v)) {
        gridCurrent[i][j-1] = v;
        lifo.push_back(pair<int, int>(i, j-1));
      }
    }

    if(j < DIMENSION-1) {
      v = gridCurrent[i][j] + grid[i][j+1];
      if(acceptValue(i, j+1, gridCurrent[i][j] + grid[i][j+1])) {
        gridCurrent[i][j+1] = gridCurrent[i][j] + grid[i][j+1];
        lifo.push_back(pair<int, int>(i, j+1));
      }
    }

  }

  cout << gridCurrent[DIMENSION-1][DIMENSION-1] << endl;
  return 0;
}
