
struct DNode
{
	int Data;
	DNode *prev;
	DNode *next; 
};

struct DList
{
	DNode *Head; 
	DNode *Tail; 
};


void Init(DList &L);
int Isempty(DList L); 
void getList(DList &L); 
void printList(DList L); 
int countNode(DList L); 
DNode *makeDNode(int x); 
void addHead(DList &L, int x); 
void addTail(DList &L, int x);  
void insertPos(DList &L, int x, int k); 
int searchtoAdd(DList L, int x);