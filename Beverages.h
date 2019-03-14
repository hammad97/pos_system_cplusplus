#pragma once
#include"Product.h"

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
