// Final Project Milestone 1
//
// Version 1.0
// Date
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace aid {

	// number of days in month mon and year year
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode)
	{
		merror = errorCode;
	}
	int Date::compValue() const
	{
		return myear * 372 + mmonth * 31 + mday;
	}
	// default constructor
	Date::Date()
	{
		myear = 0;
		mmonth = 0;
		mday = 0;
		merror = NO_ERROR;
	}

	// Three-argument constructor: 
	Date::Date(int year, int month, int day)
	{
		
		*this = Date();
		//if (compValue() >= min_date) {
			if (year >= min_year && year <= max_year)
			{
				if (month >= 1 && month <= 12)
				{
					if (day >= 1 && day <= mdays(month, year))
					{
						myear = year;
						mmonth = month;
						mday = day;
						merror = NO_ERROR;
						compValue();
					}
					else {
						errCode(DAY_ERROR);
					}
				}

				else {
					errCode(MON_ERROR);
				}
			}
			else {
				errCode(YEAR_ERROR);
			}
		/*}
		else
		{
			errCode(PAST_ERROR);
		}*/
	}

	bool Date::operator==(const Date & rhs) const
	{
		return compValue() == rhs.compValue() ? true : false;
	}

	bool Date::operator!=(const Date & rhs) const
	{
		return compValue() != rhs.compValue() ? true : false;
	}

	bool Date::operator<(const Date & rhs) const
	{
		return compValue() < rhs.compValue() ? true : false;
	}

	bool Date::operator>(const Date & rhs) const
	{
		return compValue() > rhs.compValue() ? true : false;
	}

	bool Date::operator<=(const Date & rhs) const
	{
		return compValue() <= rhs.compValue() ? true : false;
	}

	bool Date::operator>=(const Date & rhs) const
	{
		return compValue() >= rhs.compValue() ? true : false;
	}

	int Date::errCode() const
	{
		return merror;
	}

	bool Date::bad() const
	{
		return merror != NO_ERROR ? true : false;
	}

	// Read
	std::istream& Date::read(std::istream & istr)
	{
		// 
		char symbol;
		istr.clear();
		istr >> myear >> symbol >> mmonth >> symbol >> mday;
		if (istr.fail())
		{
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if (min_year > myear || myear > max_year)
		{
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (1 > mmonth || mmonth > 12)
		{
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (mday > mdays(mmonth, myear))
		{
			*this = Date();
			errCode(DAY_ERROR);
		}
		else if (compValue() < min_date)
		{
			*this = Date();
			errCode(PAST_ERROR);
		}
		return istr;
	}

	// write
	std::ostream& Date::write(std::ostream& ostr) const
	{
		// 
		ostr << myear << "/";
		if (mmonth >= 10)
		{
			ostr << mmonth;
		}
		else
		{
			ostr << '0' << mmonth;
		}
		ostr << "/";
		if (mday >= 10)
		{
			ostr << mday;
		}
		else
		{
			ostr << '0' << mday;
		}
		return ostr;
	}





	std::ostream& operator<<(std::ostream& ostr, Date& obj)
	{
		obj.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& obj)
	{
		obj.read(istr);
		return istr;
	}

}
