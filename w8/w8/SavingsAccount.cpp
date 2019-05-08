// Final Project:  SavingsAccount.cpp
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

#include "SavingsAccount.h"
using namespace std;

namespace sict {
	// Constructor
	SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance)
	{
		mRate = (rate > 0 ? rate : 0);
	}

	void SavingsAccount::monthEnd()
	{
		credit(balance() * mRate);
	}

	void SavingsAccount::display(std::ostream & os) const
	{
		os.setf(ios::fixed);
		os.precision(2);

		os << "Account type: Savings" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << mRate * 100 << endl;

	}


}