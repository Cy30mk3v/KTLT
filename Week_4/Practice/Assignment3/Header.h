#include <stdio.h>

struct Fraction
{
	int nu, de;
};

void inputFraction(int n, Fraction *&p);
void writeFraction(char * file, int &n);