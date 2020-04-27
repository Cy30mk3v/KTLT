#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


bool isPalindrome(char wordPal[], int l, int r)
{
	if (l == r)
		return true;
	if (wordPal[l] != wordPal[r])
		return false;
	if (l < r + 1)
		return isPalindrome(wordPal, l + 1, r - 1);
}

bool check(char str[])
{
	int n = strlen(str);
	if (n == 0)
		return true;
	return isPalindrome(str, 0, n - 1);
}



