#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Header.h"

int main(void)
{
	char f1[100];
	char f2[100];
	char des[100];
	char a1[100];
	char a2[100];
	char A[100];
	Help();
	printf("Input filename to copy:");
	scanf("%s", f1);
	printf("Input filename to paste:");
	scanf("%s", f2);
	CopyFile(f1, f2);
	printf("Input directory's name: ");
	scanf("%s", des);
	copytoDestination(f1, des);
	printf("Input 1st filename to append:");
	scanf("%s", a1);
	printf("Input 2nd filename to append:");
	scanf("%s", a2);
	printf("Input filename to append to:");
	scanf("%s", A);
	appendFile(a1, a2, A);
	


}