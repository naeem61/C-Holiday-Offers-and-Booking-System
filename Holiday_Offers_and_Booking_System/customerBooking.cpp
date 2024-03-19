/***********************************************************************
 * customerBooking.cpp
 * Program to store a lost of holiday special offer records
 * Mohammed Naeem
***********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::string;




#include "customerBooking.h"
#include "holidayOffers.h"
	 
	 	

CustomerBooking::CustomerBooking(){
        std::ifstream fin("holidayrecord.txt"); 
	if(fin) { 
	while(!fin.eof()) { 
                string ID; 
 		getline(fin, ID, ':'); 
	  	string country; 
	  	getline(fin, country, ':');
	  	string category;
	  	getline(fin, category, ':'); 
	  	string Description; 
	  	getline(fin, Description, ':'); 
	  	string Startdate; 
	  	getline(fin, Startdate, ':'); 
	  	int duration; 
	  	fin >> duration; 
	  	double price; 
	  	fin >> price; 
        			  
	  if(!fin.eof()) { 
		  _Customerbookingvector.push_back(Holidayoffers(ID, 
		  country, category, Description, Startdate, duration, price )); 
		  	   } 
                	   } 
                fin.close(); 
        	} 
			
			     	     }
	
CustomerBooking::CustomerBooking(string CustomersName, 
string CustomerEmailaddress, string HolidayID) 
: _CustomersName(CustomersName), 
_CustomerEmailaddress(CustomerEmailaddress), _HolidayID(HolidayID){  }
	
void CustomerBooking::Bookchoices() {
		
        int _menuchoice;
	cout << "\n\n1. Book Holiday\n";
	cout << "2. Exit program";
	cout << "\nChoose an option (1 or 2): ";
	cin >> _menuchoice;
			
	if(_menuchoice == 1){
		string IDchoice;
		string ID;
		cout << "Enter Holiday ID: ";
		cin >> IDchoice;
		ID = IDchoice;
		cout << "\nEnter Customer Name: ";
						//cin >> _CustomersName;
		getline(cin, _CustomersName);
		getline(cin, _CustomersName);
		cout << "\nEnter Customer Email: ";
		cin >> _CustomerEmailaddress;		
		_CustomersName = "<"+_CustomersName+">";
		_CustomerEmailaddress = "<"+_CustomerEmailaddress+">";
		ID = "<"+ID+">";
		string emailnameid;
						
		emailnameid = _CustomersName + _CustomerEmailaddress + ID;
	for(Holidayoffers IDsearch : _Customerbookingvector) {
	        if(IDchoice == IDsearch.getID()) {
         		IDsearch.displayrecord();
	                ofstream fout;
	                ifstream fin;
                        fin.open("Holiday booking.txt");
		        fout.open ("Holiday booking.txt",ios::app); 
		if(fin.is_open())
	                fout << emailnameid;
	  		fout << "\n";
  		        fin.close();
  		       	fout.close();			  
        	        cout << "\n\nBooking saved";
    			      			 }
        	else{
        				//cout << "\nID not found\n";
        				//Bookchoices();
		    }
				
        			
	    	     					    }
					
				}
			
		else if(_menuchoice == 2){
				
			exit(1);
			                 }
		else{
			cout << "ERROR - Choose a valid option (1 or 2)";
			Bookchoices();
		    }
		
	}
	
	



 
		
		

