#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <algorithm>

using namespace std;
void getArray(int A[], int len)
{
	
	for (int i = 0; i < len; i++)
	{
		printf("A[%i]=", i);
		scanf("%i", &A[i]);
	}
}

void printArray(int A[], int pos, int len)
{
	if (pos >= len)
		return;
	printf("A[%i]=%i\n", pos, A[pos]);
	printArray(A, pos + 1, len);
}

void reverseArray(int A[], int start, int len)
{
	if (start == len/2)
		return;
	std::swap(A[start], A[len - start - 1]);
	reverseArray(A, start + 1, len);
}

int sumPosNumberinArray(int A[], int len)
{
	if (len == 1)
	{
		if (A[0] >= 0)
			return A[0];
		else
			return 0;
	}
	if (A[len - 1] > 0)
		return A[len - 1] + sumPosNumberinArray(A, len - 1);
	else
		return sumPosNumberinArray(A, len - 1);
}

bool checkDistinct(int A[], int pos, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (A[i] == A[pos])
			count++;
	}
	return count == 1;
}

int distinctValue(int A[], int start, int len)
{
	if (start == len)
		return 0;
	int count = checkDistinct(A, start, len);
	return count + distinctValue(A, start + 1, len);
}

bool checkOdd(int A[], int len)
{
	if (len == 0)
	{
		if (A[0] % 2 == 0)
			return false;
		return true;
	}
	if (A[len] % 2 != 0)
		checkOdd(A, len-1);
	else
		return false;
}

int getMax(int A[], int len, int max, int i)
{
	if (i<len)
	{
		if (max < A[i])
			max = A[i];
		getMax(A, len, max, i+1);
	}
	return max;
}