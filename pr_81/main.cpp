/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 06-10-2011

 * Last Modified : Sat 08 Oct 2011 08:46:31 PM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/


#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
bool sumCmp (const int *a,const int *b)
{
  return a[1]<b[1];
}
int nodes[6400];
int main()
{
  int i,j; //value,adjacent,directly below
  int temp;
  deque<int *> myQueue,buffQueue;
  for ( i = 0 ; i < 80 ; i++)
  {
    for ( j = 0 ; j < 80 ; j++)
    {
      temp=i*80+j;
      cin >> nodes[temp] ;
      //cout << nodes[temp] << endl;
    }
  }

  int *start = new int[2];
  int *buf;
  int *current;
  deque<int*>::iterator it;
  start[0]=0; //position
  start[1]=nodes[0]; //current sum



  myQueue.push_back(start);
  while (true)
  {

    it = min_element(myQueue.begin(),myQueue.end(),sumCmp);

    current = *it;
    cout << myQueue.size() << " " << current[0] << " " << current[1] << endl;
    myQueue.erase(it);
    if (current[0]==6399)
    {
      cout << "Found " << current[1];
      exit(0);
    }
    buf = new int[2];
    buf[0]=current[0]+1;  //right
    if ( buf[0] % 80 != 0)
    {
      buf[1]=current[1]+nodes[buf[0]];
      myQueue.push_back(buf);
    } 
    else
    {
      cout << buf[0] << " right out" << endl;
      delete buf;
    }

    buf = new int[2];
    buf[0]=current[0]+80;  //bottom
    if (buf[0] / 80  != 80)
    {
      buf[1]=current[1]+nodes[buf[0]];
      myQueue.push_back(buf);
    }
    else
    {
      cout << buf[0] << " bottom out" << endl;
      delete buf;
    }
    delete current;
  }

  return 0;
}


