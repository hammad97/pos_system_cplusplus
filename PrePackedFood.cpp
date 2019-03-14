
#include "PrePackedFood.h"
#include "Product.h"
#pragma once
PrePackedFood::PrePackedFood(char pname[50],int aoQuantity,int noQuantity, int sQuantity,double pcode,double cp,double sp,double discount,int Quan)
:Product(pname,pcode,cp,sp,discount,aoQuantity,noQuantity,sQuantity)
{
	QuantityInUnit=Quan;
}
double PrePackedFood::CalculatePrice()
{
	double dis;
	dis=getDiscount();
	TotalPrice=TotalPrice-TotalPrice*(dis/100);
	return TotalPrice;
}
void PrePackedFood::setQuantityInUnit(int q)
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











