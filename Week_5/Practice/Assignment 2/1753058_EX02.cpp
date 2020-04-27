#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Header.h"

int main(void)
{
	char a[100];
	printf("Input string: ");
	scanf("%[^\n]s", &a);
	puts(a);
	
	int n = strlen(a);
	removeSpace(a, n);
	removeSpacemiddle(a, n);
	Capitalize(a, n);
	
	puts(a);
}