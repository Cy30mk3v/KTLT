#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Header.h"

int countNode(List L)
{
	int count = 0;
	SNode *P = L.head;
	for (P; P != NULL; P = P->next)
	{
		count++;
	}
	return count;
}

void input(List &L)
{
	int i = 0;
	int x;
	do
	{
		i++;
		printf("Nhap phan tu thu %i: ", i);
		scanf("%i", &x);
		if (x != 0)
			insertPos(L, x, countNode(L) + 1);
	} while (x != 0);
}

void insertPos(List &L, int x, int k)
{
	SNode *P;
	SNode *Q = L.head;
	int i = 1;
	if (k<1 || k>countNode(L) + 1)
		printf("Error!");
	else
	{
		P = new SNode;
		P = makeNode(P, x);
		if (k == 1)
			addHead(L, x);
		else
		{
			while (Q != NULL && i != k - 1)
			{
				i++;
				Q = Q->next;
			}
			P->next = Q->next;
			Q->next = P;
		}
	}

}

SNode *makeNode(SNode *P, int x)
{
	P = new SNode;
	P->next = NULL;
	P->data = x;
	return P;
}

void addHead(List &L, int x)
{
	SNode *P = new SNode;
	P=makeNode(P, x);
	P->next = L.head;
	L.head = P;
}

void printList(List L)
{
	SNode *P = L.head;
	int i = 1;
	for (P; P != NULL; P = P->next)
	{
		printf("%i->", P->data);
		i++;
	}
}

int Search(List L, int x) //tim x trong danh sach
{
	SNode *P = L.head;
	int i = 1;
	while (P != NULL && P->data < x) //duyet danh sach den khi tim thay hoac ket thuc danh sach
	{
		P = P->next;
		i++;
	}
	if (P != NULL) return i; //tra ve vi tri tim thay
}


void reverseList(List &L)
{
	SNode *p, *q;
	p = new SNode;
	q = new SNode;
	p = L.head;
	L.head = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L.head;
		L.head = p;
		p = q;
	}
}



