#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void main()
{
	char file[20];
	printf("Input filename:");
	scanf("%s", file);
	FILE *f = fopen(file, "rb");

	if (!isBmpFile(f))
	{
		printf("Not BMP file!\n");
		return;
	}
	printf("Is BMP file!\n");
}