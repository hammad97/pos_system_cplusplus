#pragma once
#include"Product.h"

class PrePackedFood: public Product
{
	int QuantityInUnit;
	double TotalPrice;
	public:
		PrePackedFood(char [],int ,int , int ,double ,double ,double ,double ,int );
    double CalculatePrice();
    void setQuantityInUnit(int );
    int getQuantityInUnit();
    double getTotalPrice();
};

	 

