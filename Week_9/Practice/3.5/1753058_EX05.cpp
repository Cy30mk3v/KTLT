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
	reverseList(L);
	printList(L);
}