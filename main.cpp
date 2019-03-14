#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Manager.h"
#include "walkInCustomer.h"
#include "onlineCustomer.h"
#include "Cashier.h"
#include "PrePackedFood.h"
#include "FreshFood.h"
#include "Cosmetics.h"
#include "Beverages.h"
#include "Billing.h"


using namespace std;
    int oneTime=0,manOneTime=0,OneTimeOnly=0;
	HWND box1,box2,box3,box4,box5,box6,box7,box8,box9,box10,box11,box12,box13,box14,box15,box16,box17,box18,box19,box20,box21,box22,box23,box24,box25,box26,hwnd2,hwnd3,hwnd4; 
	WNDCLASSEX temp; /* A temp struct for 2nd window */
	Billing Bill;
	Billing CBill;
	double CTotalSP=0,CTotalCP=0;
	int Cquan=0;
	int quan=0;
	double TotalSP=0,TotalCP=0;
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE:{
			if(oneTime==0)   
			{
			box1=CreateWindow("BUTTON","Cashier",                //Main screen cashier button
			WS_VISIBLE|WS_CHILD,
			150,40,200,100, //X , Y, Width , height
			hwnd,(HMENU)12,NULL,NULL);

			box1=CreateWindow("BUTTON","Manager",				//Main screen manager button
			WS_VISIBLE|WS_CHILD,
			150,160,200,100, //X , Y, Width , height
			hwnd,(HMENU)5,NULL,NULL);
			oneTime++;

			box1=CreateWindow("BUTTON","Online Customer",		//Main screen online customer button
			WS_VISIBLE|WS_CHILD,
			150,280,200,100, //X , Y, Width , height
			hwnd,(HMENU)13,NULL,NULL);
			oneTime++;
			OneTimeOnly++;
			}
			break;
		}
		case WM_COMMAND:{
			if(LOWORD(wParam)==1)
			{	
				char idE[7],passE[7],passF[7],addF[20],disp[30];		//Check if cashier exists
				int idF,salF,ageF,cnicF,CidE,Allow=0;
				GetWindowText(box21,idE,8);
				GetWindowText(box22,passE,8);
				CidE=atoi(idE);
				fstream inFile;
				inFile.open("cashier.txt");
				while(!inFile.eof())
				{
					inFile>>idF;
					inFile>>passF;
					inFile>>salF;
					inFile>>ageF;
					inFile>>addF;
					inFile>>cnicF;
					if(strcmp(passF,passE)==0 && idF==CidE)
					{
						Allow=1;
						break;
					}
				}
				inFile.close();
				if(Allow==1)						//if cashier access granted
				{
				sprintf(disp,"Access Granted!\nWelcome CashierId: %d",idF);
				MessageBox(hwnd2,disp,"Success!", MB_OK);					
				DestroyWindow(hwnd2);
					                                         //Inputs from Cashier for Product entry 
					                                         
				hwnd2 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Cashier",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				800, /* height */
				NULL,NULL,temp.hInstance,NULL);	
				
				CreateWindow("STATIC","Product Id:",
				WS_VISIBLE|WS_CHILD,
				10,20,100,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);				
						
				box2=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				110,20,100,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);

				CreateWindow("STATIC","Qty:",
				WS_VISIBLE|WS_CHILD,
				220,20,50,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);

				box3=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				270,20,50,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);

				CreateWindow("BUTTON","Done!",
				WS_VISIBLE|WS_CHILD,
				370,20,80,20, //X , Y, Width , height
				hwnd2,(HMENU)2,NULL,NULL);
				
				CreateWindow("BUTTON","Generate Bill",
				WS_VISIBLE|WS_CHILD,
				10,60,150,20, //X , Y, Width , height
				hwnd2,(HMENU)3,NULL,NULL);
 				}
 				else												//If Cashier doesn't exists
 				{   
				MessageBox(hwnd2,"User Id/Password Incorrect!\nTry Again!", "Error!", MB_OK);      
				}
			}
			else if(LOWORD(wParam)==2)                       //Searching product from file by product id entered by user
			{
				double res,temp,g=0;
				char num[6],qty[2],disp[30];
				double id,cp,sp,up,discount;
				int nQuan,aQuan,tQuan,temp2;
				char name[20];
				GetWindowText(box2,num,6);
				GetWindowText(box3,qty,2);
				ifstream inFile;
				temp=atoi(num);
				temp2=atoi(qty);
				inFile.open("product.txt");
				while(!inFile.eof())
				{
					inFile>>id;
					inFile>>name;
					inFile>>cp;
					inFile>>sp;
					inFile>>up;
					inFile>>nQuan;
					inFile>>aQuan;
					inFile>>tQuan;
					inFile>>discount;
					if(id==temp)
					{ 												//Bill Calculation
					quan=Bill.getQuantity();
					quan++;
					Bill.setQuantity(quan);
					TotalCP=Bill.getTotalCP();
					TotalSP=Bill.getTotalSP();
					TotalCP=TotalCP+(temp2*cp);
					TotalSP=TotalSP+(temp2*sp);
					Bill.setTotalCP(TotalCP);
					Bill.setTotalSP(TotalSP);						
					sprintf(disp,"%s added to Cart",name);            		//Confirmation of Addition to Cart
					MessageBox(hwnd2,disp, "Product Info", MB_OK);
					inFile.close();
																		// Decreasing available quantity in File product.txt
					fstream file5;
					fstream file6;
					file5.open("product.txt");
					file6.open("tempproduct.txt");
					while(!file5.eof())                                    
					{
						if(!file5.eof())
						break;
						file5>>id;
						file5>>name;
						file5>>cp;
						file5>>sp;
						file5>>up;
						file5>>nQuan;
						file5>>aQuan;
						file5>>tQuan;
						file5>>discount;	
						if(temp==id)
						{
						file6<<id<<endl<<name<<endl<<cp<<endl<<sp<<endl<<up<<endl<<nQuan<<endl<<aQuan-temp2<<endl<<tQuan<<endl<<discount<<endl;
						}
						else
						{
						file6<<id<<endl<<name<<endl<<cp<<endl<<sp<<endl<<up<<endl<<nQuan<<endl<<aQuan-temp2<<endl<<tQuan<<endl<<discount<<endl;
						}
					}
					file6.close();
					file5.close();

					fstream file3;
					fstream file4;
					file3.open("product.txt");
					file4.open("tempproduct.txt");
					while(!file4.eof())
					{
						if(!file4.eof())
						break;
						
						file4>>id;
						file4>>name;
						file4>>cp;
						file4>>sp;
						file4>>up;
						file4>>nQuan;
						file4>>aQuan;
						file4>>tQuan;
						file4>>discount;	
						
						file3<<id<<endl<<name<<endl<<cp<<endl<<sp<<endl<<up<<endl<<nQuan<<endl<<aQuan<<endl<<tQuan<<endl<<discount<<endl;
					}
					file4.close();
					file3.close();
					g=1;
					break;
					}
				}
				if(g!=1)
				MessageBox(hwnd2,"Product not found in List", "Product Info", MB_OK);				
			}
			else if(LOWORD(wParam)==3)								//Bill generation for Cashier Class for Walk-in Customer
			{
				char disp[30];
				sprintf(disp,"Total Items Purchased: %d\nTotal Amount Billed: %.2lf",Bill.getQuantity(),Bill.getTotalSP());
				MessageBox(hwnd2,disp, "Bill", MB_OK);			
			}
			else if(LOWORD(wParam)==5)
			{													 	//Manager Authorization
				hwnd3 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Authorization",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				200, /* height */
				NULL,NULL,temp.hInstance,NULL);
				
				CreateWindow("STATIC","UserId:",
				WS_VISIBLE|WS_CHILD,
				10,20,60,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);				
						
				CreateWindow("STATIC"," admin",
				WS_VISIBLE|WS_CHILD,
				70,20,60,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Pass:",
				WS_VISIBLE|WS_CHILD,
				130,20,50,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box4=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				180,20,80,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("BUTTON","Log in",
				WS_VISIBLE|WS_CHILD,
				260,20,80,20, //X , Y, Width , height
				hwnd3,(HMENU)6,NULL,NULL);
								
			}
			else if(LOWORD(wParam)==6)
			{
				char pass[7];
				GetWindowText(box4,pass,8);                           //Authorization Successfull
				if(strcmp(pass,"ironman")==0)
				{
					MessageBox(hwnd3,"Login Successful!\nWelcome Manager!", "Sucess!", MB_OK);
					
					DestroyWindow(hwnd3);
					hwnd3 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Manager Operations",WS_VISIBLE|WS_SYSMENU,
					CW_USEDEFAULT, /* x */
					CW_USEDEFAULT, /* y */
					600, /* width */
					800, /* height */
					NULL,NULL,temp.hInstance,NULL);
					
					box5=CreateWindow("BUTTON","Add Product",
					WS_VISIBLE|WS_CHILD,
					150,40,200,100, //X , Y, Width , height
					hwnd3,(HMENU)7,NULL,NULL);

					CreateWindow("BUTTON","Edit Product",
					WS_VISIBLE|WS_CHILD,
					150,160,200,100, //X , Y, Width , height
					hwnd3,(HMENU)9,NULL,NULL);

					CreateWindow("BUTTON","Add Cashier",
					WS_VISIBLE|WS_CHILD,
					150,280,200,100, //X , Y, Width , height
					hwnd3,(HMENU)10,NULL,NULL);
				}
				else 										//If Password is wrong 	
				{ 
				MessageBox(hwnd3,"Incorrect Password!\nTry Again!", "Error!", MB_OK);				
				}
			}
			else if(LOWORD(wParam)==7)
			{												//Manager Functions
				DestroyWindow(hwnd3);
				 			
				hwnd3 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Manager Operations: Create Product",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				800, /* height */
				NULL,NULL,temp.hInstance,NULL);
				
				CreateWindow("STATIC","Category:",
				WS_VISIBLE|WS_CHILD,
				10,20,80,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box6=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,20,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Product Code:",
				WS_VISIBLE|WS_CHILD,
				10,50,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box7=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,50,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Product Name:",
				WS_VISIBLE|WS_CHILD,
				10,80,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box8=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,80,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Cost Price:",
				WS_VISIBLE|WS_CHILD,
				10,110,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box9=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,110,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Sale Price:",
				WS_VISIBLE|WS_CHILD,
				10,140,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box10=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,140,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Unit Weight:",
				WS_VISIBLE|WS_CHILD,
				10,170,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box11=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,170,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Total Quantity:",
				WS_VISIBLE|WS_CHILD,
				10,200,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box12=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,200,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Discount:",
				WS_VISIBLE|WS_CHILD,
				10,230,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box13=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,230,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Needed Quantity:",
				WS_VISIBLE|WS_CHILD,
				10,260,150,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);		

				box20=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,260,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("BUTTON","Create Product!",
				WS_VISIBLE|WS_CHILD,
				10,300,150,20, //X , Y, Width , height
				hwnd3,(HMENU)8,NULL,NULL);
			}
			else if(LOWORD(wParam)==8)
			{															//Taking inputs from Manager Function: Create Product
				int Cctg,Ctquan,Caquan,Csquan,Ct1,Cnquan;
				double Ccode,Ccp,Csp,Cdis,Ct2;
				char ctg[2],code[6],name[25],cp[5],sp[5],uwgt[4],tquan[5],dis[4],nquan[5];
				GetWindowText(box6,ctg,3); //int
				GetWindowText(box7,code,7);		//double		
				GetWindowText(box8,name,26); //char*
				GetWindowText(box9,cp,6); //double
				GetWindowText(box10,sp,6); //double 
				GetWindowText(box11,uwgt,5); //depends on ctg
				GetWindowText(box12,tquan,6); //int
				GetWindowText(box13,dis,5); //double
				GetWindowText(box20,nquan,5); //double
				if(ctg[0]!='\0' && code[0]!='\0' && name[0]!='\0' && cp[0]!='\0' && sp[0]!='\0' && uwgt[0]!='\0' && tquan[0]!='\0' && dis[0]!='\0' && nquan[0]!='\0')
				{
				Cctg=atoi(ctg);
				Ccode=atoi(code);
				Ccp=atoi(cp);
				Csp=atoi(sp);
				Ctquan=atoi(tquan);
				Cdis=atoi(dis);
				Cnquan=atoi(nquan);
				if(Cctg==1)
				Ct1=atoi(uwgt);
				else if(Cctg==2)
				Ct2=atoi(uwgt);				
				else if(Cctg==3)
				Ct1=atoi(uwgt);
				else if(Cctg==4)
				Ct2=atoi(uwgt);		
				Manager temp;
				temp.createProduct(Cctg,Ccode,name,Ccp,Csp,Ct1,Ctquan,Cnquan,Cdis);
				MessageBox(hwnd3,"Product Created\nin Database!", "Product Info", MB_OK);
				}
				else                                                      //If All fields are not filled
				MessageBox(hwnd3,"Error:Creating Product!\nEach field needs to be filled","Error!",MB_OK);
			}
			else if(LOWORD(wParam)==9)
			{
				DestroyWindow(hwnd3);	 								//Manager function : Edit Product
				
				hwnd3 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Manager Operations: Edit Product",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				800, /* height */
				NULL,NULL,temp.hInstance,NULL);
				
				CreateWindow("STATIC","Category:",
				WS_VISIBLE|WS_CHILD,
				10,20,80,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box6=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,20,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Product Code:",
				WS_VISIBLE|WS_CHILD,
				10,50,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box7=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,50,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Product Name:",
				WS_VISIBLE|WS_CHILD,
				10,80,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box8=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,80,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Cost Price:",
				WS_VISIBLE|WS_CHILD,
				10,110,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box9=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,110,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Sale Price:",
				WS_VISIBLE|WS_CHILD,
				10,140,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box10=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,140,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Unit Weight:",
				WS_VISIBLE|WS_CHILD,
				10,170,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box11=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,170,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Total Quantity:",
				WS_VISIBLE|WS_CHILD,
				10,200,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box12=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,200,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Discount:",
				WS_VISIBLE|WS_CHILD,
				10,230,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box13=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,230,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Needed Quantity:",
				WS_VISIBLE|WS_CHILD,
				10,260,150,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);		

				box20=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,260,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("BUTTON","Edit Product!",
				WS_VISIBLE|WS_CHILD,
				10,300,150,20, //X , Y, Width , height
				hwnd3,(HMENU)15,NULL,NULL);
			}
			else if(LOWORD(wParam)==10)                       //Manager Function : Add Cashier
			{
				DestroyWindow(hwnd3);
				
				hwnd3 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Manager Operations: Add Cashier",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				800, /* height */
				NULL,NULL,temp.hInstance,NULL);
				
				CreateWindow("STATIC","Cashier id:",
				WS_VISIBLE|WS_CHILD,
				10,20,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box14=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,20,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Cashier Pass:",
				WS_VISIBLE|WS_CHILD,
				10,50,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box15=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,50,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);				

				CreateWindow("STATIC","Age:",
				WS_VISIBLE|WS_CHILD,
				10,80,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box16=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,80,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Salary:",
				WS_VISIBLE|WS_CHILD,
				10,110,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box17=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,110,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","CNIC:",
				WS_VISIBLE|WS_CHILD,
				10,140,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box18=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,140,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("STATIC","Address:",
				WS_VISIBLE|WS_CHILD,
				10,170,200,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				box19=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				220,170,120,20, //X , Y, Width , height
				hwnd3,NULL,NULL,NULL);

				CreateWindow("BUTTON","Add Cashier!",
				WS_VISIBLE|WS_CHILD,
				10,200,150,20, //X , Y, Width , height
				hwnd3,(HMENU)11,NULL,NULL);
			}
			else if(LOWORD(wParam)==11)               //Getting inputs and Adding Cashier in cashier.txt file
			{
				char id[6],pass[10],age[10],sal[10],cnic[30],add[35],disp[80];
				int Cage,Ccnic,Csal,Cid;
				GetWindowText(box14,id,10);			 //int
				GetWindowText(box15,pass,10);		 //char*
				GetWindowText(box16,age,10);          //int
				GetWindowText(box17,sal,10);         //int
				GetWindowText(box18,cnic,30);       //int
				GetWindowText(box19,add,36);        //char*
				if(id[0]!='\0' && pass[0]!='\0' && age[0]!='\0' && sal[0]!='\0' && cnic[0]!='\0' && add[0]!='\0')
				{				
				Cid=atoi(id);
				Cage=atoi(age);
				Csal=atoi(sal);
				Ccnic=atoi(cnic);
				Manager temp;
				temp.addCashier(Cid,pass,Csal,Cage,add,Ccnic);
				MessageBox(hwnd3,"Cashier Successfully Added to database!","Success!",MB_OK);
				}
				else
				MessageBox(hwnd3,"Error:Adding Cashier!\nEach field needs to be filled","Error!",MB_OK);									
			}
			else if(LOWORD(wParam)==12)     
			{														//Authorization check fir
				hwnd2 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Authorization",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				200, /* height */
				NULL,NULL,temp.hInstance,NULL);
				
				CreateWindow("STATIC","UserId:",
				WS_VISIBLE|WS_CHILD,
				10,20,60,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);				
						
				box21=CreateWindow("edit","",
				WS_VISIBLE|WS_CHILD,
				70,20,60,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);

				CreateWindow("STATIC","Pass:",
				WS_VISIBLE|WS_CHILD,
				130,20,50,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);

				box22=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				180,20,80,20, //X , Y, Width , height
				hwnd2,NULL,NULL,NULL);

				CreateWindow("BUTTON","Log in",
				WS_VISIBLE|WS_CHILD,
				260,20,80,20, //X , Y, Width , height
				hwnd2,(HMENU)1,NULL,NULL);				
			}
			else if(LOWORD(wParam)==13)
			{
				hwnd4 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Authorization",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				200, /* height */
				NULL,NULL,temp.hInstance,NULL);
				
				CreateWindow("STATIC","UserId:",
				WS_VISIBLE|WS_CHILD,
				10,20,60,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);				
						
				box23=CreateWindow("edit","",
				WS_VISIBLE|WS_CHILD,
				70,20,160,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);

				CreateWindow("STATIC","Pass:",
				WS_VISIBLE|WS_CHILD,
				290,20,50,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);

				box24=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				350,20,160,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);

				CreateWindow("BUTTON","Log in",
				WS_VISIBLE|WS_CHILD,
				10,60,80,20, //X , Y, Width , height
				hwnd4,(HMENU)14,NULL,NULL);				
			}
			else if(LOWORD(wParam)==14)
			{	
				char idE[15],passE[15],passF[15],idF[15],addF[20],disp[30];
				int Allow=0;
				GetWindowText(box23,idE,16);
				GetWindowText(box24,passE,16);
				fstream inFile;
				inFile.open("onlineCust.txt");
				while(!inFile.eof())
				{
					inFile>>idF;
					inFile>>passF;
					inFile>>addF;
					if(strcmp(passF,passE)==0 && strcmp(idF,idE)==0)
					{
						Allow=1;
						break;
					}
				}
				inFile.close();
				if(Allow==1)
				{
				sprintf(disp,"Logged in!\nWelcome %s",idF);
				MessageBox(hwnd4,disp,"Success!", MB_OK);
				DestroyWindow(hwnd4);
					
				hwnd4 = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Online Customer",WS_VISIBLE|WS_SYSMENU,
				CW_USEDEFAULT, /* x */
				CW_USEDEFAULT, /* y */
				600, /* width */
				800, /* height */
				NULL,NULL,temp.hInstance,NULL);	
				
				CreateWindow("STATIC","Name:",
				WS_VISIBLE|WS_CHILD,
				10,20,100,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);				
						
				box25=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				110,20,100,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);

				CreateWindow("STATIC","Qty:",
				WS_VISIBLE|WS_CHILD,
				220,20,50,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);

				box26=CreateWindow("EDIT","",
				WS_VISIBLE|WS_CHILD,
				270,20,50,20, //X , Y, Width , height
				hwnd4,NULL,NULL,NULL);

				CreateWindow("BUTTON","Done!",
				WS_VISIBLE|WS_CHILD,
				370,20,80,20, //X , Y, Width , height
				hwnd4,(HMENU)15,NULL,NULL);
				
				CreateWindow("BUTTON","Generate Bill",
				WS_VISIBLE|WS_CHILD,
				10,60,150,20, //X , Y, Width , height
				hwnd4,(HMENU)16,NULL,NULL);
				}
				else
				MessageBox(hwnd4,"UserId/Password Incorrect\nTry Again!","Error!", MB_OK);				
			}
			else if(LOWORD(wParam)==15)
			{
				double res,temp,g=0;
				char naam[20],qty[2],disp[30];
				double id,cp,sp,up,discount;
				int nQuan,aQuan,tQuan,temp2;
				char name[20];
				GetWindowText(box25,naam,20);
				GetWindowText(box26,qty,3);
				ifstream inFile;
				temp2=atoi(qty);
				inFile.open("product.txt");
				while(!inFile.eof())
				{
					inFile>>id;
					inFile>>name;
					inFile>>cp;
					inFile>>sp;
					inFile>>up;
					inFile>>nQuan;
					inFile>>aQuan;
					inFile>>tQuan;
					inFile>>discount;
					if(strcmp(naam,name)==0)
					{
					Cquan=CBill.getQuantity();
					Cquan++;
					CBill.setQuantity(Cquan);
					CTotalCP=CBill.getTotalCP();
					CTotalSP=CBill.getTotalSP();
					CTotalCP=CTotalCP+(temp2*cp);
					CTotalSP=CTotalSP+(temp2*sp);
					CBill.setTotalCP(CTotalCP);
					CBill.setTotalSP(CTotalSP);						
					sprintf(disp,"%s added to Cart",name);
					MessageBox(hwnd4,disp, "Product Info", MB_OK);
					inFile.close();
					// Decreasing available quantity in File product.txt
					fstream file5;
					fstream file6;
					file5.open("product.txt");
					file6.open("tempproduct.txt");
					while(!file5.eof())
					{
						if(!file5.eof())
						break;
						file5>>id;
						file5>>name;
						file5>>cp;
						file5>>sp;
						file5>>up;
						file5>>nQuan;
						file5>>aQuan;
						file5>>tQuan;
						file5>>discount;	
						if(temp==id)
						{
						file6<<id<<endl<<name<<endl<<cp<<endl<<sp<<endl<<up<<endl<<nQuan<<endl<<aQuan-temp2<<endl<<tQuan<<endl<<discount<<endl;
						}
						else
						{
						file6<<id<<endl<<name<<endl<<cp<<endl<<sp<<endl<<up<<endl<<nQuan<<endl<<aQuan-temp2<<endl<<tQuan<<endl<<discount<<endl;
						}
					}
					file6.close();
					file5.close();

					fstream file3;
					fstream file4;
					file3.open("product.txt");
					file4.open("tempproduct.txt");
					while(!file4.eof())
					{
						if(!file4.eof())
						break;
						
						file4>>id;
						file4>>name;
						file4>>cp;
						file4>>sp;
						file4>>up;
						file4>>nQuan;
						file4>>aQuan;
						file4>>tQuan;
						file4>>discount;	
						
						file3<<id<<endl<<name<<endl<<cp<<endl<<sp<<endl<<up<<endl<<nQuan<<endl<<aQuan<<endl<<tQuan<<endl<<discount<<endl;
					}
					file4.close();
					file3.close();
					///////////////////////////////////
					g=1;
					break;
					}
				}
				if(g!=1)
				MessageBox(hwnd2,"Product not found in List", "Product Info", MB_OK);
			}
			else if(LOWORD(wParam)==16)
			{
				char disp[30];
				sprintf(disp,"Total Items Purchased: %d\nTotal Amount Billed: %.2lf",CBill.getQuantity(),CBill.getTotalSP());
				MessageBox(hwnd4,disp, "Bill", MB_OK);			
			}
			break;
		}
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			if(OneTimeOnly==1)
			{
			}
			else
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+0);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","POS System",WS_VISIBLE|WS_SYSMENU|WS_MINIMIZEBOX,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		600, /* width */
		800, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}

