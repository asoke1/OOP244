// Final Project:  ChequingAccount.h
// Workshop    : at home 
// Version 1.0
// Date        : 2018-11-19
// Author      : Abiodun Stephen Oke
// Student ID  : 117180166
// Section     : SGG
// Seneca email: asoke@myseneca.ca
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sict {
		
	class ChequingAccount : public Account
	{
		double mTransFee;
		double mMonthFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;

	};



}

#endif