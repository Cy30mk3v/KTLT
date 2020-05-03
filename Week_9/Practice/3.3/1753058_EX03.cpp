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
	insertEven(L);
	printList(L);
}