#define _CRT_SECURE_NO_WARNINGS 0
#define AAA 10000
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Header.h"


void Erase(char *a, int &n, int vitri)
{
	for (int i = vitri; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}

void removeSpace(char *a, int &n)
{
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == ' ')
		{
			k++;
		}
		else
		{
			break;
		}
	}
	for (int i = k - 1; i >= 0; --i)
	{
		Erase(a, n, i);
	}
	

	k = 0;
	for (int i = n - 1; i > 0; --i)
	{
		if (a[i] == ' ')
		{
			k++;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < k-1; ++i)
	{
		Erase(a, n, n-1-i);
	}
}

void Capitalize(char *a, int n)
{
	a[0] -= 32;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] == ' ' && a[i+1]>96 && a[i+1]<123)
		{
			a[i + 1] -= 32;
		}
		if (a[i] != ' ' && a[i + 1] > 64 && a[i + 1] < 91)
		{
			a[i + 1] += 32;
		}
	}
}

void removeSpacemiddle(char *a, int &n)
{
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		 k = 0;
		if (a[i] == ' ')
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (a[j] == ' ')
				{
					k++;
				}
				else
				{
					break;
				}
			}
			for (int l = k + i; l > i; --l)
			{
				Erase(a, n, l);
			}
		}
	}
}

