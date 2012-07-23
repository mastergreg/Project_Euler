/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.c
* Creation Date : 22-07-2012
* Last Modified : Mon 23 Jul 2012 03:00:42 PM EEST
* Created By : Greg Liras <gregliras@gmail.com>
_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HP_SIZE 70000

struct hp
{
    int filled;
    int primes[HP_SIZE];
    struct hp* next;
};
typedef struct hp hp;

void append(int i, hp* h);
unsigned long long gcd(unsigned long long a,unsigned long long b);
int getPrime(int i, hp* h);
int fillPrimes(int limit, hp* h);
int isPrime(int p, int count, hp* h);
int phi(int n, int count, hp* h);
int accept(int a, int b);

int main(void)
{
    /*
     * Initialize the head of the primes
     */
    int totalPrimes = 0;
    int i;
    int minn = 1e8;
    int minp = 1e8;
    double minDIV = 1e8;
    double curDIV = 1e8;
    int p = 0;
    hp head;
    head.filled = 1;
    head.primes[0] = 2;
    head.next = NULL;
    int *phis = malloc(10000000*sizeof(int));



    printf("Starting primes calc\n");
    totalPrimes = fillPrimes(10000000, &head);

    printf("Starting phi calc\n");
    for(i=100 ; i < 10000000 ; i++)
    {
        p = phi(i, totalPrimes, &head);
        phis[i] = p;
    }

    printf("Searching \n");
    for(i=101 ; i < 10000000 ; i++)
    {
        p = phis[i];
        if(accept(i,p))
        {
            curDIV = (double) i/p;
            if(curDIV < minDIV)
            {
                minDIV = curDIV;
                minn = i;
                minp = p;
                printf("\rmin:%lf\ti:%d\tphi(i):%d",minDIV, minn, minp);
                fflush(stdout);
            }
        }

    }

    free(phis);

    return 0;
}

int cmp(const void* a, const void* b)
{
    return (*(char *)b)-(*(char *)a);
}

int accept(int a, int b)
{
    char aS[10];
    char bS[10];
    int i;
    sprintf(aS, "%d", a);
    sprintf(bS, "%d", b);

    int la = strlen(aS);
    int lb = strlen(bS);
    if(la != lb)
    {
        return 0;
    }
    qsort(aS, la, sizeof(char), cmp);
    qsort(bS, lb, sizeof(char), cmp);
    for(i=0; i<la;i++)
    {
        if(aS[i] != bS[i])
        {
            return 0;
        }
    }
    return 1;
}

int phi(int n, int count, hp* h)
{
    int i;
    double lim = sqrt(n);
    int p;
    int ans;
    unsigned long long num = n;
    unsigned long long denom = 1;
    int alloc = 0;
    unsigned long long gd;
    int *allocated = malloc(10000*sizeof(int));
    for( i=0 ; i <= count ;i++)
    {
        p = getPrime(i, h);
        if( p > lim )
        {
            if(isPrime(n, count, h))
            {
                allocated[alloc] = n;
                alloc++;
            }
            break;
        }
        if(n % p == 0)
        {
            n /= p;
            allocated[alloc] = p;
            alloc++;
        }
    }
    for( i=0 ; i<alloc ; i++)
    {
        num *= allocated[i]-1;
        denom *= allocated[i];

        gd = gcd(num, denom);
        num /= gd;
        denom /= gd;

    }

    free(allocated);
    ans = num/denom;
    return ans;

}

int isPrime(int p, int count, hp* h)
{
    int i;
    double lim = sqrt(p);
    int cur;
    for( i=0 ; i <= count ;i++)
    {
        cur = getPrime(i,h);
        if(cur > lim )
        {
            return 1;
        }
        if( p%cur == 0)
        {
            return 0;
        }
    }
    return 1;
}

int fillPrimes(int limit, hp* h)
{
    int i;
    int count = 1;
    for( i=3; i<limit; i++)
    {
        if(isPrime(i,count, h))
        {
            append(i, h);
            count++;
        }
    }
    return count;
}

int getPrime(int i, hp* h)
{
    int depth = i/HP_SIZE;
    hp* current = h;
    for( ; depth > 0 ; depth--)
    {
        current = current -> next;
    }
    return current->primes[i%HP_SIZE];
}

void append(int i, hp* h)
{
    if (h->filled < HP_SIZE)
    {
        h->primes[h->filled] = i;
        h->filled++;
    }
    else
    {
        if(h->next != NULL)
        {
            append(i,h->next);
        }
        else
        {
            h->next = malloc(sizeof(hp));
            h->next->filled=0;
            h->next->next=NULL;
            append(i,h->next);
        }
    }
}

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if (b == 0)
    {
        return a;
    }
    else if (a >= b)
    {
        return gcd(b,a % b);
    }
    else
    {
        return gcd(b,a);
    }
}

