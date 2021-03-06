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
void addTail(SList &L, int x);
int countNode(SList L);
void insertAfter(SList &L, int x);
int search(SList L, int x);