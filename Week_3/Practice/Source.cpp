#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>


using namespace std;

void inputArray(int &rows, int &cols, int **&p)
{
	FILE* FILEIN;
	FILEIN = fopen("Problem1.txt", "r");
	if (FILEIN == NULL)
	{
		printf("Khong tim thay file");
	}
	fscanf(FILEIN,"%i", &rows);
	fscanf(FILEIN, "%i", &cols);
	p = new int *[rows];
	for(int i = 0; i < rows; i++)
	{
		p[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			fscanf(FILEIN, "%i", &p[i][j]);
		}
	}
	fclose(FILEIN);
}

void printArraytoFIle(int rows, int cols, int **p)
{
	FILE * FILEOUT;
	FILEOUT = fopen("Problem2.txt", "w");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fprintf(FILEOUT, "%i", p[i][j]);
		}
	}
	fclose(FILEOUT);
}
void printArray(int rows, int cols, int **p)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}
}

void printMin(int rows, int cols, int **p)
{
	int min = p[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (p[i][j] < min)
			{
				min = p[i][j];
			}
		}
	}
	cout << "Phan tu nho nhat trong mang: ";
	cout << min;
	cout << "\n";
}

int checkPrime(int n)
{
	if (n < 2)
		return 0;
	else 
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
				return 0;
		}
	return 1;
}

void printPrimeinRows(int rows, int cols, int **p)
{
	for (int i=0; i < rows; i++)
	{
		int flag = 0;
		int total = 0;
		printf("So nguyen to o hang %i: ", i+1);
		for (int j = 0; j < cols; j++)
		{
			if (checkPrime(p[i][j]) == 1)
			{
				total = total+1;
				flag = 1;
			}
		}
		if (flag == 0)
			printf("0\n");
		else
			printf("%i \n", total);
	}
}

void findRowsArray(int rows, int cols, int **p)
{
	int *a;
	a = new int[cols];
	for (int i = 0; i < cols; i++)
	{
		int flag = 0;
		int total = 0;
		for (int j = 0; j < rows; j++)
		{
			if (checkPrime(p[j][i]) == 1)
			{
				total = total + 1;
				flag = 1;
			}
		}
		if (flag == 0)
			a[i] = 0;
		else
			a[i] = total;
	}
	int largest = 0;
	int max = a[0];
	for (int i = 0; i < cols; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < cols; i++)
	{
		if (a[i] == max)
		{
			largest = i + 1;
			break;
		}
	}
	printf("Cot co tong so nguyen to nhieu nhat: %i\n", largest);
	delete[]a;
}

void countBorder(int rows, int cols, int **p)
{
	int Left = 0;
	int Right = 0;
	int Upper = 0;
	int Lower = 0;
	for (int i = 0; i < rows; i++)
	{
		if (p[i][0] % 2 == 0)
		{
			Left = Left + 1;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		if (p[i][cols-1] % 2 == 0)
		{
			Right = Right + 1;
		}
	}
	for (int i = 0; i < cols; i++)
	{
		if (p[0][i] % 2 == 0)
		{
			Upper = Upper + 1;
		}
	}
	for (int i = 0; i < cols; i++)
	{
		if (p[rows-1][i] % 2 == 0)
		{
			Lower = Lower + 1;
		}
	}
	printf("Ben trai:%i\nBen phai:%i\nBen tren:%i\nBen duoi:%i\n", Left, Right, Upper, Lower);
}

void countPrimeInside(int rows, int cols, int **p)
{
	int total = 0;
	for (int i = 1; i < rows - 1; i++)
	{
		for (int j = 1; j < cols - 1; j++)
		{
			if (checkPrime (p[i][j]) == 1)
			{
				total += p[i][j];
			}
		}
	}
	printf("%i\n", total);
}

void countPrimeDiagonal(int rows, int cols, int **p)
{
	if (rows == cols)
	{
		int flag = 1;
		for (int i = 0; i < rows; i++)
		{
			if (checkPrime(p[i][i] == 0))
			{
				flag = 0;
				break;
			}
			else flag = 1;
		}
		if (flag == 1)
			printf("Tat ca cac phan tu tren duong cheo chinh la so nguyen to\n");
		else
			printf("Co phan tu tren duong cheo chinh khong la so nguyen to\n");
	}
	else
		printf("Khong phai ma tran vuong\n");
}

void totalinSubDiag(int rows, int cols, int **p)
{
	if (rows == cols)
	{
		int total = 0;
		for (int i = 0; i < rows; i++)
		{
			if (p[i][rows - 1 - i] % 2 == 0)
			{
				total += p[i][rows - 1 - i];
			}
		}
		printf("Tong so chan trong duong cheo phu: %i\n", total);
	}
	else
		printf("Khong phai ma tran vuong");
}

void permuteMatrix(int rows, int cols, int **p)
{
	int **p1;
	p1 = new int*[cols];
	int rows1 = cols;
	int cols1 = rows;
	for (int i = 0; i < rows1; i++)
	{
		p1[i] = new int[cols1];
		for (int j = 0; j < cols1; j++)
		{
			p1[i][j] = p[j][i];
		}
	}
	printArray(rows1, cols1, p1);
}

int maxCols(int y, int x, int rows, int cols, int **p)
{
	int A = p[y][x];
	for (int j = 0; j < rows; j++)
	{
		if (p[j][x] > A)
		{
			return false;
		}
	}
	return true;
}

int minCols(int y, int x, int rows, int cols, int **p)
{
	int A = p[y][x];
	for (int j = 0; j < rows; j++)
	{
		if (p[j][x] < A)
		{
			return false;
		}
	}
	return true;
 }

int minRows(int y, int x, int rows, int cols, int **p)
{
	int A = p[y][x];
	for (int i = 0; i < cols; i++)
	{
		if (p[y][i] < A)
		{
			return false;
		}
	}
	return true;
}

int maxRows(int y, int x, int rows, int cols, int **p)
{
	int A = p[y][x];
	for (int i = 0; i < cols; i++)
	{
		if (p[y][i] > A)
		{
			return false;
		}
	}
	return true;
}

int maxDiag(int y, int x, int rows, int cols, int **p)
{
	int A = p[y][x];
	int y1 = y + 1;
	int x1 = x + 1;
	while (x1 + 1 < cols && y1 < y)
	{
		if (p[x1][y1] > A)
			return false;
		x1++;
		y1++;
	}
	x1 = x - 1;
	y1 = y - 1;
	while (x1 - 1 >= 0 && y1 >= 0)
	{
		if (p[x1][y1] > A)
			return false;
		x1--;
		y1--;
	}
	int x2 = x - 1;
	int y2 = y + 1;
	while (x2 - 1 >= 0 && y2 < rows)
	{
		if (p[x2][y2] > A)
			return false;
		x2--;
		y2++;
	}
	x2 = x + 1;
	y2 = y - 1;
	while (y2 - 1 >= 0 && x2 < cols)
	{
		if (p[x2][y2] > A)
			return false;
		y2--;
		x1++;
	}
	return true;
}

void countHorse(int rows, int cols, int **p)
{
	if (rows = cols)
	{
		int count = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (maxRows(i, j, rows, cols, p) && minCols(i, j, rows, cols, p))
				{
					count++;
				}
			}
		}
		printf("So phan tu yen ngua co trong mang: %i\n", count);
	}
	else
		printf("Khong phai ma tran vuong\n");
}

void countQueen(int rows, int cols, int **p)
{
	if (cols == rows)
	{
		int count = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (maxCols(i, j, rows, cols, p) && maxRows(i, j, rows, cols, p)
					&& maxDiag(i, j, rows, cols, p))
				{
					count++;
				}
			}
		}
		printf("So phan tu hoang hau co trong mang: %i\n", count);
	}
	else
		printf("Khong phai ma tra vuong\n");
}

void buildHorseMatrix(int rows, int cols, int **p)
{
	int **p1;
	p1 = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		p1[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			if (maxRows(i, j, rows, cols, p) && minCols(i, j, rows, cols, p))
				p1[i][j] = 1;
			else
				p1[i][j] = 0;
		}
	}
	printf("Mang tao tu cac phan tu yen ngua: \n");
	printArray(rows, cols, p1);
	printf("\n");
}

void buildQueenMatrix(int rows, int cols, int **p)
{
	int **p1;
	p1 = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		p1[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			if (maxRows(i, j, rows, cols, p) && maxCols(i, j, rows, cols, p)
				&& maxDiag(i, j, rows, cols, p))
			{
				p1[i][j] = 1;
			}
			else p1[i][j] = 0;
		}
	}
	printf("Mang tao tu cac phan tu hoang hau: \n");
	printArray(rows, cols, p1);
	printf("\n");
}

void makeArray(int rows, int cols, int **&p)
{
	int x = 0;
	int y = 0;
	int *p1;
	while (x >= cols || y >= cols || y < 0 || x < 0 || (x==0 && y==0))
	{
		printf("Nhap toa do x: ");
		scanf("%i", &x);
		printf("Nhap toa do y: ");
		scanf("%i", &y);
	}
	int x1 = x + 1;
	int y1 = y + 1;
	int total = (rows) * (cols)-((y1 - 1)*cols + x1)+1;
	p1 = new int[total];
	int *p2 = new int[rows*cols];
	int a = 0;
	for (int i=0;i<rows;i++)
	{
		for (int j = 0; j < cols; j++)
		{
			p2[a] = p[i][j];
			a++;
		}
	}
	p1[0] = p2[rows*cols - total-2];
	p1[1] = p2[rows*cols - total - 1];
	for (int i = 2; i < total+2; i++)
	{
		p1[i] = p1[i - 1] + p1[i - 2];
	}
	int e = 0;
	for (int i = rows * cols - total - 2; i < rows*cols; i++)
	{
		p2[i] = p1[e];
		e++;
	}
	int af = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			p[i][j] = p2[af];
			af++;
		}
	}
	printArray(rows, cols, p);
}