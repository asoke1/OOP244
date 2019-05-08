// Final Project:  SavingsAccount.h
// Lab8 
// Version 1.0
// Date        : 2018-11-15
// Author      : Abiodun Stephen Oke
// Student ID  : 117180166
// Section     : SGG
// Seneca email: asoke@myseneca.ca
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account
	{
		double mRate;
	public:
		SavingsAccount(double = 0, double = 0);
		void monthEnd();
		void display(std::ostream&) const;

	};


}


#endif