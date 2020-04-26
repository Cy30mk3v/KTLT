#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void inputBinary(char *fileO, int &n)
{
	FILE *file;
	file = fopen(fileO, "wb");
	printf("Input number of elements: ");
	scanf("%i", &n);
	int *a = new int[n];
	fwrite(&n, sizeof(int), 1, file);
	inputArray(n, a);
	fwrite(a, sizeof(int), n, file);
	fclose(file);
}

void inputArray(int n, int *&a)
{
	for (int i = 0; i < n; i++)
	{
		printf("A[%i]= ", i);
		scanf("%i", &a[i]);
	}
}