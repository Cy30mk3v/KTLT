#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main(void)
{
	int len;
	int *a;
	len = -1;
	while (len <= 0)
	{
		printf("Input number of elements: ");
		scanf("%i", &len);
	}
	a = new int[len];
	getArray(a, len);
	reverseArray(a, 0, len);
	printArray(a, 0, len);
	printf("%i\n", sumPosNumberinArray(a, len));
	printf("Distinct value in array: %i\n", distinctValue(a, 0, len));
	if (checkOdd(a, len))
	{
		printf("All elements are odd numbers!\n");
	}
	else
		printf("Not all elements are odd numbers!\n");
	printf("Max value: %i\n", getMax(a, len, a[0], 0));
}