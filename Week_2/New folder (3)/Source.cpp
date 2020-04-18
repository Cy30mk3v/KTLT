#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Header.h"



using namespace std;

void printArray(int n, int p[])
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem02.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(FILEOUT, "%i ", p[i]);
	}
	fclose(FILEOUT);
}

int checkPrime(int n)
{
	if (n < 2)
		return 0;
	else
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
				return 0;
		}
	return 1;
}

void sortingDescending(int n, int p[])
{
	for (int i = 0; i < n-1; i++)
	{
		
		for (int j = i + 1; j < n; j++)
		{
			if (p[i] < p[j])
				std:swap(p[i], p[j]);
		}
	}
}

void sortingAscending(int n, int p[])
{
	for (int i = 0; i < n - 1; i++)
	{

		for (int j = i + 1; j < n; j++)
		{
			if (p[i] > p[j])
				std:swap(p[i], p[j]);
		}
	}
}


void checkPrimeArray(int n, int p[])
{
	sortingDescending(n, p);
	for (int i = 0; i < n; i++)
	{
		if (checkPrime(p[i]) == 1)
		{
			printf("So nguyen to lon nhat: %i\n", p[i]);
			break;
		}
	}
}

void splitArray(int n, int p[], int *odd, int *even)
{
	int e = 0;
	int o = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] % 2 != 0)
		{
			odd[o++] = p[i];
		}
		else
		{
			even[e++] = p[i];
		}
	}
}

int posArray(int n, int p[], int p1[])
{
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] % 2 == 0)
		{
			p1[i] = 0;
			a++; //EVEN
		}
		else
		{
			p1[i] = 1; //ODD
		}
	}
	return a;
}

void sortingArray(int n, int p1[], int odd[], int even[], int p2[])
{
	 int o = 0;
	 int e = 0;
	for (int i = 0; i < n; i++)
	{
		if (p1[i] == 0)
		{
			p2[i] = even[e++];

		}
		else
		{
			p2[i] = odd[o++];
		}
	}
	printArray(n, p2);
}


void insertNumber(int n, int *p, int *odd, int o, int *even, int e, int*p1, int *p2)
{	
	int c;
	printf("Nhap so can chen: ");
	scanf("%i", &c);
	if (c % 2 == 0)
	{
		p1[n + 1] = 0;
		insertNumbertoEven(c, e-1, even);
		sortingArray(n + 1, p1, odd, even, p2);
	}
	else
	{
		p1[n + 1] = 1;
		insertNumbertoOdd(c, o, odd);
		sortingArray(n + 1, p1, odd, even, p2);
	}
	
}

void insertNumbertoOdd(int a, int o, int*odd)
{
	for (int i = 0; i < o; i++)
	{
		if (odd[i] > a)
		{
			for (int j = o; j > i; j--)
			{
				odd[j] = odd[j - 1];
			}
			odd[i] = a;
			break;
		}
		else (odd[o] = a);
	}
}

void insertNumbertoEven(int a, int e, int*even)
{
	for (int i = 0; i < e; i++)
	{
		if (even[i] < a)
		{
			for (int j = e; j > i; j--)
			{
				even[j] = even[j - 1];
			}
			even[i] = a;
			break;
		}
		else (even[e] = a);
	}
}


void removeInt(int &n, int p[], int pos)
{
	for (int i = pos + 1; i < n; i++)
	{
		p[i - 1] = p[i];
	}
	n--;
}

void removeSimilar(int n, int c[])
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n;j++)
		{
			if (c[i] == c[j])
			{
				removeInt(n, c, j);
				i--;
			}
		}
	}
}

int GCD2(int x, int y)
{
	if (x < y)
	{
		for (int i = x; i >= 1; i--)
		{
			if (x%i == 0 && y%i == 0)
			{
				return i;
			}
		}
	}
	else
		for (int i = y; i >= 1; i--)
		{
			if (x%i == 0 && y%i == 0)
			{
				return i;
			}
		}
}

int GCDArray(int n, int p[])
{
	int x=p[0];
	for (int i=1;i<n;i++)
	{
		x= GCD2(x, p[i]);
	}
	return x;
}

