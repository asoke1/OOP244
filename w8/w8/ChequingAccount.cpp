// Final Project:  ChequingAccount.cpp
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

//#include <iostream>

#include "ChequingAccount.h"
using namespace std;

namespace sict {



	ChequingAccount::ChequingAccount(double balance, double transaction, double month) : Account(balance)
	{
		if (transaction > 0 && month > 0)
		{
			mTransFee = transaction;
			mMonthFee = month;
		}
		else {
			mTransFee = 0;
			mMonthFee = 0;
		}
	}

	bool ChequingAccount::credit(double add)
	{
		bool value = false;
		if (Account::credit(add))
		{
			Account::debit(mTransFee);
			return value = true;
		}
		return value;
	}

	bool ChequingAccount::debit(double subtr)
	{
		bool value = false;
		if (Account::debit(subtr))
		{
			Account::debit(mTransFee);
			value = true;
		}
		return value;
	}

	void ChequingAccount::monthEnd()
	{
		Account::debit(mMonthFee);
	}

	void ChequingAccount::display(std::ostream & ostr) const
	{
		ostr.setf(ios::fixed);

		ostr.precision(2);
		ostr << "Account type: Chequing" << endl;
		ostr << "Balance: $" << balance() << endl;
		ostr << "Per Transaction Fee: " << mTransFee << endl;
		ostr << "Monthly Fee: " << mMonthFee << endl;

	}

}
