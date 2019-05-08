// Final Project:  Allocator.cpp
// Lab8 
// Version 1.0
// Date        : 2018-11-15
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include "SavingsAccount.h"

namespace sict {

	const double rate = 0.05;

	iAccount* CreateAccount(const char* type, double balance)
	{
		if (type[0] == 'S')
		{
			return new SavingsAccount(balance, rate);
		}
		else {
			return nullptr;
		}
	}

	iAccount::~iAccount(){}

}