#include <stdio.h>
#include "Header.h"

int main(void)
{
	Person p;
	p.father = new Person;
	p.mother = new Person;

	p.mother->mother = new Person;
	p.father->mother = new Person;

	printf("%i\n%i\n", countAnces(&p), countMotherAnces(&p));

}