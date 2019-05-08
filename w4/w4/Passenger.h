//add file header comments here
/**********************************************************
* Name        : Abiodun Oke
* Date        : 2018/10/09
**********************************************************/

//add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// declare your namespace here
namespace sict
{
	const int size = 18;
	// define the Passenger class here
	class Passenger
	{
		char m_name[size + 1];
		char m_dest[size + 1];
		int m_year; // year of departure
		int m_month; // month of departure
		int m_day; // day of departure
		// Private member functions
		void setEmpty();
		bool validString(const char* name, const char* destination) const;
		bool validDate(int year, int month, int day) const;
		void copyString(const char* name, const char* destination);
		//bool isValid(const char* name, const char* destination, int year, int month, int day);
	public:
		// constructors
		Passenger();
		Passenger(const char* name, const char* destination);
		Passenger(const char* name, const char* destination, int year, int month, int day);
		// Public Member Functions 
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
	};
}
#endif 
