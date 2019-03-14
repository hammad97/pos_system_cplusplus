#include"Product.h"
#include"Beverages.h"


Beverages::Beverages(char pname[50],int aQuantity,int tQuantity, int sQuantity,double pcode,double cp,double sp,double discount,double Quan)
:Product(pname,pcode,cp,sp,discount,aQuantity,tQuantity,sQuantity)
{
	QuantityInLiters=Quan;
}
double Beverages::CalculatePrice()
{
	double dis;
	dis=getDiscount();
 	TotalPrice=TotalPrice-TotalPrice*(dis/100);
 	return TotalPrice;
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
