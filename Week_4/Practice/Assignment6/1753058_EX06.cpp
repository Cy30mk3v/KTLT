#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	int n;
	char file[20]; //"input.bin";
	char file1[] = "split1.bin";
	char file2[20]; // "output.bin";
	printf("Input filename need to split: ");
	scanf("%s", file);
	printf("Input number of previous file after splitting ");
	scanf("%i", &n);
	printf("Input destination file after merging: ");
	scanf("%s", file2);
	split(file, n);
	merge(file2, n);
	return 0;
}