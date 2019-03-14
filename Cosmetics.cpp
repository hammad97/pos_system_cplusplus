#include"Cosmetics.h"
#include"Product.h"
Cosmetics::Cosmetics(char pname[50],int avQuantity,int tQuantity, int sQuantity,double pcode,double cp,double sp,double discount,int Quan)
:Product(pname,pcode,cp,sp,discount,avQuantity,tQuantity,sQuantity)
{
	QuantityInUnits=Quan;
}
double Cosmetics::CalculatePrice()
{
    double dis;
	dis=getDiscount();
	TotalPrice=TotalPrice-TotalPrice*(dis/100);
	return TotalPrice;
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

