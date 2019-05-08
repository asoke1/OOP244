// Final Project Milestone 5
//	File       : Perishable.h
// Version 1.0
// Date        : 2018-11-28
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////


#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include "Good.h"
#include "Date.h"

namespace aid {

	class Perishable : public Good
	{
		//Private data
	//private:
		Date expirDate;

		// Public member functions
	public:

		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;



	};

}

#endif