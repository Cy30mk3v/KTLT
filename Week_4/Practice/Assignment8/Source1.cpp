#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "bmp.h"

bool isBmpFile(FILE *f)
{
	if (f == NULL)
		return false;

	BmpSignature signature;
	fseek(f, 0, 0L);
	fread(&signature, sizeof(BmpSignature), 1, f);

	return signature.data[0] == 'B' && signature.data[1] == 'M';
}

void readBmpHeader(FILE *f, BmpHeader &header)
{
	if (f == NULL)
		return;

	fseek(f, 0, 0L);
	fread(&header, sizeof(BmpHeader), 1, f);
}

void readBmpDib(FILE *f, BmpDib &dib)
{
	if (f == NULL)
		return;

	fseek(f, sizeof(BmpHeader), 0L);
	fread(&dib, sizeof(BmpDib), 1, f);
}

void printBmpDib(BmpDib dib)
{
	
	printf("- Size               : %d byte(s)\n", dib.dibSize);
	printf("- Image Width            : %d\n", dib.imageWidth);
	printf("- Image Height           : %d\n", dib.imageHeight);
}

