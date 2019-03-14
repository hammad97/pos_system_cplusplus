	#include"onlinecustomer.h"
	#include <string.h>
	onlineCustomer::onlineCustomer(char id1[],char pass1[]):Person("dummy", 030010, 'M')
	{
		strcpy(id,id1);
		strcpy(pass,pass1);
		
	}
	//onlineCustomer::searchCustomer(){};
	
	void onlineCustomer::setId(char  id1[])
		{
		strcpy(id,id1);

		}
	void onlineCustomer::setPass(char pass1[])
	{
	strcpy(pass,pass1);

	}
	char * onlineCustomer:: getId()
	{
		return id;
	}
	char * onlineCustomer:: getPass()
	{
		return pass;
	}
	
	onlineCustomer::~onlineCustomer()
	{
	}

