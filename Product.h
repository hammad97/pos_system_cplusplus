#pragma once

class Product     
{

	int aQuantity;               //available quantitiy
	int nQuantity;               //needed quantitiy  
	int tQuantity;			     //total quantitiy 
	char pname[50];
	double pcode;
	double cp;
	double sp;
	double discount;
	
public:
	
Product(char[] , double , double , double , double , int , int , int  );
void setAQuantity(int  );
void setNQuantity(int );
void setTQuantity(int );
void setPname(char []);
void setPcode(double );
void setCp(double );	
void setSp(double );
void setDiscount(double );
int getAQuantity();
int getNQuantity();
int getTQuantity();
char * getPname();
double getPcode();
double getCp();
double getSp();
double getDiscount();		

};
