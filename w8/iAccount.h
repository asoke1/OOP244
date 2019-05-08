// Final Project:  iAccount.h
// Lab8 
// Version 1.0
// Date        : 2018-11-15
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>

namespace sict {

	class iAccount {
		
	public:
		virtual ~iAccount() = 0;
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;

	};

	iAccount* CreateAccount(const char*, double);

}

#endif // !1