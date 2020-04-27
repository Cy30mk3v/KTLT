#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Header.h"

void CopyFile(char *f1, char *f2)
{
	FILE *fin;
	FILE *fout;
	fin = fopen(f1, "rb");
	if (fin == NULL)
	{
		printf("File not found!");
		return;
	}
	fout = fopen(f2, "wb");
	char BUFF[1000];
	int count;
	do
	{
		count = fread(BUFF, sizeof(char), 1000, fin);
		fwrite(BUFF, sizeof(char), count, fout);
	} while (count == 1000);
	fclose(fin);
	fclose(fout);
}

void copytoDestination(char *f1, char *des)
{
	FILE *fin;
	fin = fopen(f1, "rb");
	if (fin == NULL)
	{
		printf("File not found!");
		return;
	}
	char f2[1000];
	strcpy(f2,des);
	strcat(f2,"\\");
	strcat(f2, f1); 
	FILE *fout;
	fout = fopen(f2, "wb");
	if (fout == NULL)
	{
		printf("Folder not found!");
	}
	char BUFF[1000];
	int count;
	do
	{
		count = fread(BUFF, sizeof(char), 1000, fin);
		fwrite(BUFF, sizeof(char), count, fout);
	} while (count == 1000);
	fclose(fin);
	fclose(fout);
}

void appendFile(char *f1, char *f2, char *des)
{
	CopyFile(f1, des);
	FILE *fin;
	FILE *fout;
	fin = fopen(f2, "rb");
	fout = fopen(des, "ab");
	if (fin == NULL)
	{
		printf("File 2 not found!");
		return;
	}
	char BUFF1[1000];
	int count1;
	do
	{
		count1 = fread(BUFF1, sizeof(char), 1000, fin);
		fwrite(BUFF1, sizeof(char), count1, fout);
	} while (count1 == 1000);
	fclose(fin);
	fclose(fout);
}

void Help()
{
	char A[2];
	printf("Do you need help? Y/N:  ");
	scanf("%s", A);
	if (A[0] == 'Y'|| A[0] == 'y')
	{
		int i = -1;
		while (i < 0 || i>3)
		{
			printf("Which prolem you need to help? 1,2,3\n");
			printf("1: COPY FILE\n");
			printf("2: COPY FILE TO DESTINATION\n");
			printf("3: APPEND 2 FILE\n");
			scanf("%i", &i);
		}
		if (i == 1)
		{
			printf("This function will help you to copy data from file 1 to file 2\n");
			printf("You need to type names of file 1 and file 2\n");
		}
		if (i == 2)
		{
			printf("This funtion will help you to copy data from file 1 to a file in destination directory\n");
			printf("You need to type names of file input and destination directory\n");
		}
		if (i == 3)
		{
			printf("This function will help you to append 2 files\n");
			printf("You need to type 2 names of file input and a name of destination file\n");
		}
	}
	if (A[0]=='N' || A[0] == 'n')
		return;
	else Help();
}