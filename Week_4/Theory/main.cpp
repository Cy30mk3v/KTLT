#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void main()
{
	char file1[20];
	char file2[20];
	printf("Input name file 1: ");
	scanf("%s", file1);
	printf("Input name file 2: ");
	scanf("%s", file2);
	copyFile(file1, file2);
}