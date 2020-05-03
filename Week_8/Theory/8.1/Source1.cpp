#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"


void Init(DList &L)
{
	L.Head = NULL; 
	L.Tail = NULL;
}

int Isempty(DList L) 
{
	return (L.Head == NULL);
}

int countNode(DList L) 
{
	DNode *PH = L.Head, *PT = L.Tail; 
	int i = 0; 
	if (PH != NULL) i = 1;
	while (PH != NULL) 
	{
		if (PH == PT)
			break;
		PH = PH->next; 
		i++;
		if (PH == PT) 
			break;
		PT = PT->prev;
		i++;
	}
	return i; 
}

DNode *makeDNode(int x) 
{
	DNode *P = new DNode;
	P->Data = x; 
	P->prev = NULL;
	P->next = NULL;
	return P;
}

void addHead(DList &L, int x) 
{
	DNode *P;
	P = makeDNode(x); 
	if (Isempty(L)) 
	{
		L.Head = P;
		L.Tail = P;
	}
	else
	{
		P->next = L.Head;
		L.Head->prev = P;
		L.Head = P;
	}
}

void addTail(DList &L, int x)  
{
	DNode *P;
	P = makeDNode(x); 
	if (Isempty(L)) 
	{
		L.Head = P;
		L.Tail = P;
	}
	else
	{
		L.Tail->next = P; 
		P->prev = L.Tail; 
		L.Tail = P; 
	}
}

void insertPos(DList &L, int x, int pos) 
{
	DNode *PH = L.Head, *PT, *R;
	int i = 1, l = countNode(L);
	if (pos<1 || pos> l + 1) 
		printf("Unable to insert!"); 
	else
	{
		R = makeDNode(x);
		if (pos == 1) addHead(L, x); 
		else
			if (pos == l + 1) addTail(L, x); 
			else 
			{
				while (PH != NULL && i != pos - 1)
				{
					i++;
					PH = PH->next;
				}
				PT = PH->next; 
				R->next = PT;  
				R->prev = PH;    
				PH->next = R;   
				PT->prev = R;    
			}
	}
}

void removeHead(DList &L, int &x)
{
	if (!Isempty(L))
	{
		x = L.Head->Data;
		L.Head = L.Head->next;
	}
}

void removeTail(DList &L, int &x) 
{
	if (!Isempty(L))
	{
		x = L.Tail->Data;
		L.Tail = L.Tail->prev;
		L.Tail->next = NULL;
	}
}

void delPos(DList &L, int &x, int pos) 
{
	DNode *PH = L.Head, *PT;
	int i = 1, l = countNode(L);
	if (pos<1 || pos> l) 
		printf("Unable to remove!"); 
	else
	{
		if (pos == 1) removeHead(L, x); 
		else
			if (pos == l) removeTail(L, x); 
			else 
			{
				while (PH != NULL && i != pos - 1) 
				{
					i++;
					PH = PH->next;
				}
				x = PH->next->Data;
				PT = PH->next->next; 
				PH->next = PT;
				PT->prev = PH;
			}
	}
}

int search(DList L, int x) 
{
	DNode *P = L.Head;
	int i = 1;
	while (P != NULL && P->Data != x) 
	{
		P = P->next;
		i++;
	}
	if (P != NULL) return i; 
	else return 0; 
}

void removeValue(DList &L, int x) 
{
	int l = search(L, x);
	while (l)
	{
		delPos(L, x, l); 
		l = search(L, x);
	}
}


void getList(DList &L)
{
	int i = 0;
	int x;
	do
	{
		i++;
		printf("Input the element number %i : ", i);
		scanf("%i", &x);
		if (x != 0) insertPos(L, x, countNode(L) + 1);
	} while (x != 0); 
}

void printList(DList L) 
{
	DNode *P = L.Head;
	while (P != L.Tail->next)
	{
		printf("%5d", P->Data);
		P = P->next;
	}
	printf("\n");
}

void printElement(DList L, int element)
{
	DNode *P = L.Head;
	int count = 1;

	for(P;P != L.Tail->next;P=P->next)
	{
		if (count == element)
		{
			printf("Value:%i\n", P->Data);
			break;
		}
		count++;
	}
}

int searchtoAdd(DList L, int x)
{
	DNode *P = L.Head;
	int i = 1;
	while (P != NULL && P->Data < x)
	{
		P = P->next;
		i++;
	}
	if (P != NULL) return i;
	else return 0;
}

void deleteList(DNode *head) 
{
	if (head != NULL) {
		deleteList(head->next);
		delete head;
	}
}
