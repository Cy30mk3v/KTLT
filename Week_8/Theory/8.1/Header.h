

 struct DNode 
{
	int Data; 
	DNode *prev; 
	DNode *next; //con tro phai
};

 struct DList //cau truc Cua List
{
	DNode *Head; //con tro dau
	DNode *Tail; //con tro cuoi
};


void Init(DList &L);
int Isempty(DList L); //kiem tra DS rong
int countNode(DList L); // Do dai danh sach
DNode *makeDNode(int x); //tao 1 Node P chua thong tin la x 
void addHead(DList &L, int x);  //Chen x vao vi tri dau tien trong danh sach
void addTail (DList &L, int x);  //Chen x vao vi tri dau tien trong danh sach
void insertPos(DList &L, int x, int k); //chen x vao vi tri k trong danh sach
void removeHead(DList &L, int &x); //Xoa phan tu dau tien
void delPos(DList &L, int &x, int k); //Xoa Node k trong danh sach
int search(DList L, int x); //tim x trong danh sach
void removeValue(DList &L, int x); //xoa phan tu x trong danh sach
void getList(DList &L); //nhap danh sach
void printList(DList L); //xuat danh sach
void printElement(DList L, int element);
int searchtoAdd(DList L, int x);
void deleteList(DNode *head);
