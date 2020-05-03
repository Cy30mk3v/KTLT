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

int search(SList L, int x)
{
	SNode *P = L.head;
	int i = 1;
	while (P != NULL && P->data != x)
	{
		P = P->next;
		i++;
	}
	if (P != NULL) return i;
	else return 0;
}


void insertBefore(SList &L, int x)
{
	if (search(L, x) == 0)
		addHead(L, x);
	else
	{
		SNode *P, *Q = L.head;
		int i = 1;
		P = new SNode;
		P = makeNode(P, x);
		int k = search(L, x);
		while (Q != NULL && i != k)
		{
			i++;
			Q = Q->next;
		}
		P->next = Q->next;
		Q->next = P;

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