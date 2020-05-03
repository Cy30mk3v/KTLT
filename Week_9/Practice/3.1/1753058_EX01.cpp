#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

int main()
{
	DList L;
	Init(L);
	getList(L);
	printList(L);
	if (Isempty(L))
		printf("Empty list!\n");
	printf("List not empty!\n");
	int as;
	printf("Input value you need to add in ascdending order:");
	scanf("%i", &as);
	insertPos(L, as, searchtoAdd(L, as));
	printList(L);
}