#include "Error.h"
// Final Project Milestone 2
//
// Version 1.0
// Date        : 2018-11-07
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;

namespace aid
{
	// Constructor
	Error::Error(const char * errorMessage)
	{
		if (errorMessage != nullptr)
		{
			mmessage = nullptr;
			message(errorMessage);
		}
		else {
			mmessage = nullptr;
		}
	}
	// destructor
	Error::~Error()
	{
		delete[] mmessage;
	}

	void Error::clear()
	{
		delete[] mmessage;
		mmessage = nullptr;
	}

	bool Error::isClear() const
	{
		return (mmessage == nullptr || mmessage[0] == '\0') ? true : false;
	}

	void Error::message(const char * str)
	{
		clear();
		if (str != nullptr)
		{
			mmessage = new char[strlen(str) + 1];
			strcpy(mmessage, str);
		}
		else {
			mmessage = nullptr;
		}
	}

	const char * Error::message() const
	{
		//return isClear() ? nullptr : mmessage;
		if (mmessage != nullptr)
		{
			return mmessage;
		}
		else {
			return nullptr;
		}
		
	}

	std::ostream & operator<<(std::ostream & ostr, Error& rhs)
	{
		if (rhs.mmessage != nullptr)
		{
			ostr << rhs.message();
		}
		return ostr;
	}

}