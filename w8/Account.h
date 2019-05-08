// Final Project:  Account.h
// Lab8 
// Version 1.0
// Date        : 2018-11-15
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"

namespace sict {

	class Account : public iAccount
	{
		double mBalance;
	protected:
		double balance() const;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);


	};




}

#endif // !SICT_ACCOUNT_H
