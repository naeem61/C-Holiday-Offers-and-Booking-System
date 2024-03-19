/***********************************************************************
 * mainCustomerBookings.cpp
 * Program to store a lost of holiday special offer records
 * Mohammed Naeem
***********************************************************************/
#include <iostream>
#include "holidayOffers.h"
#include "customerBooking.h"

int main() {
	
	Holidaydatabase books;
	 int choice;
           cout << "\t\tHOLIDAY BOOKING SYSTEM\n";
           cout << "\t\t======================\n";
	   cout << "\n1. Search Record by Category\n";
	   cout << "2. Search Record by Country\n";
	   cout << "3. Exit program\n";
	   cout << "\nChoose option 1,2 or 3: ";
	   cin >> choice;
	   if(choice == 1){books.SearchforCategory(); 
	   CustomerBooking cust; cust.Bookchoices();}
	   else if(choice == 2){books.SearchforCountry(); 
	   CustomerBooking cust;cust.Bookchoices();}
	   else if(choice == 3){exit(1);}
	   else{main();}
	return 0;
}
