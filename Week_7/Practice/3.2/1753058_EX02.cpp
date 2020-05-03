#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void main()
{
	List L;
	L.head = NULL;
	char filenamein[50];
	char filenameout[50];
	int x, flag;
	printf("Input filename: ");
	scanf("%s", filenamein);
	getData(filenamein, L, flag);
	if (flag == 1)
	{
		printList(L.head);
		printf("Input filename return:");
		scanf("%s", filenameout);
		printData(filenameout, L);
	}
	else return;
}