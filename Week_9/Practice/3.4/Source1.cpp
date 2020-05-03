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
	while (P)
	{
		printf("%5d", P->Data);
		P = P->next;
	}
	printf("\n");
}

void removeDuplicates(struct DNode *start)
{
	struct DNode *P, *Q, *dup;
	P = start;
	while (P != NULL && P->next != NULL)
	{
		Q = P;
		while (Q->next != NULL)
		{
			if (P->Data == Q->next->Data)
			{
				dup = Q->next;
				Q->next = Q->next->next;
				delete(dup);
			}
			else
				Q = Q->next;
		}
		P = P->next;
	}
}