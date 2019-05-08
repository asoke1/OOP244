/**********************************************************
 * * Name        : Abiodun Oke
 * * Workshop	  : home
 * * Date        : 2018-11-05
 * **********************************************************/
#define _CRT_SECURE_NO_WARNINGS

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

	//
	void Contact::init(const Contact & obj)
	{
		mname[0] = '\0';
		strncpy(mname, obj.mname, MAX_CHAR);
		mname[MAX_CHAR] = '\0';
		mnoOfphone = obj.mnoOfphone;
		if (obj.mphone != nullptr)
		{
			mphone = new long long[mnoOfphone];
			for (int i = 0; i < mnoOfphone; i++)
			{
				mphone[i] = obj.mphone[i];
			}
		}
		else {
			mphone = nullptr;
		}
	}

	// default constructor
	Contact::Contact()
	{
		mname[0] = '\0';
		mphone = nullptr;
		mnoOfphone = 0;
	
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
		mphone = nullptr;
	}

	// Copy Constroctor
	Contact::Contact(const Contact& obj)
	{
		mphone = nullptr;
		//init(obj);
		*this = obj;

	}

	// Copy assignment operator
	Contact & Contact::operator=(const Contact & obj)
	{
		// check self-assignment
		if (this != &obj)
		{
			// deallocate dynamic memory
			delete[] mphone;
			init(obj);
		}
		return *this;
	}

	// Overloaded += operator
	Contact & Contact::operator+=(long long phone)
	{
		//cout << "Contact & Contact::operator+=(long long phone)" << endl;
		if (isValidPhone(phone) && !isEmpty())
		{
			long long* tmp = new long long[mnoOfphone + 1];
			for (int i = 0; i < mnoOfphone; i++)
			{
				tmp[i] = mphone[i];
			}
			tmp[mnoOfphone] = phone;
			delete[] mphone;
			mphone = tmp;
			tmp = nullptr;
			mphone[mnoOfphone] = phone;
			++mnoOfphone;
			

		}
		return *this;
	}

	//Identify empty object
	bool Contact::isEmpty() const
	{
		return (mname[0] == '\0' && mphone == nullptr && mnoOfphone == 0) ? true : false;

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
