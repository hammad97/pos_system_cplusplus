#pragma once

class Person 
{
	char name[20];
	double contactNum;
	char gender;
	public:
	Person(char[],double,char);           
	void setName(char[]);             //Setters and Getters
	void setContact(double);
	void setGender(char);
	char* getName();
	double getContact();
	char getGender();
};
