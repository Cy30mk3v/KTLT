#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	int n;
	Fraction p;
	char file[] = "output.bin";
	writeFraction(file, n);
	return 0;

}
