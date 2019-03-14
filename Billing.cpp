
#include "Billing.h"


Billing :: setTotalSP(double tsp)
{
	totalSP=tsp;	
}

Billing :: setTotalCP(double tcp)
{	
	totalCP=tcp;
}

Billing :: setQuantity(int qty) 
{	
	quantity=qty;
}

double Billing::getTotalSP()
{
	return totalSP;
}

double Billing::getTotalCP()
{
	return totalCP;
}

int Billing::getQuantity()
{
	return quantity;
}

void Billing :: printBill()
{
	// windows.h related
}
