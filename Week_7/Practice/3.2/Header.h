struct Node
{
	Node *next;
	int data;
};
struct List
{
	Node *head;
};

void getData(char *file, List &L, int &flag);
void printData(char *file, List L);
void printList(struct Node *node);
Node * makeNode(Node *N, int x);

