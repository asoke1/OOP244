// Final Project:  Allocator.cpp
// workshop    : at home 
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

#include "SavingsAccount.h"
#include "ChequingAccount.h"
namespace sict {

	const double rate = 0.05;
	const double transactionfee = 0.50;
	const double monthlyfee = 2.00;


	iAccount* CreateAccount(const char* type, double balance)
	{
		if (type[0] == 'S')
		{
			return new SavingsAccount(balance, rate);
		}
		else if (type[0] == 'C')
		{
			return new ChequingAccount(balance, transactionfee, monthlyfee);
		}
		else {
			return nullptr;
		}
	}

	iAccount::~iAccount() {}

}