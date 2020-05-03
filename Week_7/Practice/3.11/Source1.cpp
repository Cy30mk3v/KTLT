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

void removeHead(SList &L)
{
	int x = L.head->data;
	L.head = L.head->next;
}

int search(SList &L, int x)
{
	SNode *P = L.head;
	int count = 1;
	while (P != NULL && P->data != x)
	{
		P = P->next;
		count++;
	}
	if (P != NULL)
		return count;
	else
		return 0;
}


void removeValue(SList &L, int x, int pos)
{
	SNode *P = L.head;
	int i = 1;
	if (L.head->data %2==0)
	{
		removeHead(L);
		return;
	}
	else
	{
		while (P != NULL && i != pos - 1)
		{
			P = P->next;
			i++;
		}
		P->next = P->next->next;
	}
}

void removeEven(SList &L)
{
	for (SNode *P = L.head; P; P = P->next)
	{
		if (P->data % 2==0)
		{
			removeValue(L, P->data, search(L, P->data));
		}
	}
}