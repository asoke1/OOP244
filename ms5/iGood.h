// Final Project Milestone 3
//	File       : iGood.h
// Version 1.0
// Date        : 2018-11-23
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AID_IGOOD_H
#define AID_IGOOD_H
#include <iostream>
#include <fstream>

namespace aid {

	class iGood {

	public:
		virtual ~iGood() {};
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual	std::istream& read(std::istream& is) = 0;
		virtual	bool operator==(const char*) const = 0;
		virtual	double total_cost() const = 0;
		virtual	const char* name() const = 0;
		virtual	void quantity(int) = 0;
		virtual	int qtyNeeded() const = 0;
		virtual	int quantity() const = 0;
		virtual	int operator+=(int) = 0;
		virtual	bool operator>(const iGood&) const = 0;




	};
	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);
	iGood* CreateGood();
	iGood* CreatePerishable();


}



#endif 
