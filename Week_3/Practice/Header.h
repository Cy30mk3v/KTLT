#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>



void inputArray(int &rows, int &cols, int **&p);
void printArray(int rows, int cols, int **p);
void printMin(int rows, int cols, int **p);
int checkPrime(int n);
void printPrimeinRows(int rows, int cols, int **p);
void printMin(int rows, int cols, int **p);
void findRowsArray(int rows, int cols, int **p);
void countBorder(int rows, int cols, int **p);
void countPrimeInside(int rows, int cols, int **p);
void countPrimeDiagonal(int rows, int cols, int **p);
void totalinSubDiag(int rows, int cols, int **p);
void permuteMatrix(int rows, int cols, int **p);
int maxCols(int y, int x, int rows, int cols, int **p);
int minRows(int y, int x, int rows, int cols, int **p);
void countHorse(int rows, int cols, int **p);
int maxRows(int y, int x, int rows, int cols, int **p);
int maxDiag(int y, int x, int rows, int cols, int **p);
void countQueen(int rows, int cols, int **p);
void buildHorseMatrix(int rows, int cols, int **p);
void buildQueenMatrix(int rows, int cols, int **p);
void printArraytoFIle(int rows, int cols, int **p);
void makeArray(int rows, int cols, int **&p);


