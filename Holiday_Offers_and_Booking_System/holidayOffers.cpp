/***********************************************************************
 * HOLIDAYSOFFERS.cpp
 * Program to store a lost of holiday special offer records
 * Mohammed Naeem
***********************************************************************/

#include "holidayOffers.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert> 
#include <cctype>
#include <algorithm> 
//Constructor to get holiday offers
Holidayoffers::Holidayoffers() {    
       	cout << "Enter Holiday offers: \n";
	do{
			
		cout << "CREATE ID (8 characters): ";
		cin  >>  _ID;
		cin.ignore(10000, '\n');
	}while(_ID.length() != 8);
		
       		cout << "TYPE DESTINATION COUNTRY: "; 
       		cin  >>  _country;
	do{
			
	        cout << "1. Walking\n";
	        cout << "2. Citybreak\n";
	        cout << "3. Skiing\n";
                cout << "Choose Category option (1, 2 or 3?): ";
	        cin >> Catchoice;
	if( Catchoice == 1){
	        _category = "Walking";
		i = 1;
			    }
	else if(Catchoice == 2){
		_category = "Citybreak";
		i = 1;
			       }
	else if(Catchoice == 3){
		_category = "Skiing";
		i = 1;
			        }
	else{i = 0;}
	}while(i == 0);
				
       	cout << "TYPE DESCRIPTION OF HOLIDAY: ";
	
       	        getline(cin, _Description);
       		getline(cin, _Description);
    		//cin  >>  _Description;
       		cout << "HOLIDAY START DATE?: "; 
       		cin  >>  _Startdate;
       		cout << "HOW MANY DAYS WILL THE HOLIDAY LAST?: "; 
       		cin  >>  _duration;
       		cout << "ENTER COST OF HOLIDAY($): "; 
       		cin  >>  _price;
       }
       
       
       
       
       
 Holidayoffers::Holidayoffers(std::string ID, std::string country, 
 std::string category, std::string Description, std::string Startdate, 
 int duration, double price) : _ID(ID), _country(country), 
 _category(category), _Description(Description), _Startdate(Startdate), 
 _duration(duration), _price(price){ }
 //Method to display all records 
       void Holidayoffers::displayrecord() {
       	_ID.erase(std::remove_if(_ID.begin(), _ID.end(), ::isspace), 
		   _ID.end()); /*Removing white spaces*/
		cout << "\n\nID:"/*"\n\nHolidayID: " */<< _ID 
		<< "\nCountry: " << _country << "\nCategory: " 
		<< _category << "\nDescription: " << _Description 
		<< "\nStartdate: " << _Startdate << "\nduration(days): " 
		<< _duration << "\nprice: " << _price << "$";
  }
// Converts everthing to string			
    	string Holidayoffers::toString(){
		
		stringstream ss; 
		ss << _ID << ":" << _country << ":" << _category << ":" << 
		_Description << ":" << _Startdate << ":" <<_duration << " " << 
		_price << endl;
		
		return ss.str();
	}
	
// Displays records in one line	
	void Holidayoffers::displayID(){
		_ID.erase(std::remove_if(_ID.begin(), _ID.end(), ::isspace), 
		_ID.end());
                cout <<  _ID << "  " << "Country:" << 
				_country << "  " << "Category:" << _category << "  " 
				<< "Description:" << _Description << "  " 
				<< "Start date:" << _Startdate << "  " 
				<< "Duration:" << _duration << "  " 
				<< "Price:" << _price << endl;
	}
	
	
// Returns category for later searching	
	string Holidayoffers::getCategory(){
		string Cats;
		Cats = _category;
		return Cats;
	}
// Returns Country for later searching		
	string Holidayoffers::getCountry(){
			string Countreee;
			Countreee = _country;
		
			return Countreee;
	}
// Returns ID for later searching		
	string Holidayoffers::getID(){
			string Idss;
			Idss = _ID;
			
			Idss.erase(std::remove_if(Idss.begin(), 
			Idss.end(), ::isspace), Idss.end());
		
			return Idss;
	}
// Pushes offer on to vector		
	void Holidaydatabase::pushofferontovector(){
	     Holidayoffers offer; //Making object "offer" of class holidayoffers//
	     Holidaydb.push_back(offer); //Pushing the offers back onto the vector//

	}
// Constructor for Holiday database. Reads the offers into holiday offer vector	
	Holidaydatabase::Holidaydatabase(){
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
        			  
         	if(!fin.eof() && (!isDuplicate(ID))) { 
          		Holidaydb.push_back(Holidayoffers(ID, 
           		country, category, Description, Startdate, 
				   duration, price )); 
            			                     } 
                                 } 
                fin.close(); 
                       } 
 }
 // Destructor. Writes the vector to holiday record file.
 	Holidaydatabase::~Holidaydatabase(){
	     ofstream file("holidayrecord.txt");
	     	for(int i = 0; i < Holidaydb.size(); ++i){
		file << Holidaydb[i].toString();

	}
	file.close();
}
// Checks for duplicate ID's
bool Holidaydatabase::isDuplicate(string ID) { 
        for(Holidayoffers holidayoffers : Holidaydb) { 

 
                if(ID == holidayoffers.getID()) { 
                        cout << "ERROR -  " << ID 
                             << " already exists.\n"; 
                        return true; 
                } 
        } 
        return false; 
} 
// Deletes records from vector
void Holidaydatabase::deleterecords(){
	int i = 1;
	int chooserectodelete;
	for(Holidayoffers holidaydb : Holidaydb) { 
	cout << "\n\n" << i << ".  "; 
	holidaydb.displayID(); i++;} 
        cout << std::endl;
	cout <<"Enter record number to delete(descends"
	" from 1, 2, 3... etc): ";
	cin >> chooserectodelete;
	Holidaydb.erase(Holidaydb.begin()+chooserectodelete-1);
	
}
// Updates records
void Holidaydatabase::updaterecords(){
 	int i = 1;
 	int chooserecordtoupdate;
 	for(Holidayoffers holidaydb : Holidaydb) { 
	 cout << "\n\n" << i << ".  "; 
	holidaydb.displayID(); i++;} 
        cout << std::endl;
 		
  	cout << "Choose record to update(descends from 1, 2, 3... etc): ";
 	cin >> chooserecordtoupdate;
 		
 	Holidaydb[chooserecordtoupdate-1] = Holidayoffers();	
	 }
// Displays all records	numbered 
 void Holidaydatabase::Displayall(){
	int i = 1;	
	for(Holidayoffers holidaydb : Holidaydb) {
	cout << "\n\n" << i << ".  "; 
	holidaydb.displayrecord(); 
	i++;} 
        cout << std::endl; 	
	}
//Searches vector for category	
void Holidaydatabase::SearchforCategory(){
	cout << "Enter Category search by (Walking, Citybreak or Skiing): ";
	string categorychoice;
	cin >> categorychoice;
	for(Holidayoffers record : Holidaydb) {
        if(categorychoice == record.getCategory()) {
       	int i;
	cout << "\n\n" << i << ".  ";
 	record.displayrecord(); i++;
        				     	 }
        			
                                             }
		
	                                }
//Searches vector for country					
void Holidaydatabase::SearchforCountry(){
	cout << "Enter Country search by: ";
	string Countrychoice;
	cin >> Countrychoice;
	for(Holidayoffers record : Holidaydb) {
	if(Countrychoice == record.getCountry()) {
		int i;
		cout << "\n\n" << i << ".  ";
		record.displayrecord(); i++;
        				         }
        			
					     }
		
				               }
				
void Holidaydatabase::donothing(){ }
					
					

Menu::Menu(){    }

//Coontains the menu for holiday offers
bool Menu::select(){
	
	
	cout<<endl;
   cout << "\n\t\tHoliday offers Menu\n\t\t===================\n\n" 
             << "(a) add Holidayoffer\n" 
             << "(b) display all stored Holidayoffers\n"
	     << "(c) delete record\n" 
	     << "(d) update records\n"  
             //<< "(e) Search records by Category\n"
 	     //<< "(f) Search records by Country\n"
 	     <<"\nPress any other letter to exit the program.\n\n" 
             << "Select: "; 
        char choice; 
        cin >> choice; 
        cin.ignore(10000, '\n'); 
        if(choice == 'a' || choice == 'A'){ Holidaydatabase db; 
		db.pushofferontovector();//_db.pushofferontovector();
        //_db.donothing();
	}
        else if(choice == 'b' || choice == 'B'){ Holidaydatabase db; 
		db.Displayall();//_db.Displayall();
             	      //main::main();
             	      db.donothing();
	}
	else if(choice == 'c' || choice == 'C'){ Holidaydatabase db; 
	db.deleterecords();//_db.deleterecords();
             	      db.donothing();
	}
	else if(choice == 'd' || choice == 'D'){ Holidaydatabase db; 
	db.updaterecords();//_db.updaterecords();
             	       db.donothing();
	}
	//else if(choice == 'e' || choice == 'E'){  Holidaydatabase db; db.SearchforCategory();//_db.SearchforCategory();
						//_db.donothing();
	//}
	//else if(choice == 'f' || choice == 'F'){ Holidaydatabase db; db.SearchforCountry();//_db.SearchforCountry();
					//	_db.donothing();
	//}
	else{ exit(1);}
	
	    // main();

}


	
