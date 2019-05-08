//add file header comments here
/**********************************************************
* Name        : Abiodun Oke
* Date        : 2018/10/04
**********************************************************/

//add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// declare your namespace here
namespace sict
{
	const int size = 19;
	// define the Passenger class here
	class Passenger
	{
		char m_name[size + 1];
		char m_dest[size + 1];
		void setEmpty();
	public:
		Passenger();
		Passenger(const char* name, const char* destination);
		bool isEmpty() const;
		void display() const;
	};
}
#endif 