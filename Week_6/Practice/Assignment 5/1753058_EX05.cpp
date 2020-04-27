#include<stdio.h>
#include<math.h>
#include "Header.h"


int main()
{
	int n, i, j;
	int board[20];
	int count = 1;
	void queen(int row, int n, int *board, int &count);
	printf("\n\nEnter number of Queens:");
	scanf_s("%d", &n);
	queen(1, n, board, count);
	return 0;
}

