#include <stdio.h>
#include "Header.h"

int countAncestor(Person *p)
{
	if (p == NULL)
		return 0;

	if (p->father == NULL && p->mother == NULL)
		return 1;

	if (p->father == NULL || p->mother == NULL)
		return 2;

	return 1 + countAncestor(p->father) + countAncestor(p->mother);
}

int countAnces(Person *p)
{
	return countAncestor(p) - 1;
}

int countMotherAnces(Person *p)
{
	return countAncestor(p->mother);
}