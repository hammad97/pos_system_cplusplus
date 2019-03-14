#pragma once
#include "Product.h"

class Billing 						//Billing has a Product (Aggregation)
{
	double totalSP;
	double totalCP;
	int quantity;            
	double discounted;       
	Product *pB;
	public:
	setTotalSP(double);
	setTotalCP(double);
	setQuantity(int);
	double getTotalSP();
	double getTotalCP();
	int getQuantity();
	void printBill();
};
