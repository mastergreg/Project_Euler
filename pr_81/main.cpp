/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 06-10-2011

 * Last Modified : Mon 10 Oct 2011 12:23:02 AM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/


#include <iostream>
#include <deque>
#include <algorithm>
#include <time.h>

#define GRID_SIZE 80 
using namespace std;
bool sumCmp (const int *a,const int *b)
{
  return a[1]+80-(a[0]/80+a[0]%80)<b[1]+80-(b[0]/80+b[0]%80);
}
int nodes[GRID_SIZE*GRID_SIZE];
int main()
{
  int i,j; //value,adjacent,directly below
  int temp;
  time_t seconds = time(NULL);
  deque<int *> myQueue,buffQueue;
  for ( i = 0 ; i < GRID_SIZE ; i++)
  {
    for ( j = 0 ; j < GRID_SIZE ; j++)
    {
      temp=i*GRID_SIZE+j;
      cin >> nodes[temp] ;
    }
  }

  int *start = new int[2];
  int *buf;
  int *current;
  int grid_max = GRID_SIZE*GRID_SIZE-1;
  deque<int*>::iterator it;
  start[0]=0; //position
  start[1]=nodes[0]; //current sum



  myQueue.push_back(start);
  while (true)
  {

    //it = min_element(myQueue.begin(),myQueue.end(),sumCmp);

    current = myQueue.front();//*it;
    cout << myQueue.size() << "\t\t" 
      << current[0] << "\t\t" 
      << current[1] << " Running for: " 
      <<time(NULL) - seconds << " seconds\r"<<flush;
    //myQueue.erase(it);
    myQueue.pop_front();
    if (current[0]==grid_max)
    {
      cout << endl << "Found " << current[1] << endl;
      exit(0);
    }
    buf = new int[2];
    buf[0]=current[0]+1;  //right
    if ( buf[0] % GRID_SIZE != 0)
    {
      buf[1]=current[1]+nodes[buf[0]];
      myQueue.push_back(buf);
      if (buf[0]==grid_max)
      {
        cout << endl << "Found " << buf[1] << endl;
        exit(0);
      }
    } 
    else
    {
      delete buf;
    }

    buf = new int[2];
    buf[0]=current[0]+GRID_SIZE;  //bottom
    if (buf[0] / GRID_SIZE  != GRID_SIZE)
    {
      buf[1]=current[1]+nodes[buf[0]];
      myQueue.push_back(buf);
      if (buf[0]==grid_max)
      {
        cout << endl << "Found " << buf[1] << endl;
        exit(0);
      }
    }
    else
    {
      delete buf;
    }
    delete current;
  }

  return 0;
}


