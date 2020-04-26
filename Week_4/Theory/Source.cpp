#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000


void copyFile(char *p1, char *p2)
{
	FILE *pa;
	FILE *pb;
	pa = fopen(p1, "rb");
	pb = fopen(p2, "wb");
	if (pa == NULL || pb == NULL)
		return;
	char BUFF[SIZE];
	int c;
	do
	{
		c = fread(BUFF, sizeof (char), SIZE, pa);
		fwrite(BUFF, sizeof(char), c, pb);
	} while (c == SIZE);
	fclose(pa);
	fclose(pb);
}