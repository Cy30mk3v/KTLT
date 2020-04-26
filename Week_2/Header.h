#include <stdio.h>
#include <iostream>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

void printArray(int n, int p[]);
int checkPrime(int n);
void sortingDescending(int n, int p[]);
void sortingAscending(int n, int p[]);
void checkPrimeArray(int n, int p[]);
int posArray(int n, int p[], int p1[]);
void sortingArray(int n, int p1[], int odd[], int even[], int p2[]);
void splitArray(int n, int p[], int *odd, int *even);
void insertNumber(int n, int *p, int *odd, int o, int *even, int e, int*p1, int *p2);
void insertNumbertoOdd(int a, int o, int*odd);
void insertNumbertoEven(int a, int e, int*even);
void removeInt(int &n, int p[], int pos);
void removeSimilar(int n, int p[]);
int GCD2(int x, int y);
int GCDArray(int n, int p[]);