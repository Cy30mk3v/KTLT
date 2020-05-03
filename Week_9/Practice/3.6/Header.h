#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <random>

using namespace std;

struct CList
{
	struct Node *head;
	struct Node *tail;
};

struct Node
{
	char *StudendID;
	int no;
	char *fullname;
	Node *next;
};

void init(CList &L);
Node *makeNode(Node *P, char *ID, char *name, int no);
void addTail(CList &L, char *ID, char *name, int no);
void getData(CList &L, int &num, int &flag);
void printList(CList L, int num);
void delHead(CList &L);
void deleteNode(struct Node *&head, int key, int num);
void delAfterRandom(CList &L, int num, char file[]);
bool isEmpty(CList L);
void addHead(CList &L, char *ID, char *name, int no);
void addTail(CList &L, char *ID, char *name, int no);