#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void main()
{
	char file[] = "input.bin";
	int n;
	int *a;
	readBinary(file, n, a);
	printf("Max element in array: %i", maxArray(n,a));
}