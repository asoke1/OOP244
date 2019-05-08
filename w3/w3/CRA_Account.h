
/**********************************************************
* Name: Abiodun Oke
* Date : 2018/10/01
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4; // maximum number of tax years

	class CRA_Account
	{
		char m_fname[max_name_length + 1];
		char m_gname[max_name_length + 1];
		int m_sin;
		int m_taxYrs[max_yrs]; // hold the tax return years
		double m_balDue[max_yrs]; // balance owed
		int m_numYrs; // number of years stored

	public:
		void set(int year, double balance);
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		bool isValidSin(int sin) const;

	};



}
#endif // !SICT_CRA_ACCOUNT_H

