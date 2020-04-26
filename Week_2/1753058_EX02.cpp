#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Header.h"

using namespace std;

int main(void)
{
	int n, o, e, d;
	int *p;
	int *p1, *p2;
	FILE * FILEIN;
	FILEIN = fopen("problem01.txt", "r");
	fscanf(FILEIN, "%i", &n);
	p = new int[n + 1];
	p1 = new int[n+1];
	p2 = new int[n+1];
	for (int i = 0; i < n; i++)
	{
		fscanf(FILEIN, "%i", &p[i]);
	}
	fclose(FILEIN);
	printArray(n, p);
	int a = posArray(n, p, p1);
	int *even = new int[a+1];
	int *odd = new int[n - a+1];
	sortingDescending(n, p);
	checkPrimeArray(n, p);
	splitArray(n, p, odd, even);
	sortingAscending(n-a, odd);
	sortingDescending(a, even);
	sortingArray(n, p1, odd, even, p2);
	for (int i = 0; i < n; i++)
	{
		printf("%i", p2[i]);
	}
	insertNumber(n, p, odd, n-a, even, a, p1, p2);
	removeSimilar(n + 1, p2);
	for (int i = 0; i < n; i++)
	{
		printf("%i", p2[i]);
	}
	printf("\n%i", GCDArray(n + 1, p2));
	printArray(n+1, p2);
	printf("\n");
	system("pause");
}