/***********************************************************************
 * customerBooking.h
 * Program to store a lost of holiday special offer records
 * Mohammed Naeem
***********************************************************************/
#include "holidayOffers.h"
#ifndef customerBooking_h
#define customerBooking_h

	class CustomerBooking{
	
	private:
	std::vector<Holidayoffers> _Customerbookingvector;
	string _CustomersName;
	string _CustomerEmailaddress;
	string _HolidayID;
	
	
	public:
	CustomerBooking();
	CustomerBooking(string CustomersName, 
	string CustomerEmailaddress, string HolidayID);
	void Bookchoices();
};

#endif
