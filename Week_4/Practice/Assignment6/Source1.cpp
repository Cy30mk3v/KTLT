#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000
#include "Header.h"



void split(char *a, int num)
{
	char filechia[SIZE];
	int k = 0; 
	int i = 1; // so dem
	int si; // dung luong file tong
	int sifi; // dung luong file da chia
	int x = 0; // bien tam

	FILE *f1;
	f1 = fopen(a, "rb");
	if (f1 == NULL)
	{
		printf("Khong tim thay file !");
		return;
	}
	fseek(f1, SEEK_SET, SEEK_END);
	si = ftell(f1);
	fseek(f1, SEEK_SET, SEEK_SET);
	printf("%2.f", si);
	int du = si % num;
	sifi = si / num;

	while (x < num)
	{
		FILE *f2;
		char tmp1[50];
		sprintf(tmp1, "split%i.bin", i);
		f2 = fopen(tmp1, "wb");
		if (sifi)                                      //doc va ghi theo sifi
		{
			fread(filechia, 1, sifi, f1);
			fwrite(filechia, 1, sifi, f2);
		}
		if (x == num - 1)                             // ghi ph?n du còn l?i 
		{
			if (du)
			{
				char *tmp2;
				tmp2 = new char[du];
				fread(tmp2, 1, du, f1);
				fwrite(tmp2, 1, du, f2);
			}
		}
		fclose(f2);
		++x;
		i++;
	}
	fclose(f1);
}

void merge(char *a, int num)
{
	FILE *f1;
	f1 = fopen(a, "wb");
	int x = 0; // bien dem
	int y = 1; // bien dem
	while (x < num)
	{
		FILE *f2;
		int sifi;
		int block;
		int du;
		char namefile[50];
		char tmp[SIZE];
		sprintf(namefile, "split%i.bin", y);
		f2 = fopen(namefile, "rb");

		fseek(f2, SEEK_SET, SEEK_END);
		sifi = ftell(f2);
		fseek(f2, SEEK_SET, SEEK_SET);

		block = sifi / sizeof(tmp);
		du = sifi % sizeof(tmp);

		while (block)
		{
			fread(tmp, 1, sizeof(tmp), f2);
			fwrite(tmp, 1, sizeof(tmp), f1);
			--block;
		}
		if (du)
		{
			fread(tmp, 1, du, f2);
			fwrite(tmp, 1, du, f1);
		}

		++x;
		y++;
	}
	fclose(f1);
}