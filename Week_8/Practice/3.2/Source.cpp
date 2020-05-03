#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"


Node * makeNode(Node *N, int x)
{
	N = new Node;
	N->data = x;
	N->next = NULL;
	return N;
}

void getData(char *file, List &L, int &flag)
{
	FILE*fin;
	Node *cur = NULL;
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
		printf("Empty list!");
		flag = 0;
		return;
	}
	while (i != 0)
	{
		Node *P = new Node;
		P = makeNode(P, i);
		P->next = L.head;
		L.head = P;
		fscanf(fin, "%i", &i);
	}
	fclose(fin);
}


void printData(char *file, List L)
{
	FILE * fout = fopen(file, "w");
	if (fout == NULL)
	{
		printf("File not found!");
		return;
	}
	Node *p = new Node;
	p = L.head;
	while (p != NULL)
	{
		fprintf(fout, "%i ", p->data);
		p = p->next;
	}
	fprintf(fout, "0");
	fclose(fout);
}

void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}


