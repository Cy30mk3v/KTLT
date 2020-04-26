#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void readBinary(char *file, int &n, int *&a)
{
	FILE *filein;
	filein = fopen(file, "rb");
	fread(&n, sizeof(int), 1, filein);
	a = new int[n];
	fread(a, sizeof(int), n, filein);
	fclose(filein);
}

int maxArray(int n, int *&a)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}