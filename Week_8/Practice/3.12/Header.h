
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
void addHead(SList &L, int x);
void insertPos(SList &L, int x, int pos);
void insertEvenNodes(SList &L);

