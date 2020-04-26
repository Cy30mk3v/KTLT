#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	char f1[20];
	char f2[20];
	printf("Write source file's name: ");
	scanf("%s", f1);
	printf("Write destination file's name: ");
	scanf("%s", f2);
	copy(f1, f2);
}