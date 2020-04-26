#pragma once
#define _CRT_SECURE_NO_WARNINGS


struct BmpSignature
{
	unsigned char data[2];
};



bool isBmpFile(FILE *f);

