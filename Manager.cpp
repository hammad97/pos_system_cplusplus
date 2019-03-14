#include <iostream>
#include <string.h>
#include <fstream>
#include "Manager.h"
#include "Cashier.h"
#include "Product.h"
#include "PrePackedFood.h"
#include "FreshFood.h"
#include "Cosmetics.h"
#include "Beverages.h"

using namespace std;

Manager::Manager(): Person("admin",12345,'M')
{
}

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
void Manager::addCashier(int id,char pass[],int sal,int age,char add[],int cnic)
{
	Cashier temp("dummy",12345,'M',sal,age,add,cnic,id,pass);
	ofstream outFile;
	outFile.open("cashier.txt",fstream::out|fstream::app);	
	outFile<<temp.getId()<<endl<<temp.getPass()<<endl<<temp.getSalary()<<endl<<temp.getAge()<<endl<<temp.getAddress()<<endl<<temp.getCnic()<<endl;	
    outFile.close();
}
//1 for PrePacked Food, 2 for Fresh Food, 3 for Cosmetics, 4 for Beverages//
void Manager::createProduct(int opt,double pcode,char pname[],double cp,double sp,double Quan,int tQuantity,int nQuantity,double discount)
{
	ofstream outFile;
	outFile.open("product.txt",fstream::out|fstream::app);	
	double aQuantity;
	aQuantity=tQuantity;
	switch(opt)
	{
		case 1:
			PrePackedFood *ptr;
			int quan;
			quan=(int)Quan;
			ptr= new PrePackedFood(pname,aQuantity,tQuantity,nQuantity,pcode,cp,sp,discount,quan) ;
			outFile<<ptr->getPcode()<<endl<<ptr->getPname()<<endl<<ptr->getCp()<<endl<<ptr->getSp()<<endl<<ptr->getQuantityInUnit()<<endl<<ptr->getTQuantity()<<endl<<ptr->getAQuantity()<<endl<<ptr->getNQuantity()<<endl<<ptr->getDiscount()<<endl;
	//		delete []ptr; ///YE karny ki zarurat ha bhi ya nai ?
			break;
		case 2:
			FreshFood *ptr1;	
			ptr1=new FreshFood(pname,aQuantity,tQuantity,nQuantity,pcode,cp,sp,discount,Quan) ;
			outFile<<ptr1->getPcode()<<endl<<ptr1->getPname()<<endl<<ptr1->getCp()<<endl<<ptr1->getSp()<<endl<<ptr1->getQuantityInKg()<<endl<<ptr1->getTQuantity()<<endl<<ptr1->getAQuantity()<<endl<<ptr1->getNQuantity()<<endl<<ptr1->getDiscount()<<endl;
			break;//1 for PrePacked Food, 2 for Fresh Food, 3 for Cosmetics, 4 for Beverages//
		case 3:
			Cosmetics *ptr2;
			int quan2;
			quan2=(int)Quan;
			ptr2=new Cosmetics(pname,aQuantity,tQuantity,nQuantity,pcode,cp,sp,discount,quan2) ;
			outFile<<ptr2->getPcode()<<endl<<ptr2->getPname()<<endl<<ptr2->getCp()<<endl<<ptr2->getSp()<<endl<<ptr2->getQuantityInUnits()<<endl<<ptr2->getTQuantity()<<endl<<ptr2->getAQuantity()<<endl<<ptr2->getNQuantity()<<endl<<ptr2->getDiscount()<<endl;
			break;
		case 4:
			Beverages *ptr3;
			ptr3=new Beverages(pname,aQuantity,tQuantity,nQuantity,pcode,cp,sp,discount,Quan) ;
			outFile<<ptr3->getPcode()<<endl<<ptr3->getPname()<<endl<<ptr3->getCp()<<endl<<ptr3->getSp()<<endl<<ptr3->getQuantity()<<endl<<ptr3->getTQuantity()<<endl<<ptr3->getAQuantity()<<endl<<ptr3->getNQuantity()<<endl<<ptr3->getDiscount()<<endl;
			break;
		defualt:
			cout<<"Enter correct choice!!";
			break;					
	}
    outFile.close();
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
//	ofstream outFile;
//	outFile.open("abc.txt",fstream::out|fstream::app);
//
//	outFile<<endl<<x;	
//     outFile.close();
	/*Incomplete because of filing but there will be a function to search a product and edit it*/
}

