#pragma once
#include "Person.h"

class onlineCustomer : protected Person	  //customer is a Person (inheritance)
{
	char id[6]; //e.g 012016
	char pass[6];  //not more than 6 char. exception handling
	char address[30]; 
	public:
	onlineCustomer(char[],char []);
	//searchCustomer(); // search karay ga
	void setId(char  []);
	void setPass(char []);
	char * getId();
	char * getPass();
	
	~onlineCustomer();
};
