/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 15-10-2011

 * Last Modified : Sun 16 Oct 2011 12:47:31 PM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/



#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <deque>
using namespace std;

  template < class V >
ostream& operator<< (ostream &out, vector<V> &v) 
{
  copy(v.begin(), v.end(), ostream_iterator<V>(out, ", ") );
  return out;
}


  template <class T>
inline string to_string (const T& t)
{
  stringstream ss;
  ss << t;
  return ss.str();
}
vector<unsigned int> to_vector(unsigned int i)
{
  vector<unsigned int> v;
  unsigned int limit = log10(i)+1;
  unsigned int b;
  for(b=0;b<limit;b++)
  {
    v.push_back(i%10);
    i/=10;
  }
  return v;
}

unsigned long long  compute(vector<unsigned int> st)
{
  unsigned long long computed=0;
  unsigned int i;
  for (i=0;i<st.size();i++)
  {
    computed+=pow(st[i],i);
  }
  return computed;

}


vector<unsigned int> frequency(vector<unsigned int> v1)
{
  vector<unsigned int> freqs(10,0);
  unsigned int i;
  for(i=0;i<v1.size();i++)
  {
    freqs[i]++;
  }
  return freqs;
}

unsigned int permutations(vector<unsigned int> v1,deque<vector<unsigned int> > deq)
{
  unsigned int counter=0;
  deque<vector<unsigned int> >::iterator it = deq.begin();

  while(it!=deq.end())
  {
    if (v1 == *it)
    {
      counter++;
    }
    it++;
  }
  return counter;
  

}



int main()
{
  unsigned long long i=4;
  unsigned int size=1;
  unsigned long long cube=0;
  unsigned int counter;
  vector<unsigned int> st;
  vector<unsigned int> head;
  deque<vector<unsigned int> > queue;

  cout << "Hello"<<endl;
  while(true)
  {
    counter=0;
    do
    {
      cube=pow(i,3);
      st = to_vector(cube);
      queue.push_back(frequency(st));
      i++;
    }
    while(st.size()==size);

    while(queue.size()>1 && counter!=5)
    {
      head = queue.front();
      queue.pop_front();
      counter=permutations(head,queue);
      if (counter == 5)
      {
        cout << head;
        cout << "\t" << queue.size() << endl;
        return 0;
      }
    }
    queue.clear();
    cout << size <<" "<<i << endl;
    cout << "just gimme an int" << endl;
    cin >> cube;
    size++;
  }

  return 0;


}
