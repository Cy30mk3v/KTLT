#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void getData(char *file, SList &L, int &flag)
{
	FILE*fin;
	SNode *cur = NULL;
	int i = 0;
	flag = 1;
	fin = fopen(file, "r");
	if (fin == NULL)
	{
		printf("File not found!");
		flag = 0;
		return;
	}
	fscanf(fin, "%i", &i);
	if (i == NULL)
	{
		printf("Empty List!");
		flag = 0;
		return;
	}
	while (i != 0)
	{
		SNode *P = new SNode;
		P->data = i;
		P->next = NULL;
		if (L.head == NULL)
		{
			L.head = P;
			cur = P;
		}
		else
		{
			cur->next = P;
			cur = P;
		}
		fscanf(fin, "%i", &i);
	}
	fclose(fin);
}

SNode * makeNode(SNode *N, int x)
{
	N = new SNode;
	N->data = x;
	N->next = NULL;
	return N;
}

int countNode(SList L)
{
	SNode *P = L.head;
	int i = 0;
	while (P != NULL)
	{
		i++;
		P = P->next;
	}
	return i;
}


void printData(char *file, SList L)
{
	FILE * fout = fopen(file, "w");
	SNode *p = new SNode;
	p = L.head;
	while (p != NULL)
	{
		fprintf(fout, "%i ", p->data);
		p = p->next;
	}
	fprintf(fout, "0");
	fclose(fout);
}

void printList(SNode *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}


void addHead(SList &L, int x)
{
	SNode *P;
	P = new SNode;
	P = makeNode(P, x);
	P->next = L.head;
	L.head = P;
}

void insertPos(SList &L, int x, int pos)
{
	SNode *P, *Q = L.head;
	int i = 1;
	P = new SNode;
	P = makeNode(P, x);
	if (pos == 1)
	{
		addHead(L, x);
	}
	else
	{
		while (Q != NULL && i != pos - 1)
		{
			i++;
			Q = Q->next;
		}
		P->next = Q->next;
		Q->next = P;
	}
}

void insertEvenNodes(SList &L)
{
	int mark = countNode(L)*2;
	int count = 1;
	int num = 2;
	for (SNode *P = L.head; P; P = P->next)
	{
		if (count < mark)
		{
			insertPos(L, num, count);
			count = count + 2;
			num = num + 2;
		}
		else break;
	}
}