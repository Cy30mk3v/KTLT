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


int findSecondLargest(SList L, SList &L1)
{
	int max = L.head->data;
	for (SNode *P = L.head; P; P = P->next)
	{
		if (max < P->data)
		{
			max = P->data;
		}
	}
	removeValue(L1, max);
	if (L1.head == NULL)
	{
		printf("Not found");
		return -1;
	}
	int max1 = L1.head->data;
	for (SNode *S = L1.head; S; S = S->next)
	{
		if (max1 <= S->data)
		{
			max1 = S->data;
		}
	}
	printf("\nThe second largest number :%i",max1);
	return max1;
}

void removeHead(SList &L)
{
	int x = L.head->data;
	L.head = L.head->next;
}

void removeValue(SList &L, int x)
{
	int pos = search(L, x);
	SNode *P = L.head;
	int i = 1;
	if (L.head->data == x)
	{
		removeHead(L);
		return;
	}
	else
	{
		while (P != NULL && i != pos)
		{
			P = P->next;
			i++;
		}
		P->next = P->next->next;
	}
}

int search(SList &L, int x)
{
	SNode *P = L.head;
	int count = 0;
	for (P; P != NULL && P->data != x; P = P->next)
	{
		count++;
	}
	if (P != NULL)
		return count;
	else return 0;
}

void printValue(SList L, int x)
{
	int count = 0;
	printf("\nThe second largest has indicies: ");
	for (SNode *P = L.head; P; P = P->next)
	{
		if (P->data == x)
		{
			printf("%i", count);
		}
		count++;
	}
}


void remove2ndValue(SList &L, int x)
{
	int pos = search(L, x);
	SNode *P = L.head;
	int i = 1;
	if (L.head->data == x)
	{
		removeHead(L);
		return;
	}
	else
	{
		while (P != NULL && i != pos)
		{
			P = P->next;
			i++;
		}
		P->next = P->next->next;
	}
}
