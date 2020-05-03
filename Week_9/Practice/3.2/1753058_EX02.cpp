#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

int main()
{
	DList L;
	DList L1;
	Init(L);
	Init(L1);
	getList(L);
	printList(L);
	if (Isempty(L))
		printf("Empty list!\n");
	printf("List not empty!\n");
	makeSumList(L, L1);
	printList(L1);
}