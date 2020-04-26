#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include "Student.h"


#define char DH[20] = "@hcmus.edu.vn"

int main(void)
{
	list A;
	int i= readFile(A);
	for (int j = 0; j < i; j++)
	{
		lamemail(A.student[j].name, A.student[j].Email);

	}
	AVGpoint(A);
	writeFile(A);
	belowAVGpoint(A);
	findStudentID(A);
	findStudentname(A);
	findWoman(A);
	findMan(A);
	sapxepTheoMSSV(A);
	sapxepTheoten(A);
	sapxepTheoDiem(A);
	findOldest(A);
	academicYear(A);
	birthonThismonth(A);
	top5(A);
	coupleBirthday(A);
	randomLunch(A);
	
}