// Final Project:  Account.cpp
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

#include "Account.h"

namespace sict {


	// returns the current balance of the account
	double Account::balance() const
	{
		return mBalance;
	}

	// Constructor
	Account::Account(double balance)
	{
		mBalance = (balance > 0 ? balance : 0);
	}

	bool Account::credit(double balance)
	{
		mBalance += (balance > 0 ? balance : 0);
		return balance > 0;
	}

	bool Account::debit(double balance)
	{
		mBalance -= (balance > 0 ? balance : 0);
		return balance > 0;
	}

}