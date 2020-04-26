#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;


void inputMatrix(int **&m, int &rows, int &cols);
int checkPrime(int n);
void checkPrimein2Darray(int **n, int rows, int cols, int *&a);
void print1Darray(int *a, int n);

int main(void)
{
	int **n;
	int *a;
	int rows, cols;
	inputMatrix(n, rows, cols);
	a = new int[rows + cols];
	checkPrimein2Darray(n, rows, cols, a);
	delete[]n;
	system("pause");
}

void inputMatrix(int **&m, int &rows, int &cols)
{
	printf("Input number of rows: ");
	scanf_s("%i", &rows);
	printf("Input number of cols: ");
	scanf_s("%i", &cols);
	m = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		m[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			printf("A[%i][%i]= ", i, j);
			cin >> m[i][j];
		}
	}
}

int checkPrime(int n)
{
	if (n < 2)
		return 0;
	if (n == 4)
		return 0;
	for (int i = 2; i < (sqrt(n)+1); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

void checkPrimein2Darray(int **n, int rows, int cols, int *&a)
{
	int k = rows + cols;
	printf("So nguyen to co trong mang: ");
	int f = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (checkPrime((n[i][j])) == 1)
				{
					cout << " ";
					a[f] = n[i][j];
					printf("%i", a[f]);
					f++;
				}
			}
		}
}

void print1Darray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%i", a[i]);
	}
}
