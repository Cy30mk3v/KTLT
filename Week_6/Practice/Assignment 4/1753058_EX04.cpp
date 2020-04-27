#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void main()
{
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int n;
	printf("Input number of disks: ");
	scanf("%i", &n);
	towerOfHanoi(n, a, c, b);

}