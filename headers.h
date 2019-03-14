//#pragma once
//person header
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

///////////////////
class onlineCustomer : protected Person	  //customer is a Person (inheritance)
{
	char id[6]; //e.g 012016
	char pass[6];  //not more than 6 char. exception handling
	char address[30]; 
	public:
	onlineCustomer(char[],char []);
	//searchCustomer(); // search karay ga
	setId(char  []);
	setPass(char []);
	char * getId();
	char * getPass();
	
	~onlineCustomer();
};

///////////////////////
class walkInCustomer : protected Person 	  //customer is a Person (inheritance)
{
	
	public:
	walkInCustomer(char[],double,char);

};
/////////////////////////




class Product     
{

	int aQuantity;               //available quantitiy
	int nQuantity;               //needed quantitiy  
	int stQuantity;			     //total quantitiy sold
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
//searchProduct(double);			

};
///////////////////////////////////////
class Cashier : protected Person 	  //cashier is a Person (inheritance)
{
	double salary;
	int age;
	char address[50];
	double cnic;
	double id;
	Product *pC;                      //Cashier uses Product(Directed Association)          
	public:
	Cashier(char[],double,char,double,int,char[],double,double);
		
	void setSalary(double);     	 //Setters and Getters
	void setAge(int);
	void setAddress(char[]);
	void setCnic(double);
	void setId(double);
	double getSalary();
	int getAge();
	char* getAddress();
	double getCnic();	
	double getId();
};
/////////////////////////////////
////////////////////////////////////////
class Manager : protected Person  		 //manager is a Person (inheritance)
{
	double salary;
	int age;
	char address[30];
	double cnic;
	Product *pM;  		                 //Manager uses Product(Directed Association) 
	public:
	Manager(char[],double,char,double,int,char[],double);
		
	void setSalary(double);  		    //Setters and Getters
	void setAge(int);
	void setAddress(char[]);
	void setCnic(double);
	double getSalary();
	int getAge();
	char* getAddress();
	double getCnic();
	
	void createProduct();              //accessing functions of Product and Stock
	void deleteProduct();
	void editProduct();
};
/////////////////////////////////////////
class PrePackedFood:public Product
{
	int QuantityInUnit;
	double TotalPrice;
	public:
		PrePackedFood(char [],char [],char [],int ,int , int ,double ,double ,double ,double ,int );
    double    CalculatePrice();
        setQuantityInUnit(int );
        int getQuantityInUnit();
        double getTotalPrice();
};
///////////////////////////////////////

class FreshFood:public Product
{
	double QuantityInKg;
	double TotalPrice;
	public:
	FreshFood(char [],int ,int , int ,double ,double ,double ,double ,double );
	double CalculatePrice();
	setQuantityInKg(double );
    double getQuantityInKg();
    double getTotalPrice();
};
//////////////////////////////////////

class Cosmetics:public Product
{
	int QuantityInUnits;
	double TotalPrice;
	public:
		Cosmetics(char [],int ,int , int ,double ,double ,double ,double ,int );
	    double CalculatePrice();
	    setQuantityInUnits(int );
        int getQuantityInUnits();
        double getTotalPrice();
};
////////////////////////////////

class Beverages:public Product
{
	double QuantityInLiters;
	double TotalPrice;
	public:
     Beverages(char [],int ,int , int ,double ,double ,double ,double ,double );
	 double CalculatePrice();
	 void setQuantity(double );
     double getQuantity();
    double getTotalPrice();
};
/////////////////////////////////////


class Billing 						//Billing has a Product (Aggregation)
{
	double totalSP;
	double totalCP;
	int quantity;            
	double discounted;       
	Product *pB;
	public:
	setTotalSP(double);
	setTotalCP(double);
	setQuantity(int);
	double getTotalSP();
	double getTotalCP();
	int getQuantity();
	void printBill();
};
