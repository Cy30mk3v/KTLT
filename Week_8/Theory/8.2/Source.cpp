#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main()
{
	List L;
	int x;
	int pos;
	L.head=NULL;
	SNode *P;
	P = new SNode;
	printf("Input 0 to finish!\n");
	input(L);
	printList(L);
	printf("Number of nodes: %i\n",countNode(L));
	printf("Insert Data: ");
	scanf("%i", &x);
	insertPos(L, x, Search(L, x));
	printList(L);
	reverseList(L);
	printf("After reversed\n");
	printList(L);
	return 0;
}