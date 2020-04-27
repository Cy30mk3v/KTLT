#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Header.h"

int main()
{
	char A[50];
	printf("Input string: ");
	gets_s(A);
	puts(A);
	if (check(A))
	{
		printf("Palindrome!");
	}
	else
		printf("Not palindrome!");
}