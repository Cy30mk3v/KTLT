#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Header.h"

using namespace std;

int main(void)
{
	int **p, *a;
	int **p1;
	int rows, cols;
	int m,n;
	inputArray(rows, cols, p);
	printArraytoFIle(rows, cols, p);
	printArray(rows, cols, p);
	printMin(rows, cols, p);
	printPrimeinRows(rows, cols, p);
	findRowsArray(rows, cols, p);
	countBorder(rows, cols, p);
	countPrimeInside(rows, cols, p);
	countPrimeDiagonal(rows, cols, p);
	totalinSubDiag(rows, cols, p);
	permuteMatrix(rows, cols, p);
	countHorse(rows, cols, p);
	countQueen(rows, cols, p);
	buildHorseMatrix(rows, cols, p);
	buildQueenMatrix(rows, cols, p);
	makeArray(rows, cols,p);
	system("pause");
}