/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 06-10-2011

 * Last Modified : Mon 10 Oct 2011 12:39:46 AM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/


#include <iostream>
#include <algorithm>

#define GRID_SIZE 80 
using namespace std;
bool sumCmp (const int *a,const int *b)
{
  return a[1]+80-(a[0]/80+a[0]%80)<b[1]+80-(b[0]/80+b[0]%80);
}
int nodes[GRID_SIZE][GRID_SIZE];
int main()
{
  int i,j;
  for ( i = 0 ; i < GRID_SIZE ; i++)
  {
    for ( j = 0 ; j < GRID_SIZE ; j++)
    {
      cin >> nodes[i][j] ;
    }
  }

  for ( i = 1 ; i < GRID_SIZE ; i++)
  {
    nodes[0][i]+=nodes[0][i-1];
    nodes[i][0]+=nodes[i-1][0];
  }
  

  for ( i = 1 ; i < GRID_SIZE ; i++)
  {
    for ( j = 1 ; j < GRID_SIZE ; j++)
    {
      nodes[i][j]+=min(nodes[i-1][j],nodes[i][j-1]);
    }
  }
  cout << nodes[79][79] << endl;


  return 0;
}


