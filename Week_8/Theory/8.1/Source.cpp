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
	int x;
	printf("Element need to find: ");
	scanf("%d", &x);
	if (x<0 || x>countNode(L) + 1)
		printf("Not found!\n");
	printElement(L, x);
	int value;
	printf("Input value need to find: ");
	scanf("%i", &value);
	if (search(L, value) != 0)
		printf("Value was found in element number: %i\n", search(L, value));
	else
		printf("Value not found!\n");
	printf("Last element is element number %i, has value: %i\n", countNode(L), L.Tail->Data);
	printf("Input value to add at the head of list: ");
	int head;
	scanf("%i", &head);
	addHead(L, head);
	printList(L);
	printf("Input value to add at the tail of list:");
	int tail;
	scanf("%i", &tail);
	addTail(L, tail);
	printList(L);
	int valueE;
	int Element;
	printf("Input value to add after the element you choose:");
	scanf("%i %i", &valueE, &Element);
	insertPos(L, valueE, Element);
	printList(L);
	int as;
	printf("Input value you need to add in ascdending order:");
	scanf("%i", &as);
	insertPos(L, as, searchtoAdd(L, as));
	int data;
	delPos(L, data, 1);
	printList(L);
	delPos(L, data, countNode(L));
	printList(L);
	printf("Input element you want to remove:");
	int remove;
	scanf("%i", &remove);
	delPos(L, data, remove);
	printList(L);
	deleteList(L.Head);
	return 0;
	
}