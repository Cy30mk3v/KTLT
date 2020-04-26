#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bmp.h"


void main()
{
	char file[20];
	printf("Input file name: ");
	scanf("%s", file);
	FILE *f = fopen(file, "rb");

	if (!isBmpFile(f))
	{
		printf("Not Bmp File.\n");
		return;
	}

	BmpHeader header;
	readBmpHeader(f, header);

	BmpDib dib;
	readBmpDib(f, dib);
	printBmpDib(dib);

}