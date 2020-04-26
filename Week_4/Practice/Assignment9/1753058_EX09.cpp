#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


void main()
{
	BmpHeader header;
	header.signature.data[0] = 'B';
	header.signature.data[1] = 'M';
	header.fileSize = 1620054;
	header.reserved1 = 0;
	header.reserved2 = 0;
	header.dataOffset = 54;

	BmpDib dib;
	dib.dibSize = 40;
	dib.imageWidth = 900;
	dib.imageHeight = 600;
	dib.colorPlaneCount = 1;
	dib.pixelSize = 24;
	dib.compressMethod = 0;
	dib.bitmapByteCount = 1620000;
	dib.horizontalResolution = 4724;
	dib.verticalResolution = 4724;
	dib.colorCount = 0;
	dib.importantColorCount = 0;


	PixelArray data;
	data.pixels = (Color**)malloc(600 * sizeof(Color*));
	for (int i = 0; i <= 199; i++)
	{
		data.pixels[i] = (Color*)malloc(900 * sizeof(Color));
		for (int j = 0; j <= 899; j++)
		{
			data.pixels[i][j].blue = 255;
			data.pixels[i][j].green = 255;
			data.pixels[i][j].red = 255;
		}
	}

	for (int i = 200; i <= 399; i++)
	{
		data.pixels[i] = (Color*)malloc(900 * sizeof(Color));
		for (int j = 0; j <= 899; j++)
		{
			data.pixels[i][j].blue = 255;
			data.pixels[i][j].green = 0;
			data.pixels[i][j].red = 0;
		}
	}
	for (int i = 400; i <= 599; i++)
	{
		data.pixels[i] = (Color*)malloc(900 * sizeof(Color));
		for (int j = 0; j <= 899; j++)
		{
			data.pixels[i][j].blue = 0;
			data.pixels[i][j].green = 0;
			data.pixels[i][j].red =255;
		}
	}

	FILE *f1;

	f1 = fopen("Russian_flag.bmp", "wb");
	writeFileBMP(f1, header, dib, data);

	releaseBmpPixelArray(data);
	fclose(f1);
}