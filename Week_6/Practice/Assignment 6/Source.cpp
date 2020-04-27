#include<stdio.h>
#include "Header.h"
#define N 5




bool checkSafe(int x, int y, int board[N][N])
{
	return (x >= 0 && x < N && y >= 0 &&
		y < N && board[x][y] == -1);
}


void printSolution(int board[N][N])
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
			printf(" %2d ", board[x][y]);
		printf("\n");
	}
}

bool solveKT()
{
	int board[N][N];


	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			board[x][y] = -1;


	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };


	board[0][0] = 0;

	if (solveKnightUntil(0, 0, 1, board, xMove, yMove) == false)
	{
		printf("Solution does not exist");
		return false;
	}
	else
		printSolution(board);

	return true;
}


int solveKnightUntil(int x, int y, int movei, int board[N][N],
	int xMove[N], int yMove[N])
{
	int k, next_x, next_y;
	if (movei == N * N)
		return true;

	for (k = 0; k < 8; k++)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (checkSafe(next_x, next_y, board))
		{
			board[next_x][next_y] = movei;
			if (solveKnightUntil(next_x, next_y, movei + 1, board,
				xMove, yMove) == true)
				return true;
			else
				board[next_x][next_y] = -1;
		}
	}

	return false;
}
