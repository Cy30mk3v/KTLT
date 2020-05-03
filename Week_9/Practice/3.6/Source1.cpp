#include "Header.h"

void init(CList &L)
{
	L.head = NULL;
}


Node *makeNode(Node *P, char *ID, char *name, int no)
{
	P = new Node;
	P->next = NULL;
	P->fullname = _strdup(name);
	P->no = no;
	P->StudendID = _strdup(ID);
	return P;
}


void getData(CList &L,int &num, int &flag)
{
	char temp[20];
	char *filein;
	printf("Input file: ");
	gets_s(temp);
	FILE *f = fopen(temp, "r");
	if (f == NULL)
	{
		printf("File not found!");
		flag = 0;
		return;
	}
	num = -1;
	fscanf(f, "%i\n", &num);
	if (num == 0)
	{
		printf("Empty List!");
		flag = 0;
		return;
	}
	char studentID[100];
	char name[50];
	char *fullname;
	char *ID;
	Node *cur = NULL;
	for (int i = 0; i < num; i++)
	{
		Node *P = new Node;
		fgets(studentID, 100, f);
		//puts(studentID);
		fgets(name, 100, f);
		//puts(name);
		fullname = _strdup(name);
		ID = _strdup(studentID);
		addTail(L, ID, fullname, i + 1);
	}
}


bool isEmpty(CList L)
{
	if (L.head == NULL)
		return true;
	return false;
}
void addHead(CList &L, char *ID, char *name, int no) 
{
	Node *P = new Node;
	P=makeNode(P, ID, name, no);
	if (isEmpty(L)) 
		L.head = L.tail = P;
	else 
	{
		P->next = L.head; 
		L.head = P; 
	}
	L.tail->next = L.head; 
}

void addTail(CList &L, char *ID, char *name, int no)
{
	Node *P = new Node;
	P = makeNode(P, ID, name, no);
	if (isEmpty(L)) 
		addHead(L,ID,name,no);
	else 
	{
		L.tail->next = P;
		L.tail = P;
	}
	L.tail->next = L.head; 
}

void printList(CList L, int num)
{	
	Node *P = L.head;
	for (int i=0;i<num;i++)
	{
		puts(P->StudendID);
		puts(P->fullname);
		P = P->next;
	}
}



void delHead(CList &L)
{
	Node *P = new Node;
	if (L.head != L.tail)
	{
		P = L.head;
		L.head = L.head->next;
		delete P;
		L.tail->next = L.head;
	}
	else
		L.head = NULL;
}

void deleteNode(struct Node *&head, int key, int num)
{
	if (head == NULL)
		return;

	struct Node *curr = head, *prev;
	prev = NULL;
	while (curr->no != key)
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr->next == head)
	{
		head = NULL;
		free(curr);
		return;
	}

	if (curr == head)
	{
		prev = head;
		while (prev->next != head)
		{
			prev = prev->next;
		}
		head = curr->next;
		prev->next = head;
		free(curr);
	}

	else
	{
		if (curr->next == head)
		{
			prev->next = head;
			free(curr);
			return;
		}
		else
		{
			prev->next = curr->next;
			free(curr);
		}
	}
}


/*void deletePos(CList &L, int pos, int &num)
{
	if (pos == 1)
	{
		delHead(L);
		return;
	}
	if (pos == num)
	{
		delTail(L);
		return;
	}
	else
	{
		int count = 0;
		Node *P = new Node;
		P = L.head;
		Node *Q = new Node;
		while (P != NULL)
		{
			count++;
			Q = P;
			if (count == pos)
				break;
			else
				P = P->next;
		}
		Node *S = new Node;
		S = L.head;
		while (S->next != Q)
		{
			S = S->next;
			S->next = Q->next;
			delete Q;
		}
	}
	num--;
}*/

void delAfterRandom(CList &L, int num, char file[])
{
	int a = 0;
	int q = num;
	int c = 1;
	int *temp = new int[num];
	for (int i = 0; i < num; i++)
	{
		temp[i] = i;
	}
	int cur = 1;
	while (q>1)
	{
		while (cur == a)
		{
			if (q < 6)
			{
				a = 1 + rand() % (q);
			}
			else
				a = 1 + rand() % 6;
		}
		int count = 0;
		temp[a] = 0;
		FILE *f = fopen(file, "a");
		Node *P = L.head;
		fprintf(f, "after %i dice\n" , c);
		c++;
		for (int i = 0; i<num; i++)
		{
			if (temp[i] == 0)
			{
				P = P->next;
				continue;
			}
			fputs(P->StudendID, f);
			fputs(P->fullname, f);
			fprintf(f, "\n");
			P = P->next;
		}
		cur = a;
		q--;
	}
}

