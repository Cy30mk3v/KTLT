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
	printf("Input filename return: ");
	gets_s(fout);
	getData(fin, L, flag);
	if (flag == 1)
	{
		printf("Input number you want to add after value you choose:");
		scanf("%i %i", &x, &pos);
		insertAfter(L, x);
		printList(L.head);
		printData(fout, L);
	}
	else return 0;
}