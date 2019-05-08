//add file header comments here
/**********************************************************
* Name        : Abiodun Oke
* Date        : 2018/10/04
**********************************************************/


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
	}

	// implement the default constructor here
	Passenger::Passenger()
	{
		setEmpty();
	}
	// implement the constructor with 2 parameters here
	Passenger::Passenger(const char * name, const char * destination)
	{
		if (name == nullptr || destination == nullptr)
		{
			setEmpty();
		}
		else {

			strcpy(m_name, name);
			strcpy(m_dest, destination);

		}
	}
	

	// implement isEmpty query here
	bool Passenger::isEmpty() const
	{
		if (m_name[0] == '\0' || m_dest[0] == '\0')
		{
			return true;
		}
		else {
			return false;
		}
	}
	// implement display query here
	void Passenger::display() const
	{
		if (!isEmpty())
		{
			cout << m_name << " - " << m_dest << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}

	}


}