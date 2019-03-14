#pragma once
#include"Product.h"

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

