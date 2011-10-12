/*
 * main.c
 *
 *  Created on: Jul 26, 2010
 *      Author: master
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double denum(int n);
double kapa(int n);
float arithmhths(int i);
float paronomasths(int i);
void klasma(int i);

static double kapas[1000];


int main(int argc, char **argv)
{
	int i;
	for (i=1;i<1000;i++)
	{
//		printf("%d\t\t",i);
		kapas[i]=kapa(i);
		printf("%.78f\n",kapas[i]);
	}
	for (i=1;i<1000;i++)
	{
		printf("%d\t",i);
		klasma(i);
	}
	return 0;
}

void klasma(int i)
{
	printf("%.0f/", arithmhths(i));
	printf("%.0f\n", paronomasths(i));
}

float paronomasths(int i)
{
	double f = 2 * kapas[i] + 1;
	while (i > 1)
	{
		i--;
		f = f * kapas[i];
	}
	return f;
}
float arithmhths(int i)
{
	double f = 3 * kapa(i) + 1;
	while (i > 1)
	{
		i--;
		f = f * kapa(i);
	}
	return f;
}
double kapa(int n)
{
	double f;
	if (n == 1)
	{
		return 2.;
	}
	else
	{
		f=kapas[n-1];
		return (2 * f + 1) / f;
	}
}

double denum(int n)
{
	double f;
	if (n == 1)
	{
		return 2.;
	}
	else
	{
		f = denum(n - 1);
		return (2 + 1 / f);
	}
}
