#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "bmp.h"


void drawBmp(BmpDib dib, PixelArray data)
{
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);

	for (int i = 0; i < dib.imageHeight; i++)
		for (int j = 0; j < dib.imageWidth; j++)
		{
			Color pixel = data.pixels[i][j];
			SetPixel(hdc, j, i, RGB(pixel.red, pixel.green, pixel.blue));
		}

	ReleaseDC(console, hdc);
}

void releaseBmpPixelArray(PixelArray data)
{
	for (int i = 0; i < data.rowCount; i++)
		delete[]data.pixels[i];

	delete[]data.pixels;
}

void writeFileBMP(FILE *file, BmpHeader header, BmpDib dib, PixelArray &Data)
{
	if (file == NULL)
		return;

	fwrite(&header, sizeof(BmpHeader), 1, file);
	fseek(file, sizeof(BmpHeader), 0L);
	fwrite(&dib, sizeof(BmpDib), 1, file);

	Data.rowCount = dib.imageHeight;
	Data.columnCount = dib.imageWidth;

	char paddingCount = (4 - (dib.imageWidth * (dib.pixelSize / 8) % 4)) % 4;

	fseek(file, header.dataOffset, 0L);

	for (int i = 0; i < Data.rowCount; i++)
	{
		writeBmpPixelLine(file, Data.pixels[Data.rowCount - i - 1], dib.imageWidth);
		addBmpPadding(file, paddingCount);
	}

}

void addBmpPadding(FILE *f, char count)
{
	if (f == NULL)
		return;

	if (count == 0)
		return;

	char padding[3];
	fwrite(padding, count, 1, f);
}

void writeBmpPixelLine(FILE *f, Color *&line, uint32_t length)
{
	if (f == NULL)
		return;

	fwrite(line, sizeof(Color), length, f);
}