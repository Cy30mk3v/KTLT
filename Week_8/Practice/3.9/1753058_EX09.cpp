#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	SList L;
	L.head = NULL;
	int x, flag;
	char fin[20];
	char fout[20];
	printf("Input filename: ");
	gets_s(fin);
	getData(fin, L, flag);
	if (flag == 1)
	{
		printf("Input filename return: ");
		gets_s(fout);
		printf("Input duplicate value you want to remove : ");
		scanf("%i", &x);
		removeDuplicates(L.head);
		printList(L.head);
		printData(fout, L);
	}
}