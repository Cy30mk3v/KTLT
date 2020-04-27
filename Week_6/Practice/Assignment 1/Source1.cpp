#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Header.h"

int Fibonacci(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int countx(int n)
{
	if (n == 0)
		return 1;
	else 
		return  countx(n - 1) + county(n - 1);
}

int county(int n)
{
	if (n == 0)
		return 0;
	else
		return 3 * countx(n - 1) + 2 * county(n - 1);
}

int countX1(int n, int i)
{

}

int combination(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	else if (n > k)
		return combination(n - 1, k) + combination(n - 1, k - 1);
	return 0;
}

void toBinary(int x)
{
	if (x == 0)
		return;
	else
	{
		toBinary(x / 2);
		printf("%i", x % 2);
	}
}


int Digits(int n)
{
	if (n == 0)
		return 0;
	else
		return (n % 10 + Digits(n / 10));
}

void sumOfDigits(int n)
{
	printf("\n%i", Digits(n));
}





