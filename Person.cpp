#include <string.h>
#include "Person.h"

Person :: Person(char nme[],double num,char gen) : contactNum(num),gender(gen)
{
	strcpy(name,nme);
}

void Person :: setName(char nme[]) 
{
	strcpy(name,nme);
}

void Person::setContact(double num)
{
	contactNum=num;
}

void Person::setGender(char gen)
{
	gender=gen;
}

char* Person::getName()
{
	return name;
}

double Person::getContact()
{
	return contactNum;
}

char Person::getGender()
{
	return gender;
}
