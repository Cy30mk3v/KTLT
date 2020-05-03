#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	int *a;
	int *max;
	int length;
	getArray(a, length);
	maxLength(a, length, max);
	trace(a, length, max);
}