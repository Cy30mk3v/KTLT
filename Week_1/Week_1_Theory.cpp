/*
HỌ TÊN: VÕ TRẦN CHÍ HƯNG
MSSV:1753058
*/


#define _CRT_SECURE_NO_WARNINGS 1
#define TEA_ID 1
#define COFFEE_ID 0
#define MAX 1000


struct location;
struct tree;
struct plantation;
int countTrees(plantation p, int type);
int countCoffeeTrees(plantation p, int type);
int countTeaTrees(plantation p, int type);
location findUpperLeft(plantation p);
location findLowerRight(plantation p);
float calcFenceLength(plantation p);
location findPump(plantation p);
float distance(location p, location q);
float calculateTotalLength(plantation p);
void scanFile(plantation &p, int &number);
void writeFile(plantation p, int coffee, int tea, float tube, float fence);




#include <stdio.h>
#include <math.h>


// CÂU A
//KHAI BÁO STRUCT
struct location
{
	float x, y;
};

struct tree
{
	location point;
	int type;
};

struct plantation
{
	tree trees[MAX];
	int number;
};

//CÂU B
//HÀM ĐẾM SỐ LƯỢNG CÂY MỖI LOẠI


int countTrees(plantation p, int type)
{
	int count = 0;
	for (int i = 0; i < p.number; i++)
	{
		if (p.trees[i].type == type)
			count++;
	}
	return count;
}

//HÀM ĐẾM SỐ CÂY CÀ PHÊ
int countCoffeeTrees(plantation p)
{
	return countTrees(p, COFFEE_ID);
}

//HÀM ĐẾM SỐ LƯỢNG CÂY TRÀ
int countTeaTrees(plantation p)
{
	return countTrees(p, TEA_ID);
}

//CÂU C
//HÀM TÌM ĐIỂM TRÊN CÙNG BÊN TRÁI
location findUpperLeft(plantation p)
{
	float x = p.trees[0].point.x;
	float y = p.trees[0].point.y;
	for (int i = 0; i < p.number; i++)
	{
		if (p.trees[i].point.x < x)
		{
			x = p.trees[i].point.x;
		}
		if (p.trees[i].point.y > y)
		{
			y = p.trees[i].point.y;
		}
	}
	return { x,  y };
}

//TÌM ĐIỂM DƯỚI CÙNG BÊN PHẢI
location findLowerRight(plantation p)
{
	float x = p.trees[0].point.x;
	float y = p.trees[0].point.y;
	for (int i = 0; i < p.number; i++)
	{
		if (p.trees[i].point.x > x)
		{
			x = p.trees[i].point.x;
		}
		if (p.trees[i].point.y < y)
		{
			y = p.trees[i].point.y;
		}
	}
	return { x, y };
}

//TÍNH TOÁN TỔNG CHIỀU DÀI HÀNG RÀO BAO QUANH
float calcFenceLength(plantation p)
{
	location p1 = findUpperLeft(p);
	location p2 = findLowerRight(p);
	return (fabsf(p1.x - p2.x) + fabsf(p1.y - p2.y)) * 2;
}


//CÂU D
//HÀM TÍNH ĐIỂM TRUNG TÂM CỦA CÁC CÂY
location findPump(plantation p)
{
	float xCenter, yCenter;
	float xTotal = 0;
	float yTotal = 0;
	for (int i = 0; i < p.number; i++)
	{
		xTotal = xTotal + p.trees[i].point.x;
		yTotal = yTotal + p.trees[i].point.y;
	}
	xCenter = xTotal / (p.number);
	yCenter = yTotal / (p.number);
	return { xCenter,yCenter };
}

//HÀM TÍNH KHOẢNG CÁCH GIỮA 2 ĐIỂM
float distance(location p, location q)
{
	return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

// HÀM TÍNH TỔNG ĐỘ DÀI ỐNG ĐÃ SỬ DỤNG
float calculateTotalLength(plantation p)
{
	float totalLength = 0;
	for (int i = 0; i < p.number; i++)
	{
		totalLength = totalLength + distance(findPump(p), p.trees[i].point);
	}
	return totalLength;
}

//HÀM MAIN
int main()
{
	int number, countTEA, countCOFFEE;
	plantation p;
	scanFile(p, number);
	countTEA = countTeaTrees(p);
	countCOFFEE = countCoffeeTrees(p);
	float tube = calculateTotalLength(p);
	float fence = calcFenceLength(p);
	writeFile(p, countCOFFEE, countTEA, fence, tube);

}

//HÀM NHẬP FILE
void scanFile(plantation &p, int &number)
{
	FILE *FILEIN;
	FILEIN = fopen("NongTrai.in.txt", "r");
	fscanf(FILEIN, "%i", &p.number);
	for (int i = 0; i < p.number; i++)
	{
		fscanf(FILEIN, "%f %f %i", &p.trees[i].point.x, &p.trees[i].point.y, &p.trees[i].type);
	}
	fclose(FILEIN);
}

//HÀM XUẤT FILE
void writeFile(plantation p, int coffee, int tea, float tube, float fence)
{
	FILE *FILEOUT;
	FILEOUT = fopen("NongTrai.out.txt", "w");
	fprintf(FILEOUT, "%i %i", coffee, tea);
	fprintf(FILEOUT, "\n");
	fprintf(FILEOUT, "%f", tube);
	fprintf(FILEOUT, "\n");
	fprintf(FILEOUT, "%f", fence);
	fclose(FILEOUT);
}
