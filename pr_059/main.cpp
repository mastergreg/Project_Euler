/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 14-10-2011

 * Last Modified : Fri 14 Oct 2011 06:45:10 AM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>

#define L_LIMIT 97
#define H_LIMIT 122


using namespace std;

bool accept(int *dtext,int c)
{
  return dtext[c-2]=='t' && dtext[c-1] == 'h' && dtext[c] == 'e';
}

bool decode(int *text,int *dtext, int key[3])
{
  int i,counter=0;
  bool flag = false;
  for( i = 0 ; i < 1201 ; i ++)
  {
    dtext[i] = text[i] ^ key[i%3];
    if (accept(dtext,i))
    {
      flag = true;
    }
    counter+=dtext[i];
  }
  if (flag)
  {
    cout << counter << " " << key[0] << key[1] << key[2] << endl;
  }

}


int main()
{
  int text[1201];
  int dtext[1201];
  char c;
  int b,i,j,k,key[3];
  for ( i = 0 ; i < 1201 ; i++ )
  {
    cin >> b >> c;
    text[i]=b;
  }
  for ( i = 97 ; i <= 122 ; i++ )
  {
    for ( j = 97 ; j <= 122 ; j++ )
    {
      for ( k = 97 ; k <= 122 ; k++ )
      {
        key[0]=i;
        key[1]=j;
        key[2]=k;
        decode(text,dtext,key);
      }
    }
  }



}


