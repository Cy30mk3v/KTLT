#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void copy(char *src, char *des)
{
	FILE *f1 = fopen(src, "rb");
	FILE *f2 = fopen(des, "wb");
	if (f1 == NULL || f2 == NULL)
		return;
	char BUFF[1000];
	int count;
	do
	{
		count = fread(BUFF, sizeof(char), 1000, f1);
		fwrite(BUFF, sizeof(char), count, f2);
	} while (count == 1000);
	fclose(f1);
	fclose(f2);
}