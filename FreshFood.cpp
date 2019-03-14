#include"Product.h"
#include"FreshFood.h"
FreshFood::FreshFood(char pname[50],int avQuantity,int tQuantity, int sQuantity,double pcode,double cp,double sp,double discount,double Quan)
:Product(pname,pcode,cp,sp,discount,avQuantity,tQuantity,sQuantity)
{
	QuantityInKg=Quan;
}
double FreshFood::CalculatePrice()
{
	double dis;
	dis=getDiscount();
	TotalPrice=TotalPrice-TotalPrice*(dis/100);
	return TotalPrice;
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


