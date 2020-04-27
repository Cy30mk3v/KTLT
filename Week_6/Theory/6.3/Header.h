#pragma once
struct Person
{
	char *name;
	int age;
	Person *father;
	Person *mother;
};

int countAncestor(Person *p);
int countAnces(Person *p);
int countMotherAnces(Person *p); 
