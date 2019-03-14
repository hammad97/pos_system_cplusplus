
#include "Cashier.h"
#include <string.h>

Cashier::Cashier(char n[], double cn, char g, int s, int a, char add[], int cnIC, int iD,char pw[]):Person (n,cn,g)
{
	salary=s;
	age=a;
	strcpy(address,add);
	cnic=cnIC;
	id=iD;
	strcpy(pass,pw);
}
void Cashier::setSalary(int s)
{
	salary=s;
}
void Cashier::setAge(int a)
{
	age=a;
}
void Cashier::setAddress(char add[])
{
	strcpy(address,add);
}
void Cashier::setCnic(int cnIC)
{
	cnic=cnIC;
}
void Cashier::setId(int iD)
{
	id=iD;
}
void Cashier::setPass(char pw[6])
{
	strcpy(pass,pw);
}
char* Cashier::getPass()
{
	return pass;
}
int Cashier::getSalary()
{
	return salary;
}
int Cashier::getAge()
{
	return age;
}
char* Cashier::getAddress()
{
	return address;
}
int Cashier::getCnic()
{
	return cnic;
}
int Cashier::getId()
{
	return id;
}
