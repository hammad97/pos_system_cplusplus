#pragma once
#include"Product.h"

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

