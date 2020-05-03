#pragma once
struct SList
{
	struct	SNode *head;
};

struct SNode
{
	int data;
	SNode * next;
};

void getData(char *file, SList &L, int &flag);
SNode * makeNode(SNode *N, int x);
void printData(char *file, SList L);
void printList(SNode *node);
int countNode(SList L);
void removeHead(SList &L);
void removeValue(SList &L, int x);
void removeDuplicates(struct SNode *start);