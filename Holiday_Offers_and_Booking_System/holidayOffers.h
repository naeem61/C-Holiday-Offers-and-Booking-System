/***********************************************************************
 * holidayOffers.h
 * Program to store a lost of holiday special offer records
 * Mohammed Naeem
***********************************************************************/
#ifndef holidayOffers_H
#define holidayOffers_H
#include <string>
#include <vector>


using namespace std;

class Holidayoffers{

private:
	std::string _ID;
	std::string _country;
	std::string _category;
	std::string _Description;
	std::string _Startdate;
	int _duration;
	double _price;
	int i;
	int Catchoice;
public:
       Holidayoffers();
	
	Holidayoffers(std::string ID, std::string country, 
	std::string category, std::string Description, 
	std::string Startdate, int duration, double price);
	void displayrecord();
	string toString();
	void displayID();
	string getCategory();
	string getCountry();
	string getID();
};





class Holidaydatabase{

private:
	std::vector<Holidayoffers> Holidaydb; //Creating a Vector//
	
public:
	void pushofferontovector();
	
 	Holidaydatabase();
	~Holidaydatabase();
	bool isDuplicate(string ID);
	void deleterecords();
	void updaterecords();
	void Displayall();
	void SearchforCategory();
	void SearchforCountry();
	void donothing();


};


class Menu{
	private:
		
	public:
		Menu();
		bool select();
};

#endif
