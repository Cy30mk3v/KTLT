#include "Header.h"

int main()
{
	SList L, L1;
	L.head = NULL;
	L1.head = NULL;
	int x, flag;
	int secLarge;
	char fin[20];
	printf("Input filename: ");
	gets_s(fin);
	getData(fin, L, flag);
	getData(fin, L1, flag);
	if (flag == 1)
	{
		printList(L.head);
		secLarge=findSecondLargest(L, L1);
		printValue(L1, secLarge);
		remove2ndValue(L, secLarge);
		printList(L.head);
	}
}