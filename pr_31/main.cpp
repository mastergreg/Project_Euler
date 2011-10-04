/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : main.c

 * Purpose :

 * Creation Date : 04-10-2011

 * Last Modified : Tue 04 Oct 2011 06:13:13 AM EEST

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>

using namespace std;

int main()
{
  int one_p,two_p,five_p,ten_p,twenty_p,fifty_p,one_P;
  int money=0;
  long long c=1;
  for (one_p = 0 ; one_p <= 200; one_p++)
  {
    cout << one_p << endl;
    for (two_p = 0 ; two_p <= 200; two_p+=2)
    {
      for (five_p = 0 ; five_p <= 200; five_p+=5)
      {
        for (ten_p = 0 ; ten_p <= 200; ten_p+=10)
        {
          for (twenty_p = 0 ; twenty_p <= 200; twenty_p+=20)
          {
            for (fifty_p = 0 ; fifty_p <= 200; fifty_p+=50)
            {
              for (one_P = 0 ; one_P <= 200; one_P+=100)
              {
                money = one_p + two_p + five_p + ten_p + twenty_p + fifty_p + one_P;
                if (money == 200)
                {
                  c++;
                }
              }
            }
          }
        }
      }
    }
  }
  cout << c << endl;

}

