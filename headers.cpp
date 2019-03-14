#include <string.h>
#include "headers.h"

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
//////////////////////////////
	onlineCustomer::onlineCustomer(char id1[],char pass1[]):Person("dummy", 030010, 'M' )
	{
		strcpy(id,id1);
		strcpy(pass,pass1);
		
	}
	//onlineCustomer::searchCustomer(){};
	
	void onlineCustomer::setId(char  id1[])
		{
		strcpy(id,id1);

		}
	void onlineCustomer::setPass(char pass1[])
	{
	strcpy(pass,pass1);

	}
	char * onlineCustomer:: getId()
	{
		return id;
	}
	char * onlineCustomer:: getPass()
	{
		return pass;
	}
	
	onlineCustomer::~onlineCustomer();
//////////////////////////////////////

class walkInCustomer : protected Person 	  //customer is a Person (inheritance)
{
	
	public:
	walkInCustomer(char[],double,char);
};

walkInCustomer::walkInCustomer(char nme[],double num,char gen): contactNum(num), gender(gen)
{
	strcpy(name,nme);
}
///////////////////////////////////////

Manager::Manager(char n[], double cn, char g, double s, int a, char add[], double cnIC):Person (n,cn,g)
{
	salary=s;
	age=a;
	strcpy(address,add);
	cnic=cnIC;
}
void Manager::setSalary(double s)
{
	salary=s;
}
void Manager::setAge(int a)
{
	age=a;
}
void Manager::setAddress(char add[])
{
	strcpy(address,add);
}
void Manager::setCnic(double cnIC)
{
	cnic=cnIC;
}
double Manager::getSalary()
{
	return salary;
}
int Manager::getAge()
{
	return age;
}
char* Manager::getAddress()
{
	return address;
}
double Manager::getCnic()
{
	return cnic;
}
//1 for PrePacked Food, 2 for Fresh Food, 3 for Cosmetics, 4 for Beverages//
void Manager::createProduct()
{
	Product *ptr;
	int opt;
	cout<<"Which type of product you want to enter: ";
	cin>>opt;
	char pname[50],mfgdate[10],expdate[10];
	double aQuantity,sQuantity,tQuantity,pcode,cp,sp,discount;
	cout<<"Enter Product Name: ";
	cin>>pname;
	cout<<"Enter Manafucturing Date: ";
	cin>>mfgdate;
	cout<<"Enter Expiry Date: ";
	cin>>mfgdate;
	cout<<"Available Quantity: ";
	cin>>aQuantity;
	cout<<"Sold Quantity: ";
	cin>>sQuantity;
	cout<<"Total Quantity: ";
	cin>>tQuantity;
	cout<<"Product Code: ";
	cin>>pcode;
	cout<<"Enter Cost Price: ";
	cin>>cp;
	cout<<"Enter Sell Price: ";
	cin>>sp;
	cout<<"Enter Discount: ";
	cin>>discount;
	switch(opt)
	{
		case 1:
			int Quan;
			cout<<"Enter PrePacked Item Quantity: ";
			cin>>Quan;
			ptr= new PrePackedFood(pname,mfgdate,expdate,aQuantity,sQuantity,tQuantity,pcode,cp,sp,discount,Quan) ;
			break;
		case 2:
			double Quani;
			cout<<"Enter Fresh Food Item Quantity: ";
			cin>>Quani;
			ptr=new FreshFood(pname,mfgdate,expdate,aQuantity,sQuantity,tQuantity,pcode,cp,sp,discount,Quani) ;
			break;
		case 3:
			int Quant;
			cout<<"Enter Cosmetic Item Quantity: ";
			cin>>Quant;
			ptr=new Cosmetics(pname,mfgdate,expdate,aQuantity,sQuantity,tQuantity,pcode,cp,sp,discount,Quant) ;
			break;
		case 4:
			double Quany;
			cout<<"Enter Beverage Item Quantity: ";
			cin>>Quany;
			ptr=new Beverages(pname,mfgdate,expdate,aQuantity,sQuantity,tQuantity,pcode,cp,sp,discount,Quany) ;
			break;
		defualt:
			cout<<"Enter correct choice!!";
			break;					
	}
}
void Manager::deleteProduct()
{
	//yahan filing se kaam hoga. file se delete hoga.
}
void Manager::editProduct()
{
	double tempPCode;
	cout<<"Enter Product Code: ";
	cin>>tempPCode;
//	pM->searchProduct(tempPCode);
	/*Incomplete because of filing but there will be a function to search a product and edit it*/
}
//////////////////////////////////////////////

Cashier::Cashier(string n, double cn, char g, double s, int a, string add, double cnIC, double iD):Person (n,cn,g)
{
	salary=s;
	age=a;
	address=add;
	cnic=cnIC;
	id=iD;
}
void Cashier::setSalary(double s)
{
	salary=s;
}
void Cashier::setAge(int a)
{
	age=a;
}
void Cashier::setAddress(string add)
{
	address=add;
}
void Cashier::setCnic(double cnIC)
{
	cnic=cnIC;
}
void Cashier::setId(double iD)
{
	id=iD;
}
double Cashier::getSalary()
{
	return salary;
}
int Cashier::getAge()
{
	return age;
}
string Cashier::getAddress()
{
	return address;
}
double Cashier::getCnic()
{
	return cnic;
}
double Cashier::getId()
{
	return id;
}
/////////////////////////////////////////////
	Product::	Product(char pname1[], double pcode1, double cp1, double sp1, double discount1, int aquantity, int nquantity, int stquantity )
	{
		strcpy(pname, pname1);
		pcode=pcode1;
		cp=cp1;
		sp=sp1;
		discount=discount1;
		aQuantity=aquantity;
		nQuantity=nquantity;
		stQuantity=stquantity;

	}
	void Product::setAQuantity(int aquantity )
	{
	 aQuantity =aquantity;
	}
	void Product::setNQuantity(int nquantity)
	{
		nQuantity=nquantity;
	}
	void Product::setTQuantity(int stquantity)
	{
		stQuantity=stquantity;
	}
	int Product::getAQuantity()
	{
		return aQuantity;
	}
	int Product:: getNQuantity()
	{
		return nQuantity;

	}
	int Product::getTQuantity()
	{
		return stQuantity;

	}	
	void Product::setPname(char pname1[])
	{
		strcpy(pname,pname1 );
	}
	void Product::setPcode(double pcode1)
	{
		pcode=pcode1;
	}
	void Product::setCp(double cp1)
	{
		cp=cp1;
	}
	void Product::setSp(double sp1)
	{
		sp=sp1;
	}
	void Product::setDiscount(double discount1)
	{
		discount=discount1;
	}
	char * Product::getPname()
	{
		return pname;
	}
	double Product::getPcode()
	{
		return pcode;

	}
	double Product::getCp()
	{
		return cp;
	}
	double Product::getSp()
	{
		return sp;
	}
	double Product::getDiscount()
	{
		return discount;
	}
//	void searchProduct(double pcoode)
//	{
//		
//	}

///////////////////////////////
PrePackedFood::PrePackedFood(char pname[50],char mfgdate[10],char expdate[10],int aoQuantity,int noQuantity, int stQuantity,double pcode,double cp,double sp,double discount,int Quan)
:Product(pname,pcode,cp,sp,discount,aoQuantity,noQuantity,stQuantity)
{
	QuantityInUnit=Quan;
}
double PrePackedFood::CalculatePrice()
{
	double pric;
	double dis;
	dis=getDiscount();
     //filing 
     TotalPrice=pric*QuantityInUnit;
     if(dis>0)
     {
     	TotalPrice=TotalPrice*(dis/100);
	 }
	 else if(dis==0)
	 {
	 	TotalPrice=TotalPrice+TotalPrice*(dis/100);
	 }
}
PrePackedFood::setQuantityInUnit(int q)
{
	QuantityInUnit=q;
}
int PrePackedFood::getQuantityInUnit()
{
	return QuantityInUnit;
}
double PrePackedFood::getTotalPrice()
{
        return TotalPrice;
}
//////////////////////////////////////
FreshFood::FreshFood(char pname[50],int avQuantity,int soQuantity, int toQuantity,double pcode,double cp,double sp,double discount,double Quan)
:Product(pname,pcode,cp,sp,discount,avQuantity,toQuantity,soQuantity)
{
	QuantityInKg=Quan;
}
double FreshFood::CalculatePrice()
{
	double pric;
	double dis;
	dis=getDiscount();
     //filing 
     TotalPrice=pric*QuantityInKg;
     if(dis>0)
     {
     	TotalPrice=TotalPrice*(dis/100);
	 }
	 else if(dis==0)
	 {
	 	TotalPrice=TotalPrice+TotalPrice*(dis/100);
	 }
}
FreshFood::setQuantityInKg(double q)
{
	QuantityInKg=q;
}
double FreshFood::getQuantityInKg()
{
	return QuantityInKg;
}
double FreshFood::getTotalPrice()
{
        return TotalPrice;
}

///////////////////////////
Cosmetics::Cosmetics(char pname[50],int avQuantity,int soQuantity, int toQuantity,double pcode,double cp,double sp,double discount,int Quan)
:Product(pname,pcode,cp,sp,discount,avQuantity,soQuantity,toQuantity)
{
	QuantityInUnits=Quan;
}
double Cosmetics::CalculatePrice()
{
	double pric;
     //filing 
     TotalPrice=pric*QuantityInUnits;
      double dis;
	 dis=getDiscount();
     if(dis>0)
     {
     	TotalPrice=TotalPrice*(dis/100);
	 }
	 else if(dis==0)
	 {
	 	TotalPrice=TotalPrice+TotalPrice*(dis/100);
	 }
}
Cosmetics::setQuantityInUnits(int q)
{
	QuantityInUnits=q;
}
int Cosmetics::getQuantityInUnits()
{
	return QuantityInUnits;
}
double Cosmetics::getTotalPrice()
{
        return TotalPrice;
}
//////////////////////////////////

Beverages::Beverages(char pname[50],int aQuantity,int sQuantity, int tQuantity,double pcode,double cp,double sp,double discount,double Quan)
:Product(pname,pcode,cp,sp,discount,aQuantity,tQuantity,sQuantity)
{
	QuantityInLiters=Quan;
}
double Beverages::CalculatePrice()
{
	double pric;
	double dis;
	dis=getDiscount();
     //filing 
     TotalPrice=pric*QuantityInLiters;
     if(dis>0)
     {
     	TotalPrice=TotalPrice*(dis/100);
	 }
	 else if(dis==0)
	 {
	 	TotalPrice=TotalPrice+TotalPrice*(dis/100);
	 }
}
void Beverages::setQuantity(double q)
{
	QuantityInLiters=q;
}
double Beverages::getQuantity()
{
	return QuantityInLiters;
}
double Beverages::getTotalPrice()
{
        return TotalPrice;
}
//////////////////////////////////////

Billing :: setTotalSP(double tsp) : totalSP(tsp)
{	
}

Billing :: setTotalCP(double tcp) : totalCP(tcp)
{	
}

Billing :: setQuantity(int qty) : quantity(qty)
{	
}

double Billing::getTotalSP()
{
	return totalSP;
}

double Billing::getTotalCP()
{
	return totalCP;
}

int Billing::getQuantity()
{
	return quantity;
}

void Billing :: printBill()
{
	// windows.h related
}
