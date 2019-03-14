#include"product.h"
#include<string.h>

	Product::	Product(char pname1[], double pcode1, double cp1, double sp1, double discount1, int aquantity, int nquantity, int stquantity )
	{
		strcpy(pname, pname1);
		pcode=pcode1;
		cp=cp1;
		sp=sp1;
		discount=discount1;
		aQuantity=aquantity;
		nQuantity=nquantity;
		tQuantity=stquantity;

	}
	void Product::setAQuantity(int aquantity )
	{
	 aQuantity =aquantity;
	}
	void Product::setNQuantity(int nquantity)
	{
		nQuantity=nquantity;
	}
	void Product::setTQuantity(int stquantity)
	{
		tQuantity=stquantity;
	}
	int Product::getAQuantity()
	{
		return aQuantity;
	}
	int Product:: getNQuantity()
	{
		return nQuantity;

	}
	int Product::getTQuantity()
	{
		return tQuantity;

	}	
	void Product::setPname(char pname1[])
	{
		strcpy(pname,pname1 );
	}
	void Product::setPcode(double pcode1)
	{
		pcode=pcode1;
	}
	void Product::setCp(double cp1)
	{
		cp=cp1;
	}
	void Product::setSp(double sp1)
	{
		sp=sp1;
	}
	void Product::setDiscount(double discount1)
	{
		discount=discount1;
	}
	char * Product::getPname()
	{
		return pname;
	}
	double Product::getPcode()
	{
		return pcode;

	}
	double Product::getCp()
	{
		return cp;
	}
	double Product::getSp()
	{
		return sp;
	}
	double Product::getDiscount()
	{
		return discount;
	}


