#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void main()
{
	int c1, c2, c3, c4k, c4n, c5, c6;
	printf("Input number of elements fibo:");
	scanf("%i", &c1);
	printf("%i", Fibonacci(c1));
	printf("Input number n of x(n) and y(n): ");
	scanf("%i", &c2);
	printf("%i %i\n", countx(c2), county(c2));
	printf("Input N and K of combination:");
	scanf("%i %i", &c4n, &c4k);
	printf("%i\n", combination(c4n, c4k));
	printf("Input number to convert to binary:");
	scanf("%i", &c5);
	toBinary(c5);
	printf("Input number to calculate sum of digits:");
	scanf("%i", &c6);
	sumOfDigits(c6);

}