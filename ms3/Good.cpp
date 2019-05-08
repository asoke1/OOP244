// Final Project Milestone 3
//	File       : Good.cpp
// Version 1.0
// Date        : 2018-11-16
// Author      : Abiodun Stephen Oke
//Description
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Good.h"
using namespace std;

namespace aid {



	void Good::name(const char* name)
	{
		if (name != nullptr)
		{
			int length = strlen(name);
			mName = new char[length + 1];
			strcpy(mName, name);
			mName[length] = '\0';
		}
		else {
			mName = nullptr;
		}
	}

	// return name
	const char * Good::name() const
	{
		return mName;
	}

	// return sku
	const char * Good::sku() const
	{
		return mSku;
	}

	// return unit
	const char * Good::unit() const
	{
		return mUnit;
	}

	// return taxable
	bool Good::taxed() const
	{
		return mTaxable;
	}

	// return price
	double Good::itemPrice() const
	{
		return mPrice;
	}

	// return price + taxed
	double Good::itemCost() const
	{
		return mTaxable ? mPrice * (1.0 + tax_rate) : mPrice;
	}

	void Good::message(const char * msg)
	{
		mError.message(msg);
	}

	bool Good::isClear() const
	{
		return mError.isClear();
	}


	// Constructor
	Good::Good(const char type)
	{
		mTypeGood = type;
		mSku[0] = '\0';
		mUnit[0] = '\0';
		mName = nullptr;
		mQuantityHand = 0;
		mQuantityNeeded = 0;
		mPrice = 0;
		mTaxable = false;
		mError.message();
	}

	// Seven argument Constructor 
	Good::Good(const char * sku, const char * pname, const char * unit, int qty, bool taxed, double price, int qtyNeeded)
	{
		strncpy(mSku, sku, max_sku_length);
		mSku[max_sku_length] = '\0';
		name(pname);
		strncpy(mUnit, unit, max_unit_length);
		mUnit[max_unit_length] = '\0';
		mQuantityHand = qty;
		mTaxable = taxed;
		mPrice = price;
		mQuantityNeeded = qtyNeeded;

	}

	// Copy Constructor 
	Good::Good(Good& obj)
	{
		mName = nullptr;
		*this = obj;
	}

	// Distructor
	Good::~Good()
	{
		delete[] mName;
		mName = nullptr;
	}

	// Copy Assignment Operator 
	Good & Good::operator=(const Good& obj)
	{
		if (this != &obj)
		{
			strcpy(mSku, obj.mSku);
			strcpy(mUnit, obj.mUnit);
			name(obj.mName);
			mQuantityHand = obj.mQuantityHand;
			mTaxable = obj.mTaxable;
			mPrice = obj.mPrice;
			mQuantityNeeded = obj.mQuantityNeeded;
		}
		return *this;
	}

	bool Good::operator==(const char* sku) const
	{
		return (strcmp(mSku, sku) == 0);
	}

	bool Good::operator>(const char* sku) const
	{
		return strcmp(mSku, sku) > 0;
	}

	bool Good::operator>(const Good & obj) const
	{
		return strcmp(mName, obj.name()) > 0;
	}

	int Good::operator+=(int add)
	{
		return (mQuantityHand += (add > 0 ? add : 0));
	}

	double Good::total_cost() const
	{
		return itemCost() * mQuantityHand;
	}

	void Good::quantity(int no)
	{
		mQuantityHand = no;
	}

	bool Good::isEmpty() const
	{
		return mName == nullptr && mSku[0] == '\0' && mUnit[0] == '\0' && mQuantityHand == 0 && mPrice == 0 && mTaxable == false;
	}

	int Good::qtyNeeded() const
	{
		return mQuantityNeeded;
	}

	int Good::quantity() const
	{
		return mQuantityHand;
	}

	std::fstream & Good::store(std::fstream & file, bool newLine) const
	{
		file << mTypeGood << "," << mSku << ',' << mName << ',' << mUnit
			<< ',' << mTaxable << ',' << quantity() << ',' << qtyNeeded();
		if (newLine)
		{
			file << endl;

		}
		return file;

	}

	std::fstream & Good::load(std::fstream & file)
	{
		char tmpSku[max_sku_length + 1];
		char tmpUnit[max_unit_length + 1];
		char tmpName[max_name_length + 1];
		int tmpQty;
		int tmpQtyNeeded;
		double tmpPrice;
		char tax;

		file.getline(tmpSku, 1999, '\t');
		file.getline(tmpName, 1999, '\t');
		file.getline(tmpUnit, 1999, '\t');

		file >> tax;
		file.ignore();
		file >> tmpPrice;
		file.ignore();
		file >> tmpQty;
		file.ignore();
		file >> tmpQtyNeeded;
		file.ignore();

		*this = Good(tmpSku, tmpName, tmpUnit, tmpQty, tax != '0', tmpPrice, tmpQtyNeeded);
		return file;

	}

	std::ostream & Good::write(std::ostream & os, bool linear) const
	{
		if (!mError.isClear())
		{
			os << mError.message();
		}
		else if (!isEmpty())
		{
			char N[75];
			int qt = mQuantityHand;
			if (linear)
			{
				strncpy(N, mName, 20);
				N[20] = 0;
				os << std::setw(max_sku_length) << std::left << mSku << "|" << std::setw(20) << std::left << N << "|"
					<< std::setw(7) << std::fixed << std::setprecision(2) << std::right << itemCost() << "|" << std::setw(4) << std::right << qt << "|" << std::setw(10) << std::left << mUnit << "|" << std::setw(4) << std::right << mQuantityNeeded << "|";
			}
			else {
				strncpy(N, mName, 74);
				N[74] = 0;
				os << " Sku: " << mSku << std::endl
					<< " Name (no spaces): " << N << std::endl
					<< " Price: " << mPrice << std::endl
					<< " Price after tax: ";
				if (mTaxable)
				{
					os << itemCost() << std::endl;
				}
				else {
					os << " N/A" << std::endl;
					os << " Quantity on hand: " << qt << " " << mUnit << std::endl
						<< " Quantity needed: " << mQuantityNeeded;
				}
			}

		}
		return os;

	}

	std::istream & Good::read(std::istream & is)
	{
		char tmpSku[max_sku_length + 1];
		char tmpUnit[max_unit_length + 1];
		char tmpName[max_name_length + 1];
		int tmpQty;
		int tmpQtyNeeded;
		double tmpPrice;
		char tax;

		if (!is.fail()) mError.clear();

		std::cout << " Sku: ";
		is.getline(tmpSku, max_sku_length, '\n');
		std::cout << " Name (no spaces): ";
		is.getline(tmpName, 74, '\n');
		std::cout << " Unit: ";
		is.getline(tmpUnit, 10, '\n');
		std::cout << " Taxed? (y/n): ";
		is >> tax;

		if (tax == 'y' || tax == 'Y' || tax == 'n' || tax == 'N') {
			std::cin.ignore(1000, '\n');
			std::cout << " Price: ";
			is >> tmpPrice;
		}
		else {
			is.setstate(std::ios::failbit);
			mError.message("Only (Y)es or (N)o are acceptable");
		}
		if (mError.isClear() && is.fail()) {
			mError.message("Invalid Price Entry");
		}
		if (mError.isClear()) {
			std::cout << " Quantity on hand: ";
			std::cin >> tmpQty;
		}
		if (mError.isClear() && is.fail()) {
			mError.message("Invalid Quantity Entry");
		}
		if (mError.isClear()) {
			std::cout << " Quantity needed: ";
			std::cin >> tmpQtyNeeded;
			std::cin.ignore();
		}
		if (mError.isClear() && is.fail()) {
			mError.message("Invalid Quantity Needed Entry");
		}


		if (!is.fail())
			*this = Good(tmpSku, tmpName, tmpUnit, tmpQty, tax == 'y' || tax == 'Y', tmpPrice, tmpQtyNeeded);

		return is;

	}


	// helper functions
	std::ostream & operator<<(std::ostream & os, const Good & obj)
	{
		return obj.write(os, true);
	}

	std::istream & operator>>(std::istream& is, Good & obj)
	{
		return obj.read(is);
	}

	double operator+=(double & add, const Good & obj)
	{
		return obj.total_cost() + add;
	}

}