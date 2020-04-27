#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void towerOfHanoi(int n, char start, char finish, char middle)
{
	if (n == 1)
	{
		printf("Move disk 1 from %c to %c\n", start, finish);
		return;
	}
	towerOfHanoi(n - 1, start, middle, finish);
	printf("Move disk %i from %c to %c\n", n, start, finish);
	towerOfHanoi(n - 1, middle, finish, start);
}

