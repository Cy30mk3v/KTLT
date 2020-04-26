#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include "Header.h"

void loadFraction(char *filein, char *fileout, int &n)
{
	FILE *f1;
	FILE *f2;
	f1 = fopen(filein, "rb");
	f2 = fopen(fileout, "wb");
	fread(&n, sizeof(int), 1, f1);
	Fraction *A = new Fraction[n];
	fread(A, sizeof(Fraction), n, f1);
	ascendingArray(n, A);
	fwrite(&n, sizeof(int), 1, f2);
	fwrite(A, sizeof(Fraction), n, f2);
	fclose(f1);
	fclose(f2);
}

void ascendingArray(int n, Fraction *&p)
{
	for (int i = 0; i < n; i++)
	{
		float x = p[i].nu / p[i].de;
		float y = p[i++].nu / p[i].de;
		if (x > y)
		{
			std::swap(p[i], p[i++]);
		}
	}
}