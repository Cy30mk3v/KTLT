#include <stdio.h>
#include "Header.h"

int findpos(int x, int a[], int left, int right)
{
	int mid;
	if (left > right)
		return -1;
	mid = (right + left) / 2;
	if (a[mid] == x)
		return mid;
	if (a[mid] > x)
		return findpos(x, a, left, mid - 1);
	if (a[mid] < x)
		return findpos(x, a, mid + 1, right);
}

void getArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("A[%i]=", i);
		scanf_s("%i", &a[i]);
	}
}

int checkPrime(int n)
{
	if (n <2)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int printPrime(int n, int a[])
{
	if (n == 0)
		return 0;
	else if (checkPrime(a[n]) == 1)
	{
		printf(" %i", a[n]);
	}
	n--;
	return printPrime(n, a);
}