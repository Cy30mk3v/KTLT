#include <stdio.h>

struct Fraction
{
	int nu, de;
};

void loadFraction(char *filein, char *fileout, int &n);
void ascendingArray(int n, Fraction *&p);