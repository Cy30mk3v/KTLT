#include <stdio.h>
#include "Header.h"

float Fraction(int n)
{
	if (n == 1)
		return 1.0;
	if (n % 2 == 0 )
		return -1.0 / n + Fraction(n-1);
	if (n % 2 != 0 )
		return 1.0 / n + Fraction(n-1);
}

