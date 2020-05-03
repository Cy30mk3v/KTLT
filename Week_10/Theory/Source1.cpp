#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"


void maxLength(int *a, int length, int *&max)
{
	max = new int[length];
	for (int i = 0; i < length; i++)
	{
		max[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] <= a[i] && max[i] < max[j] + 1)
			{
				max[i] = max[j] + 1;
			}
		}
	}
}

void trace(int *a, int length, int maxlength[])
{
	int maxI;
	maxI = 0;
	for (int i = 1; i < length; i++)
	{
		if (maxlength[i] > maxlength[maxI])
			maxI = i;
	}
	int *s;
	int max = maxlength[maxI];
	s = new int[max + 1];
	int t = max;
	while (maxI>=0&&max>0)
	{
		if (maxlength[maxI] == max)
		{
			s[max] = a[maxI];
			max--;
		}
		maxI--;
	}
	for (int i = 1; i <= t; i++)
	{
		printf("%i ", s[i]);
	}
}

void getArray(int *&a, int &length)
{
	printf("Input number of values in array: ");
	scanf("%i", &length);
	a = new int[length];
	for (int i = 0; i < length; i++)
	{
		printf("A[%i]= ", i);
		scanf("%i", &a[i]);
	}
}