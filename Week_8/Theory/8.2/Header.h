

struct List
{
	struct SNode *head;
};

struct SNode
{
	SNode *next;
	int data;
};

int countNode(List L);
void input(List &L);
void insertPos(List &L, int x, int k);
SNode *makeNode(SNode *P, int x);
void addHead(List &L, int x);
void printList(List L);
int Search(List L, int x);
void reverseList(List &L);