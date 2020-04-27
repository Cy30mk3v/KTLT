#include <stdio.h>
#include <math.h>
#include "Header.h"

void print(int n, int *board, int &count)
{
	int i, j;

	printf("\n\nSolution %i", count++);

	for (i = 1; i <= n; ++i)
	{
		printf("\n\n");
		for (j = 1; j <= n; ++j)
		{
			if (board[i] == j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}
}


int place(int row, int cols, int *board)
{
	int i;
	for (i = 1; i <= row - 1; ++i)
	{
		if (board[i] == cols)
			return 0;
		else
			if (abs(board[i] - cols) == abs(i - row))
				return 0;
	}

	return 1;
}

void queen(int row, int n, int *board, int &count)
{
	int cols;
	for (cols = 1; cols <= n; ++cols)
	{
		if (place(row, cols, board))
		{
			board[row] = cols;
			if (row == n)
				print(n, board, count);
			else
				queen(row + 1, n, board, count);
		}
	}
}