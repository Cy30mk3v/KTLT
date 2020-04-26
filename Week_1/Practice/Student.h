
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <stdio.h>
#include <string.h>
#define MAX 1000


struct date {

	int day;
	int month;
	int year;
};

//Enum no tu xep theo thu tu tu-tren-xuong-duoi
enum gender
{
	MAN, //0
	WOMAN, //1
	NA, // 2
};

struct infomation {
	int studentID;
	char name[30];
	int socialID;
	date dayofBirth;
	gender genderstudent;
	float GPA;
	char Email[100];
};


struct list
{
	infomation student[MAX];
	int number;
};

int readFile(list &A);
void writeFile(list A);
int firstnumber(int n);
void AVGpoint(list A);
void belowAVGpoint(list A);
void academicYear(list A);
void findStudentID(list A);
void findStudentname(list A);
void findWoman(list A);
void findMan(list A);
void sapxepTheoMSSV(list A);
void sapxepTheoten(list A);
void sapxepTheoDiem(list A);
void findOldest(list A);
void fprintInfomation(FILE* FILEOUT, infomation student);
void top5(list A);
void birthonThismonth(list A);
void randomLunch(list A);
void coupleBirthday(list A);
int lastnumber(int n);
void lamemail(char a[], char b[]);
#endif