#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>

struct BmpSignature
{
	unsigned char data[2];
};

#pragma pack(1)
struct BmpHeader
{
	BmpSignature signature;
	uint32_t fileSize;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t dataOffset;
};

struct BmpDib
{
	uint32_t dibSize;
	int32_t	 imageWidth;
	int32_t  imageHeight;
};


bool isBmpFile(FILE *f);

void readBmpHeader(FILE *f, BmpHeader &header);

void readBmpDib(FILE *f, BmpDib &dib);
void printBmpDib(BmpDib dib);

