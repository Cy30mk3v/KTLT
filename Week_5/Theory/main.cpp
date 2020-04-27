#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bmp.h"

void changeBmp(PixelArray &p)
{
	for (int i = 0; i < p.rowCount; i++)
		for (int j = 0; j < p.columnCount; j++)
		{
			if (p.pixels[i][j].red == 255 && p.pixels[i][j].green == 0 && p.pixels[i][j].blue == 0)
			{
				p.pixels[i][j].red = 255;
				p.pixels[i][j].green = 0;
				p.pixels[i][j].blue = 255;
			}
		}
}

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
	printBmpHeader(header);

	BmpDib dib;
	readBmpDib(f, dib);
	printBmpDib(dib);

	PixelArray data;
	readBmpPixelArray(f, header, dib, data);

	fclose(f);
	getchar();

	int i = -1;
	int j = -1;
	while (i<0 || i >dib.imageHeight)
	{
		printf("Input the i: ");
		scanf("%i", &i);
	}
	while (j<0 || j>dib.imageWidth)
	{
		printf("Input the j: ");
		scanf("%i", &j);
	}
	printf("R:%i G:%i B:%i", data.pixels[i][j].red, data.pixels[i][j].green, data.pixels[i][j].blue);

	changeBmp(data);
	drawBmp(dib, data);
	char file1[20];
	printf("Input file name to print: ");
	scanf("%s", file1);
	FILE *f1 = fopen(file1, "wb");
	writeFileBMP(f1, header, dib, data);
	fclose(f1);


	
	releaseBmpPixelArray(data);
}