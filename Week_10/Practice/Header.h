#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct SList
{
	struct SNode *head;
};

struct SNode
{
	SNode *next;
	int data;
};


void getData(char *file, SList &L, int &flag);
SNode * makeNode(SNode *N, int x);
void printData(char *file, SList L);
void printList(SNode *node);
void removeValue(SList &L, int x);
int countNode(SList L);
void removeHead(SList &L);
int search(SList &L, int x);
int findSecondLargest(SList L, SList &L1);
void printValue(SList L, int x);
void remove2ndValue(SList &L, int x);