#pragma once
#include "Person.h"
#include "Product.h"

class Manager : protected Person  		 //manager is a Person (inheritance)
{
	double salary;
	int age;
	char address[30];
	double cnic;
	Product *pM;  		                 //Manager uses Product(Directed Association) 
	public:
	Manager(char[],double,char,double,int,char[],double);
	Manager();
		
	void setSalary(double);  		    //Setters and Getters
	void setAge(int);
	void setAddress(char[]);
	void setCnic(double);
	double getSalary();
	int getAge();
	char* getAddress();
	double getCnic();
	
	void addCashier(int,char[],int,int,char[],int);
	
	void createProduct(int,double,char[],double,double,double,int,int,double);              //accessing functions of Product and Stock
	void deleteProduct();
	void editProduct();
};
