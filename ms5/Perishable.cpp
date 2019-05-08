// Final Project Milestone 5
//	File       : Perishable.cpp
// Version 1.0
// Date        : 2018-11-28
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Perishable.h"

using namespace std;

namespace aid {

	// No argument Constructor 
	Perishable::Perishable() : Good('P')
	{
		expirDate = Date();
	}


	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		// insert return statement here
		Good::store(file, false);
		Date tmpDate;
		tmpDate = expirDate;
		if (newLine == false)
		{
			file << "," << tmpDate;
		}
		else {
			file << "," << tmpDate << endl;
		}
		return file;

	}

	std::fstream& Perishable::load(std::fstream & file)
	{
		// insert return statement here
		Good::load(file);
		expirDate.read(file);
		file.ignore();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		// insert return statement here
		Good::write(os, linear);
		if (isClear() && !isEmpty())
		{
			if (linear)
			{
				expirDate.write(os);
				//os << expirDate;
			}
			else {
				os << '\n' << " Expiry date: ";
				expirDate.write(os);
				//os << std::endl << " Expiry date: " << expirDate;
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is)
	{
		// insert return statement here
		Date tmp;
		Good::read(is);
		if (isClear()) {
			std::cout << " Expiry date (YYYY/MM/DD): ";
			std::cin >> tmp;
		}
		if (isClear() && tmp.bad())
		{
			switch (tmp.errCode())
			{
			case CIN_FAILED:
				message("Invalid Date Entry");
				break;
			case YEAR_ERROR:
				message("Invalid Year in Date Entry");
				break;
			case MON_ERROR:
				message("Invalid Month in Date Entry");
				break;
			case DAY_ERROR:
				message("Invalid Day in Date Entry");
				break;
			case PAST_ERROR:
				message("Invalid Expiry in Date Entry");
				break;
			}
			is.setstate(std::ios::failbit);
		}
		if (!is.fail())
		{
			expirDate = tmp;
		}
		return is;

	}

	const Date & Perishable::expiry() const
	{
		// insert return statement here
		return expirDate;
	}


}
