/**********************************************************
* Name        : Abiodun Oke
* Workshop	  : lab6
* Date        : 2018-11-02
**********************************************************/

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {
	
	// Validate Phone Number
	bool Contact::isValidPhone(const long long phone) const
	{
		
		long long first, second, third, fourth;
		if (0 > phone || 1000000000000 <= phone || 10000000000 > phone) {
			return false;
		}
		else if (phone >= 100000000000) {
			first = phone / 100000000000;
			second = (phone / 10000000000) % 10;
			third = (phone / 1000000000) % 10;
			fourth = (phone / 1000000) % 10;
			if (first == 0 || second == 0 || third == 0 || fourth == 0)
			{
				return false;
			}
			if (phone >= 10000000000)
			{
				first = phone / 10000000000;
				third = (phone / 100000000) % 10;
				fourth = (phone / 100000) % 10;
				if (first == 0 || third == 0 || fourth == 0)
				{
					return false;
				}

			}
		}

		return true;

	}

	// default constructor
	Contact::Contact()
	{
		mname[0] = '\0';
		mphone = nullptr;
		mnoOfphone = 0;
		//setEmpty();
	}

	// constructor with 3 argument
	Contact::Contact(const char * name, const long long * phone, int numofphone)
	{
		if (name != nullptr && name[0] != '\0')
		{
			mname[0] = '\0';
			strncpy(mname, name, MAX_CHAR);
			mname[MAX_CHAR] = '\0';
			mnoOfphone = numofphone;

			for (int i = 0; i < numofphone; i++)
			{
				if (isValidPhone(phone[i]))
				{

					mnoOfphone++;
				}
			}
			
			mphone = new long long[mnoOfphone];
			int count = 0;
			for (int i = 0; i < numofphone; i++)
			{
				if (isValidPhone(phone[i]))
				{
					mphone[count] = phone[i];
					count++;
				}
			}


		}
		else {
			*this = Contact();
		
		}
	}
	// destructor
	Contact::~Contact()
	{
		delete[] mphone;
	}

	//Identify empty object
	bool Contact::isEmpty() const
	{
		if (mname[0] == '\0' && mphone == nullptr && mnoOfphone == -0)
		{
			return true;
		}
		else {
			return false;
		}

	}

	// Prints the data stored by the object 
	void Contact::display() const
	{
		if (!isEmpty())
		{

			cout << mname << endl;
			for (int i = 0; i < mnoOfphone; i++) {
				if (mphone[i] >= 100000000000) {
					long long first = mphone[i] / 100000000000;
					long long second = (mphone[i] / 10000000000) % 10;
					long long third = (mphone[i] / 1000000000) % 10;
					cout << "(+" << first << second
						<< ") " << third << (mphone[i] / 100000000) % 10 << (mphone[i] / 10000000) % 10
						<< " " << (mphone[i] / 1000000) % 10 << (mphone[i] / 100000) % 10 << (mphone[i] / 10000) % 10
						<< "-" << (mphone[i] / 1000) % 10 << (mphone[i] / 100) % 10 << (mphone[i] / 10) % 10 << (mphone[i] / 1) % 10
						<< endl;
				}
				else if (mphone[i] >= 10000000000) {
					long long first = mphone[i] / 10000000000;
					long long second = (mphone[i] / 1000000000) % 10;
					cout << "(+" << first
						<< ") " << second << (mphone[i] / 100000000) % 10 << (mphone[i] / 10000000) % 10
						<< " " << (mphone[i] / 1000000) % 10 << (mphone[i] / 100000) % 10 << (mphone[i] / 10000) % 10
						<< "-" << (mphone[i] / 1000) % 10 << (mphone[i] / 100) % 10 << (mphone[i] / 10) % 10 << (mphone[i] / 1) % 10
						<< endl;
				}
			}
		}
		else {

			cout << "Empty contact!" << endl;
		}
	}



}
