#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include "Student.h"
#define MAN_ID 0
#define WOMAN_ID  1


int readFile(list &A)
{
	FILE *FILEIN;
	FILEIN = fopen("problem1.txt", "rt");
	fscanf(FILEIN, "%i", &A.number);
	int x = 0;
	for (int i = 0; i < A.number; i++)
	{
		fscanf(FILEIN, "%d\n", &A.student[i].studentID);
		fgets(A.student[i].name, 30, FILEIN);
		fscanf(FILEIN, "%i", &A.student[i].socialID);
		fscanf(FILEIN, "\n%d %d %d", &A.student[i].dayofBirth.day, &A.student[i].dayofBirth.month, &A.student[i].dayofBirth.year);
		fscanf(FILEIN, "%d", &x);
		fscanf(FILEIN, "%f", &A.student[i].GPA);

		if (x == 0)
			A.student[i].genderstudent = MAN;
		else
			A.student[i].genderstudent = WOMAN;

	}
	fclose(FILEIN);
	return A.number;
}

void writeFile(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem2.txt", "w");
	for (int i = 0; i < A.number; i++)
	{
		fprintInfomation(FILEOUT, A.student[i]);
	}
	fclose(FILEOUT);
}


void AVGpoint(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem3.txt", "w");
	float max = A.student[0].GPA;
	int a = 0;
	for (int i = 0; i < A.number; i++)
	{
		if (max < A.student[i + 1].GPA) {
			max = A.student[i + 1].GPA;
			a = i + 1;
		}
		else if (max == A.student[i + 1].GPA && (A.student[i + 1].studentID < A.student[i].studentID)) {
			max = A.student[i + 1].GPA;
			a = i + 1;
		}
	}
	fprintInfomation(FILEOUT, A.student[a]);
}

void belowAVGpoint(list A)
{
	FILE *FILEOUT;
	readFile(A);
	FILEOUT = fopen("problem4.txt", "w");
	fprintf(FILEOUT, "Danh sach sinh vien duoi diem trung binh:\n");
	for (int i = 0; i < A.number; i++)
	{
		if (A.student[i].GPA < 5)
			fprintInfomation(FILEOUT, A.student[i]);
	}
	fclose(FILEOUT);
}

void academicYear(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem5.txt", "w");
	int flag = 0;
	for (int i = 0; i < A.number - 1; i++)
	{
		for (int j = i + 1; j < A.number; j++)
		{
			if ((A.student[i].studentID) > (A.student[j].studentID))
			{
				std::swap(A.student[i], A.student[j]);
			}
		}
	}
	for (int i = 0; i < A.number; i++)
	{
		int f = firstnumber(A.student[i].studentID);
		if ((f) == 10)
		{
			fprintf(FILEOUT, "khoa 10: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if ((f) == 11)
		{
			fprintf(FILEOUT, "khoa 11: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if ((f) == 12)
		{
			fprintf(FILEOUT, "khoa 12: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if ((f) == 13)
		{
			fprintf(FILEOUT, "khoa 13: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if ((f) == 14)
		{
			fprintf(FILEOUT, "khoa 14: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if ((f) == 15)
		{
			fprintf(FILEOUT, "khoa 15: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if (f == 16)
		{
			fprintf(FILEOUT, "khoa 16: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if (f == 17)
		{
			fprintf(FILEOUT, "khoa 17: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
		if (f == 18)
		{
			fprintf(FILEOUT, "khoa 18: ");
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
	}
	fclose(FILEOUT);
}

void findStudentID(list A)
{
	FILE *FILEIN;
	FILE *FILEOUT;
	int MSSV;
	int flag = 0;
	FILEOUT = fopen("problem6.txt", "w");
	printf("Nhap MSSV: ");
	scanf("%i", &MSSV);
	for (int i = 0; i < A.number; i++)
	{
		if (A.student[i].studentID == MSSV)
		{
			fprintInfomation(FILEOUT, A.student[i]);
			return;
		}
	}
	if (flag == 0)
		fprintf(FILEOUT, "Khong tim thay");
	fclose(FILEOUT);
}

void findStudentname(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("Problem7.txt", "w");
	char Ten[10];
	scanf("%s", &Ten);
	int flag = 1;
	for (int i = 0; i < A.number; i++)
	{
		if (strstr(A.student[i].name, Ten) != NULL)
		{
			fprintInfomation(FILEOUT, A.student[i]);
		}
	}
	if (flag == 0)
		fprintf(FILEOUT, "Khong tim thay");
	fclose(FILEOUT);
}

void findWoman(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem8.txt", "w");
	int flag = 0;
	for (int i = 0; i < A.number; i++)
	{
		if (A.student[i].genderstudent == WOMAN_ID)
		{
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		fprintf(FILEOUT, "Khong tim thay");
	fclose(FILEOUT);
}

void findMan(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem9.txt", "w");
	int flag = 0;
	for (int i = 0; i < A.number; i++)
	{
		if (A.student[i].genderstudent == MAN_ID)
		{
			fprintInfomation(FILEOUT, A.student[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		fprintf(FILEOUT, "Khong tim thay");
	fclose(FILEOUT);
}

void sapxepTheoMSSV(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem10.txt", "w");
	for (int i = 0; i < A.number - 1; i++)
	{
		for (int j = i + 1; j < A.number; j++)
		{
			if ((A.student[i].studentID) >(A.student[j].studentID))
			{
				std::swap(A.student[i], A.student[j]);
			}
		}
	}
	for (int i = 0; i < A.number; i++)
	{
		fprintInfomation(FILEOUT, A.student[i]);
	}
	fclose(FILEOUT);
}

void sapxepTheoten(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem11.txt", "w");
	for (int i = 0; i < A.number - 1; i++)
	{
		for (int j = i + 1; j < A.number; j++)
		{
			if (strcmp((A.student[i].name), (A.student[j].name)) > 0)
			{
				std::swap(A.student[i], A.student[j]);
			}
		}
	}
	for (int i = 0; i < A.number; i++)
	{
		fprintInfomation(FILEOUT, A.student[i]);
	}
	fclose(FILEOUT);
}

void sapxepTheoDiem(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem12.txt", "w");
	for (int i = 0; i < A.number - 1; i++)
	{
		for (int j = i + 1; j < A.number; j++)
		{
			if ((A.student[i].GPA) >(A.student[j].GPA))
			{
				std::swap(A.student[i], A.student[j]);
			}
			if ((A.student[i].GPA == A.student[j].GPA) && A.student[i].studentID > A.student[j].studentID)
				std::swap(A.student[i], A.student[j]);
		}
	}
	for (int i = 0; i < A.number; i++)
	{
		fprintInfomation(FILEOUT, A.student[i]);
	}
	fclose(FILEOUT);
}

void findOldest(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem13.txt", "w");
	int min = A.student[0].dayofBirth.year;
	int a = 0;
	for (int i = 0; i < A.number; i++)
	{
		if (A.student[i].dayofBirth.year < min)
		{
			min = A.student[i].dayofBirth.year;
			a = i;
		}

		if (A.student[i].dayofBirth.year == A.student[i + 1].dayofBirth.year &&
			A.student[i].studentID < A.student[i + 1].studentID)
		{
			min = A.student[i].dayofBirth.year;
			a = i;
		}
	}
	fprintInfomation(FILEOUT, A.student[a]);
	fclose(FILEOUT);
}

void top5(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem14.txt", "w");
	int a = 0;
	for (int i = 0; i < A.number; i++)
	{
		if (A.student[i].GPA < A.student[i++].GPA)
			std::swap(A.student[i], A.student[i++]);
		if (A.student[i].GPA == A.student[i++].GPA && ((A.student[i].genderstudent == MAN_ID) && (A.student[i++].genderstudent == WOMAN_ID)))
			std::swap(A.student[i], A.student[i++]);
		if (A.student[i].GPA == A.student[i++].GPA && ((A.student[i].genderstudent == WOMAN_ID) && (A.student[i++].genderstudent == WOMAN_ID))
			&& (A.student[i].studentID < A.student[i++].studentID))
			std::swap(A.student[i], A.student[i++]);
	}
	for (int i = 0; i < 5; i++)
	{
		fprintInfomation(FILEOUT, A.student[i]);
	}
	fclose(FILEOUT);
}

void birthonThismonth(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem15.txt", "w");
	time_t  timenow;
	struct tm *timeinfo;
	time(&timenow);
	timeinfo = localtime(&timenow);
	time_t t = time(0);
	struct tm *now = localtime(&t);
	fprintf(FILEOUT, "Danh sach sinh vien co sinh nhat trong thang nay: ");
	for (int i = 0; i < A.number; i++)
	{
		if (A.student[i].dayofBirth.month == now->tm_mon + 1)
			fprintInfomation(FILEOUT, A.student[i]);
	}
	fclose(FILEOUT);
}

void coupleBirthday(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem16.txt", "w");
	int flag = 0;
	for (int i = 0; i < (A.number / 2); i++)
	{
		for (int j = i + 1; j < A.number; j++)
		{
			int a = A.student[i].dayofBirth.day;
			int b = A.student[j].dayofBirth.day;
			if ((a == b) && (A.student[i].dayofBirth.month == A.student[j].dayofBirth.month) && (i != j))
			{
				fprintf(FILEOUT, "Cap trung ngay sinh: ");
				fprintInfomation(FILEOUT, A.student[i]);
				fprintInfomation(FILEOUT, A.student[j]);
			}
		}
	}
	fclose(FILEOUT);
}

void randomLunch(list A)
{
	FILE *FILEOUT;
	FILEOUT = fopen("problem17.txt", "w");
	int a = rand() % 100;
	int min = abs(lastnumber(A.student[0].studentID) - a);
	for (int i = 0; i < A.number; i++)
	{
		if (abs(lastnumber(A.student[i].studentID) - a) >(abs(lastnumber(A.student[i++].studentID) - a)))
			std::swap(A.student[i], A.student[i++]);
	}
	for (int i = 0; i < A.number; i++)
	{
		int a = A.student[i].studentID / 1000000;
		int b = (A.student[i].studentID - firstnumber(a)*pow(10, 6)) / 100000;
		if ((abs(lastnumber(A.student[i].studentID) - a) == (abs(lastnumber(A.student[i++].studentID) - a)))
			&& (firstnumber(A.student[i].studentID) >(firstnumber(A.student[i++].studentID))))
			std::swap(A.student[i], A.student[i++]);
	}
	fprintInfomation(FILEOUT, A.student[0]);
	fclose(FILEOUT);
}

void fprintInfomation(FILE* FILEOUT, infomation student) {
	const char a[] = "@hcmus.edu.vn";
	char *p = strcat(student.Email, a);
	fprintf(FILEOUT, "%i\n", student.studentID);
	fprintf(FILEOUT, "%s", student.name);
	fprintf(FILEOUT,"%i", student.socialID);
	fprintf(FILEOUT, "\n%i %i %i\n",
		student.dayofBirth.day,
		student.dayofBirth.month,
		student.dayofBirth.year);
	fprintf(FILEOUT, "%i\n", student.genderstudent);
	fprintf(FILEOUT, "%f\n", student.GPA);
	fprintf(FILEOUT, "%s\n", p);
}


int firstnumber(int n)
{
	int a = n / 1000000;
	int b = (n - (a * 1000000)) / 100000;
	return (a * 10 + b);
}

int lastnumber(int n)
{
	int a = n / 1000000;
	int b = (n - (a * 1000000)) / 100000;
	int c = (n - (a * 1000000) - b * 100000) / 10000;
	int d = (n - (a * 1000000) - (b * 100000) - (c * 10000)) / 1000;
	int e = (n - (a * 1000000) - (b * 100000) - (c * 10000) - (d * 1000)) / 100;
	int f = (n - (a * 1000000) - (b * 100000) - (c * 10000) - (d * 1000) - (e * 100)) / 10;
	int g = (n - (a * 1000000) - (b * 100000) - (c * 10000) - (d * 1000) - (e * 100) - (f * 10));
	return f * 10 + g;
}

void lamemail(char a[], char b[])
{
	int c = 0, u = 0;
	int n = strlen(a);
	b[c++] = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] == ' ')
		{
			b[c++] = a[i + 1];
			u = i + 2;
		}
	}
	for (int i = u; i <= n; ++i)
	{
		b[c++] = a[i];
	}

	for (int i = 0; i < strlen(b); ++i)
	{
		b[i] = tolower(b[i]);
	}

}
