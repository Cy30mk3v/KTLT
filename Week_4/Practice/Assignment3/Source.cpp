#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void inputFraction(int n, Fraction *&p)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan so thu %i\n", i + 1);
		printf("Tu: ");
		scanf("%i", &p[i].nu);
		printf("Mau: ");
		scanf("%i", &p[i].de);
		while (p[i].de == 0)
		{
			printf("Mau: ");
			scanf("%i", &p[i].de);
		}
	}
}

void writeFraction(char * file, int &n)
{
	FILE *f;
	f = fopen(file, "wb");
	printf("Input number of element:");
	scanf("%i", &n);
	Fraction *frac = new Fraction[n];
	fwrite(&n, sizeof(int), 1, f);
	inputFraction(n, frac);
	fwrite(frac, sizeof(Fraction), n, f);
	fclose(f);
}