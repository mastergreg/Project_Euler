/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.c
* Creation Date : 23-07-2012
* Last Modified : Mon 23 Jul 2012 09:15:30 PM EEST
* Created By : Greg Liras <gregliras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int accept(int s);
int main(void)
{
    int i;
    int count;
    for( count=0,i=10; i<1000000001; i++)
    {
        if(accept(i))
        {
            count++;
            printf("\ri: %10.0d\tcount: %10.0d",i,count);
            fflush(stdout);
        }
    }
    return 0;
}

int accept(int s)
{
    int s2;
    int i;
    int bs;
    if(s % 10 == 0)
    {
        return 0;
    }
    i = 0;
    bs = s;
    s2 = 0;
    for(bs=s; bs > 0; bs /= 10)
    {
        s2 *= 10;
        s2 += bs%10;
    }
    s2+=s;
    bs = s2;
    for(bs=s2; bs > 0; bs /= 10)
    {
        if ((bs & 1) == 0)
        {
            return 0;
        }
    }
    return 1;
}


