#include "Header.h"

void main()
{
	int flag = 1;
	int num = 0;
	CList L;
	L.head = NULL;
	getData(L, num, flag);
	if (flag == 0)
		printf("Error!");
	printList(L, num);
	char out[20];
	printf("Output file: ");
	gets_s(out);
	delAfterRandom(L, num, out);
	return;
}