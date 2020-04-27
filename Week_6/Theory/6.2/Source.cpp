

#include <stdio.h>
#include "Header.h"

int main(void)
{
	int a1, x;
	int *a;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%i", &a1);
	a = new int[a1];
	getArray(a, a1);
	printf("Nhap so can tim: ");
	scanf_s("%i", &x);
	if (findpos(x, a, 0, a1) != -1 || x == a[0])
	{
		printf("Vi tri cua so can tim la vi tri thu: %i\n", findpos(x, a, 0, a1) + 1);
	}
	else
		printf("Khong tim thay!\n");
	bool flag = false;
	if (printPrime(a1, a) != 0)
	{
		flag = true;
	}
	if (flag)
	{
		printPrime(a1, a);
		printf("\n");
	}
	if (a1 == 1 && checkPrime(a[0]) == 1)
		printf("%i\n", a[0]);
	delete a;
}