// Final Project Milestone 3
//	File       : Good.h
// Version 1.0
// Date        : 2018-11-16
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AID_GOOD_H
#define	AID_GOOD_H
#include <fstream>
#include "iGood.h"
#include "Error.h"

namespace aid {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Good : public iGood
	{
		// private data member
		char mTypeGood;
		char mSku[max_sku_length + 1];
		char mUnit[max_unit_length];
		char* mName; // contain the name of good
		int mQuantityHand;
		int mQuantityNeeded;
		double mPrice;
		bool mTaxable;
		Error mError;
		// Protected member functions:
	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;

		// Public member functions:
	public:
		// Constructors
		Good(const char type = 'N');
		Good(const char* sku, const char* name, const char* unit, int qty = 0, bool taxed = true, double price = 0, int qtyNeeded = 0);
		Good(Good&);
		~Good();

		// Operators
		Good& operator=(const Good&);
		bool operator==(const char*) const;
		bool operator>(const char*) const;
		bool operator>(const iGood&) const; // changed
		int operator+=(int);


		//
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;


		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

	};

	// Helper functions:
	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&); // Changed
	iGood* CreateGood();

}

#endif // ! AID_GOOD_H

