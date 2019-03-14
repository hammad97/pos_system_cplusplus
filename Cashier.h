#pragma once
#include "Person.h"
#include "Product.h"

class Cashier : protected Person 	  //cashier is a Person (inheritance)
{	
	int id;
	char pass[6];
	int salary;
	int age;
	char address[50];
	int cnic;
	Product *pC;                      //Cashier uses Product(Directed Association)          
	public:
	Cashier(char[],double,char,int,int,char[],int,int,char[]);
		
	void setSalary(int);     	 //Setters and Getters
	void setAge(int);
	void setAddress(char[]);
	void setCnic(int);
	void setId(int);
	void setPass(char[]);
	int getSalary();
	int getAge();
	char* getAddress();
	int getCnic();	
	int getId();
	char* getPass();
};

