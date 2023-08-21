#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int count[200]={0};
struct Cars {

	string company[200]= {"Maruti Suzuki","Volkswagun","BMW","Audi","KIA","Tesla","Mercedes","Mahindra","TATA"};
	string model[200]= {"800","2020","Q7","R8","Saltos","S-Series","Benz","Thar","Nano"};
	string color[200]={"Yellow","Black","Red","Brown","Blue","Silver","Balck","Grey","Red"};
	string max_speed[200]={"80 Km/h ","200 Km/h","300 Km/h","250 Km/h","320 Km/h","400 Km/h","200 Km/h","250 Km/h","280 Km/h"};

    int price[100]={10000,20000,50000,40000,50000,50000,20000,20000,20000};
	int date [100] = {2020,2012,2019,2018,2017,2016,2015,2021,2010};
}car;

struct Lease_info{

   string Name[100];
   string ID[100];
   int payment_acc[100] ;
}lease;


//First output
void Menu ()
{
	int num=1;
	cout<<"\n\n";
	for(int i=0 ;i<9;++i)
	{
    	cout<<"\t\t\t";
    	cout<<"Enter "<<num<<"\t- To Select  "<<car.company[i]<<endl;
    	num++ ;
	}
}

//Second output
void Details (int Choice)
{
	system("CLS");
	cout<<"\n\n\n\t\t\t-----------------------------\n";
    cout<<"\t\t\tYou Have Selected - "<<car.company[Choice-1]<<endl;
	cout<<"\t\t\t-----------------------------\n\n\n";
    cout<<"\t\t\tModel : "<<car.model[Choice-1]<<endl;
    cout<<"\t\t\tColor : "<<car.color[Choice-1]<<endl;
    cout<<"\t\t\tMaximum Speed : "<<car.max_speed[Choice-1]<<endl;
    cout<<"\t\t\tPrice : "<<car.price[Choice-1]<<endl;
}

//User Inputcpo
void user_input (int theChoice)
{
	system("CLS");
	int i;
	int j=theChoice-1 ;
    cout<<"\t\t\t----------------------------------------\n";
    cout<<"\t\t\tPlease Provide Your Personal Details  : \n";
    cout<<"\t\t\t----------------------------------------\n\n";
    cout<<"\n\tNOTE: PROVIDE FULL NAME, DONOT ENTER SPACE WHILE PROVIDING NAME,\n\tIT IS MANDATORY TO ENTER AADHAR NO AS A NATIONAL ID\n\n\n\n";
    cout<<"\t\t\tEnter Your Name : ";
    cin>>lease.Name[100];
    cout<<"\t\t\tEnter Your Aadhar No : ";
    cin>>lease.ID[j] ;
    cout<<"\t\t\tPayment Account No : " ;
    cin>>lease.payment_acc[j] ;
	//checklease( j ) ;
}

//cpo
void login()
{
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\t  Gifty Car Rental System Login";
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13)
   {//character 13 is enter
    	pass.push_back(ch);
    	cout<<'*';
    	ch = _getch();
   }
   if(pass == "pass")
   {
      cout <<"\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      system("CLS");
	}
	else
	{
      cout <<"\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
	}
}

int main()
{
	//int login();
    login();
	string decide ="yes" ;
    cout<<"\t\t\t----------------------------------------------\n";
    cout<<"\t\t\t\tGIFTY CAR RENTAL SYSTEM \n";
    cout<<"\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
    cout<<"\t\t\t----------------------------------------------\n";
    while(decide!="exit")
    {
        Menu();
    	cout<<"\n\n\n\t\t\tYour Choice: ";
    	int theChoice ;
    	cin>>theChoice ;
    	if(count[theChoice-1]==1)
    	{
			cout<<"\n\n\t\t\tSorry ! This Car is Alredy Booked For Today.\n\n\t\t\tPlease Choose Another One. Sorry for the inconvenience !"<<endl;
			system("PAUSE");
			system("CLS");
			continue;
		}
    	Details(theChoice);
    	cout<<"\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes /no /exit ) : ";
    	cin>>decide ;
    	if(decide=="yes")
		{
			count[theChoice-1]=1;
        	user_input(theChoice);
        	cout<<"\n\n\n\t\t\tProcess has been done successfully!! "<<endl;
        	cout<<"\n\n\t\t\tDo you want to continue ?(yes/no) ";
        	cin>>decide;
        	if (decide=="no")
        	{
        		system("CLS");
				cout <<"\n\n\n\n\n\n\n\t\t\t\t\t  THANK YOU FOR AVAILING OUR SERVICE ! ";
    			cout<<"\n\n\t\t\t\t\t\t  HAVE A GOOD DAY ! \n\n\n\n\n\n\n\n\n\n";
				break;	
			}
			//system("CLS");
    	}
		else
		{
    		if(decide=="no")
    		{
    			system("CLS");
        		continue;
    		}
    		else if (decide=="exit")
    		{
    			system("CLS");
    			cout <<"\n\n\n\n\n\n\n\t\t\t\t\t  THANK YOU FOR AVAILING OUR SERVICE ! ";
    			cout<<"\n\n\t\t\t\t\t\t  HAVE A GOOD DAY ! \n\n\n\n\n\n\n\n\n\n";
				break;
    		}
		}
		system("CLS");
    }
	//getch();
    return 0;
}

