//add file header comments here
/**********************************************************
* Name        : Abiodun Oke
* Date        : 2018/10/09
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS

// add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

//continue your namespace here
namespace sict
{
	// private function
	void Passenger::setEmpty()
	{
		m_name[0] = '\0';
		m_dest[0] = '\0';
		m_year = 0;
		m_month = 0;
		m_day = 0;
	}
	// validate string and date
	// validate stlring 
	bool Passenger::validString(const char* name, const char* destination) const {
		if (name != nullptr && destination != nullptr && name[0] != '\0' && destination[0] != '\0')
		{
			return true;
		}
		else {
			return false;
		}
	}
	// validate date
	bool Passenger::validDate(int year, int month, int day) const
	{
		if (year >= 2018 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void Passenger::copyString(const char * name, const char * destination)
	{
		m_name[0] = '\0';
		m_dest[0] = '\0';
		strncpy(m_name, name, size);
		strncpy(m_dest, destination, size);
		m_name[size] = '\0';
		m_dest[size] = '\0';
	}

	



	// implement the default constructor here
	Passenger::Passenger()
	{
		setEmpty();
	}
	// implement the constructor with 2 parameters here
	Passenger::Passenger(const char * name, const char * destination)
	{
		if (validString(name, destination))
		{
			copyString(name, destination);
			m_year = 2018;
			m_month = 10;
			m_day = 1;
			
		}
		else {

			setEmpty();
		}
	}
	// constructor with 5 parameter
	Passenger::Passenger(const char * name, const char * destination, int year, int month, int day)
	{
		if (validString(name, destination) && validDate(year, month, day))
		{
			copyString(name, destination);
			m_year = year;
			m_month = month;
			m_day = day;
			
		}
		else {
			setEmpty();
		}
	}


	const char* Passenger::name() const
	{
		return (isEmpty()) ? nullptr : m_name; 
	}

	bool Passenger::canTravelWith(const Passenger& obj) const
	{
		bool result;
		result = strcmp(obj.m_dest, m_dest) == 0 &&
			obj.m_year == m_year &&
			obj.m_month == m_month &&
			obj.m_day == m_day ? true : false;
		return result;
		
	}

	

	// implement isEmpty query here
	bool Passenger::isEmpty() const
	{
		return (m_name[0] == '\0' && m_dest[0] == '\0') ? true : false;
		
	}
	// implement display query here
	void Passenger::display() const
	{
		if (!isEmpty())
		{
			cout << m_name << " - " << m_dest << " on " << m_year << "/";
			cout.width(2);
			cout.fill('0');
			cout << m_month << "/";
			cout.width(2);
			cout.fill('0');
		       	cout<< m_day << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}

	}


}
