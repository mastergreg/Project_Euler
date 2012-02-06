/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.cpp

 * Purpose :

 * Creation Date : 14-10-2011

 * Last Modified : Mon 06 Feb 2012 10:00:07 AM EET

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>

#define L_LIMIT 97
#define H_LIMIT 122


using namespace std;

bool accept(char c)
{
  return c == ' ' || ( c >= 97 && c <= 122) || ( c >= 65 && c <= 90);
}

bool decode(char *text,char *dtext, char key[3])
{
  int i,counter=0;
  bool flag = false;
  for( i = 0 ; i < 1201 ; i ++)
  {
    dtext[i] = text[i] ^ key[i%3];
    if (accept(dtext[i]))
    {
      flag = true;
    }
    else
    {
      cout << dtext[i] << endl;
      flag = false;
      break;
    }
    counter+=dtext[i];
  }
  if (flag)
  {
    cout << endl << counter << " " << key[0] << key[1] << key[2] << endl;
  }
  return flag;

}


int main()
{
  char text[1201];
  char dtext[1201];
  char c;
  int b;
  int i,j,k;
  char key[3];
  for ( i = 0 ; i < 1201 ; i++ )
  {
    cin >> b;
    //cout << i << "\r" << flush;
    text[i]=b;
  }
  for ( i = 97 ; i <= 122 ; i++ )
  {
    cout << i << "\r" << flush;
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


