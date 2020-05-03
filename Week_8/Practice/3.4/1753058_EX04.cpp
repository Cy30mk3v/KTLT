#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	SList L;
	L.head = NULL;
	int x, pos, flag;
	char fin[20];
	char fout[20];
	printf("Input filename: ");
	gets_s(fin);
	getData(fin, L, flag);
	if (flag == 1)
	{
		printf("Input filename return: ");
		gets_s(fout);

		printf("Input number you want to add before value you choose:");
		scanf("%i %i", &x, &pos);
		insertBefore(L, x);
		printList(L.head);
		printData(fout, L);
	}
}