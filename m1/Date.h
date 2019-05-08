// Final Project Milestone 1
//
// Version 1.0
// Date
// Author      : Abiodun Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
namespace aid {
	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;
	const int NO_ERROR = 0; //  No error - the date is valid
	const int CIN_FAILED = 1; // --istream failed on information entry
	const int DAY_ERROR = 2; // --Day value is invalid
	const int MON_ERROR = 3;  //--Month value is invalid
	const int YEAR_ERROR = 4;  //--Year value is invalid
	const int PAST_ERROR = 5;  //--Date value is invalid

  class Date {
	  // Private members:
	  int myear;
	  int mmonth;
	  int mday;
	  int merror;
	  // Member functions:
     int mdays(int, int)const;
	 void errCode(int errorCode);
	 int compValue() const;
  public:
	  //Public members:
	  Date();
	  Date(int year, int month, int day);

	  //Relational Operators
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	  //Queries and modifier
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;

  };

	//Helper functions:
  std::ostream& operator<<(std::ostream& ostr, Date&);
  std::istream& operator>>(std::istream& istr, Date&);
}
#endif